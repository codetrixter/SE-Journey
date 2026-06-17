# Load Balancer

> **Deep dive** extracted from `Overview.md`. Load balancers distribute incoming client
> requests across computing resources (app servers, databases) and return responses.

---

## Table of Contents

1. [What a Load Balancer Does](#what-a-load-balancer-does)
2. [Core Benefits](#core-benefits)
3. [Additional Capabilities](#additional-capabilities)
4. [Load Balancing Algorithms](#load-balancing-algorithms)
5. [Layer 4 Load Balancing](#layer-4-load-balancing)
6. [Layer 7 Load Balancing](#layer-7-load-balancing)
7. [Layer 4 vs Layer 7](#layer-4-vs-layer-7)
8. [Horizontal Scaling](#horizontal-scaling)
9. [Avoiding the LB as a Single Point of Failure](#avoiding-the-lb-as-a-single-point-of-failure)
10. [Hardware vs Software vs Cloud LBs](#hardware-vs-software-vs-cloud-lbs)
11. [Disadvantages](#disadvantages)
12. [Interview Talking Points](#interview-talking-points)
13. [Further Exploration](#further-exploration)

---

## What a Load Balancer Does

A **load balancer (LB)** sits in front of a pool of servers, distributing requests and
relaying each response back to the right client. It is fundamental to horizontal scaling
and high availability.

```
                ┌─► App Server 1
Client ─► LB ───┼─► App Server 2
                └─► App Server 3
```

## Core Benefits

Load balancers are effective at:

- **Preventing requests from reaching unhealthy servers** (via health checks).
- **Preventing resource overload** (spreading load evenly).
- **Eliminating single points of failure** (combined with redundancy).

Implemented in **hardware** (expensive, e.g., F5) or **software** (HAProxy, NGINX, Envoy).

## Additional Capabilities

- **SSL/TLS termination** — decrypt incoming requests / encrypt responses so backends skip
  this expensive work; removes the need to install **X.509 certificates** on every server.
  - **X.509 certificate:** an ITU-standard public-key certificate binding an identity
    (hostname/org/individual) to a public key via digital signatures; used in TLS/SSL,
    CA-signed or self-signed.
- **Session persistence ("sticky sessions")** — issue cookies and route a client's requests
  to the same instance when the app isn't stateless.
- **Health checks, request routing, compression, rate limiting**.

To avoid the LB being a SPOF, deploy multiple LBs in **active-passive** or **active-active**.

## Load Balancing Algorithms

| Algorithm | Behaviour |
|-----------|-----------|
| **Round robin** | Rotate through servers in order |
| **Weighted round robin** | Round robin biased by server capacity |
| **Least connections** | Send to the server with fewest active connections |
| **Least response time** | Factor in latency, not just connection count |
| **Random** | Pick a server at random (with optional weights) |
| **IP hash / consistent hashing** | Map client/key → server deterministically (session affinity, cache locality) |
| **Session/cookie based** | Route by session identifier |

## Layer 4 Load Balancing

Operates at the **transport layer**. Decisions use **source/destination IP and port** from
the packet header — **not** the payload. The LB forwards packets and performs **NAT
(Network Address Translation)**.

- ✅ Fast, low overhead, protocol-agnostic.
- ❌ Can't make decisions based on application content (URLs, cookies).

## Layer 7 Load Balancing

Operates at the **application layer**. The LB **terminates** the connection, reads the
**HTTP headers/message/cookies**, makes a routing decision, then opens a connection to the
chosen server.

- ✅ Content-aware routing. *Example:* send `/video/*` to media servers and billing traffic
  to security-hardened servers; route by host, path, cookie, header.
- ✅ Enables TLS termination, header rewriting, sticky sessions, A/B routing.
- ❌ More CPU/time than L4 (though minimal on modern commodity hardware).

## Layer 4 vs Layer 7

| Aspect | Layer 4 | Layer 7 |
|--------|---------|---------|
| OSI layer | Transport (TCP/UDP) | Application (HTTP) |
| Inspects | IP + port headers | Headers, body, cookies, URL |
| Mechanism | Packet forwarding + NAT | Terminates, reads, re-opens connection |
| Speed | Faster, less compute | Slightly more compute |
| Flexibility | Lower | Higher (content-based routing) |
| Examples | AWS NLB, LVS | AWS ALB, NGINX, HAProxy, Envoy |

## Horizontal Scaling

LBs enable **scaling out** (more commodity machines) instead of **scaling up** (one bigger
box). Scaling out is more cost-efficient and more available than buying expensive hardware.

### Disadvantages of Horizontal Scaling

- Introduces complexity and requires **cloning** servers.
- Servers should be **stateless** — no user sessions or profile pictures stored locally.
- Sessions belong in a **centralized store** (SQL/NoSQL) or **persistent cache** (Redis,
  Memcached).
- Downstream caches/databases must handle **more simultaneous connections** as you scale out.

## Avoiding the LB as a Single Point of Failure

- Run **multiple LBs** (active-active or active-passive) with health checks.
- Use **floating/virtual IPs** + protocols like VRRP/keepalived for failover.
- DNS or anycast can distribute across LB clusters across regions.

## Hardware vs Software vs Cloud LBs

- **Hardware:** F5 BIG-IP, Citrix — high throughput, expensive, less elastic.
- **Software:** HAProxy, NGINX, Envoy — flexible, cheap, run on commodity hardware.
- **Cloud-managed:** AWS ELB/ALB/NLB, GCP Cloud Load Balancing — elastic, integrated health
  checks & autoscaling.

## Disadvantages

- Can become a **performance bottleneck** if under-resourced or misconfigured.
- Adds **complexity**.
- A single LB is itself a **SPOF**; making it redundant adds further complexity.

## Interview Talking Points

- Distinguish **L4 vs L7** and justify which you'd use (e.g., L7 for path-based microservice routing).
- Stress **stateless servers + external session store** as the key to horizontal scaling.
- Always make the LB **redundant** — never leave it a SPOF.
- Mention **TLS termination** and **health checks** as built-in wins.

## Further Exploration

- NGINX & HAProxy architecture guides; Envoy docs.
- AWS ELB listener configuration.
- *Scalability for Dummies — Clones* (lecloud).
- Explore next: **consistent hashing**, **service mesh (Envoy/Istio)**, **GSLB**,
  **connection draining & graceful deploys**.
