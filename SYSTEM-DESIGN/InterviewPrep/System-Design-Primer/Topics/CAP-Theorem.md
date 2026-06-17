# CAP Theorem (Availability vs Consistency)

> **Deep dive** extracted from `Overview.md`. The CAP theorem is the single most cited
> result in distributed systems design and underpins almost every database trade-off.

---

## Table of Contents

1. [The Core Statement](#the-core-statement)
2. [Defining the Three Guarantees](#defining-the-three-guarantees)
3. [Why You Must Tolerate Partitions](#why-you-must-tolerate-partitions)
4. [CP - Consistency + Partition Tolerance](#cp---consistency--partition-tolerance)
5. [AP - Availability + Partition Tolerance](#ap---availability--partition-tolerance)
6. [CA - The Theoretical Corner](#ca---the-theoretical-corner)
7. [PACELC - The Missing Half of CAP](#pacelc---the-missing-half-of-cap)
8. [Mapping Real Databases to CAP](#mapping-real-databases-to-cap)
9. [Common Misconceptions](#common-misconceptions)
10. [Interview Talking Points](#interview-talking-points)
11. [Further Exploration](#further-exploration)

---

## The Core Statement

In a distributed system, when a **network partition** occurs, you must choose between
**Consistency** and **Availability** — you cannot have both. The theorem (proven by
Gilbert & Lynch, 2002, formalizing Eric Brewer's 2000 conjecture) says you can only
guarantee **two of three** properties simultaneously.

```
        Consistency
           /  \
          /    \
         / CP   \  CA (only without partitions)
        /        \
 Availability --- Partition Tolerance
            AP
```

## Defining the Three Guarantees

| Property | Precise Meaning |
|----------|-----------------|
| **Consistency (C)** | Every read receives the most recent write **or an error**. This is *linearizability* — the system behaves as if there is a single, up-to-date copy of the data. (Note: this is **not** the "C" in ACID.) |
| **Availability (A)** | Every request received by a non-failing node returns a **non-error response** — but with no guarantee it is the latest data. |
| **Partition Tolerance (P)** | The system continues operating despite an arbitrary number of dropped/delayed messages between nodes (a network split). |

> ⚠️ **Key nuance:** CAP's "Consistency" = **linearizability**, while ACID's "Consistency"
> = preserving database invariants. They are different concepts that share a name.

## Why You Must Tolerate Partitions

Networks are unreliable: switches fail, cables get cut, GC pauses and packet loss create
*effective* partitions. Since partitions **will** happen, `P` is non-negotiable for any
real distributed system. CAP therefore collapses into a practical binary choice:

> **During a partition, do you sacrifice Consistency (stay available) or sacrifice
> Availability (stay consistent)?**

## CP - Consistency + Partition Tolerance

When a partition happens, a CP system **refuses requests** (returns errors/timeouts) on
the minority side rather than serve stale or conflicting data.

- **Behaviour:** Waiting for a response from a partitioned node may time out.
- **Use when:** Business requires atomic reads/writes and correctness over uptime.
- **Examples:** Banking ledgers, inventory counts, distributed locks, leader election.
- **Tech:** HBase, MongoDB (default majority), Redis (with strong settings), Zookeeper,
  etcd, Google Spanner (leans CP).

## AP - Availability + Partition Tolerance

When a partition happens, an AP system **keeps serving** the most recent locally-available
version, reconciling later when the partition heals.

- **Behaviour:** Reads always succeed but may be stale; writes propagate after healing.
- **Use when:** Eventual consistency is acceptable and uptime is paramount.
- **Examples:** Shopping carts, social feeds, DNS, product catalogs, like counters.
- **Tech:** Cassandra, DynamoDB, CouchDB, Riak, Voldemort.

## CA - The Theoretical Corner

A "CA" system gives up partition tolerance — meaningful only for **single-node** systems
or systems on a perfectly reliable network (which doesn't exist at scale). A classic
single-instance RDBMS (PostgreSQL/MySQL on one node) is effectively CA. **In a distributed
context, CA is not a real option.**

## PACELC - The Missing Half of CAP

CAP only describes behaviour *during a partition*. **PACELC** (Abadi, 2012) extends it:

> **If Partition (P)** → choose between **Availability (A)** and **Consistency (C)**,
> **Else (E)** (normal operation) → choose between **Latency (L)** and **Consistency (C)**.

This captures the everyday trade-off: even with no partition, strong consistency costs
latency (coordination/quorums).

| System | PACELC Classification |
|--------|----------------------|
| DynamoDB / Cassandra | **PA/EL** — availability under partition, low latency otherwise |
| Spanner / VoltDB | **PC/EC** — consistency always (pays latency cost) |
| MongoDB | **PA/EC** (tunable) |

## Mapping Real Databases to CAP

| Database | Default Lean | Notes |
|----------|-------------|-------|
| Cassandra | **AP** | Tunable consistency per query (`ONE`, `QUORUM`, `ALL`) |
| DynamoDB | **AP** | Optional strongly-consistent reads |
| MongoDB | **CP** | Majority write concern; tunable read concern |
| HBase | **CP** | Built on HDFS, strong consistency |
| Zookeeper / etcd | **CP** | Coordination services need consistency |
| Spanner | **CP** | TrueTime + Paxos; "effectively CA" via redundancy |
| Riak / Cassandra | **AP** | Quorum tuning blurs the line |

> 💡 Most modern stores offer **tunable consistency**, so "AP vs CP" is per-operation,
> not a fixed label.

## Common Misconceptions

- ❌ *"You permanently pick 2 of 3."* → The choice only matters **during a partition**.
- ❌ *"CAP's C == ACID's C."* → No; CAP-C is linearizability.
- ❌ *"CA systems exist at scale."* → Not realistically; partitions are unavoidable.
- ❌ *"AP means no consistency ever."* → AP systems are usually **eventually consistent**.

## Interview Talking Points

- Frame designs as: *"During a partition, this subsystem favours **X** because **business reason**."*
- Different subsystems can pick differently: payments = CP, news feed = AP.
- Mention **tunable consistency** (quorums: `W + R > N`) to show nuance.
- Bring up **PACELC** to demonstrate you understand the latency/consistency cost in normal operation.

## Further Exploration

- Gilbert & Lynch — *Brewer's Conjecture and the Feasibility of CAP* (2002 proof)
- Eric Brewer — *CAP Twelve Years Later: How the "Rules" Have Changed*
- Daniel Abadi — *Consistency Tradeoffs in Modern Distributed Database System Design (PACELC)*
- Kleppmann — *Designing Data-Intensive Applications*, Ch. 9 (Consistency & Consensus)
- Concepts to explore next: **Quorums (N/W/R)**, **Linearizability vs Serializability**,
  **Consensus (Paxos, Raft)**, **Vector clocks & conflict resolution**.
