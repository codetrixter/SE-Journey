# System Design Primer - Performance, Scalability, and Availability

## Performance vs Scalability

A service is **scalable** if it results in increased performance in a manner proportional to resources added. Generally, increasing performance means serving more units of work, but it can also be to handle larger units of work, such as when datasets grow.

### Another Way to Look at Performance vs Scalability

- **Performance problem**: Your system is slow for a single user.
- **Scalability problem**: Your system is fast for a single user but slow under heavy load.

---

## Latency vs Throughput

- **Latency**: The time to perform some action or to produce some result.
- **Throughput**: The number of such actions or results per unit of time.

**Goal**: Aim for maximal throughput with acceptable latency.

---

## Availability vs Consistency (CAP Theorem)

In a distributed computer system, you can only support **two** of the following guarantees:

1. **Consistency** - Every read receives the most recent write or an error
2. **Availability** - Every request receives a response, without guarantee that it contains the most recent version of the information
3. **Partition Tolerance** - The system continues to operate despite arbitrary partitioning due to network failures

> **Note**: Networks aren't reliable, so you'll need to support partition tolerance. You'll need to make a software tradeoff between consistency and availability.

### CP - Consistency and Partition Tolerance

Waiting for a response from the partitioned node might result in a timeout error. 

**Use CP when**: Your business needs require atomic reads and writes.

### AP - Availability and Partition Tolerance

Responses return the most readily available version of the data available on any node, which might not be the latest. Writes might take some time to propagate when the partition is resolved.

**Use AP when**: The business needs allow for eventual consistency or when the system needs to continue working despite external errors.

---

## Consistency Patterns

With multiple copies of the same data, we are faced with options on how to synchronize them so clients have a consistent view of the data. 

> **Recall**: Consistency from the CAP theorem means every read receives the most recent write or an error.

### Weak Consistency

After a write, reads may or may not see it. A best effort approach is taken.

**Examples**: Memcached, VoIP, video chat, realtime multiplayer games

**Use case**: Real-time use cases where occasional data loss is acceptable. For example, if you are on a phone call and lose reception for a few seconds, when you regain connection you do not hear what was spoken during connection loss.

### Eventual Consistency

After a write, reads will eventually see it (typically within milliseconds). Data is replicated asynchronously.

**Examples**: DNS, email

**Use case**: Highly available systems where temporary inconsistency is acceptable.

### Strong Consistency

After a write, reads will see it. Data is replicated synchronously.

**Examples**: File systems, RDBMSes

**Use case**: Systems that need transactions and require immediate consistency.

---

## Availability Patterns

There are two complementary patterns to support high availability: **fail-over** and **replication**.

### Fail-over

#### Active-Passive

With active-passive fail-over, heartbeats are sent between the active and the passive server on standby. If the heartbeat is interrupted, the passive server takes over the active's IP address and resumes service.

The length of downtime is determined by whether the passive server is already running in **'hot' standby** or whether it needs to start up from **'cold' standby**. Only the active server handles traffic.

> **Also known as**: Master-slave failover

#### Active-Active

In active-active, both servers are managing traffic, spreading the load between them.

**Configuration requirements**:
- **Public-facing servers**: DNS needs to know about the public IPs of both servers
- **Internal-facing servers**: Application logic needs to know about both servers

> **Also known as**: Master-master failover

#### Disadvantages of Fail-over

- Adds more hardware and additional complexity
- Potential for loss of data if the active system fails before any newly written data can be replicated to the passive

### Replication

Master-slave and master-master replication patterns.

---

## Availability in Numbers
Availability is often quantified by uptime (or downtime) as a percentage of time the service is available. Availability is generally measured in number of 9s—a service with 99.99% availability is described as having **four 9s**.

### 99.9% Availability - Three 9s

| Duration | Acceptable Downtime |
|----------|-------------------|
| Downtime per year | 8h 45min 57s |
| Downtime per month | 43m 49.7s |
| Downtime per week | 10m 4.8s |
| Downtime per day | 1m 26.4s |

### 99.99% Availability - Four 9s

| Duration | Acceptable Downtime |
|----------|-------------------|
| Downtime per year | 52min 35.7s |
| Downtime per month | 4m 23s |
| Downtime per week | 1m 5s |
| Downtime per day | 8.6s |

---

## Availability in Parallel vs in Sequence

If a service consists of multiple components prone to failure, the service's overall availability depends on whether the components are in sequence or in parallel.

### In Sequence

Overall availability **decreases** when two components with availability < 100% are in sequence:

```
Availability (Total) = Availability (Foo) * Availability (Bar)
```

**Example**: If both Foo and Bar each had 99.9% availability, their total availability in sequence would be 99.8%.

### In Parallel

Overall availability **increases** when two components with availability < 100% are in parallel:

```
Availability (Total) = 1 - (1 - Availability (Foo)) * (1 - Availability (Bar))
```

**Example**: If both Foo and Bar each had 99.9% availability, their total availability in parallel would be 99.9999%.

---

## Domain Name Systems

A Domain Name System (DNS) translates a domain name such as www.example.com to an IP address.

DNS is hierarchical, with a few authoritative servers at the top level. Your router or ISP provides information about which DNS server(s) to contact when doing a lookup. Lower level DNS servers cache mappings, which could become stale due to DNS propagation delays. DNS results can also be cached by your browser or OS for a certain period of time, determined by the time to live (TTL).

- NS record (name server) - Specifies the DNS servers for your domain/subdomain.
- MX record (mail exchange) - Specifies the mail servers for accepting messages.
- A record (address) - Points a name to an IP address.
- CNAME (canonical) - Points a name to another name or CNAME (example.com to www.example.com) or to an A record.

Services such as CloudFlare and Route 53 provide managed DNS services. Some DNS services can route traffic through various methods:

- Weighted round robin
Prevent traffic from going to servers under maintenance
Balance between varying cluster sizes
A/B testing
- Latency-based
- Geolocation-based

Disadvantage(s): DNS
Accessing a DNS server introduces a slight delay, although mitigated by caching described above.
DNS server management could be complex and is generally managed by governments, ISPs, and large companies.
DNS services have recently come under DDoS attack, preventing users from accessing websites such as Twitter without knowing Twitter's IP address(es).

---

## CDN(Content Delivery Network)

A content delivery network (CDN) is a globally distributed network of proxy servers, serving content from locations closer to the user. Generally, static files such as HTML/CSS/JS, photos, and videos are served from CDN, although some CDNs such as Amazon's CloudFront support dynamic content. The site's DNS resolution will tell clients which server to contact.

Serving content from CDNs can significantly improve performance in two ways:

Users receive content from data centers close to them
Your servers do not have to serve requests that the CDN fulfills

Push CDNs
Push CDNs receive new content whenever changes occur on your server. You take full responsibility for providing content, uploading directly to the CDN and rewriting URLs to point to the CDN. You can configure when content expires and when it is updated. Content is uploaded only when it is new or changed, minimizing traffic, but maximizing storage.

Sites with a small amount of traffic or sites with content that isn't often updated work well with push CDNs. Content is placed on the CDNs once, instead of being re-pulled at regular intervals.

Pull CDNs
Pull CDNs grab new content from your server when the first user requests the content. You leave the content on your server and rewrite URLs to point to the CDN. This results in a slower request until the content is cached on the CDN.

A time-to-live (TTL) determines how long content is cached. Pull CDNs minimize storage space on the CDN, but can create redundant traffic if files expire and are pulled before they have actually changed.

Sites with heavy traffic work well with pull CDNs, as traffic is spread out more evenly with only recently-requested content remaining on the CDN.

Disadvantage(s): CDN
CDN costs could be significant depending on traffic, although this should be weighed with additional costs you would incur not using a CDN.
Content might be stale if it is updated before the TTL expires it.
CDNs require changing URLs for static content to point to the CDN.