# System Design — Mastery Scope for 10+ Years Experience

---

## 📊 Master Progress Tracker

| Section | Must Know Done | Should Know Done | Nice to Have Done | Last Reviewed | Notes |
|-----------------------------------|----------------|------------------|-------------------|---------------|-------|
| Fundamentals of System Design | | | | | |
| Networking & Communication | | | | | |
| Load Balancing & Reverse Proxy | | | | | |
| Caching | | | | | |
| Database Design | | | | | |
| Database Scaling & Replication | | | | | |
| Distributed Systems Concepts | | | | | |
| Message Queues & Event Streaming | | | | | |
| Storage & Data Systems | | | | | |
| Microservices Architecture | | | | | |
| Reliability & Fault Tolerance | | | | | |
| Scalability Patterns | | | | | |
| Monitoring, Logging & Observability| | | | | |
| Security in System Design | | | | | |
| Classic System Design Problems | | | | | |

---

## Table of Contents

1. [Fundamentals of System Design](#1-fundamentals-of-system-design)
2. [Networking & Communication](#2-networking--communication)
3. [Load Balancing & Reverse Proxy](#3-load-balancing--reverse-proxy)
4. [Caching](#4-caching)
5. [Database Design](#5-database-design)
6. [Database Scaling & Replication](#6-database-scaling--replication)
7. [Distributed Systems Concepts](#7-distributed-systems-concepts)
8. [Message Queues & Event Streaming](#8-message-queues--event-streaming)
9. [Storage & Data Systems](#9-storage--data-systems)
10. [Microservices Architecture](#10-microservices-architecture)
11. [Reliability & Fault Tolerance](#11-reliability--fault-tolerance)
12. [Scalability Patterns](#12-scalability-patterns)
13. [Monitoring, Logging & Observability](#13-monitoring-logging--observability)
14. [Security in System Design](#14-security-in-system-design)
15. [Classic System Design Problems](#15-classic-system-design-problems)

---

## 1. Fundamentals of System Design

### 1.1 Requirements Gathering
- **Must Know:** Functional requirements — what the system does
- **Must Know:** Non-functional requirements — scalability, availability, latency, consistency, durability
- **Must Know:** Clarifying questions — users, scale, read/write ratio, data size

### 1.2 Back-of-the-Envelope Estimation
- **Must Know:** QPS estimation — daily active users × actions per user / 86400
- **Must Know:** Storage estimation — records × size × retention period
- **Must Know:** Bandwidth estimation — QPS × request/response size
- **Must Know:** Memory estimation — cache size, hot data percentage
- **Should Know:** Powers of 2, common latencies (L1 cache: 1ns, RAM: 100ns, SSD: 100μs, HDD: 10ms, network: 1-100ms)

### 1.3 SLAs, SLOs, SLIs
- **Must Know:** Availability nines — 99.9% = 8.76h downtime/year, 99.99% = 52.6min/year
- **Must Know:** Latency percentiles — p50, p95, p99, p99.9
- **Should Know:** Error budgets — how much unreliability is acceptable
- **Should Know:** SLI metrics — what to measure for each SLO

### 1.4 Trade-offs
- **Must Know:** Consistency vs availability (CAP theorem practical implications)
- **Must Know:** Latency vs throughput
- **Must Know:** Cost vs performance
- **Should Know:** Simplicity vs flexibility, monolith vs microservices

### 1.5 Design Methodology
- **Must Know:** Top-down decomposition — requirements → high-level → detailed design
- **Must Know:** Iterative refinement — start simple, add complexity as needed
- **Should Know:** Constraint-driven design — identify bottlenecks first

### ✅ Checklist – Fundamentals
- [ ] Requirements gathering framework memorized
- [ ] Back-of-envelope calculations practiced (QPS, storage, bandwidth)
- [ ] Availability nines table memorized
- [ ] Latency numbers every engineer should know
- [ ] Design methodology applied in mock interviews

---

## 2. Networking & Communication

### 2.1 Communication Protocols
- **Must Know:** REST — resource-oriented, HTTP methods, status codes, stateless
- **Must Know:** gRPC — HTTP/2, protobuf, streaming, strong typing, code generation
- **Should Know:** GraphQL — flexible queries, schema, resolvers, N+1 problem
- **Should Know:** WebSockets — persistent bidirectional, real-time use cases

### 2.2 Message Formats
- **Must Know:** JSON — human-readable, widely supported, verbose
- **Must Know:** Protocol Buffers — binary, schema-based, efficient, backward compatible
- **Should Know:** Avro — schema evolution, Kafka integration
- **Nice to Have:** Thrift, FlatBuffers — zero-copy alternatives

### 2.3 API Gateway
- **Must Know:** Routing, request transformation, aggregation
- **Must Know:** Rate limiting, authentication at edge
- **Should Know:** Request/response transformation, protocol translation
- **Should Know:** API versioning strategies — URL path, header, query parameter

### 2.4 Service Mesh
- **Should Know:** Sidecar proxy pattern — Envoy, Linkerd proxy
- **Should Know:** Data plane (proxy) vs control plane (Istio, Linkerd)
- **Should Know:** mTLS, traffic management, observability via mesh

### ✅ Checklist – Networking & Communication
- [ ] REST vs gRPC trade-offs articulated
- [ ] Protocol Buffers schema designed and used
- [ ] API gateway purpose and components explained
- [ ] Service mesh concept understood
- [ ] API versioning strategy chosen

---

## 3. Load Balancing & Reverse Proxy

### 3.1 Load Balancing Layers
- **Must Know:** L4 (Transport) — TCP/UDP level, fast, no content inspection
- **Must Know:** L7 (Application) — HTTP level, content-based routing, more flexible
- **Must Know:** Trade-offs — L4 (performance) vs L7 (flexibility)

### 3.2 Algorithms
- **Must Know:** Round-robin, weighted round-robin
- **Must Know:** Least connections, least response time
- **Must Know:** Consistent hashing — minimal redistribution on server add/remove
- **Should Know:** IP hash — session affinity
- **Should Know:** Random, power of two random choices

### 3.3 Health Checks
- **Must Know:** Active health checks — periodic probing, configurable intervals
- **Should Know:** Passive health checks — detect failures from real traffic
- **Should Know:** Circuit breaker integration with load balancer

### 3.4 Global Server Load Balancing
- **Should Know:** DNS-based GSLB — geo-routing, latency-based routing
- **Should Know:** Anycast — single IP, routed to nearest instance
- **Nice to Have:** Multi-CDN, failover strategies

### 3.5 Reverse Proxy
- **Must Know:** SSL/TLS termination — offload encryption from backend
- **Must Know:** Caching at proxy level
- **Should Know:** Compression, request buffering
- **Should Know:** Software: Nginx, HAProxy, Envoy — strengths comparison
- **Should Know:** Cloud: ALB, NLB, GLB — managed alternatives

### 3.6 Sticky Sessions
- **Should Know:** When needed — stateful backends, session data
- **Should Know:** Trade-offs — reduces scalability, complicates failover
- **Should Know:** Alternatives — externalize state (Redis/DB)

### ✅ Checklist – Load Balancing
- [ ] L4 vs L7 load balancing explained with use cases
- [ ] Consistent hashing algorithm understood and diagrammed
- [ ] Health check strategy designed
- [ ] Nginx / HAProxy / Envoy compared
- [ ] Sticky sessions trade-offs articulated

---

## 4. Caching

### 4.1 Cache Tiers
- **Must Know:** Client-side cache — browser, mobile app
- **Must Know:** CDN cache — edge locations, static content
- **Must Know:** Application cache — Redis, Memcached
- **Must Know:** Database cache — query cache, buffer pool
- **Should Know:** Reverse proxy cache — Nginx, Varnish

### 4.2 Cache Strategies
- **Must Know:** Cache-aside (lazy loading) — app reads DB on miss, writes cache
- **Must Know:** Write-through — write to cache and DB simultaneously
- **Should Know:** Write-behind (write-back) — write to cache, async DB write
- **Should Know:** Read-through — cache itself loads from DB on miss

### 4.3 Eviction Policies
- **Must Know:** LRU (Least Recently Used) — most common
- **Should Know:** LFU (Least Frequently Used) — frequency-based
- **Should Know:** TTL (Time to Live) — expiration-based
- **Should Know:** FIFO, random eviction

### 4.4 Cache Invalidation
- **Must Know:** TTL-based — simple but may serve stale data
- **Must Know:** Event-driven — invalidate on write/update
- **Should Know:** Versioned keys — append version number to cache key
- **Should Know:** Cache stampede prevention — locking, probabilistic early expiration

### 4.5 Distributed Caching
- **Must Know:** Redis — data structures, persistence, pub/sub, clustering
- **Must Know:** Memcached — simple key-value, multi-threaded, no persistence
- **Should Know:** Redis Cluster — sharding, replication, failover
- **Should Know:** Consistent hashing for cache distribution

### 4.6 Cache Consistency
- **Must Know:** Stale reads — trade-off with performance
- **Should Know:** Thundering herd — many misses at TTL expiry
- **Should Know:** Look-aside vs inline cache — who manages the cache

### 4.7 CDN
- **Must Know:** Edge caching — reduce latency for static content
- **Must Know:** Cache invalidation at CDN — purge, versioned URLs
- **Should Know:** Origin shield — reduce origin load
- **Should Know:** Dynamic content acceleration — route optimization
- **Nice to Have:** Multi-CDN strategies

### 4.8 Advanced Caching
- **Should Know:** Cache warming — pre-populate cache on deploy
- **Should Know:** Pre-computation — materialized views, denormalized data
- **Nice to Have:** Multi-layer caching — L1 (local) + L2 (distributed)

### ✅ Checklist – Caching
- [ ] Cache tiers identified for a given system
- [ ] Cache-aside vs write-through vs write-behind trade-offs
- [ ] LRU eviction understood and implemented (LRU Cache problem)
- [ ] Cache invalidation strategy designed
- [ ] Redis vs Memcached — decision criteria clear
- [ ] Cache stampede / thundering herd mitigated
- [ ] CDN caching strategy designed

---

## 5. Database Design

### 5.1 Relational Databases
- **Must Know:** ACID properties — Atomicity, Consistency, Isolation, Durability
- **Must Know:** Normalization — 1NF, 2NF, 3NF, BCNF, when to denormalize
- **Must Know:** SQL queries — JOINs, GROUP BY, subqueries, window functions
- **Must Know:** Indexes — B-tree, hash, composite, covering indexes

### 5.2 Query Optimization
- **Must Know:** EXPLAIN / query plans — identifying full table scans, index usage
- **Should Know:** Index selection — which columns, composite order, cardinality
- **Should Know:** Query anti-patterns — SELECT *, N+1 queries, missing indexes
- **Should Know:** Partitioning — range, list, hash partitioning

### 5.3 NoSQL Categories
- **Must Know:** Document stores — MongoDB, DynamoDB — flexible schema, nested data
- **Must Know:** Key-value stores — Redis, DynamoDB — simple, fast, O(1) lookup
- **Must Know:** Column-family stores — Cassandra, HBase — wide rows, time-series
- **Should Know:** Graph databases — Neo4j — relationship-heavy queries
- **Should Know:** When to use SQL vs NoSQL — decision criteria

### 5.4 Database Selection
- **Must Know:** Decision criteria — data model, query patterns, consistency, scale
- **Should Know:** Schema design — star schema, snowflake schema (OLAP)
- **Should Know:** Entity-relationship modeling (OLTP)
- **Nice to Have:** NewSQL — CockroachDB, TiDB, Spanner — distributed SQL

### ✅ Checklist – Database Design
- [ ] ACID properties explained with examples
- [ ] Normalization levels understood, denormalization justified
- [ ] Index types and selection criteria clear
- [ ] EXPLAIN used for query optimization
- [ ] SQL vs NoSQL decision framework applied
- [ ] Database selected and justified for a design problem

---

## 6. Database Scaling & Replication

### 6.1 Scaling Strategies
- **Must Know:** Vertical scaling — bigger machine, has limits
- **Must Know:** Horizontal scaling — add more machines, requires sharding
- **Must Know:** Read replicas — leader-follower, offload reads

### 6.2 Replication
- **Must Know:** Leader-follower (master-slave) — single write point, read replicas
- **Must Know:** Replication lag — stale reads, read-after-write consistency
- **Should Know:** Multi-master — multiple write points, conflict resolution
- **Should Know:** Synchronous vs asynchronous replication — durability vs performance
- **Nice to Have:** CRDTs — Conflict-free Replicated Data Types

### 6.3 Sharding
- **Must Know:** Hash-based sharding — uniform distribution, resharding difficulty
- **Must Know:** Range-based sharding — range queries, hotspot risk
- **Must Know:** Shard key selection — avoid hotspots, consider query patterns
- **Should Know:** Directory-based sharding — lookup table
- **Should Know:** Cross-shard queries — scatter-gather, denormalization
- **Should Know:** Resharding strategies — consistent hashing, virtual shards

### 6.4 Database Infrastructure
- **Should Know:** Connection pooling — PgBouncer, ProxySQL
- **Should Know:** Database proxies — Vitess (MySQL), Citus (PostgreSQL)
- **Nice to Have:** Multi-region database deployment — geo-distributed

### ✅ Checklist – Database Scaling
- [ ] Vertical vs horizontal scaling trade-offs
- [ ] Read replica configuration and replication lag handling
- [ ] Sharding strategy designed (hash/range/directory)
- [ ] Shard key selection with hotspot analysis
- [ ] Cross-shard query strategies identified
- [ ] Connection pooling configured

---

## 7. Distributed Systems Concepts

### 7.1 CAP Theorem & Consistency
- **Must Know:** CAP — choose 2 of 3: Consistency, Availability, Partition tolerance
- **Must Know:** In practice: choose CP or AP (partitions always possible)
- **Should Know:** PACELC — when no partition: latency vs consistency trade-off
- **Must Know:** Consistency models — strong, eventual, causal, read-your-writes

### 7.2 Consensus Algorithms
- **Should Know:** Raft — leader election, log replication, safety
- **Should Know:** Paxos — classic consensus (conceptual)
- **Should Know:** When consensus is needed — leader election, metadata, config
- **Nice to Have:** ZAB (ZooKeeper), EPaxos

### 7.3 Distributed Transactions
- **Must Know:** 2PC (Two-Phase Commit) — prepare + commit, coordinator failure issue
- **Should Know:** 3PC — non-blocking but impractical
- **Must Know:** Saga pattern — choreography (events) vs orchestration (coordinator)
- **Must Know:** Compensating transactions — undo partial work

### 7.4 Time & Ordering
- **Should Know:** Lamport timestamps — partial ordering
- **Should Know:** Vector clocks — causality tracking
- **Nice to Have:** Hybrid logical clocks (HLC)
- **Should Know:** NTP limitations — clock skew in distributed systems

### 7.5 Idempotency
- **Must Know:** Idempotent operations — safe to retry without side effects
- **Must Know:** Idempotency keys — prevent duplicate processing
- **Should Know:** Exactly-once semantics — at-least-once + idempotency

### 7.6 Failure Modes
- **Must Know:** Partial failures — some nodes fail, others continue
- **Must Know:** Cascading failures — one failure triggers others
- **Should Know:** Byzantine failures — nodes behaving arbitrarily (concept)
- **Should Know:** Split-brain — network partition causes two leaders

### ✅ Checklist – Distributed Systems
- [ ] CAP theorem explained with real-world examples (Dynamo=AP, Spanner=CP)
- [ ] Consistency models compared and appropriate model chosen per use case
- [ ] Raft algorithm explained (leader election, log replication)
- [ ] Saga pattern designed (choreography vs orchestration)
- [ ] Idempotency strategy implemented
- [ ] Failure modes identified and mitigated

---

## 8. Message Queues & Event Streaming

### 8.1 Message Queue Patterns
- **Must Know:** Point-to-point — one consumer per message
- **Must Know:** Pub-sub — multiple consumers per message
- **Must Know:** Fan-out — broadcast to all consumers

### 8.2 Kafka
- **Must Know:** Topics, partitions — parallel consumption
- **Must Know:** Consumer groups — load distribution, offset management
- **Must Know:** Ordering — guaranteed within partition, not across
- **Should Know:** Log compaction — keep latest value per key
- **Should Know:** Exactly-once semantics — idempotent producers, transactional consumers
- **Should Know:** Kafka Connect — source and sink connectors

### 8.3 RabbitMQ
- **Should Know:** Exchanges — direct, topic, fanout, headers
- **Should Know:** Queues, bindings, routing keys
- **Should Know:** Acknowledgments, dead-letter queues
- **Should Know:** RabbitMQ vs Kafka — when to use which

### 8.4 Cloud Managed Services
- **Should Know:** AWS SQS, SNS, Kinesis
- **Should Know:** GCP Pub/Sub
- **Nice to Have:** Azure Service Bus, Event Hubs

### 8.5 Event-Driven Architecture
- **Must Know:** Event sourcing — store events, derive state
- **Must Know:** CQRS — separate read and write models
- **Should Know:** Event-carried state transfer — events contain full data
- **Should Know:** Event schema evolution — backward/forward compatibility

### 8.6 Reliability Patterns
- **Must Know:** At-least-once delivery — default for most systems
- **Must Know:** Retry with exponential backoff + jitter
- **Should Know:** Back-pressure — slow down producer when consumer overwhelmed
- **Should Know:** Poison messages / dead-letter queues — handle unprocessable messages
- **Should Know:** Message ordering vs parallelism trade-off

### 8.7 Stream Processing
- **Should Know:** Kafka Streams — stateful processing, windowing
- **Should Know:** Apache Flink — event time, watermarks, exactly-once
- **Nice to Have:** Spark Streaming — micro-batch approach

### ✅ Checklist – Message Queues & Event Streaming
- [ ] Kafka architecture explained (topics, partitions, consumer groups)
- [ ] Point-to-point vs pub-sub vs fan-out trade-offs
- [ ] Event sourcing + CQRS pattern designed
- [ ] Retry + dead-letter queue strategy implemented
- [ ] Kafka vs RabbitMQ — decision criteria clear
- [ ] Message ordering guarantees articulated

---

## 9. Storage & Data Systems

### 9.1 Storage Types
- **Must Know:** Block storage — EBS, persistent disks — raw volumes
- **Must Know:** Object storage — S3, GCS — immutable blobs, key-based access
- **Must Know:** File storage — EFS, NFS — shared filesystems
- **Must Know:** When to use which — block (databases), object (media/logs), file (shared)

### 9.2 Object Storage
- **Must Know:** S3/GCS — buckets, keys, versioning, lifecycle policies
- **Should Know:** Multipart upload — large file handling
- **Should Know:** Presigned URLs — temporary access without credentials
- **Should Know:** Content-addressable storage — hash-based keys

### 9.3 Data Lakes & Warehouses
- **Should Know:** Data lake — raw data, schema-on-read, Parquet/ORC formats
- **Should Know:** Data warehouse — structured, schema-on-write, OLAP
- **Should Know:** OLAP vs OLTP — analytical vs transactional workloads
- **Should Know:** Columnar storage — efficient for aggregation queries
- **Nice to Have:** Snowflake, BigQuery, Redshift — managed warehouses

### 9.4 Specialized Databases
- **Should Know:** Time-series DB — InfluxDB, TimescaleDB, Prometheus — retention, downsampling
- **Should Know:** Search engines — Elasticsearch, OpenSearch — inverted index, relevance scoring
- **Nice to Have:** Vector databases — for ML embeddings, similarity search

### 9.5 Storage Engine Internals
- **Should Know:** LSM trees — write-optimized, compaction, SSTables (Cassandra, RocksDB)
- **Should Know:** B-trees — read-optimized, balanced, page-based (PostgreSQL, MySQL InnoDB)
- **Should Know:** LSM vs B-tree trade-offs — write amplification vs read amplification

### ✅ Checklist – Storage & Data Systems
- [ ] Storage types compared (block, object, file)
- [ ] S3-style object storage designed into a system
- [ ] OLAP vs OLTP trade-offs articulated
- [ ] Time-series DB use case identified
- [ ] LSM vs B-tree storage engine trade-offs understood

---

## 10. Microservices Architecture

### 10.1 Architecture Styles
- **Must Know:** Monolith — simple, single deploy, shared DB, harder to scale
- **Must Know:** Microservices — independent deploy, own DB, network overhead
- **Must Know:** Trade-offs — monolith (simplicity) vs microservices (scalability, team autonomy)
- **Should Know:** Modular monolith — best of both, module boundaries, single deploy

### 10.2 Service Design
- **Must Know:** Domain-Driven Design (DDD) — bounded contexts, ubiquitous language
- **Must Know:** Service boundaries — aligned with business capabilities
- **Must Know:** Database per service — autonomy, eventual consistency
- **Should Know:** Aggregates — consistency boundaries within a service

### 10.3 Communication
- **Must Know:** Synchronous — REST, gRPC (request-response)
- **Must Know:** Asynchronous — events, messages (decoupled)
- **Must Know:** Trade-offs — sync (simpler, tighter coupling) vs async (resilient, complex)
- **Should Know:** Saga pattern for distributed transactions

### 10.4 Service Discovery
- **Should Know:** Client-side discovery — client queries registry (Eureka)
- **Should Know:** Server-side discovery — load balancer queries registry
- **Should Know:** DNS-based discovery — simple, TTL-based
- **Should Know:** Consul, etcd, ZooKeeper — service registries

### 10.5 Migration & Patterns
- **Should Know:** Strangler fig — incremental migration from monolith
- **Should Know:** Anti-corruption layer — protect new service from legacy
- **Should Know:** API versioning — backward compatibility
- **Nice to Have:** Sidecar pattern, ambassador pattern

### 10.6 Observability
- **Must Know:** Distributed tracing — OpenTelemetry, Jaeger, Zipkin
- **Must Know:** Correlation IDs — trace requests across services
- **Should Know:** Span context propagation, sampling strategies

### ✅ Checklist – Microservices
- [ ] Monolith vs microservices decision framework applied
- [ ] Service boundaries defined using DDD bounded contexts
- [ ] Sync vs async communication decided per interaction
- [ ] Service discovery mechanism chosen
- [ ] Distributed tracing integrated
- [ ] Strangler fig migration planned

---

## 11. Reliability & Fault Tolerance

### 11.1 Redundancy
- **Must Know:** Active-active — all instances serve traffic
- **Must Know:** Active-passive — standby takes over on failure
- **Should Know:** N+1 redundancy — one extra for failover
- **Should Know:** Geographic redundancy — multi-region for disaster recovery

### 11.2 Circuit Breaker
- **Must Know:** States: closed (normal), open (fail fast), half-open (probe)
- **Must Know:** Prevent cascading failures to downstream services
- **Should Know:** Configuration — failure threshold, timeout, reset interval

### 11.3 Retry Strategies
- **Must Know:** Exponential backoff — increasing delay between retries
- **Must Know:** Jitter — randomize delay to prevent thundering herd
- **Should Know:** Retry budgets — limit total retries across system
- **Should Know:** Idempotent operations required for safe retries

### 11.4 Bulkhead Pattern
- **Must Know:** Resource isolation — separate thread pools per dependency
- **Should Know:** Connection pool isolation, circuit breaker per dependency
- **Should Know:** Prevent one slow dependency from affecting others

### 11.5 Rate Limiting
- **Must Know:** Token bucket — smooth traffic with burst allowance
- **Must Know:** Leaky bucket — smooth traffic at constant rate
- **Should Know:** Sliding window — fixed or log-based
- **Should Know:** Distributed rate limiting — Redis-based, coordination overhead

### 11.6 Graceful Degradation
- **Must Know:** Feature flags — disable features under load
- **Must Know:** Fallback responses — cached data, default values
- **Should Know:** Priority-based degradation — critical vs non-critical features
- **Should Know:** Read-only mode, reduced functionality mode

### 11.7 Chaos Engineering
- **Should Know:** Fault injection — simulate failures in production
- **Should Know:** Game days — planned failure exercises
- **Should Know:** Steady-state hypothesis — define normal, test deviations
- **Nice to Have:** Netflix Chaos Monkey, Gremlin

### 11.8 Failover
- **Must Know:** Automatic failover — health checks trigger switch
- **Should Know:** Manual failover — operator-initiated
- **Should Know:** Split-brain prevention — fencing, quorum
- **Should Know:** Failover vs failback — returning to primary

### ✅ Checklist – Reliability & Fault Tolerance
- [ ] Circuit breaker pattern designed and configured
- [ ] Retry strategy with exponential backoff + jitter implemented
- [ ] Bulkhead pattern applied for resource isolation
- [ ] Rate limiting strategy chosen (token bucket / sliding window)
- [ ] Graceful degradation plan — feature flags, fallbacks
- [ ] Chaos engineering experiment designed
- [ ] Failover strategy — automatic with split-brain prevention

---

## 12. Scalability Patterns

### 12.1 Horizontal Scaling
- **Must Know:** Stateless services — no server-side session state
- **Must Know:** Shared-nothing architecture — each node independent
- **Must Know:** Externalize state — sessions in Redis/DB, not in-memory

### 12.2 Vertical Scaling
- **Must Know:** CPU/memory upgrades — simple, has limits
- **Must Know:** Cost curve — diminishing returns at high end
- **Should Know:** When vertical is appropriate — small-to-medium scale, databases

### 12.3 Auto-Scaling
- **Must Know:** Metric-based — CPU, memory, request rate thresholds
- **Should Know:** Predictive scaling — anticipate load from patterns
- **Should Know:** Scheduled scaling — known traffic patterns (time-of-day, events)
- **Should Know:** Cool-down periods — prevent scaling oscillation

### 12.4 Data Partitioning
- **Must Know:** Functional partitioning — separate by feature/service
- **Must Know:** Horizontal partitioning (sharding) — split data across nodes
- **Should Know:** Hybrid — combine functional + horizontal

### 12.5 Read/Write Splitting
- **Must Know:** CQRS — separate read and write paths
- **Must Know:** Read replicas — offload queries
- **Should Know:** Eventual consistency handling in read path
- **Should Know:** Materialized views for read optimization

### 12.6 Async Processing
- **Must Know:** Work queues — decouple producer from consumer
- **Must Know:** Batch processing — aggregate work, process periodically
- **Should Know:** Deferred computation — return immediately, process later
- **Should Know:** Priority queues — critical work first

### 12.7 Multi-Region Architecture
- **Should Know:** Active-active multi-region — serve traffic from both regions
- **Should Know:** Active-passive — disaster recovery standby
- **Should Know:** Data sovereignty — GDPR, data residency requirements
- **Nice to Have:** Global data replication, conflict resolution

### 12.8 Edge Computing
- **Nice to Have:** CDN functions — compute at the edge (Cloudflare Workers, Lambda@Edge)
- **Nice to Have:** IoT edge — process data near source

### ✅ Checklist – Scalability Patterns
- [ ] Stateless service design — externalized state
- [ ] Auto-scaling configured with appropriate metrics
- [ ] Data partitioning strategy designed
- [ ] CQRS / read-write splitting applied
- [ ] Async processing with work queues designed
- [ ] Multi-region architecture planned

---

## 13. Monitoring, Logging & Observability

### 13.1 Three Pillars
- **Must Know:** Metrics — quantitative measurements over time
- **Must Know:** Logs — discrete events, structured logging
- **Must Know:** Traces — request lifecycle across services

### 13.2 Metrics
- **Must Know:** Types — counters, gauges, histograms, summaries
- **Must Know:** RED method — Rate, Errors, Duration (for services)
- **Should Know:** USE method — Utilization, Saturation, Errors (for resources)
- **Should Know:** Prometheus — pull-based, PromQL, alerting
- **Should Know:** StatsD, Datadog, Grafana — metrics infrastructure

### 13.3 Logging
- **Must Know:** Structured logging — JSON format, key-value pairs
- **Must Know:** Log levels — DEBUG, INFO, WARN, ERROR, FATAL
- **Must Know:** Correlation IDs — trace requests across services in logs
- **Should Know:** Log aggregation — ELK stack (Elasticsearch, Logstash, Kibana)
- **Should Know:** Loki, Splunk — alternative log platforms
- **Should Know:** Log retention, rotation, cost management

### 13.4 Distributed Tracing
- **Must Know:** Trace context — trace ID, span ID, parent span
- **Should Know:** OpenTelemetry — standard for metrics + traces + logs
- **Should Know:** Jaeger, Zipkin — trace visualization
- **Should Know:** Sampling strategies — head-based, tail-based, adaptive

### 13.5 Alerting
- **Must Know:** SLO-based alerting — alert on error budget burn rate
- **Should Know:** Threshold vs anomaly detection
- **Should Know:** Alert fatigue — too many alerts, alert consolidation
- **Should Know:** Runbooks — standard response procedures

### 13.6 Dashboards & Practices
- **Must Know:** SLI/SLO dashboards — real-time health overview
- **Should Know:** On-call practices — rotation, escalation, handoff
- **Should Know:** Incident management — severity levels, war rooms
- **Must Know:** Postmortems — blameless, timeline, action items, follow-up

### ✅ Checklist – Monitoring & Observability
- [ ] Three pillars understood (metrics, logs, traces)
- [ ] RED and USE methods applied
- [ ] Structured logging with correlation IDs implemented
- [ ] Distributed tracing integrated (OpenTelemetry)
- [ ] SLO-based alerting configured
- [ ] Blameless postmortem template used

---

## 14. Security in System Design

### 14.1 Authentication
- **Must Know:** OAuth 2.0 — authorization framework, flows (auth code, client credentials)
- **Must Know:** OIDC — identity layer on OAuth 2.0
- **Must Know:** JWT — structure, validation, expiry, refresh tokens
- **Should Know:** Session-based vs token-based authentication
- **Should Know:** API keys — simple, less secure, rate limiting

### 14.2 Authorization
- **Must Know:** RBAC — role-based access control
- **Should Know:** ABAC — attribute-based access control
- **Should Know:** Policy engines — OPA (Open Policy Agent)
- **Should Know:** Principle of least privilege

### 14.3 Encryption
- **Must Know:** Encryption at rest — AES-256, disk encryption, database encryption
- **Must Know:** Encryption in transit — TLS 1.3, mTLS
- **Should Know:** End-to-end encryption — only endpoints can read
- **Should Know:** Key management — KMS (AWS/GCP/Azure), key rotation

### 14.4 Application Security
- **Must Know:** Input validation — prevent injection attacks
- **Must Know:** SQL injection prevention — parameterized queries
- **Should Know:** XSS (Cross-Site Scripting) — output encoding
- **Should Know:** CSRF (Cross-Site Request Forgery) — token-based prevention
- **Should Know:** DDoS protection — WAF, rate limiting, CDN

### 14.5 Data Privacy
- **Should Know:** GDPR — right to erasure, data portability
- **Should Know:** PII handling — identification, classification, access control
- **Should Know:** Anonymization vs pseudonymization
- **Nice to Have:** Data lineage, audit trails

### 14.6 Secrets Management
- **Must Know:** Never hardcode secrets — use environment variables or secrets manager
- **Should Know:** HashiCorp Vault, AWS Secrets Manager, GCP Secret Manager
- **Should Know:** Secret rotation — automated, zero-downtime
- **Should Know:** Least privilege for secret access

### ✅ Checklist – Security
- [ ] OAuth 2.0 / OIDC flow designed
- [ ] JWT validation and refresh implemented
- [ ] RBAC / ABAC model designed
- [ ] Encryption at rest and in transit configured
- [ ] Input validation and injection prevention applied
- [ ] Secrets management strategy in place

---

## 15. Classic System Design Problems

### 15.1 URL Shortener
- [ ] **Must Know:** Base62 encoding, hash collision handling
- [ ] Analytics, click tracking, expiration
- [ ] Read-heavy system — caching, 301 vs 302 redirect

### 15.2 Rate Limiter
- [ ] **Must Know:** Token bucket, leaky bucket algorithms
- [ ] Distributed rate limiting with Redis
- [ ] Sliding window log vs counter approach

### 15.3 Notification System
- [ ] **Must Know:** Push, email, SMS channels — priority, templating
- [ ] Delivery tracking, retry, rate limiting per user
- [ ] Fan-out architecture, message queue integration

### 15.4 Chat System
- [ ] **Must Know:** WebSocket for real-time, presence detection
- [ ] Message persistence, read receipts, typing indicators
- [ ] Group chat, 1:1, message ordering

### 15.5 News Feed / Timeline
- [ ] **Must Know:** Fan-out on write (push) vs fan-out on read (pull)
- [ ] Hybrid approach for celebrities vs normal users
- [ ] Ranking algorithm, infinite scroll, caching

### 15.6 Search Autocomplete / Typeahead
- [ ] **Must Know:** Trie data structure, prefix matching
- [ ] Ranking by frequency, personalization
- [ ] Caching top queries, sharding the trie

### 15.7 Web Crawler
- [ ] **Must Know:** URL frontier, BFS crawling, politeness (robots.txt)
- [ ] Deduplication (URL + content), distributed crawling
- [ ] Priority queue, DNS caching, trap detection

### 15.8 Video Streaming (YouTube/Netflix)
- [ ] **Should Know:** Adaptive bitrate streaming (HLS, DASH)
- [ ] Transcoding pipeline, CDN distribution
- [ ] Resumable upload, thumbnail generation

### 15.9 File Storage (Google Drive / Dropbox)
- [ ] **Should Know:** File sync — chunking, deduplication, delta sync
- [ ] Conflict resolution — last-writer-wins, manual merge
- [ ] Metadata service, block storage, notification of changes

### 15.10 Distributed Key-Value Store
- [ ] **Should Know:** Consistent hashing, virtual nodes
- [ ] Replication — quorum reads/writes (W+R > N)
- [ ] Gossip protocol, failure detection, hinted handoff

### 15.11 Ticket Booking System
- [ ] **Should Know:** Seat locking — pessimistic vs optimistic
- [ ] Double-booking prevention, eventual consistency
- [ ] Payment integration, idempotency

### 15.12 Payment System
- [ ] **Should Know:** Idempotency keys, exactly-once processing
- [ ] Ledger, double-entry bookkeeping
- [ ] Reconciliation, fraud detection, PCI DSS compliance

### ✅ Checklist – Classic Problems
- [ ] URL Shortener designed end-to-end
- [ ] Rate Limiter — distributed with Redis
- [ ] Chat System — WebSocket + message persistence
- [ ] News Feed — fan-out strategy chosen and justified
- [ ] At least 8/12 classic problems practiced
- [ ] Back-of-envelope calculations done for each
- [ ] Trade-offs articulated clearly for each design
