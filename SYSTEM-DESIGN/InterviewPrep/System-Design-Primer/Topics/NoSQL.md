# NoSQL Databases

> **Deep dive** extracted from `Overview.md`. NoSQL stores represent data as **key-value**,
> **document**, **wide-column**, or **graph** models. Data is denormalized; joins typically
> happen in application code; most favor **eventual consistency** over ACID.

---

## Table of Contents

1. [What NoSQL Is](#what-nosql-is)
2. [BASE vs ACID](#base-vs-acid)
3. [Key-Value Store](#key-value-store)
4. [Document Store](#document-store)
5. [Wide Column Store](#wide-column-store)
6. [Graph Database](#graph-database)
7. [The Four Models Compared](#the-four-models-compared)
8. [SQL or NoSQL?](#sql-or-nosql)
9. [Interview Talking Points](#interview-talking-points)
10. [Further Exploration](#further-exploration)

---

## What NoSQL Is

**NoSQL** = a family of non-relational data stores. Data is **denormalized**, joins are
done in application code, and most stores **lack true ACID transactions**, favoring
**eventual consistency**. They trade relational features for scalability and flexible schemas.

## BASE vs ACID

**BASE** describes NoSQL properties; vs CAP it chooses **availability over consistency**:

- **Basically Available** — the system guarantees availability.
- **Soft state** — state may change over time, even without input.
- **Eventual consistency** — becomes consistent over time, absent new input.

| | ACID (SQL) | BASE (NoSQL) |
|--|-----------|--------------|
| Consistency | Strong/immediate | Eventual |
| Availability | Lower under partition | Higher |
| Schema | Rigid | Flexible |
| Use | Correctness-critical | Scale/availability-critical |

## Key-Value Store

**Abstraction:** a hash table.

- **O(1)** reads/writes; often memory- or SSD-backed.
- Can keep keys in **lexicographic order** → efficient key-range scans.
- Can store **metadata** alongside a value.
- High performance, simple model; complexity is pushed to the **application layer** (limited
  operation set). Forms the **basis** for document stores and some graph DBs.
- **Examples:** Redis, Memcached, DynamoDB, Riak.
- **Use:** caches, session stores, rapidly-changing simple data.

## Document Store

**Abstraction:** key-value store with **documents** (XML/JSON/binary) as values.

- A document holds **all info for an object**; APIs/query languages query the document's
  **internal structure**.
- Organized by **collections, tags, metadata, or directories**; documents in a collection
  may have **different fields**.
- Some (MongoDB, CouchDB) offer **SQL-like** querying; DynamoDB supports key-value + documents.
- High flexibility; good for **occasionally changing** data.
- **Examples:** MongoDB, CouchDB, DynamoDB, Elasticsearch.

## Wide Column Store

**Abstraction:** nested map → `ColumnFamily<RowKey, Columns<ColKey, Value, Timestamp>>`.

- Basic unit = a **column** (name/value pair). Columns group into **column families**
  (≈ a SQL table); **super column families** group those.
- Access columns via a **row key**; columns sharing a row key form a **row**. Each value
  carries a **timestamp** for versioning/conflict resolution.
- Google **Bigtable** was the first; influenced **HBase** (Hadoop) and **Cassandra**
  (Facebook). Keys kept in **lexicographic order** → efficient range retrieval.
- **High availability + scalability**; used for **very large datasets**.

## Graph Database

**Abstraction:** a graph.

- Each **node** = a record; each **arc/edge** = a relationship between two nodes.
- Optimized for **complex relationships** (many foreign keys / many-to-many), e.g. social
  networks.
- High performance for relationship-heavy models; relatively **new**, fewer tools/resources;
  many are accessed via **REST APIs**.
- **Examples:** Neo4j, FlockDB, JanusGraph, Amazon Neptune.

## The Four Models Compared

| Model | Abstraction | Strengths | Examples | Typical Use |
|-------|-------------|-----------|----------|-------------|
| Key-Value | Hash table | Fastest, simplest | Redis, DynamoDB | Cache, sessions |
| Document | KV w/ documents | Flexible schema, rich queries | MongoDB, CouchDB | Catalogs, content |
| Wide-Column | Nested map | Huge scale, write-heavy | Cassandra, HBase | Time-series, logs, IoT |
| Graph | Graph | Relationship traversal | Neo4j, Neptune | Social, fraud, recommendations |

## SQL or NoSQL?

**Reasons for SQL:**
- Structured data; strict schema; relational data.
- Need for **complex joins**; **transactions**.
- Clear scaling patterns; mature ecosystem; fast **index lookups**.

**Reasons for NoSQL:**
- Semi-structured data; **dynamic/flexible** schema; non-relational data.
- No need for complex joins; store **TB–PB** of data.
- **Very data-intensive** workload; very high **IOPS** throughput.

**Sample data well-suited to NoSQL:**
- Rapid ingest of **clickstream/log** data.
- **Leaderboard / scoring** data.
- **Temporary** data (e.g., shopping cart).
- Frequently accessed **'hot'** tables.
- **Metadata / lookup** tables.

> 🔑 It's not either/or — **polyglot persistence** uses SQL and NoSQL together, each where
> it fits.

## Interview Talking Points

- Match the **access pattern** to the model (KV for cache, wide-column for time-series, graph for relationships).
- Mention **BASE/eventual consistency** and tunable consistency (e.g., Cassandra quorums).
- Justify **denormalized data modeling** ("model around queries, not entities").
- Embrace **polyglot persistence** instead of forcing one store.

## Further Exploration

- Amazon **Dynamo** paper; Google **Bigtable** paper.
- *NoSQL databases: a survey and decision guidance* (Baqend).
- Kleppmann — *DDIA*, Ch. 2 (Data Models) & Ch. 3 (Storage).
- Explore next: **LSM-trees vs B-trees**, **consistent hashing**, **CRDTs**,
  **secondary indexes in NoSQL**, **time-series databases**.
