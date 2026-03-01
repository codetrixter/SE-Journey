# System Design Primer - Performance, Scalability, and Availability

## Performance vs Scalability

A service is **scalable** if it results in increased performance in a manner proportional to resources added. Generally, increasing performance means serving more units of work, but it can also be to handle larger u### Load Balancer vs Reverse Proxy

Deploying a load balancer is useful when you have multiple servers. Often, load balancers route traffic to a set of servers serving the same function.

Reverse proxies can be useful even with just one web server or application server, opening up the benefits described in the previous section.

Solutions such as NGINX and HAProxy can support both layer 7 reverse proxying and load balancing.

### Disadvantage(s): Reverse Proxy

- Introducing a reverse proxy results in increased complexity.
- A single reverse proxy is a single point of failure, configuring multiple reverse proxies (ie a failover) further increases complexity.

### Source(s) and Further Reading

- [Reverse proxy vs load balancer](https://www.nginx.com/resources/glossary/reverse-proxy-vs-load-balancer/)
- [NGINX architecture](https://www.nginx.com/blog/inside-nginx-how-we-designed-for-performance-scale/)
- [HAProxy architecture guide](http://www.haproxy.org/#docs)
- [Wikipedia](https://en.wikipedia.org/wiki/Reverse_proxy), such as when datasets grow.

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

1. Master-slave replication patterns.
2. Master-master replication patterns.

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

- **Weighted round robin**
  - Prevent traffic from going to servers under maintenance
  - Balance between varying cluster sizes
  - A/B testing
- **Latency-based**
- **Geolocation-based**

### Disadvantage(s): DNS

- Accessing a DNS server introduces a slight delay, although mitigated by caching described above.
- DNS server management could be complex and is generally managed by governments, ISPs, and large companies.
- DNS services have recently come under DDoS attack, preventing users from accessing websites such as Twitter without knowing Twitter's IP address(es).

---

## CDN (Content Delivery Network)

A content delivery network (CDN) is a globally distributed network of proxy servers, serving content from locations closer to the user. Generally, static files such as HTML/CSS/JS, photos, and videos are served from CDN, although some CDNs such as Amazon's CloudFront support dynamic content. The site's DNS resolution will tell clients which server to contact.

Serving content from CDNs can significantly improve performance in two ways:

- Users receive content from data centers close to them
- Your servers do not have to serve requests that the CDN fulfills

### Push CDNs

Push CDNs receive new content whenever changes occur on your server. You take full responsibility for providing content, uploading directly to the CDN and rewriting URLs to point to the CDN. You can configure when content expires and when it is updated. Content is uploaded only when it is new or changed, minimizing traffic, but maximizing storage.

**Use case**: Sites with a small amount of traffic or sites with content that isn't often updated work well with push CDNs. Content is placed on the CDNs once, instead of being re-pulled at regular intervals.

### Pull CDNs

Pull CDNs grab new content from your server when the first user requests the content. You leave the content on your server and rewrite URLs to point to the CDN. This results in a slower request until the content is cached on the CDN.

A time-to-live (TTL) determines how long content is cached. Pull CDNs minimize storage space on the CDN, but can create redundant traffic if files expire and are pulled before they have actually changed.

**Use case**: Sites with heavy traffic work well with pull CDNs, as traffic is spread out more evenly with only recently-requested content remaining on the CDN.

### Disadvantage(s): CDN

- CDN costs could be significant depending on traffic, although this should be weighed with additional costs you would incur not using a CDN.
- Content might be stale if it is updated before the TTL expires it.
- CDNs require changing URLs for static content to point to the CDN.

---

## Load Balancer

Load balancers distribute incoming client requests to computing resources such as application servers and databases. In each case, the load balancer returns the response from the computing resource to the appropriate client. 

### Benefits

Load balancers are effective at:

- **Preventing requests from going to unhealthy servers**
- **Preventing overloading resources**
- **Helping to eliminate a single point of failure**

Load balancers can be implemented with hardware (expensive) or with software such as HAProxy.

### Additional Benefits

- **SSL termination** - Decrypt incoming requests and encrypt server responses so backend servers do not have to perform these potentially expensive operations
  - Removes the need to install X.509 certificates on each server
  - **X.509 Certificates**: An ITU standard format for public key certificates that bind an identity (hostname, organization, or individual) to a public key using digital signatures. Used in TLS/SSL (HTTPS) and can be signed by a Certificate Authority (CA) or self-signed. Enables secure communication when validated.
- **Session persistence** - Issue cookies and route a specific client's requests to same instance if the web apps do not keep track of sessions

To protect against failures, it's common to set up multiple load balancers, either in active-passive or active-active mode.

### Load Balancing Methods

Load balancers can route traffic based on various metrics, including:

- Random
- Least loaded
- Session/cookies
- Round robin or weighted round robin
- Layer 4
- Layer 7

### Layer 4 Load Balancing

Layer 4 load balancers look at info at the transport layer to decide how to distribute requests. Generally, this involves the source, destination IP addresses, and ports in the header, but not the contents of the packet. Layer 4 load balancers forward network packets to and from the upstream server, performing Network Address Translation (NAT).

### Layer 7 Load Balancing

Layer 7 load balancers look at the application layer to decide how to distribute requests. This can involve contents of the header, message, and cookies. Layer 7 load balancers terminate network traffic, reads the message, makes a load-balancing decision, then opens a connection to the selected server. 

**Example**: A layer 7 load balancer can direct video traffic to servers that host videos while directing more sensitive user billing traffic to security-hardened servers.

At the cost of flexibility, layer 4 load balancing requires less time and computing resources than Layer 7, although the performance impact can be minimal on modern commodity hardware.

### Horizontal Scaling

Load balancers can also help with horizontal scaling, improving performance and availability. Scaling out using commodity machines is more cost efficient and results in higher availability than scaling up a single server on more expensive hardware, called Vertical Scaling. It is also easier to hire for talent working on commodity hardware than it is for specialized enterprise systems.

### Disadvantage(s): Horizontal Scaling

- Scaling horizontally introduces complexity and involves cloning servers
- Servers should be stateless: they should not contain any user-related data like sessions or profile pictures
- Sessions can be stored in a centralized data store such as a database (SQL, NoSQL) or a persistent cache (Redis, Memcached)
- Downstream servers such as caches and databases need to handle more simultaneous connections as upstream servers scale out

### Disadvantage(s): Load Balancer

- The load balancer can become a performance bottleneck if it does not have enough resources or if it is not configured properly.
- Introducing a load balancer to help eliminate a single point of failure results in increased complexity.
- A single load balancer is a single point of failure, configuring multiple load balancers further increases complexity.

### Source(s) and Further Reading

- [NGINX architecture](https://www.nginx.com/blog/inside-nginx-how-we-designed-for-performance-scale/)
- [HAProxy architecture guide](http://www.haproxy.org/#docs)
- [Scalability](http://www.lecloud.net/post/7295452622/scalability-for-dummies-part-1-clones)
- [Wikipedia](https://en.wikipedia.org/wiki/Load_balancing_(computing))
- [Layer 4 load balancing](https://www.nginx.com/resources/glossary/layer-4-load-balancing/)
- [Layer 7 load balancing](https://www.nginx.com/resources/glossary/layer-7-load-balancing/)
- [ELB listener config](http://docs.aws.amazon.com/elasticloadbalancing/latest/classic/elb-listener-config.html)

---

## Reverse Proxy (Web Server)

A reverse proxy is a web server that centralizes internal services and provides unified interfaces to the public. Requests from clients are forwarded to a server that can fulfill it before the reverse proxy returns the server's response to the client.

### Additional Benefits

- **Increased security** - Hide information about backend servers, blacklist IPs, limit number of connections per client
- **Increased scalability and flexibility** - Clients only see the reverse proxy's IP, allowing you to scale servers or change their configuration
- **SSL termination** - Decrypt incoming requests and encrypt server responses so backend servers do not have to perform these potentially expensive operations
  - Removes the need to install X.509 certificates on each server
  - **X.509 Certificates**: An ITU standard format for public key certificates that bind an identity (hostname, organization, or individual) to a public key using digital signatures. Used in TLS/SSL (HTTPS) and can be signed by a Certificate Authority (CA) or self-signed. Enables secure communication when validated.
- **Compression** - Compress server responses
- **Caching** - Return the response for cached requests
- **Static content** - Serve static content directly
  - HTML/CSS/JS
  - Photos
  - Videos

### Load Balancer vs Reverse Proxy
Deploying a load balancer is useful when you have multiple servers. Often, load balancers route traffic to a set of servers serving the same function.
Reverse proxies can be useful even with just one web server or application server, opening up the benefits described in the previous section.
Solutions such as NGINX and HAProxy can support both layer 7 reverse proxying and load balancing.
Disadvantage(s): reverse proxy
Introducing a reverse proxy results in increased complexity.
A single reverse proxy is a single point of failure, configuring multiple reverse proxies (ie a failover) further increases complexity.
Source(s) and further reading
Reverse proxy vs load balancer
NGINX architecture
HAProxy architecture guide
Wikipedia

---

## Application Layer

Separating out the web layer from the application layer (also known as platform layer) allows you to scale and configure both layers independently. Adding a new API results in adding application servers without necessarily adding additional web servers. The single responsibility principle advocates for small and autonomous services that work together. Small teams with small services can plan more aggressively for rapid growth.

Workers in the application layer also help enable asynchronism.

### Microservices

Related to this discussion are microservices, which can be described as a suite of independently deployable, small, modular services. Each service runs a unique process and communicates through a well-defined, lightweight mechanism to serve a business goal.

Pinterest, for example, could have the following microservices: user profile, follower, feed, search, photo upload, etc.

### Service Discovery

Systems such as Consul, Etcd, and Zookeeper can help services find each other by keeping track of registered names, addresses, and ports. Health checks help verify service integrity and are often done using an HTTP endpoint. Both Consul and Etcd have a built in key-value store that can be useful for storing config values and other shared data.

### Disadvantage(s): Application Layer

- Adding an application layer with loosely coupled services requires a different approach from an architectural, operations, and process viewpoint (vs a monolithic system).
- Microservices can add complexity in terms of deployments and operations.

### Source(s) and Further Reading

- [Intro to architecting systems for scale](http://lethain.com/introduction-to-architecting-systems-for-scale/)
- [Crack the system design interview](http://www.puncsky.com/blog/2016-02-13-crack-the-system-design-interview)
- [Service oriented architecture](https://en.wikipedia.org/wiki/Service-oriented_architecture)
- [Introduction to Zookeeper](http://www.slideshare.net/sauravhaloi/introduction-to-apache-zookeeper)
- [Here's what you need to know about building microservices](https://cloudncode.wordpress.com/2016/07/22/msa-getting-started/)