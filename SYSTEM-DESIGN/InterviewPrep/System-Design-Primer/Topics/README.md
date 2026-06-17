# System Design Primer — In-Depth Topics

This folder contains **deep-dive notes** for the major topics extracted from
[`../Overview.md`](../Overview.md). Each file expands a topic that has real **scope for
exploration** — beyond the summary in the Overview — with diagrams, comparison tables,
trade-offs, interview talking points, and pointers for further study.

> Topics that are short comparisons or simple reference tables (e.g., *Performance vs
> Scalability*, *Latency vs Throughput*, *Availability in Numbers*, the *RPC/REST table*)
> were **kept in the Overview** rather than split out.

---

## 📚 Index

### Consistency & Availability Theory
| Topic | What it covers |
|-------|----------------|
| [CAP Theorem](./CAP-Theorem.md) | CP/AP/CA, PACELC, DB classifications, misconceptions |
| [Consistency Patterns](./Consistency-Patterns.md) | Weak/eventual/strong, quorums (N,W,R), conflict resolution |
| [Availability Patterns](./Availability-Patterns.md) | Fail-over, replication, the 9s, sequence vs parallel |

### Networking & Infrastructure
| Topic | What it covers |
|-------|----------------|
| [DNS](./DNS.md) | Hierarchy, lookup flow, records, routing policies, security |
| [CDN](./CDN.md) | Push vs pull, invalidation, edge compute |
| [Load Balancer](./Load-Balancer.md) | L4 vs L7, algorithms, horizontal scaling |
| [Reverse Proxy](./Reverse-Proxy.md) | Benefits, LB vs reverse proxy, tooling |

### Application & Data
| Topic | What it covers |
|-------|----------------|
| [Application Layer](./Application-Layer.md) | Microservices, service discovery, monolith vs services |
| [RDBMS](./RDBMS.md) | ACID, replication, federation, sharding, denormalization, SQL tuning, indexes |
| [NoSQL](./NoSQL.md) | Key-value, document, wide-column, graph, BASE, SQL-or-NoSQL |
| [Cache](./Cache.md) | Levels, cache-aside/write-through/write-behind/refresh-ahead, eviction, stampede |

### Communication & Async
| Topic | What it covers |
|-------|----------------|
| [Asynchronism](./Asynchronism.md) | Message/task queues, back pressure, delivery guarantees |
| [Communication](./Communication.md) | HTTP, TCP, UDP, RPC, REST, gRPC, GraphQL |

---

## How these map to the Overview

| Overview Section | Deep-Dive File |
|------------------|----------------|
| Availability vs Consistency (CAP Theorem) | `CAP-Theorem.md` |
| Consistency Patterns | `Consistency-Patterns.md` |
| Availability Patterns + Availability in Numbers + Parallel/Sequence | `Availability-Patterns.md` |
| Domain Name Systems (DNS) | `DNS.md` |
| CDN | `CDN.md` |
| Load Balancer | `Load-Balancer.md` |
| Reverse Proxy | `Reverse-Proxy.md` |
| Application Layer (Microservices, Service Discovery) | `Application-Layer.md` |
| RDBMS + Federation + Sharding + Denormalization + SQL Tuning | `RDBMS.md` |
| NoSQL + Key-Value/Document/Wide-Column/Graph + SQL-or-NoSQL | `NoSQL.md` |
| Cache | `Cache.md` |
| Asynchronism | `Asynchronism.md` |
| Communication + HTTP/TCP/UDP + RPC + REST | `Communication.md` |

---

*Source material based on the open-source [System Design Primer](https://github.com/donnemartin/system-design-primer), expanded with additional depth.*
