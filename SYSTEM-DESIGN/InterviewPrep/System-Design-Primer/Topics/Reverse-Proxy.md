# Reverse Proxy (Web Server)

> **Deep dive** extracted from `Overview.md`. A reverse proxy is a web server that
> centralizes internal services and provides a unified interface to the public.

---

## Table of Contents

1. [What a Reverse Proxy Is](#what-a-reverse-proxy-is)
2. [Forward Proxy vs Reverse Proxy](#forward-proxy-vs-reverse-proxy)
3. [Benefits](#benefits)
4. [Load Balancer vs Reverse Proxy](#load-balancer-vs-reverse-proxy)
5. [Common Tools](#common-tools)
6. [Typical Architecture](#typical-architecture)
7. [Disadvantages](#disadvantages)
8. [Interview Talking Points](#interview-talking-points)
9. [Further Exploration](#further-exploration)

---

## What a Reverse Proxy Is

A **reverse proxy** receives client requests, forwards them to one of several backend
servers, and returns the backend's response to the client. Clients only ever talk to the
proxy — they never see the backends directly.

```
Client ──► Reverse Proxy ──► Backend services (web/app/api)
        ◄──               ◄──
```

## Forward Proxy vs Reverse Proxy

| | Forward Proxy | Reverse Proxy |
|--|---------------|----------------|
| Acts on behalf of | The **client** | The **server** |
| Hides | The client from the server | The servers from the client |
| Typical use | Corporate egress, content filtering, anonymity | Security, caching, LB, TLS termination |
| Example | A company proxy your browser routes through | NGINX in front of app servers |

## Benefits

- **Increased security** — hide backend details, blacklist IPs, limit connections per
  client, act as a WAF chokepoint.
- **Increased scalability & flexibility** — clients see only the proxy's IP, so you can
  add/remove/reconfigure backends freely.
- **SSL/TLS termination** — decrypt requests / encrypt responses so backends skip the work;
  removes the need to install **X.509 certificates** on every server.
- **Compression** — compress responses (gzip/brotli) centrally.
- **Caching** — return cached responses without hitting backends.
- **Static content** — serve HTML/CSS/JS, images, and video directly from the edge of your
  own infrastructure.

## Load Balancer vs Reverse Proxy

These overlap (NGINX/HAProxy do both at L7), but the *intent* differs:

| | Load Balancer | Reverse Proxy |
|--|---------------|----------------|
| Primary purpose | **Distribute** traffic across **many identical** servers | **Centralize/abstract** access to backend(s) |
| Useful with 1 server? | Not really (nothing to balance) | **Yes** — still gives caching, TLS, security, compression |
| Focus | Spreading load, removing SPOF | Unified interface, offloading cross-cutting concerns |

> 💡 A single box (NGINX/HAProxy) often plays **both** roles simultaneously: L7 reverse
> proxy **and** load balancer.

## Common Tools

- **NGINX**, **HAProxy**, **Envoy**, **Apache httpd**, **Traefik**, **Caddy**.
- Cloud: NGINX-based managed services, AWS ALB (acts proxy-like at L7).

## Typical Architecture

```
              ┌──────────────► Static files (cached)
Client ─► Reverse Proxy (NGINX) ─► App Server 1
              │  TLS termination  ─► App Server 2
              │  gzip + cache     ─► App Server 3
              └──────────────► /api ► API service
```

The reverse proxy also commonly fronts a **load-balancing** pool and enables
**asynchronism** by routing to worker-backed endpoints.

## Disadvantages

- Introducing a reverse proxy **increases complexity**.
- A single reverse proxy is a **single point of failure**; running multiple (a failover)
  further increases complexity.

## Interview Talking Points

- Use a reverse proxy to **offload TLS, caching, compression, and static serving** from
  app servers.
- Clarify the LB-vs-reverse-proxy distinction: reverse proxy is valuable **even with one
  backend**.
- Note that NGINX/HAProxy do **both L7 proxying and load balancing**.
- Make it redundant to avoid SPOF.

## Further Exploration

- NGINX: *Inside NGINX — designed for performance & scale*.
- HAProxy architecture guide.
- *Reverse proxy vs load balancer* (NGINX glossary).
- Explore next: **API gateways**, **service mesh sidecars (Envoy)**, **WAFs**,
  **mTLS between services**.
