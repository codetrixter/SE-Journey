# Asynchronism

> **Deep dive** extracted from `Overview.md`. Asynchronous workflows reduce request times
> for expensive operations and let you do time-consuming work ahead of time.

---

## Table of Contents

1. [Why Asynchronism](#why-asynchronism)
2. [Message Queues](#message-queues)
3. [Task Queues](#task-queues)
4. [Back Pressure](#back-pressure)
5. [Message Brokers Compared](#message-brokers-compared)
6. [Delivery Guarantees](#delivery-guarantees)
7. [Queue vs Pub/Sub vs Event Streaming](#queue-vs-pubsub-vs-event-streaming)
8. [Common Pitfalls](#common-pitfalls)
9. [Disadvantages](#disadvantages)
10. [Interview Talking Points](#interview-talking-points)
11. [Further Exploration](#further-exploration)

---

## Why Asynchronism

Asynchronous workflows **reduce request latency** for expensive operations that would
otherwise run inline, and allow **doing work in advance** (e.g., periodic aggregation).
The user isn't blocked while heavy work happens in the background.

```
Client ─► API (enqueue job, return fast) ─► Queue ─► Worker(s) ─► Data store / notify
```

## Message Queues

A message queue **receives, holds, and delivers** messages. Workflow for a too-slow-inline
operation:

1. App **publishes a job** to the queue, tells the user the **status**.
2. A **worker** picks up the job, processes it, signals **completion**.

The user isn't blocked; the client may **optimistically** show the task as done. *Example:*
a tweet is instantly shown on your timeline, but delivery to all followers happens
asynchronously.

- **Redis** — usable as a simple broker, but **messages can be lost**.
- **RabbitMQ** — popular; you adopt **AMQP** and manage your own nodes.
- **Amazon SQS** — hosted; can have **higher latency** and possible **double delivery**.

## Task Queues

A task queue **receives tasks + data, runs them, delivers results**. Supports **scheduling**
and **computationally-intensive** background jobs.

- **Celery** — supports scheduling; primarily **Python**.

## Back Pressure

If queues grow faster than they drain, the queue can exceed memory → cache misses, disk
reads, slower performance. **Back pressure** limits queue size to keep throughput and
response times healthy:

- When the queue is full, clients get a **server busy / HTTP 503** → retry later.
- Clients should retry with **exponential backoff (+ jitter)**.

> Back pressure protects the system from collapsing under overload by **shedding load**
> gracefully rather than failing catastrophically.

## Message Brokers Compared

| Broker | Model | Strengths | Watch-outs |
|--------|-------|-----------|-----------|
| **RabbitMQ** | Queue (AMQP) | Routing, reliability, mature | Self-managed, throughput ceiling |
| **Amazon SQS** | Queue (hosted) | Zero ops, scalable | At-least-once, no ordering (std) |
| **Apache Kafka** | Log / streaming | Huge throughput, replay, retention | More ops, not a task queue |
| **Redis (Streams/Lists)** | In-memory | Simple, fast | Durability/loss risk |
| **Celery** | Task queue | Scheduling, Python | Needs a broker (Redis/RabbitMQ) |

## Delivery Guarantees

| Guarantee | Meaning | Cost |
|-----------|---------|------|
| **At-most-once** | May drop, never duplicates | Simple, lossy |
| **At-least-once** | Never drops, may duplicate | Needs **idempotent** consumers |
| **Exactly-once** | No loss, no dup | Hardest (dedup/transactions) |

> Most systems are **at-least-once** → make consumers **idempotent** (safe to reprocess).

## Queue vs Pub/Sub vs Event Streaming

- **Queue (point-to-point):** each message consumed by **one** worker (work distribution).
- **Pub/Sub:** each message delivered to **all** subscribers (fan-out, decoupling).
- **Event streaming (Kafka):** durable, **replayable log**; many consumers read at their own
  offset; supports event sourcing and analytics.

## Common Pitfalls

- **Poison messages** → use a **dead-letter queue (DLQ)** after N failed retries.
- **Ordering** → most queues don't guarantee global order (use partitions/keys if needed).
- **Duplicate processing** → idempotency keys.
- **Visibility timeout** misconfig → duplicate or stuck messages.

## Disadvantages

- Inexpensive calculations and **real-time** workflows may be better **synchronous** —
  queues add **delays and complexity**.

## Interview Talking Points

- Introduce a queue to **decouple** producers from consumers and **smooth spikes**.
- Always mention **idempotent consumers** + **DLQ** for at-least-once systems.
- Use **back pressure + 503 + backoff** to handle overload gracefully.
- Distinguish **task queue (Celery)** vs **event log (Kafka)** vs **message queue (SQS/RabbitMQ)**.

## Further Exploration

- *Apply back pressure when overloaded* (mechanical-sympathy).
- **Little's Law** (queue length ↔ arrival rate × wait time).
- Kafka docs; *Designing Event-Driven Systems* (Stopford).
- Explore next: **event sourcing**, **CQRS**, **saga pattern**, **outbox pattern**,
  **stream processing (Kafka Streams/Flink)**.
