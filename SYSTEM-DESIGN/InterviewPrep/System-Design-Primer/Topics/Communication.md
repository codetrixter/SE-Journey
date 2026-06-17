# Communication (HTTP, TCP, UDP, RPC, REST)

> **Deep dive** extracted from `Overview.md`. How services and clients talk to each other —
> from transport protocols (TCP/UDP) up to application protocols (HTTP) and API styles
> (RPC, REST).

---

## Table of Contents

1. [The Protocol Stack](#the-protocol-stack)
2. [HTTP](#hypertext-transfer-protocol-http)
3. [TCP](#transmission-control-protocol-tcp)
4. [UDP](#user-datagram-protocol-udp)
5. [TCP vs UDP](#tcp-vs-udp)
6. [Remote Procedure Call (RPC)](#remote-procedure-call-rpc)
7. [Representational State Transfer (REST)](#representational-state-transfer-rest)
8. [RPC vs REST](#rpc-vs-rest)
9. [RPC and REST Calls Comparison](#rpc-and-rest-calls-comparison)
10. [Where GraphQL & gRPC Fit](#where-graphql--grpc-fit)
11. [Interview Talking Points](#interview-talking-points)
12. [Further Exploration](#further-exploration)

---

## The Protocol Stack

```
Application │ HTTP, gRPC, REST, GraphQL, DNS, SMTP   ← what apps speak
Transport   │ TCP (reliable), UDP (fast)             ← how bytes move
Network     │ IP                                     ← addressing/routing
```

API styles (REST, RPC) ride on **HTTP**, which rides on **TCP/UDP**, which ride on **IP**.

## Hypertext Transfer Protocol (HTTP)

HTTP encodes and transports data between client and server. It's a **request/response**
protocol: clients issue requests; servers respond with content + status. HTTP is
**self-contained**, so requests/responses flow through intermediaries (LBs, caches,
proxies) that do load balancing, caching, encryption, compression.

A request has a **verb (method)** + a **resource (endpoint)**:

| Verb | Description | Idempotent* | Safe | Cacheable |
|------|-------------|-------------|------|-----------|
| GET | Read a resource | Yes | Yes | Yes |
| POST | Create a resource / trigger a process | No | No | Yes (if response has freshness info) |
| PUT | Create or replace a resource | Yes | No | No |
| PATCH | Partially update a resource | No | No | Yes (if response has freshness info) |
| DELETE | Delete a resource | Yes | No | No |

> **\*Idempotent** = can be called many times with the same outcome.

HTTP is an **application-layer** protocol relying on lower-level **TCP/UDP**.

> **Versions worth knowing:** HTTP/1.1 (keep-alive), **HTTP/2** (multiplexing, header
> compression, server push), **HTTP/3** (runs over **QUIC/UDP** — faster setup, no
> head-of-line blocking).

## Transmission Control Protocol (TCP)

TCP is **connection-oriented** over IP. Connections are set up/torn down via a
**handshake**. All packets are guaranteed to arrive **in order, uncorrupted**, via:

- **Sequence numbers** and **checksums** per packet.
- **Acknowledgements** and **automatic retransmission**.

If a correct response isn't received, the sender **resends**; repeated timeouts **drop** the
connection. TCP also does **flow control** and **congestion control**. These guarantees add
**delay** → generally less efficient than UDP.

For high throughput, servers keep **many TCP connections open** → high memory. Large numbers
of open connections (e.g., to memcached) are expensive → use **connection pooling**, and
switch to UDP where applicable.

**Use TCP when:** you need all data intact; you want automatic best-estimate use of
throughput. Examples: web, DB connections, SMTP, FTP, SSH.

## User Datagram Protocol (UDP)

UDP is **connectionless**. **Datagrams** are guaranteed only at the datagram level — they
may arrive **out of order or not at all**. **No congestion control** → more efficient.

UDP can **broadcast** datagrams to all devices on a subnet — useful for **DHCP** (client has
no IP yet, so TCP can't be used).

**Use UDP when:** you need the **lowest latency**; **late data is worse than lost data**;
you'll implement your **own error correction**. Examples: VoIP, video chat, streaming,
real-time multiplayer games.

## TCP vs UDP

| Aspect | TCP | UDP |
|--------|-----|-----|
| Connection | Connection-oriented (handshake) | Connectionless |
| Reliability | Guaranteed, ordered, error-checked | Best-effort, may drop/reorder |
| Flow/Congestion control | Yes | No |
| Overhead/latency | Higher | Lower |
| Broadcast | No | Yes |
| Use cases | Web, DB, SSH, FTP | VoIP, streaming, gaming, DHCP, DNS |

## Remote Procedure Call (RPC)

In RPC, a client invokes a procedure that **executes on a remote server**, coded as if it
were **local** — the communication details are abstracted away. Remote calls are slower/less
reliable than local ones, so it helps to distinguish them. Popular frameworks: **Protobuf
(gRPC), Thrift, Avro**.

RPC is a **request-response** protocol:

- **Client program** — calls the client **stub**; params pushed on the stack (like a local call).
- **Client stub** — **marshals** (packs) procedure id + args into a request message.
- **Client comm module** — OS sends the message to the server.
- **Server comm module** — OS passes packets to the server stub.
- **Server stub** — **unmarshals**, calls the matching procedure with the args.

The response repeats these steps in reverse.

```
GET  /someoperation?data=anId

POST /anotheroperation
{ "data": "anId", "anotherdata": "another value" }
```

RPC **exposes behaviors**. Often used for **internal** communication for **performance**
(hand-crafted native calls).

**Choose a native library/SDK when:** you know the target platform; you want to control how
logic is accessed and how errors propagate; performance & UX are primary.

> Public APIs tend to use **REST over HTTP** instead.

### Disadvantages of RPC

- Clients become **tightly coupled** to the service implementation.
- A **new API** is needed for every new operation/use case.
- **Harder to debug**.
- May not leverage existing tooling out-of-the-box (e.g., caching on Squid needs extra effort).

## Representational State Transfer (REST)

REST is an **architectural style**: a client acts on **resources** managed by a server. The
server exposes representations of resources and actions. All communication is **stateless**
and **cacheable**.

Four qualities of a RESTful interface:

- **Identify resources (URI)** — same URI regardless of operation.
- **Change via representations (verbs)** — use verbs, headers, body.
- **Self-descriptive errors (status codes)** — don't reinvent the wheel.
- **HATEOAS** — the service should be fully navigable in a browser.

```
GET /someresources/anId

PUT /someresources/anId
{ "anotherdata": "another value" }
```

REST **exposes data**, minimizes client/server coupling, and is ideal for **public HTTP
APIs**. It uses URIs (resources), headers (representation), and verbs (GET/POST/PUT/DELETE/
PATCH). Being **stateless**, REST scales horizontally and partitions well.

### Disadvantages of REST

- Poor fit when resources aren't a natural **hierarchy** (e.g., "all records updated in the
  past hour matching events" → awkward path; needs URI + query params + body).
- The few verbs sometimes **don't fit** (e.g., "move expired docs to archive").
- Nested resources need **multiple round trips** (blog entry + its comments) — bad on mobile
  with variable networks.
- Response **bloat** over time: new fields are sent to **all** clients even if unneeded →
  larger payloads/latency.

## RPC vs REST

| | RPC | REST |
|--|-----|------|
| Exposes | **Behaviors** (actions) | **Resources** (data) |
| Coupling | Tighter (impl-coupled) | Looser (uniform interface) |
| Typical use | **Internal**, performance-critical | **Public** APIs |
| Per operation | New endpoint/method | Reuse verbs on URIs |
| Caching | Harder | Built into HTTP (GET) |
| Examples | gRPC, Thrift, Avro | HTTP/JSON APIs |

## RPC and REST Calls Comparison

| Operation | RPC | REST |
|-----------|-----|------|
| Signup | `POST /signup` | `POST /persons` |
| Resign | `POST /resign` `{ "personid": "1234" }` | `DELETE /persons/1234` |
| Read a person | `GET /readPerson?personid=1234` | `GET /persons/1234` |
| Read a person's items | `GET /readUsersItemsList?personid=1234` | `GET /persons/1234/items` |
| Add an item | `POST /addItemToUsersItemsList` `{ "personid":"1234", "itemid":"456" }` | `POST /persons/1234/items` `{ "itemid": "456" }` |
| Update an item | `POST /modifyItem` `{ "itemid":"456", "key":"value" }` | `PUT /items/456` `{ "key": "value" }` |
| Delete an item | `POST /removeItem` `{ "itemid": "456" }` | `DELETE /items/456` |

## Where GraphQL & gRPC Fit

- **gRPC** — modern RPC on HTTP/2 + Protobuf; fast, streaming, strongly-typed; great for
  **internal** microservices.
- **GraphQL** — client specifies exactly the fields it needs in **one** request → fixes
  REST's over-fetching/round-trip issues; great for **mobile** and complex nested data.

## Interview Talking Points

- Pick **TCP vs UDP** by stating the trade-off (reliability vs latency) for the workload.
- Use **REST for public APIs**, **gRPC/RPC for internal** high-performance calls.
- Mention **idempotency** of HTTP verbs (matters for retries/caching).
- Reach for **GraphQL** to solve REST over-fetching and mobile round-trips.

## Further Exploration

- *Crack the system design interview* (puncsky).
- *Do you really know why you prefer REST over RPC* (apihandyman).
- *Networking for game programming* (ithare) — TCP/UDP trade-offs.
- HTTP/2 & HTTP/3 (QUIC) specs; gRPC and GraphQL docs.
- Explore next: **WebSockets/SSE**, **long polling**, **TLS handshake**, **API versioning**,
  **protocol buffers**.
