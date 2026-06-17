# Availability Patterns

> **Deep dive** extracted from `Overview.md`. Two complementary patterns support high
> availability: **fail-over** and **replication**. This file also covers how to *quantify*
> availability and combine components.

---

## Table of Contents

1. [What Availability Means](#what-availability-means)
2. [Fail-over](#fail-over)
   - [Active-Passive](#active-passive)
   - [Active-Active](#active-active)
   - [Disadvantages of Fail-over](#disadvantages-of-fail-over)
3. [Replication](#replication)
4. [Availability in Numbers (The 9s)](#availability-in-numbers-the-9s)
5. [Combining Availability: Sequence vs Parallel](#combining-availability-sequence-vs-parallel)
6. [Heartbeats, Health Checks & Failure Detection](#heartbeats-health-checks--failure-detection)
7. [Related Resilience Patterns](#related-resilience-patterns)
8. [Interview Talking Points](#interview-talking-points)
9. [Further Exploration](#further-exploration)

---

## What Availability Means

**Availability** = the proportion of time a system is operational and able to respond.
Achieved through **redundancy** (no single point of failure) plus a mechanism to detect
failure and shift load (**fail-over**) and keep data copies in sync (**replication**).

## Fail-over

### Active-Passive

- Heartbeats flow between an **active** server and a **passive** standby.
- If heartbeats stop, the passive server takes over the active's IP and resumes service.
- Downtime depends on whether standby is **hot** (already running) or **cold** (must boot).
- Only the active node serves traffic.
- **a.k.a.** Master-slave failover.

### Active-Active

- **Both** nodes serve traffic, sharing the load.
- Requirements:
  - **Public-facing:** DNS must know the public IPs of both servers.
  - **Internal-facing:** Application logic must know about both servers.
- **a.k.a.** Master-master failover.

### Disadvantages of Fail-over

- Adds hardware and complexity.
- **Data-loss risk:** if the active node dies before newly written data replicates to the
  passive node, that data is lost.
- Split-brain risk (both think they're active) requires fencing/quorum.

## Replication

Keeps redundant data copies in sync so a standby can take over with current data.

1. **Master-slave replication** — master serves writes (+reads), slaves serve reads.
2. **Master-master replication** — multiple masters accept writes, coordinate with each other.

> See `RDBMS.md` for full replication mechanics, lag, and trade-offs.

## Availability in Numbers (The 9s)

Availability is measured in "9s." A 99.99% service has **four 9s**.

### 99.9% — Three 9s

| Period | Acceptable Downtime |
|--------|---------------------|
| per year | 8h 45min 57s |
| per month | 43m 49.7s |
| per week | 10m 4.8s |
| per day | 1m 26.4s |

### 99.99% — Four 9s

| Period | Acceptable Downtime |
|--------|---------------------|
| per year | 52min 35.7s |
| per month | 4m 23s |
| per week | 1m 5s |
| per day | 8.6s |

> Each extra "9" costs ~10× the engineering effort. Five 9s (99.999%) ≈ 5.26 min/year.

## Combining Availability: Sequence vs Parallel

The overall availability depends on how failure-prone components are arranged.

### In Sequence (dependency chain) — availability **decreases**

```
Availability(Total) = Availability(Foo) × Availability(Bar)
```

**Example:** 99.9% × 99.9% = **99.8%** (worse than either alone).

### In Parallel (redundant copies) — availability **increases**

```
Availability(Total) = 1 − (1 − Availability(Foo)) × (1 − Availability(Bar))
```

**Example:** two 99.9% components in parallel = **99.9999%** (six 9s).

> 🔑 **Design lesson:** Long dependency chains erode availability; redundancy multiplies it.
> Minimize the number of *in-sequence* single points of failure.

## Heartbeats, Health Checks & Failure Detection

- **Heartbeat:** periodic "I'm alive" signal between nodes.
- **Health checks:** LB/orchestrator probes (HTTP `/health`, TCP connect) to mark nodes
  in/out of rotation.
- **Timeouts & thresholds:** avoid flapping by requiring N consecutive failures.
- **Quorum / fencing:** prevent **split-brain** when both nodes believe they are primary.

## Related Resilience Patterns

- **Circuit breaker** — stop calling a failing dependency to prevent cascading failure.
- **Bulkhead** — isolate resources so one overloaded component can't sink the whole system.
- **Retry with exponential backoff + jitter** — recover from transient faults safely.
- **Graceful degradation** — serve reduced functionality instead of total failure.
- **Redundancy across AZs/regions** — survive datacenter-level outages.

## Interview Talking Points

- State a target SLA ("four 9s") and justify the redundancy it implies.
- Use the sequence/parallel formulas to reason about end-to-end SLA.
- Always call out and eliminate **single points of failure (SPOF)**.
- Mention **split-brain** + how quorum/fencing prevents it.

## Further Exploration

- Google SRE Book — *Service Level Objectives*, *Managing Risk*.
- Nygard — *Release It!* (circuit breaker, bulkhead, stability patterns).
- Explore next: **consensus for leader election (Raft)**, **chaos engineering**,
  **multi-region active-active**, **error budgets**.
