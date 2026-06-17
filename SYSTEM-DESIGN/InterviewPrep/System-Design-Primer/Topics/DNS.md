# Domain Name System (DNS)

> **Deep dive** extracted from `Overview.md`. DNS translates human-readable domain names
> (e.g., `www.example.com`) into IP addresses — the "phone book" of the internet.

---

## Table of Contents

1. [What DNS Does](#what-dns-does)
2. [The DNS Hierarchy](#the-dns-hierarchy)
3. [Anatomy of a Lookup (Step by Step)](#anatomy-of-a-lookup-step-by-step)
4. [Caching and TTL](#caching-and-ttl)
5. [Record Types](#record-types)
6. [DNS-Based Traffic Routing](#dns-based-traffic-routing)
7. [Managed DNS Providers](#managed-dns-providers)
8. [DNS and Security](#dns-and-security)
9. [Disadvantages of DNS](#disadvantages-of-dns)
10. [Interview Talking Points](#interview-talking-points)
11. [Further Exploration](#further-exploration)

---

## What DNS Does

A **Domain Name System** maps a domain name to an IP address so users don't memorize
numbers. Your router or ISP tells your machine which DNS resolver to contact. Results are
cached at multiple layers (browser, OS, resolver), which can cause **propagation delays**
when records change.

## The DNS Hierarchy

DNS is a **distributed, hierarchical** database with a handful of authoritative servers
at the top:

```
            . (root)
             |
   ┌─────────┼─────────┐
  .com      .org      .net        ← Top-Level Domain (TLD) servers
   |
 example.com                       ← Authoritative name server for the domain
   |
 www.example.com → 93.184.216.34   ← Final A record
```

- **Root servers** — direct queries to the right TLD.
- **TLD servers** — `.com`, `.org`, country codes (`.in`, `.uk`).
- **Authoritative name servers** — hold the actual records for a domain.
- **Recursive resolvers** — do the legwork on the client's behalf (often ISP/CloudFlare `1.1.1.1`, Google `8.8.8.8`).

## Anatomy of a Lookup (Step by Step)

1. Browser/OS cache checked first. Hit → done.
2. Miss → query the **recursive resolver**.
3. Resolver asks a **root** server → referred to the `.com` TLD server.
4. Resolver asks the **TLD** server → referred to the domain's **authoritative** server.
5. Resolver asks the **authoritative** server → gets the **A/AAAA** record.
6. Resolver caches the answer (per **TTL**) and returns the IP to the client.
7. Client opens a TCP/HTTP(S) connection to that IP.

> Steps 3–5 are *iterative* from the resolver's view; the client sees a single *recursive*
> answer.

## Caching and TTL

- Every record has a **TTL (Time To Live)** controlling how long it may be cached.
- **Low TTL** (e.g., 60s) → faster failover/changes, more query load.
- **High TTL** (e.g., 24h) → less load, slower propagation when you change records.
- Stale caches are why DNS changes can take time to "propagate" globally.

## Record Types

| Record | Purpose |
|--------|---------|
| **A** | Maps a name → IPv4 address |
| **AAAA** | Maps a name → IPv6 address |
| **CNAME** | Alias: points a name → another name (e.g., `example.com` → `www.example.com`) |
| **NS** | Specifies the authoritative name servers for the domain/subdomain |
| **MX** | Specifies the mail servers that accept email for the domain |
| **TXT** | Arbitrary text — used for SPF/DKIM/domain verification |
| **SOA** | Start of Authority — zone metadata (serial, refresh, TTLs) |
| **PTR** | Reverse DNS: IP → name |

## DNS-Based Traffic Routing

Managed DNS can route intelligently — useful for global load distribution:

- **Weighted round robin** — split traffic by weights; drain servers under maintenance;
  balance unequal cluster sizes; A/B testing.
- **Latency-based** — send users to the lowest-latency region.
- **Geolocation-based** — route by the user's geographic location (data residency, locale).
- **Failover / health-checked** — stop returning IPs of unhealthy endpoints.

## Managed DNS Providers

- **AWS Route 53**, **CloudFlare**, **Google Cloud DNS**, **Azure DNS**, **NS1**.
- Provide health checks, traffic policies, DNSSEC, and global anycast networks.

## DNS and Security

- **DDoS target:** DNS infrastructure has been attacked (e.g., the 2016 Dyn attack took
  down Twitter, GitHub, etc.). Mitigations: anycast, over-provisioning, multiple providers.
- **DNSSEC:** cryptographically signs records to prevent spoofing/cache poisoning.
- **DoH / DoT:** DNS-over-HTTPS / over-TLS encrypt queries for privacy.

## Disadvantages of DNS

- Adds a slight lookup delay (mitigated by caching).
- Management is complex; ultimately governed by ISPs, registrars, and large orgs.
- A target for DDoS — an outage can make sites unreachable even if servers are healthy.

## Interview Talking Points

- DNS is the **first hop** in almost every "design a web-scale system" answer.
- Use **latency/geo routing** to introduce global traffic management before the LB layer.
- Discuss **TTL trade-offs** for failover speed vs query load.
- Mention DNS as a **SPOF** and how anycast + multi-provider mitigates it.

## Further Exploration

- *How DNS Works* (comic, howdns.works).
- RFC 1034 / 1035 (DNS specifications).
- AWS Route 53 routing-policy docs.
- Explore next: **Anycast networks**, **DNSSEC**, **service discovery (internal DNS)**,
  **GSLB (Global Server Load Balancing)**.
