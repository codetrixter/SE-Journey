# Application Layer (Microservices & Service Discovery)

> **Deep dive** extracted from `Overview.md`. Separating the web layer from the application
> (platform) layer lets you scale and configure each independently.

---

## Table of Contents

1. [Web Layer vs Application Layer](#web-layer-vs-application-layer)
2. [Why Separate Them](#why-separate-them)
3. [Microservices](#microservices)
4. [Monolith vs Microservices](#monolith-vs-microservices)
5. [Service Discovery](#service-discovery)
6. [Inter-Service Communication](#inter-service-communication)
7. [Cross-Cutting Concerns](#cross-cutting-concerns)
8. [Disadvantages](#disadvantages)
9. [Interview Talking Points](#interview-talking-points)
10. [Further Exploration](#further-exploration)

---

## Web Layer vs Application Layer

- **Web layer** — handles HTTP, serves/forwards requests (often the reverse proxy / web servers).
- **Application (platform) layer** — runs business logic on application servers and workers.

Splitting them means adding a new API needs only **more application servers**, not
necessarily more web servers — and vice versa.

```
Client ─► Web Layer (NGINX) ─► Application Layer (services + workers) ─► Data Layer
```

## Why Separate Them

- **Independent scaling** of web vs compute.
- **Single Responsibility Principle** → small, autonomous services that compose.
- Small teams own small services → **faster, more aggressive iteration**.
- Workers in the application layer **enable asynchronism** (see `Asynchronism.md`).

## Microservices

A suite of **independently deployable, small, modular** services. Each runs its own
process and communicates over a lightweight mechanism to serve a business goal.

> **Example (Pinterest):** separate services for *user profile*, *follower*, *feed*,
> *search*, *photo upload*, etc.

Characteristics: bounded context, own data store, independent deploy & scale, fault isolation.

## Monolith vs Microservices

| Dimension | Monolith | Microservices |
|-----------|----------|---------------|
| Deploy unit | One artifact | Many independent services |
| Scaling | Whole app together | Per-service |
| Tech diversity | Usually uniform | Polyglot possible |
| Fault isolation | Weak (one bug → whole app) | Strong (blast radius limited) |
| Dev velocity (small) | Faster early on | Overhead early on |
| Dev velocity (large) | Slows with size | Scales with teams |
| Operational complexity | Lower | Higher (network, observability) |

> 🔑 Start monolith → extract services as boundaries and scale needs become clear.

## Service Discovery

As service instances come and go (autoscaling, failures), others must find them.

- **Tools:** Consul, etcd, Zookeeper (also Eureka, Kubernetes DNS).
- They track registered **names, addresses, and ports**.
- **Health checks** (often an HTTP endpoint) verify a service is alive before routing to it.
- Consul and etcd include a **key-value store** for config and shared data.

**Patterns:**
- **Client-side discovery** — client queries the registry, picks an instance.
- **Server-side discovery** — an LB/router queries the registry on the client's behalf.

## Inter-Service Communication

- **Synchronous:** REST/HTTP, gRPC (RPC). Simple but couples availability.
- **Asynchronous:** message/event queues (Kafka, RabbitMQ) for decoupling and resilience.
- **API Gateway:** single entry point handling auth, rate limiting, routing, aggregation.

## Cross-Cutting Concerns

- **Observability:** centralized logging, metrics, distributed tracing (OpenTelemetry).
- **Resilience:** timeouts, retries, circuit breakers, bulkheads.
- **Security:** mTLS between services, token-based auth.
- **Data:** each service owns its data; use **saga**/eventual consistency across services.

## Disadvantages

- A loosely-coupled service architecture needs a different **architectural, operations, and
  process** approach than a monolith.
- Microservices add **deployment and operational complexity** (networking, versioning,
  distributed debugging, data consistency).

## Interview Talking Points

- Justify splitting web vs app layer for **independent scaling**.
- Use **bounded contexts** to decide service boundaries.
- Mention **service discovery + health checks** for dynamic fleets.
- Call out the **operational cost** of microservices — don't over-split early.

## Further Exploration

- *Introduction to architecting systems for scale* (lethain).
- Martin Fowler — *Microservices*, *MonolithFirst*.
- *Introduction to Zookeeper*; Consul/etcd docs.
- Explore next: **API gateway**, **service mesh (Istio/Linkerd)**, **saga pattern**,
  **distributed tracing**.
