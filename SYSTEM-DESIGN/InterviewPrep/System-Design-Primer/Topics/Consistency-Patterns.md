# Consistency Patterns

> **Deep dive** extracted from `Overview.md`. With multiple copies of the same data, we
> must decide how clients observe writes. These patterns define the contract.

---

## Table of Contents

1. [The Replication Problem](#the-replication-problem)
2. [Weak Consistency](#weak-consistency)
3. [Eventual Consistency](#eventual-consistency)
4. [Strong Consistency](#strong-consistency)
5. [The Consistency Spectrum](#the-consistency-spectrum)
6. [Quorum Consistency (N, W, R)](#quorum-consistency-n-w-r)
7. [Client-Centric Consistency Models](#client-centric-consistency-models)
8. [Conflict Resolution Strategies](#conflict-resolution-strategies)
9. [Choosing a Pattern](#choosing-a-pattern)
10. [Interview Talking Points](#interview-talking-points)
11. [Further Exploration](#further-exploration)

---

## The Replication Problem

The moment data is copied to more than one node (for availability, locality, or
throughput), reads and writes can diverge. A **consistency model** is the *contract*
between the data store and the application about what a read can return after a write.

> Recall (CAP): **Consistency** = every read receives the most recent write or an error.

## Weak Consistency

After a write, reads **may or may not** see it — best-effort, no guarantee.

- **Mechanics:** No coordination; if you miss an update, it's gone for you.
- **Examples:** Memcached, VoIP, video chat, real-time multiplayer games.
- **Use case:** Real-time systems where stale/lost data is acceptable. Lose phone
  reception for a few seconds → you simply miss those words; no replay.

## Eventual Consistency

After a write, reads will **eventually** see it (typically milliseconds). Replicas
converge asynchronously once writes stop.

- **Mechanics:** Asynchronous replication, anti-entropy, read-repair, hinted handoff.
- **Examples:** DNS, email, Cassandra, DynamoDB, Amazon S3.
- **Use case:** Highly available systems tolerating brief inconsistency.
- **Guarantee:** *Convergence* — given no new writes, all replicas reach the same value.

## Strong Consistency

After a write, **all** subsequent reads see it. Replication is synchronous.

- **Mechanics:** Writes block until replicated/committed (quorum, 2PC, consensus).
- **Examples:** File systems, RDBMSes, Spanner, Zookeeper/etcd.
- **Use case:** Transactions and correctness-critical state (money, inventory, locks).
- **Cost:** Higher latency and reduced availability during partitions (CP behaviour).

## The Consistency Spectrum

```
Weak ──────── Eventual ──────── Causal ──────── Read-your-writes ──────── Linearizable (Strong)
  ▲                                                                              ▲
less coordination / lower latency / higher availability      more coordination / correctness
```

## Quorum Consistency (N, W, R)

A practical, tunable middle ground used by Dynamo-style stores:

- **N** = number of replicas
- **W** = nodes that must **acknowledge a write**
- **R** = nodes that must **respond to a read**

> **Strong (quorum) consistency when `W + R > N`** — read and write sets overlap on at
> least one up-to-date node.

| Config | Behaviour |
|--------|-----------|
| `W=N, R=1` | Fast reads, slow/strongly-durable writes |
| `W=1, R=N` | Fast writes, slow reads |
| `W=R=⌈(N+1)/2⌉` | Balanced quorum (e.g., N=3 → W=R=2) |
| `W + R ≤ N` | Eventual consistency (possible stale reads) |

## Client-Centric Consistency Models

Useful guarantees that sit between eventual and strong:

- **Read-your-writes:** A user always sees their own updates (e.g., your profile edit).
- **Monotonic reads:** You never see data go "backwards" in time.
- **Monotonic writes:** Your writes apply in the order you issued them.
- **Causal consistency:** Operations with a cause→effect relationship are seen in order
  by everyone (e.g., reply appears after the comment it answers).

## Conflict Resolution Strategies

When concurrent writes diverge (AP systems), reconcile via:

- **Last-Write-Wins (LWW):** Pick highest timestamp — simple but can lose data.
- **Vector clocks / version vectors:** Detect causality vs true conflicts.
- **CRDTs (Conflict-free Replicated Data Types):** Merge automatically (counters, sets).
- **Application-level merge:** e.g., Amazon's "merge shopping carts" — union of items.
- **Quorum read-repair:** Stale replicas fixed on read.

## Choosing a Pattern

| Need | Pattern |
|------|---------|
| Money, inventory, locks | **Strong** |
| Social feed, catalog, DNS | **Eventual** |
| Live game state, telemetry | **Weak** |
| "See my own edits instantly" | **Read-your-writes** (client-centric) |

## Interview Talking Points

- Tie the model to **CAP/PACELC**: strong = CP/EC, eventual = AP/EL.
- Quote `W + R > N` to show quorum understanding.
- Note you can mix models per-feature within one product.
- Mention **read-repair**, **hinted handoff**, **anti-entropy** for eventual systems.

## Further Exploration

- Kleppmann — *DDIA*, Ch. 5 (Replication) & Ch. 9 (Consistency).
- Amazon Dynamo paper (2007) — quorums, vector clocks, hinted handoff.
- Werner Vogels — *Eventually Consistent*.
- Explore next: **CRDTs**, **linearizability proofs**, **causal+ consistency**, **Spanner TrueTime**.
