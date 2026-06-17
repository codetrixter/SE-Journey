# Caching

> **Deep dive** extracted from `Overview.md`. Caching improves page-load times and reduces
> load on servers and databases by serving previously-computed results.

---

## Table of Contents

1. [Why Cache](#why-cache)
2. [Where to Cache (Cache Levels)](#where-to-cache-cache-levels)
3. [What to Cache (Granularity)](#what-to-cache-granularity)
4. [Caching at the Database Query Level](#caching-at-the-database-query-level)
5. [Caching at the Object Level](#caching-at-the-object-level)
6. [Cache Update Strategies](#cache-update-strategies)
   - [Cache-Aside](#cache-aside-lazy-loading)
   - [Write-Through](#write-through)
   - [Write-Behind](#write-behind-write-back)
   - [Refresh-Ahead](#refresh-ahead)
7. [Eviction Policies](#eviction-policies)
8. [Cache Invalidation & Hard Problems](#cache-invalidation--hard-problems)
9. [Disadvantages](#disadvantages)
10. [Interview Talking Points](#interview-talking-points)
11. [Further Exploration](#further-exploration)

---

## Why Cache

A cache stores the result of expensive work (a DB query, computation, render) so future
requests are served faster. Databases like **uniform** read/write distribution; popular
("hot") items skew it and cause bottlenecks. A cache in front **absorbs uneven loads and
traffic spikes**.

## Where to Cache (Cache Levels)

| Level | Description |
|-------|-------------|
| **Client caching** | In the OS or browser (HTTP cache headers, local storage) |
| **CDN caching** | CDNs are themselves a cache for static/dynamic content (see `CDN.md`) |
| **Web server caching** | Reverse proxies (e.g., Varnish) serve static & dynamic content; web servers cache responses without hitting app servers |
| **Database caching** | The DB's built-in cache (buffer pool, etc.) — tune for your workload |
| **Application caching** | In-memory stores (Memcached, Redis) between app and data store |

**Application cache notes:**
- Data lives in **RAM** → far faster than disk-based DBs.
- RAM is limited → use eviction (e.g., **LRU**) to drop **cold** entries, keep **hot** ones.
- **Redis** extras: **persistence** option; built-in data structures (**sorted sets**, lists).
- Avoid **file-based caching** — it complicates cloning and auto-scaling.

## What to Cache (Granularity)

Two broad categories — **database queries** and **objects**:

- Row level
- Query level
- Fully-formed **serializable objects**
- Fully-rendered **HTML**

## Caching at the Database Query Level

Hash the **query** as the key, store its result.

- ❌ **Expiration is hard:** difficult to delete a cached result for complex queries.
- ❌ If one cell changes, you must delete **every cached query** that might include it.

## Caching at the Object Level

Treat data as **objects** (like your app code). Assemble the dataset from the DB into a
class instance / data structure and cache that.

- Remove the object when its **underlying data changes**.
- Enables **asynchronous processing**: workers assemble objects from the latest cache.

**Good things to cache:** user sessions, fully-rendered pages, activity streams, user-graph data.

## Cache Update Strategies

Because cache capacity is limited, choose how/when it's updated.

### Cache-Aside (Lazy Loading)

The **application** manages the cache; the cache doesn't talk to storage.

1. Look in cache → **miss**.
2. Load from DB.
3. Write into cache.
4. Return.

```python
def get_user(self, user_id):
    user = cache.get("user.{0}", user_id)
    if user is None:
        user = db.query("SELECT * FROM users WHERE user_id = {0}", user_id)
        if user is not None:
            key = "user.{0}".format(user_id)
            cache.set(key, json.dumps(user))
    return user
```

- ✅ Only requested data is cached (no waste); resilient to cache failure.
- ❌ Each miss = **3 trips** (noticeable delay); data can go **stale** (mitigate with TTL or
  write-through); a new/empty node → higher latency until warmed.
- **Memcached** is typically used this way.

### Write-Through

The app treats the **cache as the system of record**; the cache synchronously writes to the DB.

1. App adds/updates entry in **cache**.
2. Cache **synchronously** writes to the data store.
3. Return.

```python
set_user(12345, {"foo": "bar"})

def set_user(user_id, values):
    user = db.query("UPDATE Users WHERE id = {0}", user_id, values)
    cache.set(user_id, user)
```

- ✅ Cache never stale; subsequent reads of just-written data are fast.
- ❌ Slower writes (extra hop); a new node won't have an entry until it's **updated in the
  DB** (pair with cache-aside); much written data may **never be read** (mitigate with TTL).

### Write-Behind (Write-Back)

1. Add/update entry in **cache**.
2. **Asynchronously** write to the data store → better write performance.

- ✅ Fast writes; can batch/coalesce writes.
- ❌ **Data loss** risk if cache dies before flushing; more complex than cache-aside/write-through.

### Refresh-Ahead

Cache **proactively refreshes** recently-accessed entries **before** they expire.

- ✅ Lower latency **if** the cache predicts needed items well.
- ❌ **Mispredictions** waste resources and can perform worse than no refresh-ahead.

## Eviction Policies

| Policy | Evicts |
|--------|--------|
| **LRU** | Least Recently Used (most common) |
| **LFU** | Least Frequently Used |
| **FIFO** | Oldest inserted |
| **TTL** | Entries past their time-to-live |
| **Random** | A random entry |

## Cache Invalidation & Hard Problems

> "There are only two hard things in CS: cache invalidation and naming things." — Phil Karlton

- **TTL** — simple but allows bounded staleness.
- **Write-through / write-behind** — keep cache and DB aligned.
- **Explicit invalidation** — delete keys on data change (hard for derived/complex data).
- **Thundering herd / cache stampede** — many misses hit the DB at once when a hot key
  expires. Mitigate with **request coalescing, locks, jittered TTLs, early recompute**.
- **Hot keys** — a single popular key overloads one node; mitigate with replication/sharding
  of the key or local in-process caches.

## Disadvantages

- Must maintain **consistency** between cache and source of truth (invalidation).
- **Cache invalidation is hard**; adds complexity around *when* to update.
- App changes required (introduce Redis/Memcached, client libraries).

## Interview Talking Points

- Default to **cache-aside + TTL**; reach for write-through when staleness is unacceptable.
- Name the **eviction policy** (usually LRU) and why.
- Proactively address **stampede/hot-key** problems — shows senior-level depth.
- Distinguish **query-level vs object-level** caching and prefer object-level for complex data.

## Further Exploration

- *A hitchhiker's guide to caching patterns* (Hazelcast).
- *Scalable system design patterns* (horicky).
- AWS ElastiCache caching strategies.
- Explore next: **consistent hashing for cache clusters**, **Redis data structures &
  persistence (RDB/AOF)**, **CDN + HTTP caching headers**, **bloom filters for cache lookups**.
