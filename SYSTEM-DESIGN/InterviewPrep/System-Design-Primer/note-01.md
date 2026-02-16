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