# Content Delivery Network (CDN)

> **Deep dive** extracted from `Overview.md`. A CDN is a globally distributed network of
> proxy servers that serve content from locations close to the user.

---

## Table of Contents

1. [What a CDN Is](#what-a-cdn-is)
2. [Why CDNs Improve Performance](#why-cdns-improve-performance)
3. [How a CDN Request Flows](#how-a-cdn-request-flows)
4. [Push CDNs](#push-cdns)
5. [Pull CDNs](#pull-cdns)
6. [Push vs Pull Comparison](#push-vs-pull-comparison)
7. [Cache Invalidation & Versioning](#cache-invalidation--versioning)
8. [Static vs Dynamic Content](#static-vs-dynamic-content)
9. [Edge Computing (Beyond Caching)](#edge-computing-beyond-caching)
10. [Disadvantages of CDNs](#disadvantages-of-cdns)
11. [Interview Talking Points](#interview-talking-points)
12. [Further Exploration](#further-exploration)

---

## What a CDN Is

A **Content Delivery Network** is a geographically distributed set of **edge** proxy
servers (Points of Presence, "PoPs"). Static assets — HTML, CSS, JS, images, video — are
cached at the edge. Some CDNs (e.g., CloudFront) also accelerate **dynamic** content. DNS
resolution directs the client to the nearest edge.

## Why CDNs Improve Performance

1. **Proximity:** users fetch from a nearby PoP → lower latency (fewer network hops, RTTs).
2. **Origin offload:** the CDN absorbs most requests, so your origin servers do less work.
3. **Bandwidth savings & DDoS absorption** at the edge.
4. **Higher availability** — edge survives origin hiccups for cached content.

## How a CDN Request Flows

```
User ── DNS ──► nearest CDN edge (PoP)
                     │  cache HIT  → serve immediately
                     │  cache MISS → fetch from origin, cache, then serve
                     ▼
                  Origin server
```

## Push CDNs

Content is **uploaded to the CDN whenever it changes** on your origin — you take
responsibility for pushing and for URL rewriting.

- You control **when** content is uploaded and when it expires.
- Content is sent only when **new or changed** → minimizes traffic, **maximizes storage**.
- **Use case:** sites with **low traffic** or **infrequently changing** content. Content
  is placed once instead of being re-pulled periodically.

## Pull CDNs

Content is **pulled from your origin on the first user request**, then cached at the edge.

- You leave files on the origin and rewrite URLs to point at the CDN.
- First request is **slower** (cache miss → origin fetch), subsequent ones are fast.
- **TTL** decides how long the edge caches before re-validating.
- Minimizes CDN storage, but can cause **redundant pulls** if files expire before changing.
- **Use case:** **high-traffic** sites — load is spread out and only popular, recently
  requested content stays cached.

## Push vs Pull Comparison

| Dimension | Push CDN | Pull CDN |
|-----------|----------|----------|
| Who uploads | You (proactively) | CDN (lazily, on first miss) |
| Storage used | High (everything pushed) | Low (only requested) |
| First-request latency | Fast (pre-warmed) | Slow (cold miss) |
| Traffic to origin | Minimal | Periodic re-pulls on expiry |
| Best for | Low traffic / rarely changing | High traffic / large catalogs |
| Control over freshness | High (explicit) | TTL-driven |

## Cache Invalidation & Versioning

- **TTL expiry** — simplest; content refreshes after the TTL window.
- **Purge / invalidation API** — force-evict an object immediately (can be slow/rate-limited).
- **Cache busting / fingerprinting** — embed a hash/version in the filename
  (`app.9f2c1.js`) so a new deploy = a new URL = guaranteed fresh fetch. **Preferred** for
  static assets.

## Static vs Dynamic Content

- **Static** (images, JS, CSS, video) → ideal CDN candidates.
- **Dynamic** (personalized HTML, API responses) → use **Dynamic Site Acceleration**:
  optimized routing, persistent origin connections, edge TLS termination, partial caching
  of cacheable fragments.

## Edge Computing (Beyond Caching)

Modern CDNs run code at the edge:

- **Cloudflare Workers**, **AWS Lambda@Edge**, **Fastly Compute@Edge**.
- Use cases: A/B testing, auth checks, header rewriting, personalization, image resizing —
  all close to the user, reducing origin round-trips.

## Disadvantages of CDNs

- **Cost** can be significant at high traffic (weigh against origin/bandwidth savings).
- **Staleness** — content may be outdated until the TTL expires.
- **URL rewriting** — static content URLs must point to the CDN.
- Extra moving part / vendor dependency.

## Interview Talking Points

- Place a CDN **right after DNS** in any read-heavy / media design.
- Pick **pull for high traffic**, **push for small/static** sites — and justify it.
- Use **content fingerprinting** for cache busting instead of manual purges.
- Mention CDN as **DDoS protection** and **TLS termination** point.

## Further Exploration

- CloudFront / Akamai / Cloudflare / Fastly architecture docs.
- *Why use a CDN* (lecloud / high-scalability articles).
- Explore next: **Anycast routing**, **edge compute**, **HTTP caching headers
  (`Cache-Control`, `ETag`)**, **multi-CDN strategies**.
