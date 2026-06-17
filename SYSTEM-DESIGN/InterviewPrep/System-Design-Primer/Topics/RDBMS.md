# Relational Database Management System (RDBMS)

> **Deep dive** extracted from `Overview.md`. A relational database (SQL) organizes data in
> tables. This file covers ACID and the major techniques to **scale** a relational DB:
> replication, federation, sharding, denormalization, and SQL tuning.

---

## Table of Contents

1. [What an RDBMS Is](#what-an-rdbms-is)
2. [ACID](#acid)
3. [Isolation Levels (Deeper)](#isolation-levels-deeper)
4. [Scaling Techniques Overview](#scaling-techniques-overview)
5. [Master-Slave Replication](#master-slave-replication)
6. [Master-Master Replication](#master-master-replication)
7. [Replication Disadvantages](#replication-disadvantages)
8. [Federation](#federation)
9. [Sharding](#sharding)
10. [Denormalization](#denormalization)
11. [SQL Tuning](#sql-tuning)
12. [Indexes Deep Dive](#indexes-deep-dive)
13. [Interview Talking Points](#interview-talking-points)
14. [Further Exploration](#further-exploration)

---

## What an RDBMS Is

A relational database is a collection of data organized in **tables** (rows + typed
columns) with relationships enforced by **keys** and queried with **SQL**. Examples:
PostgreSQL, MySQL, Oracle, SQL Server.

## ACID

ACID is the set of guarantees for relational transactions:

| Property | Meaning |
|----------|---------|
| **Atomicity** | Each transaction is **all or nothing** |
| **Consistency** | A transaction moves the DB from one **valid state to another** (invariants hold) |
| **Isolation** | Concurrent transactions yield the **same result as if run serially** |
| **Durability** | Once **committed**, data survives crashes |

> Note: ACID's "Consistency" (invariants) ≠ CAP's "Consistency" (linearizability).

Techniques to scale a relational DB: **master-slave replication**, **master-master
replication**, **federation**, **sharding**, **denormalization**, **SQL tuning**.

## Isolation Levels (Deeper)

| Level | Prevents | Allows |
|-------|----------|--------|
| Read Uncommitted | — | Dirty reads |
| Read Committed | Dirty reads | Non-repeatable reads |
| Repeatable Read | Non-repeatable reads | Phantom reads (in some engines) |
| Serializable | All anomalies | (lowest concurrency) |

Anomalies: **dirty read**, **non-repeatable read**, **phantom read**. Higher isolation =
stronger correctness, lower concurrency.

## Scaling Techniques Overview

```
Replication ─► more read capacity / availability
Federation  ─► split DBs by function
Sharding    ─► split rows of one table across nodes
Denormalize ─► trade write cost for faster reads
SQL Tuning  ─► squeeze more from existing hardware
```

## Master-Slave Replication

The **master** serves **reads and writes**, replicating writes to **slaves**, which serve
**reads only**. Slaves can replicate to further slaves (tree). If the master fails, the
system runs **read-only** until a slave is promoted or a new master is provisioned.

- ✅ Scales **reads**; provides redundancy.
- ❌ Promoting a slave to master needs extra logic; replication lag → stale reads.

## Master-Master Replication

Both masters serve **reads and writes** and coordinate on writes. If one fails, the system
keeps serving reads **and** writes.

- ❌ Needs an LB or app logic to decide **where to write**.
- ❌ Usually **loosely consistent** (violating ACID) or has **higher write latency** from
  synchronization.
- ❌ **Conflict resolution** grows harder as write nodes and latency increase.

## Replication Disadvantages

- **Data-loss risk** if the master dies before replicating newly written data.
- Heavy writes → read replicas busy **replaying writes**, leaving less capacity for reads.
- More read slaves → more to replicate → greater **replication lag**.
- Masters may write in parallel (multi-threaded) while replicas replay **sequentially**.
- Replication adds hardware and complexity.

## Federation

**Federation (functional partitioning)** splits databases **by function**. Instead of one
monolithic DB, have e.g. **forums**, **users**, and **products** databases.

- ✅ Less read/write traffic per DB → less replication lag.
- ✅ Smaller DBs fit more in memory → better **cache locality** → more cache hits.
- ✅ No single central master → **write in parallel** → higher throughput.
- ❌ Ineffective if a schema needs **huge functions/tables**.
- ❌ App logic must route to the right DB; **cross-DB joins** get complex (server links).
- ❌ More hardware and complexity.

## Sharding

**Sharding** distributes data so each DB holds only a **subset of the rows**. As users
grow, add shards. Common shard keys: **user's last-name initial** or **geographic location**.

- ✅ Less read/write traffic, less replication, more cache hits, smaller indexes → faster
  queries. One shard down ≠ all down (add replication to prevent loss). Parallel writes.
- ❌ App logic must be shard-aware → complex queries.
- ❌ **Hotspots/lopsided** data (power users on one shard).
- ❌ **Rebalancing** is hard — **consistent hashing** reduces data movement.
- ❌ **Cross-shard joins** are complex; more hardware/complexity.

> **Federation vs Sharding:** federation splits **by feature/table**; sharding splits the
> **rows of one table** across nodes.

## Denormalization

Improves **read** performance at the cost of **write** performance by writing **redundant
copies** across tables to avoid expensive joins.

- Some RDBMS (PostgreSQL, Oracle) support **materialized views** to manage redundancy.
- Valuable once data is federated/sharded and cross-node joins are costly.
- Reads often outnumber writes **100:1 or 1000:1**, so paying on writes can be worth it.
- ❌ Data duplication; constraints to keep copies in sync add complexity; heavy-write loads
  may perform **worse** than normalized.

## SQL Tuning

Broad topic — **benchmark** and **profile** to find bottlenecks:

- **Benchmark:** simulate high load (e.g., Apache `ab`).
- **Profile:** enable the **slow query log** to find slow queries.

### Tighten the Schema

- MySQL dumps to disk in contiguous blocks for fast access.
- `CHAR` (fixed length) → fast random access; `VARCHAR` requires finding the string end.
- `TEXT` for large blocks (allows boolean search; stores a pointer on disk).
- `INT` for numbers up to 2³² (~4B); `DECIMAL` for currency (avoids float errors).
- Don't store large `BLOB`s — store a **location/reference** instead.
- `VARCHAR(255)` fits length in an 8-bit count → byte-efficient in some RDBMS.
- Set `NOT NULL` where applicable to speed up searches.

### Use Good Indices

- Index columns used in `SELECT`, `WHERE`, `GROUP BY`, `ORDER BY`, `JOIN`.
- Usually a self-balancing **B-tree**: sorted data, log-time search/insert/delete.
- Indexes cost **memory** and **slower writes** (index must update too).
- For bulk loads, **disable indices, load, then rebuild**.

### Avoid Expensive Joins

- **Denormalize** where performance demands it.

### Partition Tables

- Put **hot spots** in a separate table to keep them in memory.

### Tune the Query Cache

- In some cases the **query cache** can hurt performance — measure.

## Indexes Deep Dive

- **B-tree:** great for ranges and ordered scans (default).
- **Hash index:** O(1) equality lookups, no range queries.
- **Composite index:** multi-column; **leftmost-prefix** rule applies.
- **Covering index:** query satisfied entirely from the index (no table lookup).
- **Clustered vs non-clustered:** clustered = table physically ordered by key (one per
  table); non-clustered = separate structure pointing to rows.

## Interview Talking Points

- Lead with **read replicas** for read scaling; call out **replication lag**.
- Use **federation** (by feature) before **sharding** (by rows) when possible.
- Choose a **shard key** that avoids hotspots; mention **consistent hashing** for rebalancing.
- Justify **denormalization** with the read:write ratio.
- Mention **indexes + slow query log** as first-line tuning.

## Further Exploration

- *Scalability, availability, stability patterns* (Jonas Bonér).
- *Scaling up to your first 10 million users* (AWS).
- Kleppmann — *DDIA*, Ch. 3 (Storage & Retrieval), Ch. 5–6 (Replication, Partitioning).
- Explore next: **2-phase commit**, **MVCC**, **B+ tree internals**, **consistent hashing**,
  **read replicas vs Vitess/Citus**.
