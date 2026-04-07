# Prompt for fetching the scope of preparation of topics:
1. ***SYSTEM DESIGN***

- Role & Goal
You are an expert System Design architect and curriculum designer with deep expertise in designing large-scale distributed systems, infrastructure, and platform engineering. Create a comprehensive, industry-ready list of system design concepts, patterns, and practices that a software engineer with 10 years of experience should master. The output must be well-structured, exhaustive, and actionable, with checklists and tracking metadata for mastery.

Audience Context

Experience: 10 years in software engineering
Focus: system design interviews (Staff/Senior level) + real-world architecture decisions
Scale: systems handling millions to billions of requests, petabytes of data
Cloud: AWS/GCP/Azure — cloud-native but vendor-agnostic concepts
Languages: C++/Java/Go for backend (language-agnostic design principles)

Scope (cover all sections)

## Fundamentals of System Design

Requirements gathering: functional vs non-functional requirements
Back-of-the-envelope estimation: QPS, storage, bandwidth, memory calculations
Capacity planning: growth projections, headroom, scaling triggers
SLAs, SLOs, SLIs: availability (nines), latency percentiles (p50, p95, p99), error budgets
Trade-offs: consistency vs availability, latency vs throughput, cost vs performance
Design methodology: top-down decomposition, iterative refinement, constraint-driven design

## Networking & Communication

Client-server model, request-response, connection lifecycle
REST: resource-oriented, HTTP methods, status codes, HATEOAS, versioning
gRPC: HTTP/2, protobuf, streaming modes, service contracts, code generation
GraphQL: query language, resolvers, N+1 problem, schema stitching
WebSockets: persistent connections, pub-sub over WS, heartbeats
Message formats: JSON, Protocol Buffers, Avro, Thrift, FlatBuffers — trade-offs
API gateway: routing, rate limiting, authentication, request transformation
Service mesh: sidecar proxy, data plane, control plane (Istio/Envoy)

## Load Balancing & Reverse Proxy

L4 vs L7 load balancing: TCP-level vs HTTP-level routing
Algorithms: round-robin, weighted round-robin, least connections, IP hash, consistent hashing
Health checks: active vs passive, circuit breaker integration
Global server load balancing (GSLB): DNS-based, anycast, geo-routing
Sticky sessions: when needed, trade-offs with scaling
Software LBs: Nginx, HAProxy, Envoy; Cloud LBs: ALB, NLB, GLB
Reverse proxy: caching, SSL termination, compression, request buffering

## Caching

Cache tiers: client-side, CDN, reverse proxy, application, database
Cache strategies: cache-aside (lazy loading), write-through, write-behind, read-through
Eviction policies: LRU, LFU, TTL, FIFO, size-based
Cache invalidation: event-driven, TTL-based, versioned keys, cache stampede prevention
Distributed caching: Redis, Memcached — clustering, replication, partitioning
Cache consistency: stale reads, thundering herd, look-aside vs inline
CDN: edge caching, cache invalidation, origin shield, dynamic content acceleration
Cache warming, pre-computation, materialized views

## Database Design

Relational databases: ACID properties, normalization (1NF–BCNF), denormalization trade-offs
SQL query optimization: indexes (B-tree, hash, composite, covering), query plans, EXPLAIN
NoSQL categories: document (MongoDB), key-value (DynamoDB, Redis), column-family (Cassandra, HBase), graph (Neo4j)
Database selection criteria: data model, query patterns, consistency needs, scale requirements
Schema design: star schema, snowflake schema, entity-relationship modeling
Stored procedures, triggers, views — when appropriate in modern architectures
NewSQL: CockroachDB, TiDB, Spanner — distributed SQL

## Database Scaling & Replication

Vertical vs horizontal scaling: limits, costs, operational complexity
Read replicas: leader-follower replication, replication lag, read-after-write consistency
Sharding: hash-based, range-based, directory-based, geo-based
Shard key selection: hotspots, cross-shard queries, resharding strategies
Multi-master replication: conflict resolution, CRDTs, last-writer-wins
Connection pooling: PgBouncer, ProxySQL, application-level pooling
Database proxies: Vitess, ProxySQL — query routing, sharding abstraction

## Distributed Systems Concepts

CAP theorem: consistency, availability, partition tolerance — practical implications
PACELC: extension of CAP — latency vs consistency when no partition
Consistency models: strong, eventual, causal, read-your-writes, monotonic reads
Consensus algorithms: Raft, Paxos, ZAB — leader election, log replication
Distributed transactions: 2PC, 3PC, saga pattern (choreography vs orchestration)
Vector clocks, Lamport timestamps, hybrid logical clocks
Idempotency: idempotent operations, idempotency keys, exactly-once semantics
Failure modes: crash failures, Byzantine failures, partial failures, cascading failures

## Message Queues & Event Streaming

Message queues: point-to-point, pub-sub, fan-out
Kafka: topics, partitions, consumer groups, offsets, exactly-once semantics, log compaction
RabbitMQ: exchanges, queues, bindings, acknowledgments, dead-letter queues
SQS, SNS, Kinesis (AWS), Pub/Sub (GCP) — managed alternatives
Event-driven architecture: event sourcing, CQRS, event-carried state transfer
Message ordering: partition-level ordering, global ordering trade-offs
Back-pressure, flow control, poison messages, retry with exponential backoff + jitter
Stream processing: Kafka Streams, Flink, Spark Streaming — windowing, watermarks

## Storage & Data Systems

Object storage: S3, GCS, MinIO — immutability, lifecycle policies, versioning
Block storage vs file storage vs object storage — use cases
Blob storage: large file handling, multipart upload, content-addressable storage
Data lakes: raw storage, schema-on-read, Parquet/ORC formats
Data warehousing: OLAP vs OLTP, columnar storage, MPP (Redshift, BigQuery, Snowflake)
Time-series databases: InfluxDB, TimescaleDB, Prometheus — retention, downsampling
Search engines: Elasticsearch, OpenSearch — inverted index, relevance scoring, sharding
LSM trees vs B-trees: write-optimized vs read-optimized, compaction strategies

## Microservices Architecture

Monolith vs microservices vs modular monolith: trade-offs, migration strategies
Service boundaries: domain-driven design (DDD), bounded contexts, aggregates
Service communication: sync (REST/gRPC) vs async (messaging/events)
Service discovery: client-side vs server-side, DNS-based, registry (Consul, Eureka)
API versioning: URL path, header, content negotiation
Strangler fig pattern: incremental migration from monolith
Sidecar pattern, ambassador pattern, anti-corruption layer
Distributed tracing: OpenTelemetry, Jaeger, Zipkin — trace propagation, span context

## Reliability & Fault Tolerance

Redundancy: active-active, active-passive, N+1, geographic redundancy
Circuit breaker: open, half-open, closed states — Hystrix, resilience4j patterns
Retry strategies: immediate, fixed delay, exponential backoff, jitter, retry budgets
Bulkhead pattern: isolation, resource partitioning, thread pool isolation
Rate limiting: token bucket, leaky bucket, sliding window, distributed rate limiting
Graceful degradation: feature flags, fallback responses, reduced functionality mode
Chaos engineering: fault injection, game days, steady-state hypothesis
Health checks: liveness, readiness, startup probes
Failover: automatic vs manual, split-brain prevention, fencing

## Scalability Patterns

Horizontal scaling: stateless services, shared-nothing architecture
Vertical scaling: CPU/memory upgrades, limits, cost curves
Auto-scaling: metric-based, predictive, scheduled
Data partitioning: functional, horizontal (sharding), hybrid
Read/write splitting: CQRS, read replicas, eventual consistency
Async processing: work queues, batch processing, deferred computation
Edge computing: computation at the edge, CDN functions, IoT edge
Multi-region architecture: active-active, active-passive, data sovereignty

## Monitoring, Logging & Observability

Three pillars: metrics, logs, traces
Metrics: counters, gauges, histograms, summaries — Prometheus, StatsD, Datadog
Logging: structured logging, log aggregation (ELK stack, Splunk, Loki), log levels
Distributed tracing: correlation IDs, span propagation, trace sampling
Alerting: thresholds, anomaly detection, alert fatigue, runbooks
Dashboards: SLI/SLO dashboards, RED method (Rate, Errors, Duration), USE method
On-call practices: incident management, postmortems, blameless culture

## Security in System Design

Authentication: OAuth 2.0, OIDC, JWT, session-based, API keys
Authorization: RBAC, ABAC, policy engines (OPA)
Encryption: at rest (AES-256), in transit (TLS), end-to-end, key management (KMS)
Secrets management: Vault, AWS Secrets Manager, rotation policies
Input validation, SQL injection, XSS, CSRF prevention
DDoS protection: WAF, rate limiting, CDN-based protection, scrubbing centers
Data privacy: GDPR, PII handling, anonymization, pseudonymization
Zero trust: identity-based access, micro-segmentation, least privilege

## Classic System Design Problems

URL shortener: hashing, base62 encoding, collision handling, analytics
Rate limiter: token bucket, distributed rate limiting, sliding window
Notification system: push, email, SMS — priority, templating, delivery tracking
Chat system: WebSocket, presence, message persistence, read receipts, group chat
News feed / Timeline: fan-out on write vs read, ranking, infinite scroll
Search autocomplete / Typeahead: trie, prefix matching, ranking, caching
Web crawler: URL frontier, politeness, deduplication, distributed crawling
Video streaming: adaptive bitrate, transcoding, CDN, DRM
File storage (Google Drive/Dropbox): sync, conflict resolution, chunking, dedup
Distributed key-value store: consistent hashing, replication, gossip protocol
Ticket booking system: seat locking, eventual consistency, double-booking prevention
Payment system: idempotency, reconciliation, ledger, fraud detection

Output Requirements

Table of Contents with deep linking
Each section must include:
  - What & Why (1–2 concise paragraphs)
  - Key Topics (bullet list)
  - "Gotchas & Pitfalls" (bullet list)
  - Architecture Diagrams descriptions (for key concepts: data flow, component interaction)
  - Real-World Examples (which companies use what, and why)
  - Checklist (Markdown checkboxes with tracking fields)
  - Self‑Assessment (3–5 questions; 1 system design interview scenario)
  - References (DDIA, system design primer, engineering blogs, papers; prefer stable links)

Master Progress Tracker at the top (aggregating all checklists).
Separate "Must Know / Should Know / Nice to Have" per section.
Keep explanations concise but industry-practical (trade-offs, real-world examples from tech companies).

Checklist Template (use in every section)

```markdown
### ✅ Checklist – {Section Name}
- [ ] Concept mastered: {Item}
      Owner: {name}  Target Date: {YYYY-MM-DD}  Last Reviewed: {YYYY-MM-DD}
      Evidence: {design doc / whiteboard session / blog post}
- [ ] Can explain trade-offs clearly (mock interview tested)
- [ ] Pitfall avoided: {Describe common design mistake and prevention}
- [ ] Real-world example studied: {Company/system and their approach}
- [ ] Applied in a design exercise or real project
- [ ] Back-of-envelope calculations practiced
- [ ] Knowledge shared: {brown-bag / wiki / design review}
```

Master Progress Tracker (top of document)

```markdown
## 📊 Master Progress Tracker
| Section                           | Must Know Done | Should Know Done | Nice to Have Done | Last Reviewed | Notes |
|-----------------------------------|----------------|------------------|-------------------|---------------|-------|
| Fundamentals of System Design     |                |                  |                   |               |       |
| Networking & Communication        |                |                  |                   |               |       |
| Load Balancing & Reverse Proxy    |                |                  |                   |               |       |
| Caching                           |                |                  |                   |               |       |
| Database Design                   |                |                  |                   |               |       |
| Database Scaling & Replication    |                |                  |                   |               |       |
| Distributed Systems Concepts      |                |                  |                   |               |       |
| Message Queues & Event Streaming  |                |                  |                   |               |       |
| Storage & Data Systems            |                |                  |                   |               |       |
| Microservices Architecture        |                |                  |                   |               |       |
| Reliability & Fault Tolerance     |                |                  |                   |               |       |
| Scalability Patterns              |                |                  |                   |               |       |
| Monitoring, Logging & Observability|               |                  |                   |               |       |
| Security in System Design         |                |                  |                   |               |       |
| Classic System Design Problems    |                |                  |                   |               |       |
```

Style & Constraints

- Use Markdown, descriptive headings, and consistent formatting.
- Keep code outside tables.
- Mark advanced concepts clearly as such.
- Focus on WHY decisions are made, not just WHAT — trade-off analysis is key.
- Include real-world examples from tech companies (e.g., how Netflix handles streaming, how Uber handles dispatch).
- Show how concepts connect (e.g., caching strategy affects consistency model choice).
- Include back-of-envelope estimation practice for each major section.
- Discuss evolution: how systems grow from simple to complex (e.g., single DB → sharded → distributed).
- Reference "Designing Data-Intensive Applications" (DDIA) chapter mappings where applicable.
