# 🔄 Process Synchronization
### *Operating System Concepts — Silberschatz, Galvin & Gagne*

> **"Cooperation between processes requires communication and synchronization — without it, chaos reigns."**

---

## 📋 Table of Contents

1. [Background & Motivation](#1-background--motivation)
2. [The Critical Section Problem](#2-the-critical-section-problem)
   - 2.1 [Requirements for a Valid Solution](#21-requirements-for-a-valid-solution)
   - 2.2 [Structure of a Process with Critical Section](#22-structure-of-a-process-with-critical-section)
3. [Peterson's Solution](#3-petersons-solution)
   - 3.1 [How It Works](#31-how-it-works)
   - 3.2 [Proof of Correctness](#32-proof-of-correctness)
   - 3.3 [Limitations](#33-limitations)
4. [Synchronization Hardware](#4-synchronization-hardware)
   - 4.1 [Memory Barriers](#41-memory-barriers)
   - 4.2 [Test-and-Set Instruction](#42-test-and-set-instruction)
   - 4.3 [Compare-and-Swap (CAS)](#43-compare-and-swap-cas)
5. [Mutex Locks](#5-mutex-locks)
   - 5.1 [Spinlocks vs Blocking Locks](#51-spinlocks-vs-blocking-locks)
6. [Semaphores](#6-semaphores)
   - 6.1 [Binary Semaphore](#61-binary-semaphore)
   - 6.2 [Counting Semaphore](#62-counting-semaphore)
   - 6.3 [Implementation](#63-implementation)
   - 6.4 [Common Pitfalls](#64-common-pitfalls)
7. [Classic Synchronization Problems](#7-classic-synchronization-problems)
   - 7.1 [Producer–Consumer (Bounded Buffer)](#71-producerconsumer-bounded-buffer)
   - 7.2 [Readers–Writers Problem](#72-readerswriters-problem)
   - 7.3 [Dining Philosophers Problem](#73-dining-philosophers-problem)
8. [Monitors](#8-monitors)
   - 8.1 [Condition Variables](#81-condition-variables)
   - 8.2 [Dining Philosophers with Monitors](#82-dining-philosophers-with-monitors)
9. [Deadlock & Starvation (Linkage)](#9-deadlock--starvation-linkage)
10. [Chapter Summary](#10-chapter-summary)
11. [Exam Tips & Memory Aids](#11-exam-tips--memory-aids)
12. [Further Reading & References](#12-further-reading--references)

---

## 1. Background & Motivation

### 🎯 Why Do We Need Process Synchronization?

In a multiprogramming/multithreading environment, **multiple processes/threads share data**. When they access and manipulate shared data **concurrently**, the integrity of that data may be compromised.

### 🔴 The Race Condition

> A **race condition** occurs when the outcome of execution depends on the **particular order** in which shared data is accessed.

#### Classic Example: The `counter` Variable

Imagine two processes sharing a variable `counter`, both trying to update it simultaneously:

```c
// Process P1            // Process P2
counter++;               counter--;
```

These single statements are **NOT atomic** — they compile to multiple machine instructions:

```
// counter++ expands to:       // counter-- expands to:
register1 = counter            register2 = counter
register1 = register1 + 1      register2 = register2 - 1
counter = register1            counter = register2
```

**Interleaved execution (race condition scenario):**

| Step | Process | Operation                  | counter value |
|------|---------|----------------------------|---------------|
| 1    | P1      | register1 = counter        | 5             |
| 2    | P1      | register1 = register1 + 1  | 5 (reg1 = 6)  |
| 3    | P2      | register2 = counter        | 5             |
| 4    | P2      | register2 = register2 - 1  | 5 (reg2 = 4)  |
| 5    | P1      | counter = register1        | 6             |
| 6    | P2      | counter = register2        | **4** ❌      |

**Expected result:** 5. **Actual result:** 4. This is the race condition.

> 💡 **Real-world analogy:** Two people simultaneously editing the same bank account — one deposits ₹500, another withdraws ₹200. Without synchronization, either change could be lost!

![Race Condition](images/race-condition.png)

---

## 2. The Critical Section Problem

### 📌 Definition

A **critical section** is a segment of code in which a process **accesses shared resources** (shared variables, files, databases). The critical section problem is to design a **protocol** so that processes can cooperate without conflict.

```
while (true) {
    /* --- ENTRY SECTION --- */
        // Request permission to enter CS
    
    /* === CRITICAL SECTION === */
        // Access shared resources here
    
    /* --- EXIT SECTION --- */
        // Signal that CS is done
    
    /* REMAINDER SECTION */
        // Rest of the process
}
```

![Critical Section Diagram](images/critical-section.png)

### 2.1 Requirements for a Valid Solution

Every valid solution to the Critical Section Problem **must satisfy all three conditions**:

| # | Property | Description |
|---|----------|-------------|
| 1 | **Mutual Exclusion** | Only **one** process can execute in the CS at a time |
| 2 | **Progress** | If no process is in the CS and some want to enter, **selection cannot be postponed indefinitely** — only non-remainder processes can participate in the decision |
| 3 | **Bounded Waiting** | A **limit must exist** on the number of times other processes enter the CS after a process has made a request — prevents **starvation** |

> 🧠 **Mnemonic:** **MPB** — **M**utual exclusion, **P**rogress, **B**ounded waiting  
> Think: "**M**y **P**rocess **B**elongs in the CS fairly."

### 2.2 Structure of a Process with Critical Section

```c
do {
    // Entry Section
    // ↓ Acquire lock / check flag

    /* CRITICAL SECTION */

    // Exit Section
    // ↓ Release lock / reset flag

    /* REMAINDER SECTION */

} while (true);
```

---

## 3. Peterson's Solution

> A **software-based** solution for the critical section problem for **two processes** (P0 and P1).

### Shared Variables

```c
int turn;          // Whose turn it is to enter the CS
bool flag[2];      // flag[i] = true means Pi WANTS to enter the CS
```

### 3.1 How It Works

```c
// Process Pi (where j = 1 - i, the other process)
do {
    flag[i] = true;       // "I want to enter"
    turn = j;             // "But you go first (be polite)"

    while (flag[j] && turn == j)
        ; // busy wait — spin until either Pj doesn't want in, or it's my turn

    /* === CRITICAL SECTION === */

    flag[i] = false;      // "I'm done, I no longer want to enter"

    /* REMAINDER SECTION */

} while (true);
```

> 💡 **Analogy:** Two people reaching a door simultaneously. Each says "You go first!" (sets turn to the other). The one who said it last waits. The first person enters.

![Peterson's Solution](images/petersons-solution.png)

### 3.2 Proof of Correctness

| Property | Proof |
|----------|-------|
| **Mutual Exclusion** | P0 enters CS only if `flag[1] == false` OR `turn == 0`. Since `turn` can't be both 0 and 1, both can't enter simultaneously. ✅ |
| **Progress** | If Pj is not in CS (`flag[j] = false`), Pi's while loop exits immediately. ✅ |
| **Bounded Waiting** | After Pi sets `turn = j`, Pj can enter at most once before Pi gets to enter. ✅ |

### 3.3 Limitations

- ❌ Works only for **two processes**
- ❌ Uses **busy waiting** (wastes CPU cycles)
- ❌ May **not work on modern hardware** with instruction reordering (requires memory barriers)

---

## 4. Synchronization Hardware

> Modern CPUs provide **atomic hardware instructions** to build synchronization primitives efficiently.

### 4.1 Memory Barriers

- Modern CPUs and compilers may **reorder instructions** for performance
- A **memory barrier (fence)** instruction forces all memory operations before the barrier to **complete before** any after it
- Required to make software solutions like Peterson's work on modern hardware

```c
// Memory barrier example (Linux-like)
smp_mb();   // full memory barrier
smp_rmb();  // read memory barrier
smp_wmb();  // write memory barrier
```

### 4.2 Test-and-Set Instruction

An **atomic** instruction that tests and modifies a memory word in a single step:

```c
// Hardware definition (atomic)
bool test_and_set(bool *target) {
    bool rv = *target;
    *target = true;     // always sets to true
    return rv;          // returns old value
}
```

**Using test_and_set for mutual exclusion:**

```c
bool lock = false;   // shared lock variable

// Process Pi
do {
    while (test_and_set(&lock))
        ; // spin (busy wait)

    /* === CRITICAL SECTION === */

    lock = false;    // release the lock

    /* REMAINDER SECTION */

} while (true);
```

> ⚠️ **Note:** This satisfies Mutual Exclusion and Progress, but **NOT Bounded Waiting** (starvation possible).

**Bounded Waiting with Test-and-Set:**

```c
// Uses a waiting[] array to ensure bounded waiting
bool waiting[n] = {false};
bool lock = false;

// Process Pi
do {
    waiting[i] = true;
    bool key = true;

    while (waiting[i] && key)
        key = test_and_set(&lock);

    waiting[i] = false;

    /* === CRITICAL SECTION === */

    // Find next waiting process (circular scan)
    j = (i + 1) % n;
    while ((j != i) && !waiting[j])
        j = (j + 1) % n;

    if (j == i)
        lock = false;       // no one waiting, free lock
    else
        waiting[j] = false; // hand off to Pj directly

    /* REMAINDER SECTION */
} while (true);
```

### 4.3 Compare-and-Swap (CAS)

Also called **compare-and-exchange**. Atomically: compares a value, and swaps only if equal.

```c
// Hardware definition (atomic)
int compare_and_swap(int *value, int expected, int new_value) {
    int temp = *value;
    if (*value == expected)
        *value = new_value;
    return temp;   // returns old value
}
```

**Using CAS for mutual exclusion:**

```c
int lock = 0;   // 0 = free, 1 = held

// Process Pi
do {
    while (compare_and_swap(&lock, 0, 1) != 0)
        ; // spin until lock acquired

    /* === CRITICAL SECTION === */

    lock = 0;    // release

    /* REMAINDER SECTION */

} while (true);
```

> 💡 **Real-world use:** CAS is the foundation of Java's `AtomicInteger`, C++'s `std::atomic`, and most lock-free data structures.

| Instruction | Returns | Sets to | Atomic? |
|-------------|---------|---------|---------|
| `test_and_set(target)` | Old value | Always `true` | ✅ |
| `compare_and_swap(val, expected, new)` | Old value | `new` if matches | ✅ |

---

## 5. Mutex Locks

> **Mutex** = **Mut**ual **Ex**clusion lock — the **simplest** synchronization tool.

The OS provides `acquire()` and `release()` operations which must be **atomic**.

```c
// Mutex lock structure (conceptual)
bool available;   // true = lock is free

void acquire() {
    while (!available)
        ; // busy wait (spinlock)
    available = false;
}

void release() {
    available = true;
}
```

**Usage Pattern:**

```c
mutex_lock lock;

// Process Pi
do {
    acquire(lock);          // enter CS

    /* === CRITICAL SECTION === */

    release(lock);          // exit CS

    /* REMAINDER SECTION */

} while (true);
```

### 5.1 Spinlocks vs Blocking Locks

| Feature | Spinlock (Busy Wait) | Blocking Lock |
|---------|---------------------|---------------|
| Waiting mechanism | Loop (spin) | Sleep/block |
| CPU usage while waiting | High | None (freed up) |
| Context switch overhead | None | Yes |
| Best for | **Short** CS, multicore | **Long** CS |
| Where used | OS kernels, low-level | User-space, long waits |

> 🧠 **Mnemonic:** "**Spin** for short, **Sleep** for long"

> ⚠️ **Busy waiting drawback:** A process continuously executes in its entry code. This wastes CPU cycles that could be used by other processes — called a **spinlock**.

---

## 6. Semaphores

> A **semaphore** is a more powerful synchronization tool — an integer variable accessed only through two atomic operations: **`wait()`** and **`signal()`** (also called **P** and **V** from Dutch).

```c
wait(S)   {           // P(S) — proberen (to test)
    while (S <= 0)
        ; // busy wait
    S--;
}

signal(S) {           // V(S) — verhogen (to increment)
    S++;
}
```

> 💡 **Origin of P & V:** Dutch words by Dijkstra — **P** = *proberen* (to test/try), **V** = *verhogen* (to increment/raise).

![Semaphore Working](images/semaphore-working.png)

### 6.1 Binary Semaphore

- Value is **0 or 1** only
- Equivalent to a **mutex lock**
- Used for **mutual exclusion**

```c
semaphore mutex = 1;   // initialized to 1 (free)

// Process Pi
do {
    wait(mutex);        // P(mutex) — lock

    /* === CRITICAL SECTION === */

    signal(mutex);      // V(mutex) — unlock

    /* REMAINDER */

} while (true);
```

### 6.2 Counting Semaphore

- Value ranges over an **unrestricted domain**
- Used to **control access** to a finite number of instances of a resource

```c
semaphore S = N;   // N = number of available resources

// Any Process Pi
wait(S);           // decrement — one resource acquired
    // use resource
signal(S);         // increment — resource released
```

> 💡 **Real-world analogy:** A parking lot with N spots. `wait()` = drive in (count--). `signal()` = drive out (count++). When count = 0, no spots left — wait!

### 6.3 Implementation

**Semaphore without busy waiting** uses a waiting queue:

```c
typedef struct {
    int value;
    struct process *list;   // waiting queue
} semaphore;

void wait(semaphore *S) {
    S->value--;
    if (S->value < 0) {
        // add this process to S->list
        block();    // suspend process
    }
}

void signal(semaphore *S) {
    S->value++;
    if (S->value <= 0) {
        // remove process P from S->list
        wakeup(P);  // resume P
    }
}
```

> **Note on negative values:** When using the blocking implementation, if `S->value = -N`, it means **N processes are waiting** in the queue.

| Semaphore Value | Meaning |
|----------------|---------|
| Positive (+N) | N resources available |
| Zero (0) | No resources available, no one waiting |
| Negative (-N) | N processes are waiting |

### 6.4 Common Pitfalls

| Mistake | Consequence |
|---------|-------------|
| `wait()` on same semaphore twice (no signal in between) | **Deadlock** |
| `signal()` before `wait()` | **Mutual exclusion violated** |
| Omitting `wait()` or `signal()` | Race condition or deadlock |
| Swapping `wait()` and `signal()` order | Multiple processes enter CS |

```c
// ❌ WRONG: causes deadlock
wait(S);
wait(S);   // blocks forever
signal(S);

// ❌ WRONG: mutual exclusion violated
signal(S);
/* CS */
wait(S);

// ✅ CORRECT
wait(S);
/* CS */
signal(S);
```

---

## 7. Classic Synchronization Problems

> These three problems are **benchmarks** for evaluating synchronization schemes. Know them cold for exams!

### 7.1 Producer–Consumer (Bounded Buffer)

#### Problem Statement

- A **producer** produces items and puts them in a **shared buffer**
- A **consumer** takes items from the buffer
- Buffer has **fixed size N** (bounded buffer)
- Producer must **wait** if buffer is full; consumer must **wait** if buffer is empty

![Producer-Consumer](images/producer-consumer.png)

#### Semaphore Solution

```c
semaphore mutex = 1;    // mutual exclusion for buffer access
semaphore empty = N;    // counts empty slots (initially N)
semaphore full  = 0;    // counts filled slots (initially 0)

// PRODUCER
do {
    // produce item in next_produced

    wait(empty);        // wait for empty slot
    wait(mutex);        // lock buffer

    // add next_produced to buffer

    signal(mutex);      // unlock buffer
    signal(full);       // signal that there's a new item

} while (true);

// CONSUMER
do {
    wait(full);         // wait for filled slot
    wait(mutex);        // lock buffer

    // remove item from buffer to next_consumed

    signal(mutex);      // unlock buffer
    signal(empty);      // signal that a slot is now empty

    // consume item in next_consumed

} while (true);
```

> ⚠️ **Critical order:** `wait(mutex)` must come **after** `wait(empty/full)`. Reversing causes **deadlock!**

**Why?** If producer does `wait(mutex)` first and buffer is full, it holds the mutex while waiting on `empty`. Consumer can't get mutex to signal — **deadlock!**

### 7.2 Readers–Writers Problem

#### Problem Statement

- **Readers** only read the shared data — multiple readers can read **simultaneously**
- **Writers** read AND write — require **exclusive access**
- Two variants:
  - **First Readers-Writers Problem:** No reader shall wait unless a writer already has permission (**readers priority** — writers may starve)
  - **Second Readers-Writers Problem:** Once a writer is ready, it performs as soon as possible (**writers priority** — readers may starve)

![Readers-Writers](images/readers-writers.png)

#### First Readers-Writers Solution (Readers Priority)

```c
semaphore rw_mutex = 1;   // exclusive access for writers (and first/last reader)
semaphore mutex   = 1;    // protect read_count
int read_count = 0;       // number of active readers

// WRITER
do {
    wait(rw_mutex);         // exclusive lock

    /* writing */

    signal(rw_mutex);       // release

} while (true);

// READER
do {
    wait(mutex);
    read_count++;
    if (read_count == 1)
        wait(rw_mutex);     // first reader locks out writers
    signal(mutex);

    /* reading */

    wait(mutex);
    read_count--;
    if (read_count == 0)
        signal(rw_mutex);   // last reader frees writers
    signal(mutex);

} while (true);
```

> 💡 **Key insight:** The first reader acquires `rw_mutex` (blocking writers). The last reader releases it. Readers in between just increment/decrement `read_count`.

| Condition | Behavior |
|-----------|----------|
| No writer, no reader | Anyone can proceed |
| Reader(s) reading | More readers can join; writers blocked |
| Writer writing | All readers and writers blocked |
| Writer waiting | New readers can still enter (in v1 — readers priority) |

### 7.3 Dining Philosophers Problem

#### Problem Statement

- **5 philosophers** sit at a round table
- Each has a **plate of spaghetti** and needs **2 forks** to eat
- There are exactly **5 forks**, one between each pair
- A philosopher alternates between **thinking** and **eating**
- Must pick up **both adjacent forks** to eat

> 💡 **Analogy:** Models resource allocation where processes need **multiple exclusive resources** simultaneously.

![Dining Philosophers](images/dining-philosophers.png)

#### Naive Solution (Has Deadlock)

```c
semaphore fork[5] = {1, 1, 1, 1, 1};   // all forks available

// Philosopher i
do {
    wait(fork[i]);              // pick left fork
    wait(fork[(i+1) % 5]);     // pick right fork

    /* eat */

    signal(fork[i]);            // put left fork
    signal(fork[(i+1) % 5]);   // put right fork

    /* think */

} while (true);
```

> ❌ **Deadlock!** If every philosopher picks up their left fork simultaneously — all are waiting for their right fork, and nobody can proceed.

#### Solutions to Avoid Deadlock

**Solution 1: Allow at most 4 philosophers at the table simultaneously**

```c
semaphore table = 4;   // only 4 can sit at a time

// Philosopher i
do {
    wait(table);                        // sit down (max 4)
    wait(fork[i]);
    wait(fork[(i+1) % 5]);

    /* eat */

    signal(fork[i]);
    signal(fork[(i+1) % 5]);
    signal(table);                      // get up

    /* think */

} while (true);
```

**Solution 2: Asymmetric solution — odd/even philosophers differ**

```c
// Even philosopher: left fork first, then right
// Odd philosopher:  right fork first, then left

// Philosopher i
do {
    if (i % 2 == 0) {
        wait(fork[i]);
        wait(fork[(i+1) % 5]);
    } else {
        wait(fork[(i+1) % 5]);
        wait(fork[i]);
    }

    /* eat */

    signal(fork[i]);
    signal(fork[(i+1) % 5]);

    /* think */

} while (true);
```

**Solution 3: Pick up both forks atomically (only if both available)**
→ Implemented elegantly with **Monitors** (see Section 8.2).

| Solution | Deadlock-free? | Starvation-free? |
|----------|----------------|-----------------|
| Naive | ❌ | ❌ |
| At most 4 at table | ✅ | ❌ (may still starve) |
| Asymmetric (odd/even) | ✅ | ❌ |
| Monitor-based (state machine) | ✅ | ✅ |

---

## 8. Monitors

> A **monitor** is a high-level synchronization construct that provides a **convenient and effective mechanism** for process synchronization. It's a **programming language construct** (not just OS-level).

### Key Properties

- Only **one process** can be active within the monitor at a time (mutual exclusion built-in)
- **No need** to code `wait()` / `signal()` on mutexes manually
- Internal: shared variables + procedures + initialization code

```
monitor monitor-name {
    // shared variable declarations

    procedure P1(...) { ... }
    procedure P2(...) { ... }
    // ...
    procedure Pn(...) { ... }

    // initialization code
    {  ...  }
}
```

![Monitor Structure](images/monitor-structure.png)

### 8.1 Condition Variables

Monitors use **condition variables** to allow processes to wait for certain conditions:

```c
condition x, y;

x.wait();    // process is suspended until another calls x.signal()
x.signal();  // resumes exactly ONE suspended process (or does nothing if none waiting)
```

> ⚠️ **Semaphore vs Monitor condition:**
> - `semaphore.signal()` always has an effect (increments value)
> - `condition.signal()` only wakes a waiting process; if none waiting, **it has no effect!**

#### Signal & Wait vs Signal & Continue

When process Q calls `x.signal()` and process P is waiting on `x`, two strategies:

| Strategy | Description |
|----------|-------------|
| **Signal and Wait** | Q waits until P leaves or waits again |
| **Signal and Continue** | Q continues; P resumes when Q leaves monitor |
| **Hoare semantics** | Signal and Wait — P immediately resumes |
| **Mesa semantics** | Signal and Continue — P may need to re-check condition |

> 💡 Most real implementations (Java, POSIX) use **Mesa semantics** — always use `while` loops, not `if`, when checking conditions!

```c
// ✅ CORRECT (Mesa semantics — while loop)
while (!condition)
    x.wait();

// ❌ RISKY (Hoare semantics only — if statement)
if (!condition)
    x.wait();
```

### 8.2 Dining Philosophers with Monitors

#### States for Each Philosopher

```c
// Each philosopher is in one of these states
enum { THINKING, HUNGRY, EATING } state[5];

condition self[5];   // philosopher i waits on self[i]
```

#### Monitor Implementation

```c
monitor DiningPhilosophers {
    enum { THINKING, HUNGRY, EATING } state[5];
    condition self[5];

    void pickup(int i) {
        state[i] = HUNGRY;
        test(i);                    // try to eat
        if (state[i] != EATING)
            self[i].wait();         // wait if can't eat
    }

    void putdown(int i) {
        state[i] = THINKING;
        test((i + 4) % 5);         // check if left neighbor can now eat
        test((i + 1) % 5);         // check if right neighbor can now eat
    }

    void test(int i) {
        // Eat only if both neighbors are NOT eating and I am HUNGRY
        if ((state[(i + 4) % 5] != EATING) &&
            (state[i] == HUNGRY) &&
            (state[(i + 1) % 5] != EATING)) {
            state[i] = EATING;
            self[i].signal();       // notify philosopher i
        }
    }

    // initialization
    { for (int i = 0; i < 5; i++) state[i] = THINKING; }
}

// Philosopher i calls:
DiningPhilosophers.pickup(i);
    /* eat */
DiningPhilosophers.putdown(i);
```

> ✅ This solution is **deadlock-free** and satisfies all requirements!  
> ⚠️ **Starvation is still possible** (philosopher might never get both forks if neighbors keep eating).

---

## 9. Deadlock & Starvation (Linkage)

> Synchronization mechanisms, if used incorrectly, can lead to **deadlock** and **starvation**.

### Deadlock

> A set of processes is in a **deadlock** state when **every process in the set is waiting for an event** that can only be caused by another process in the set.

**Example with semaphores:**

```c
// P0                    // P1
wait(S);                 wait(Q);
wait(Q);                 wait(S);
/* ... */                /* ... */
signal(S);               signal(Q);
signal(Q);               signal(S);
```

If P0 executes `wait(S)` and P1 executes `wait(Q)` simultaneously:
- P0 waits for Q (held by P1)
- P1 waits for S (held by P0)
- **Deadlock!**

### Starvation (Indefinite Blocking)

> A process **never gets removed from a semaphore queue** in which it is suspended.

- Can happen with **LIFO (stack-based)** semaphore queues
- **Prevention:** Use FIFO queues in semaphore implementation (bounded waiting)

### Priority Inversion

> A **lower-priority process** holds a lock that a **higher-priority process** needs — the high-priority process is effectively blocked by the low-priority one.

**Classic case:** Low → Medium → High priority processes.
- Solution: **Priority Inheritance Protocol** — temporarily raise low-priority process's priority to that of the waiting high-priority process.

| Problem | Cause | Impact |
|---------|-------|--------|
| Deadlock | Circular wait on resources | All involved processes stuck |
| Starvation | Unfair scheduling / LIFO queues | One process never proceeds |
| Priority Inversion | Lock held by low-priority process | High-priority process delayed |

---

## 10. Chapter Summary

### 🔑 Key Concepts (Exam-focused Bullets)

#### Critical Section
- [ ] Shared data + concurrent access = race condition
- [ ] CS problem requires: **Mutual Exclusion**, **Progress**, **Bounded Waiting**
- [ ] Four sections of a process: Entry → CS → Exit → Remainder

#### Peterson's Solution
- [ ] Software solution for **2 processes** only
- [ ] Uses `turn` (whose turn) + `flag[]` (intention to enter)
- [ ] Satisfies all 3 CS requirements
- [ ] **Busy waits** and may fail on modern hardware without memory barriers

#### Hardware Synchronization
- [ ] `test_and_set` & `compare_and_swap` are **atomic** hardware instructions
- [ ] Memory barriers prevent instruction reordering
- [ ] CAS is the basis of lock-free programming

#### Mutex Locks
- [ ] Simplest OS tool — `acquire()` + `release()`
- [ ] Spinlock = busy wait; fine for short CS on multicore
- [ ] Not suitable for long critical sections (wastes CPU)

#### Semaphores
- [ ] **Binary** (0 or 1) ≡ mutex; **Counting** (0 to N) for resource pools
- [ ] Operations: `wait()` (P, decrement) and `signal()` (V, increment)
- [ ] Blocking implementation uses queues — avoids busy waiting
- [ ] Negative value = number of waiting processes

#### Classic Problems

| Problem | Key Semaphores | Key Issue |
|---------|---------------|-----------|
| Producer-Consumer | `mutex`, `empty`, `full` | Order of waits matters |
| Readers-Writers | `rw_mutex`, `mutex`, `read_count` | Readers share, writers exclusive |
| Dining Philosophers | `fork[5]` | Deadlock if all pick left fork |

#### Monitors
- [ ] High-level construct — mutual exclusion is **implicit**
- [ ] Uses **condition variables** with `.wait()` and `.signal()`
- [ ] Use `while` loops (not `if`) with condition variables (Mesa semantics)
- [ ] Dining Philosophers monitor uses **state machine** (THINKING/HUNGRY/EATING)

#### Deadlock & Starvation
- [ ] Improper semaphore use → deadlock
- [ ] LIFO semaphore queues → starvation
- [ ] Priority inversion → priority inheritance protocol

---

## 11. Exam Tips & Memory Aids

### 🧠 Mnemonics

| Topic | Mnemonic |
|-------|---------|
| CS Requirements | **MPB** — Mutual exclusion, Progress, Bounded waiting |
| Semaphore P/V | **P** = *Proberen* (try/decrement), **V** = *Verhogen* (raise/increment) |
| Producer-Consumer wait order | "**Empty before Mutex**" for producer; "**Full before Mutex**" for consumer |
| Peterson's shared vars | "**TF**" — Turn + Flag[] |

### ⚡ Quick Comparison Table

| Tool | Mutual Excl. | Counting | Language Level | Busy Wait |
|------|-------------|---------|----------------|-----------|
| Peterson's | ✅ (2 proc) | ❌ | Software | ✅ |
| Test-and-Set | ✅ | ❌ | Hardware | ✅ |
| Mutex Lock | ✅ | ❌ | OS | Optional |
| Binary Semaphore | ✅ | ❌ | OS | Optional |
| Counting Semaphore | ✅ | ✅ | OS | Optional |
| Monitor | ✅ | ✅ (via CV) | Language | ❌ |

### 🎯 Common Exam Traps

1. **Semaphore wait order** — always acquire resource semaphore before mutex semaphore
2. **Peterson's `turn` variable** — a process sets `turn` to the **other** process (politeness)
3. **Condition variable `signal()`** — if no one is waiting, the signal is **lost** (unlike semaphore)
4. **Monitor** — only one process active inside monitor at any time (mutual exclusion is automatic)
5. **Dining Philosophers naive solution** — ALL picking left fork simultaneously causes deadlock
6. **Negative semaphore value** — means that many processes are waiting, NOT that value wraps around
7. **CAS vs TAS** — CAS takes expected value as param; TAS always sets to true

### 📊 Mind Map: Synchronization Tools

```
SYNCHRONIZATION
│
├── SOFTWARE
│   └── Peterson's Solution (2 processes, turn + flag)
│
├── HARDWARE
│   ├── Memory Barriers (prevent reordering)
│   ├── Test-and-Set (atomic read + set-to-true)
│   └── Compare-and-Swap (atomic compare + conditional swap)
│
├── OS-LEVEL
│   ├── Mutex Lock (binary, simple)
│   └── Semaphore
│       ├── Binary (0/1) ← acts like mutex
│       └── Counting (0..N) ← resource pools
│
└── LANGUAGE-LEVEL
    └── Monitor
        ├── Implicit mutual exclusion
        └── Condition Variables (wait / signal)
```

---

## 12. Further Reading & References

### 📖 Official Textbook
- **Operating System Concepts** (10th Edition) — Silberschatz, Galvin, Gagne
  - Chapter 6: Synchronization Tools
  - Chapter 7: Synchronization Examples
  - Appendix A: Influential OS (for historical semaphore context)

### 🌐 Online Resources

| Resource | Link | Best For |
|----------|------|---------|
| GeeksForGeeks OS | https://www.geeksforgeeks.org/process-synchronization-set-1/ | Quick revision |
| Wikipedia — Semaphore | https://en.wikipedia.org/wiki/Semaphore_(programming) | History & variants |
| Wikipedia — Monitor | https://en.wikipedia.org/wiki/Monitor_(synchronization) | Deep dive |
| MIT OpenCourseWare — 6.004 | https://ocw.mit.edu | Concurrency theory |
| Carnegie Mellon CS 15-410 | https://www.cs.cmu.edu/~410/ | Advanced OS |

### 🎥 Recommended YouTube Lectures

| Channel | Topic | Notes |
|---------|-------|-------|
| **Gate Smashers** | Process Synchronization playlist | Excellent for GATE prep |
| **Neso Academy** | OS Synchronization series | Clear, step-by-step |
| **Jenny's Lectures CS/IT** | Critical Section & Semaphores | Beginner-friendly |
| **MIT OpenCourseWare** | Concurrent programming lectures | University-level depth |
| **Abdul Bari** | Operating Systems | Comprehensive coverage |

### 📄 University Lecture Notes
- **Stanford CS140** — Operating Systems (http://cs140.stanford.edu)
- **Berkeley CS162** — OS and System Programming (https://cs162.org)
- **NPTEL — Operating Systems** — IIT lectures (https://nptel.ac.in)

### 💻 Practice & Simulation
- **OS-161** (Harvard/Boston University) — hands-on OS implementation
- **Pintos** — educational OS for synchronization experiments
- **Java `java.util.concurrent`** — real-world monitor/semaphore implementations

---

*Notes compiled from: Operating System Concepts, 10th Edition — Silberschatz, Galvin & Gagne*  
*Last updated: March 2026*

---
> 💡 **Pro Tip for Exams:** Draw diagrams! A timeline showing interleaved execution of two processes, or the state transitions of the Dining Philosophers, is worth more than a paragraph of text when explaining these concepts.
