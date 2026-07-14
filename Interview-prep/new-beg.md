# Career Growth Plan: C++ Engineer (8 YoE)

You're actually in a very good position already.

- 8 years experience
- C++ engineer
- Bangalore
- 26 LPA fixed
- Feeling bored with language study but still interested in growth

This is a very common situation around the 7-10 year experience mark. The biggest mistake engineers make now is trying to become a better C++ syntax expert. The market pays much more for engineers who solve bigger problems, not for engineers who know every corner of the standard.

---

## 1. How to Increase CTC from 26 LPA to 40+ LPA

**The good news:** 40 LPA is not a difficult target for an 8-year engineer in Bangalore. The challenge is positioning yourself correctly.

### What companies pay 40+ LPA for 8 YoE?

Examples:

- Microsoft
- Google
- Amazon
- Atlassian
- Uber
- Goldman Sachs
- Salesforce
- Adobe
- Qualcomm
- Nvidia
- Samsung R&D
- Rubrik
- Nutanix
- Arista
- Cisco
- ServiceNow
- Intuit

Even many tier-2 product companies pay:

- 35-50 fixed
- plus joining bonus
- plus RSUs

### What skills are actually valued?

**Not:**

- ❌ C++20 modules details
- ❌ Obscure template tricks
- ❌ Every STL implementation detail

**Instead:**

- ✅ System Design
- ✅ Distributed Systems
- ✅ Concurrency
- ✅ Performance Engineering
- ✅ Networking
- ✅ Linux Internals
- ✅ Multithreading
- ✅ Debugging complex production issues
- ✅ Architecture ownership

### My recommendation

Split your preparation into:

#### 40% DSA

Needed to clear interviews.

Target:

- Leetcode 250-300 quality problems
- Medium + Hard

Focus:

- Graphs
- DP
- Trees
- Sliding Window
- Heaps
- Binary Search

#### 40% System Design

This is where senior engineers win.

Study:

- Load balancing
- Caching
- Kafka
- Consistency
- Replication
- Sharding
- Scalability

Resources:

- System Design Interview (Alex Xu)
- Designing Data Intensive Applications

#### 20% Advanced C++

Study only interview-relevant topics:

- Move semantics
- Smart pointers
- Thread library
- Atomics
- Memory model
- Lock-free basics
- Templates

### Expected timeline

If you consistently prepare:

- 6 months → 35-40 LPA achievable
- 9-12 months → 40-55 LPA realistic

---

## 2. Bored with Learning C++ from Books? That's Normal.

Let me tell you something: many senior engineers stop learning C++ because they are learning it incorrectly.

### Bad approach

Read:

- Effective Modern C++
- C++20 standard articles
- cppreference pages

Then forget everything. This feels like studying for an exam.

### Better approach

Learn through building.

Example — instead of reading about:

- `thread`
- `mutex`
- `condition_variable`

Build a **Thread Pool**:

```cpp
class ThreadPool {};
```

While building you'll naturally learn:

- threads
- synchronization
- RAII
- futures
- move semantics

and remember them forever.

### Another method

Read open-source production code.

Examples:

- Redis
- ClickHouse
- RocksDB
- gRPC
- Folly
- LLVM

You will learn far more from 1000 lines of production code than from 10 chapters of a book.

### Build a reputation score

Create a LinkedIn series: **"C++ Deep Dive #1"**

Once a week:

- Small article
- One concept learned
- One performance trick

Now learning has a public outcome. Motivation increases dramatically.

---

## 3. Personal Projects You Should Build

**Don't build:**

- ❌ Calculator
- ❌ To-do app
- ❌ Library management

These don't help a senior C++ engineer. Build projects that demonstrate systems expertise.

### Project 1: Thread Pool

- **Difficulty:** Easy-Medium
- **Timeline:** 2 weeks

**Phase 1**

```cpp
submit(Task);
```

Worker threads consume tasks.

**Phase 2** — Return futures.

```cpp
auto result = pool.submit(fn);
```

**Phase 3** — Dynamic thread count.

**Things learned:**

- Threads
- Mutexes
- Condition variables
- Futures
- Move semantics

### Project 2: In-Memory Key Value Store

- **Difficulty:** Medium
- **Timeline:** 3-4 weeks

Implement:

```text
SET key value
GET key
DEL key
```

Then add:

- TTL
- Persistence
- Snapshotting

Inspired by Redis.

**Things learned:**

- Hash tables
- Storage design
- Background threads
- Performance optimization

### Project 3: Mini Linux Shell

- **Difficulty:** Medium
- **Timeline:** 2 weeks

Implement:

```shell
ls
pwd
cd
```

Then:

```shell
cat file | grep text
```

**Learn:**

- Fork
- Exec
- Pipes
- Signals

Huge interview value.

### Project 4: HTTP Server

- **Difficulty:** Medium-Hard
- **Timeline:** 4 weeks

Build:

```text
GET /users
POST /users
```

Then:

- Thread pool
- Logging
- Metrics

**Learn:**

- Sockets
- TCP
- Networking
- Concurrency

### Project 5: Distributed Cache

- **Difficulty:** Hard
- **Timeline:** 6-8 weeks

Build:

- Multiple nodes
- Replication
- Leader election
- Hash partitioning

This project alone can become a talking point in senior interviews.

---

## Recommended 12-Month Roadmap

| Months | Focus |
| ------ | ----- |
| 1-2 | Leetcode, Thread Pool, Modern C++ refresh |
| 3-4 | System Design, Mini Redis |
| 5-6 | Networking, HTTP Server |
| 7-8 | Linux Internals, Shell Project |
| 9-10 | Distributed Cache |
| 11-12 | Resume polishing, Mock interviews, Product company applications |

---

## If I Were in Your Position

At 8 YoE and 26 LPA, I would focus on becoming a **systems engineer**, not a C++ language expert.

My priority order would be:

1. DSA
2. System Design
3. Linux + Networking
4. Concurrency
5. Build 3 production-quality projects
6. Interview aggressively

That path is much more likely to take you from 26 LPA → 40-50+ LPA than spending another year mastering obscure C++ language features.