# System Design — Coverage Analysis

> **Last Analyzed:** April 7, 2026
> **Source Folder:** `SYSTEM-DESIGN/`
> **Reference:** `System-design-concepts-scope.md`

---

## 📊 Coverage Summary

| Section | Must Know | Should Know | Nice to Have | Status |
|---------|-----------|-------------|--------------|--------|
| Fundamentals of System Design | 🟢 Done | 🟡 Partial | N/A | Mostly Complete |
| Networking & Communication | 🟡 Partial | 🟡 Partial | 🔴 Not Started | In Progress |
| Load Balancing & Reverse Proxy | 🟡 Partial | 🟡 Partial | 🔴 Not Started | In Progress |
| Caching | 🟡 Partial | 🟡 Partial | 🔴 Not Started | In Progress |
| Database Design | 🟡 Partial | 🟡 Partial | 🔴 Not Started | In Progress |
| Database Scaling & Replication | 🟡 Partial | 🟡 Partial | 🔴 Not Started | In Progress |
| Distributed Systems Concepts | 🟡 Partial | 🟡 Partial | 🔴 Not Started | In Progress |
| Message Queues & Event Streaming | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Storage & Data Systems | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Microservices Architecture | 🟡 Partial | 🔴 Not Started | 🔴 Not Started | In Progress |
| Reliability & Fault Tolerance | 🟡 Partial | 🔴 Not Started | 🔴 Not Started | In Progress |
| Scalability Patterns | 🟡 Partial | 🔴 Not Started | 🔴 Not Started | In Progress |
| Monitoring, Logging & Observability | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Security in System Design | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Classic System Design Problems | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |

**Sources:**
- `FOUNDATIONS-OF-DATA-SYSTEMS/Chapter1.md` — Reliability, Scalability, Maintainability (DDIA Ch. 1)
- `FOUNDATIONS-OF-DATA-SYSTEMS/Chapter2.md` — Data Models and Query Languages (DDIA Ch. 2)
- `InterviewPrep/System-Design-Primer/Overview.md` — Comprehensive system design primer covering: performance vs scalability, latency vs throughput, CAP theorem, consistency patterns, availability patterns, DNS, CDN, load balancers, reverse proxy, microservices, RDBMS, sharding, denormalization, SQL tuning, NoSQL, caching, async/messaging, communication (HTTP/TCP/UDP), RPC, REST

---

## 1. Fundamentals of System Design

### 1.1 Requirements Gathering
- [x] **Must Know:** Functional requirements — *Covered in DDIA Ch.1 (system design thinking)*
- [x] **Must Know:** Non-functional requirements — scalability, availability, latency — *Covered in DDIA Ch.1 and Primer (performance vs scalability)*
- [ ] **Must Know:** Clarifying questions — users, scale, read/write ratio

### 1.2 Back-of-the-Envelope Estimation
- [ ] **Must Know:** QPS estimation
- [ ] **Must Know:** Storage estimation
- [ ] **Must Know:** Bandwidth estimation
- [ ] **Must Know:** Memory estimation
- [x] **Should Know:** Powers of 2, common latencies — *Covered in Primer (latency numbers)*

### 1.3 SLAs, SLOs, SLIs
- [x] **Must Know:** Availability nines — *Covered in Primer (Availability in Numbers — 99.9%, 99.99%)*
- [x] **Must Know:** Latency percentiles — p50, p95, p99 — *Covered in DDIA Ch.1 (performance measurement)*
- [ ] **Should Know:** Error budgets
- [ ] **Should Know:** SLI metrics

### 1.4 Trade-offs
- [x] **Must Know:** Consistency vs availability (CAP theorem) — *Covered in Primer (Availability vs Consistency, CP/AP)*
- [x] **Must Know:** Latency vs throughput — *Covered in Primer (Latency vs Throughput section)*
- [ ] **Must Know:** Cost vs performance
- [ ] **Should Know:** Simplicity vs flexibility

### 1.5 Design Methodology
- [x] **Must Know:** Top-down decomposition — *Covered in DDIA Ch.1 (system design approach)*
- [ ] **Must Know:** Iterative refinement
- [ ] **Should Know:** Constraint-driven design

### ✅ Checklist – Fundamentals
- [x] Requirements gathering basics understood
- [ ] Back-of-envelope calculations practiced
- [x] Availability nines table covered
- [x] Latency numbers covered
- [ ] Design methodology applied in mock interviews

---

## 2. Networking & Communication

### 2.1 Communication Protocols
- [x] **Must Know:** REST — resource-oriented, HTTP methods, status codes — *Covered in Primer (REST section, HTTP)*
- [x] **Must Know:** gRPC — *Mentioned in Primer (RPC section)*
- [ ] **Should Know:** GraphQL
- [ ] **Should Know:** WebSockets

### 2.2 Message Formats
- [ ] **Must Know:** JSON
- [ ] **Must Know:** Protocol Buffers
- [ ] **Should Know:** Avro

### 2.3 API Gateway
- [ ] **Must Know:** Routing, request transformation
- [ ] **Must Know:** Rate limiting, authentication at edge

### 2.4 Service Mesh
- [ ] **Should Know:** Sidecar proxy pattern
- [ ] **Should Know:** Data plane vs control plane

### ✅ Checklist – Networking & Communication
- [x] REST vs RPC trade-offs articulated
- [ ] Protocol Buffers schema designed
- [ ] API gateway components explained
- [ ] Service mesh concept
- [ ] API versioning strategy

---

## 3. Load Balancing & Reverse Proxy

### 3.1 Load Balancing Layers
- [x] **Must Know:** L4 (Transport) — *Covered in Primer (Layer 4 Load Balancing)*
- [x] **Must Know:** L7 (Application) — *Covered in Primer (Layer 7 Load Balancing)*
- [x] **Must Know:** Trade-offs — L4 vs L7 — *Covered in Primer*

### 3.2 Algorithms
- [x] **Must Know:** Round-robin, weighted round-robin — *Covered in Primer (Load Balancing Methods)*
- [x] **Must Know:** Least connections — *Covered in Primer*
- [ ] **Must Know:** Consistent hashing
- [ ] **Should Know:** IP hash
- [ ] **Should Know:** Random, power of two choices

### 3.3-3.6 Health Checks, GSLB, Reverse Proxy, Sticky Sessions
- [x] **Must Know:** Reverse Proxy — SSL termination, caching — *Covered in Primer (Reverse Proxy section)*
- [x] **Should Know:** Nginx, HAProxy — *Covered in Primer (Load Balancer vs Reverse Proxy)*
- [ ] Health checks — **Not Started**
- [ ] GSLB — **Not Started**
- [ ] Sticky sessions — **Not Started**

### ✅ Checklist – Load Balancing
- [x] L4 vs L7 load balancing explained
- [ ] Consistent hashing algorithm
- [ ] Health check strategy
- [x] Nginx / HAProxy mentioned
- [ ] Sticky sessions trade-offs

---

## 4. Caching

### 4.1 Cache Tiers
- [x] **Must Know:** Client-side cache — *Covered in Primer (Client Caching)*
- [x] **Must Know:** CDN cache — *Covered in Primer (CDN Caching)*
- [x] **Must Know:** Application cache — *Covered in Primer (Application Caching)*
- [x] **Must Know:** Database cache — *Covered in Primer (Database Caching)*
- [x] **Should Know:** Reverse proxy cache — *Covered in Primer (Web Server Caching)*

### 4.2 Cache Strategies
- [x] **Must Know:** Cache-aside (lazy loading) — *Covered in Primer (When to Update the Cache)*
- [x] **Must Know:** Write-through — *Covered in Primer*
- [x] **Should Know:** Write-behind (write-back) — *Covered in Primer*
- [x] **Should Know:** Read-through — *Covered in Primer (Refresh-Ahead)*

### 4.3-4.8 Eviction, Invalidation, Distributed, Advanced
- [ ] **Must Know:** LRU eviction
- [ ] **Must Know:** TTL-based invalidation
- [ ] **Must Know:** Redis, Memcached
- [ ] **Should Know:** Cache stampede prevention
- [ ] **Should Know:** CDN invalidation

### ✅ Checklist – Caching
- [x] Cache tiers identified
- [x] Cache-aside vs write-through vs write-behind trade-offs covered
- [ ] LRU eviction implemented
- [ ] Cache invalidation strategy designed
- [ ] Redis vs Memcached decision
- [ ] Cache stampede prevention

---

## 5. Database Design

### 5.1 Relational Databases
- [x] **Must Know:** ACID properties — *Covered in Primer (ACID section under RDBMS)*
- [x] **Must Know:** Normalization — *Covered in Primer (Denormalization section — implies normalization understood)*
- [ ] **Must Know:** SQL queries — JOINs, GROUP BY, window functions
- [ ] **Must Know:** Indexes — B-tree, hash, composite

### 5.2 Query Optimization
- [x] **Should Know:** Query anti-patterns — *Covered in Primer (SQL Tuning section — schema, indices, joins, partitioning, query cache)*
- [x] **Should Know:** Partitioning — *Covered in Primer (Partition Tables)*

### 5.3 NoSQL Categories
- [x] **Must Know:** Key-value stores — *Covered in Primer (Key-Value Store section)*
- [x] **Must Know:** Document stores — *Covered in Primer (Document Store section) and DDIA Ch.2*
- [x] **Must Know:** Column-family stores — *Covered in Primer (Wide Column Store)*
- [x] **Should Know:** Graph databases — *Covered in Primer (Graph Database) and DDIA Ch.2*
- [x] **Should Know:** SQL vs NoSQL decision — *Covered in Primer (SQL or NoSQL section)*

### 5.4 Database Selection
- [x] **Must Know:** Decision criteria — *Covered in Primer and DDIA Ch.2 (data models analysis)*

### ✅ Checklist – Database Design
- [x] ACID properties covered
- [x] Normalization/Denormalization covered
- [ ] Index types and selection
- [x] SQL vs NoSQL decision framework
- [x] NoSQL categories understood (key-value, document, wide-column, graph)
- [x] Database selection justified

---

## 6. Database Scaling & Replication

### 6.1 Scaling Strategies
- [x] **Must Know:** Vertical scaling — *Covered in Primer (Horizontal Scaling section)*
- [x] **Must Know:** Horizontal scaling — *Covered in Primer and DDIA Ch.1 (scaling approaches)*
- [x] **Must Know:** Read replicas — *Covered in Primer (Master-Slave Replication)*

### 6.2 Replication
- [x] **Must Know:** Leader-follower (master-slave) — *Covered in Primer (Master-Slave Replication)*
- [x] **Must Know:** Replication lag — *Covered in Primer*
- [x] **Should Know:** Multi-master — *Covered in Primer (Master-Master Replication)*
- [ ] **Should Know:** Synchronous vs asynchronous replication
- [ ] **Nice to Have:** CRDTs

### 6.3 Sharding
- [x] **Must Know:** Hash-based sharding — *Covered in Primer (Sharding section)*
- [ ] **Must Know:** Range-based sharding
- [ ] **Must Know:** Shard key selection
- [ ] **Should Know:** Directory-based sharding
- [ ] **Should Know:** Cross-shard queries

### 6.4 Database Infrastructure
- [ ] **Should Know:** Connection pooling — **Not Started**

### ✅ Checklist – Database Scaling
- [x] Vertical vs horizontal scaling trade-offs
- [x] Read replica and replication covered
- [x] Sharding strategy covered (basics)
- [ ] Shard key selection with hotspot analysis
- [ ] Cross-shard query strategies
- [ ] Connection pooling

---

## 7. Distributed Systems Concepts

### 7.1 CAP Theorem & Consistency
- [x] **Must Know:** CAP — choose 2 of 3 — *Covered in Primer (Availability vs Consistency, CP/AP)*
- [x] **Must Know:** In practice: choose CP or AP — *Covered in Primer*
- [ ] **Should Know:** PACELC
- [x] **Must Know:** Consistency models — strong, eventual, causal — *Covered in Primer (Consistency Patterns — Weak, Eventual, Strong)*

### 7.2 Consensus Algorithms
- [ ] **Should Know:** Raft — **Not Started**
- [ ] **Should Know:** Paxos — **Not Started**

### 7.3 Distributed Transactions
- [ ] **Must Know:** 2PC — **Not Started**
- [ ] **Must Know:** Saga pattern — **Not Started**

### 7.4 Time & Ordering
- [ ] **Should Know:** Lamport timestamps — **Not Started**
- [ ] **Should Know:** Vector clocks — **Not Started**

### 7.5 Idempotency
- [ ] **Must Know:** Idempotent operations — **Not Started**

### 7.6 Failure Modes
- [x] **Must Know:** Partial failures — *Covered in DDIA Ch.1 (fault types: hardware, software, human)*
- [x] **Must Know:** Cascading failures — *Covered in DDIA Ch.1*
- [ ] **Should Know:** Byzantine failures
- [ ] **Should Know:** Split-brain

### ✅ Checklist – Distributed Systems
- [x] CAP theorem explained with CP/AP examples
- [x] Consistency models compared
- [ ] Raft algorithm
- [ ] Saga pattern
- [ ] Idempotency strategy
- [x] Failure modes identified

---

## 8. Message Queues & Event Streaming
- [x] **Partial:** Message queue and task queue concepts — *Covered in Primer (Asynchronism section — Message Queues, Task Queues, Back Pressure)*
- [ ] Kafka — **Not Started**
- [ ] RabbitMQ — **Not Started**
- [ ] Event-Driven Architecture — **Not Started**
- [ ] Stream Processing — **Not Started**

### ✅ Checklist – Message Queues
- [ ] Kafka architecture explained
- [x] Message queue concept understood
- [x] Back-pressure concept covered
- [ ] Event sourcing + CQRS
- [ ] Kafka vs RabbitMQ
- [ ] Message ordering guarantees

---

## 9. Storage & Data Systems
- [ ] Storage Types — **Not Started**
- [ ] Object Storage — **Not Started**
- [ ] Data Lakes & Warehouses — **Not Started**
- [ ] Specialized Databases — **Not Started**
- [ ] Storage Engine Internals — **Not Started**

---

## 10. Microservices Architecture

### 10.1 Architecture Styles
- [x] **Must Know:** Monolith vs Microservices — *Covered in Primer (Microservices section)*
- [x] **Must Know:** Trade-offs — *Covered in Primer*
- [ ] **Should Know:** Modular monolith

### 10.2-10.6 Service Design, Communication, Discovery, Migration, Observability
- [x] **Should Know:** Service Discovery — *Covered in Primer (Service Discovery section)*
- [ ] DDD, Bounded Contexts — **Not Started**
- [ ] Saga pattern — **Not Started**
- [ ] Distributed tracing — **Not Started**

### ✅ Checklist – Microservices
- [x] Monolith vs microservices trade-offs covered
- [ ] Service boundaries defined using DDD
- [ ] Sync vs async communication decided
- [x] Service discovery mechanism covered
- [ ] Distributed tracing
- [ ] Strangler fig migration

---

## 11. Reliability & Fault Tolerance

### 11.1-11.8 Redundancy, Circuit Breaker, Retry, etc.
- [x] **Must Know:** Redundancy — active-active, active-passive — *Covered in Primer (Availability Patterns — Fail-over: Active-Passive, Active-Active)*
- [x] **Must Know:** Replication — *Covered in Primer (Replication section)*
- [ ] Circuit Breaker — **Not Started**
- [ ] Retry with backoff — **Not Started**
- [ ] Bulkhead Pattern — **Not Started**
- [ ] Rate Limiting — **Not Started**
- [ ] Graceful Degradation — **Not Started**
- [ ] Chaos Engineering — **Not Started**

### ✅ Checklist – Reliability
- [ ] Circuit breaker pattern
- [ ] Retry strategy
- [ ] Bulkhead pattern
- [ ] Rate limiting strategy
- [ ] Graceful degradation plan
- [ ] Chaos engineering
- [x] Failover strategy — active-passive/active-active covered

---

## 12. Scalability Patterns

### 12.1-12.8 Horizontal Scaling, Auto-Scaling, etc.
- [x] **Must Know:** Horizontal Scaling — *Covered in Primer (Horizontal Scaling section)*
- [x] **Must Know:** Vertical Scaling — *Covered in DDIA Ch.1 and Primer*
- [x] **Must Know:** Async Processing — work queues — *Covered in Primer (Asynchronism section)*
- [ ] Auto-Scaling — **Not Started**
- [ ] CQRS / Read-Write Splitting — **Not Started**
- [ ] Multi-Region Architecture — **Not Started**

### ✅ Checklist – Scalability
- [ ] Stateless service design
- [ ] Auto-scaling configured
- [ ] Data partitioning strategy
- [ ] CQRS / read-write splitting
- [x] Async processing with work queues covered
- [ ] Multi-region architecture

---

## 13. Monitoring, Logging & Observability
- [ ] **Not Started** — No coverage found

---

## 14. Security in System Design
- [ ] **Not Started** — No coverage found

---

## 15. Classic System Design Problems
- [ ] URL Shortener — **Not Started**
- [ ] Rate Limiter — **Not Started**
- [ ] Notification System — **Not Started**
- [ ] Chat System — **Not Started**
- [ ] News Feed / Timeline — **Not Started**
- [ ] Search Autocomplete — **Not Started**
- [ ] Web Crawler — **Not Started**
- [ ] Video Streaming — **Not Started**
- [ ] File Storage — **Not Started**
- [ ] Distributed Key-Value Store — **Not Started**
- [ ] Ticket Booking System — **Not Started**
- [ ] Payment System — **Not Started**

---

## 📈 Overall Progress Estimate

| Priority Level | Covered | Total (est.) | Percentage |
|---------------|---------|--------------|------------|
| Must Know | ~25 | ~65 | ~38% |
| Should Know | ~10 | ~60 | ~17% |
| Nice to Have | 0 | ~15 | 0% |
| **Overall** | **~35** | **~140** | **~25%** |

> **Key Gaps:** Message Queues (Kafka/RabbitMQ), Storage & Data Systems, Monitoring & Observability, Security in System Design, ALL Classic System Design Problems (none practiced), Distributed transactions (2PC, Saga), Consensus (Raft/Paxos), Reliability patterns (circuit breaker, retry, rate limiting). **Strengths:** Good conceptual foundation from DDIA (reliability, scalability, maintainability, data models) and System Design Primer (comprehensive coverage of: CAP theorem, consistency patterns, availability patterns, DNS, CDN, load balancing L4/L7, reverse proxy, caching strategies, RDBMS/NoSQL, sharding, replication, denormalization, SQL tuning, async/messaging basics, REST/RPC, microservices).
