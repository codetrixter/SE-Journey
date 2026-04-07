# Operating Systems Concepts — Mastery Scope for 10+ Years Experience

---

## 📊 Master Progress Tracker

| Section | Must Know Done | Should Know Done | Nice to Have Done | Last Reviewed | Notes |
|---------------------------------|----------------|------------------|-------------------|---------------|-------|
| Process Management | | | | | |
| Threads & Concurrency | | | | | |
| Synchronization & Deadlocks | | | | | |
| Memory Management | | | | | |
| File Systems | | | | | |
| I/O & Device Management | | | | | |
| Inter-Process Communication | | | | | |
| Process Scheduling (Advanced) | | | | | |
| Security & Protection | | | | | |
| Containers & Virtualization | | | | | |
| System Calls & Kernel Interface | | | | | |
| Performance & Observability | | | | | |
| Boot Process & Initialization | | | | | |

---

## Table of Contents

1. [Process Management](#1-process-management)
2. [Threads & Concurrency](#2-threads--concurrency)
3. [Synchronization & Deadlocks](#3-synchronization--deadlocks)
4. [Memory Management](#4-memory-management)
5. [File Systems](#5-file-systems)
6. [I/O & Device Management](#6-io--device-management)
7. [Inter-Process Communication (IPC)](#7-inter-process-communication-ipc)
8. [Process Scheduling (Advanced)](#8-process-scheduling-advanced)
9. [Security & Protection](#9-security--protection)
10. [Containers & Virtualization](#10-containers--virtualization)
11. [System Calls & Kernel Interface](#11-system-calls--kernel-interface)
12. [Performance & Observability](#12-performance--observability)
13. [Boot Process & System Initialization](#13-boot-process--system-initialization)

---

## 1. Process Management

### 1.1 Process Concepts
- **Must Know:** Process vs program — process is a running instance of a program
- **Must Know:** Process Control Block (PCB) — PID, state, registers, memory maps, open files
- **Must Know:** Process states — new, ready, running, waiting/blocked, terminated
- **Must Know:** Context switching — save/restore PCB, cost (TLB flush, cache pollution)

### 1.2 Process Creation & Termination
- **Must Know:** `fork()` — creates child process, copy-on-write semantics
- **Must Know:** `exec()` family — replaces process image (`execve`, `execvp`, etc.)
- **Must Know:** `wait()` / `waitpid()` — parent waits for child termination
- **Must Know:** Zombie processes — terminated but not reaped, `SIGCHLD` handling
- **Must Know:** Orphan processes — reparented to init/systemd
- **Should Know:** `clone()` — fine-grained control (shared memory, PID namespace)
- **Should Know:** `posix_spawn()` — combined fork+exec, more efficient
- **Should Know:** Exit codes — convention (0 = success, non-zero = error)

### 1.3 Process Hierarchy
- **Must Know:** Parent-child relationships, `getpid()`, `getppid()`
- **Should Know:** Process groups, sessions — `setpgid()`, `setsid()`
- **Should Know:** Daemon creation — double fork, detach from terminal
- **Should Know:** init/systemd — PID 1, orphan reaping, service management
- **Should Know:** Job control — foreground, background, `SIGTSTP`, `SIGCONT`

### 1.4 Process Scheduling (Basic)
- **Must Know:** FIFO (First Come First Served) — simple, convoy effect
- **Must Know:** Round Robin — time quantum, preemptive
- **Must Know:** Priority scheduling — starvation risk, aging
- **Should Know:** Multilevel feedback queue — general purpose schedulers
- **Should Know:** CFS (Completely Fair Scheduler) — Linux default (overview)

### ✅ Checklist – Process Management
- [ ] fork/exec/wait lifecycle implemented and debugged
- [ ] Zombie and orphan process handling understood
- [ ] Context switching cost articulated
- [ ] Process states and transitions diagrammed
- [ ] Daemon creation process understood
- [ ] Basic scheduling algorithms compared

---

## 2. Threads & Concurrency

### 2.1 Thread Models
- **Must Know:** Kernel threads — managed by OS, scheduled independently
- **Must Know:** User threads — managed by user-space library, many-to-one mapping
- **Should Know:** Hybrid (M:N) — user threads multiplexed onto kernel threads
- **Should Know:** Trade-offs — kernel threads (heavier, preemptive) vs user threads (lighter, cooperative)

### 2.2 POSIX Threads (pthreads)
- **Must Know:** `pthread_create()`, `pthread_join()`, `pthread_detach()`
- **Must Know:** Thread attributes — stack size, detach state
- **Should Know:** Thread cancellation — `pthread_cancel()`, cleanup handlers
- **Should Know:** Mapping to C++ `std::thread`

### 2.3 Thread Scheduling & Affinity
- **Should Know:** Thread priorities — nice values, scheduling policies
- **Should Know:** CPU affinity — `sched_setaffinity()`, pinning threads to cores
- **Should Know:** NUMA awareness — allocating memory near the CPU that uses it
- **Nice to Have:** Hyper-threading implications — logical vs physical cores

### 2.4 Thread-Local Storage
- **Must Know:** `thread_local` (C++11) / `__thread` (GCC)
- **Must Know:** Use cases — per-thread caches, errno, random number generators
- **Should Know:** TLS implementation — TLS block, dynamic TLS, overhead

### 2.5 Alternative Concurrency Models
- **Should Know:** Green threads — user-space scheduled threads (Go goroutines, Erlang processes)
- **Should Know:** Fibers — cooperative, explicit yield points
- **Should Know:** Coroutines — C++20 coroutines, stackless vs stackful
- **Should Know:** Concurrency vs parallelism — Amdahl's law, Gustafson's law

### ✅ Checklist – Threads & Concurrency
- [ ] pthreads / std::thread — creation, joining, detaching mastered
- [ ] Thread models compared (kernel, user, hybrid)
- [ ] CPU affinity and NUMA awareness explored
- [ ] Thread-local storage used appropriately
- [ ] Amdahl's law applied to parallel speedup estimation

---

## 3. Synchronization & Deadlocks

### 3.1 Mutexes
- **Must Know:** `pthread_mutex_t` / `std::mutex` — lock, unlock, RAII wrappers
- **Must Know:** Critical section protection
- **Should Know:** Recursive mutex — `pthread_mutex_recursive` / `std::recursive_mutex`
- **Should Know:** Robust mutex — handling owner thread death
- **Should Know:** Priority inversion — priority inheritance protocol, priority ceiling

### 3.2 Semaphores
- **Must Know:** Counting semaphore — `sem_wait()`, `sem_post()`, producer-consumer
- **Must Know:** Binary semaphore — mutual exclusion (like mutex but different ownership)
- **Should Know:** Named semaphores — `sem_open()`, inter-process synchronization
- **Should Know:** POSIX vs System V semaphores

### 3.3 Condition Variables
- **Must Know:** `pthread_cond_wait()` / `std::condition_variable` — wait, signal, broadcast
- **Must Know:** Spurious wakeups — always use predicate in while loop
- **Must Know:** Predicate checking pattern — `while(!condition) { wait(); }`
- **Should Know:** Signaling patterns — signal-before-unlock vs signal-after-unlock

### 3.4 Read-Write Locks
- **Must Know:** `pthread_rwlock_t` / `std::shared_mutex` — multiple readers OR one writer
- **Should Know:** Reader-writer problem variants — reader-priority, writer-priority, fair
- **Should Know:** When to use rw-lock vs mutex (read-heavy workloads)

### 3.5 Spinlocks
- **Should Know:** Busy-waiting — when context switch cost exceeds wait time
- **Should Know:** Adaptive spinning — spin briefly, then sleep
- **Should Know:** When NOT to use spinlocks — long critical sections, single-core systems

### 3.6 Barriers & Latches
- **Should Know:** `pthread_barrier_t` / `std::barrier` [C++20]
- **Should Know:** `std::latch` [C++20] — single-use countdown synchronization
- **Should Know:** Use cases — phase-based parallel computation

### 3.7 Lock-Free & Wait-Free
- **Should Know:** Compare-and-swap (CAS) — `std::atomic::compare_exchange_strong/weak`
- **Should Know:** ABA problem — tagged pointers, hazard pointers
- **Should Know:** Memory ordering — `relaxed`, `acquire`, `release`, `seq_cst`
- **Nice to Have:** Lock-free queue, lock-free stack implementations
- **Nice to Have:** Wait-free vs lock-free vs obstruction-free — hierarchy

### 3.8 Deadlocks
- **Must Know:** Four necessary conditions — mutual exclusion, hold-and-wait, no preemption, circular wait
- **Must Know:** Prevention — break one condition (ordering, timeouts, all-or-nothing)
- **Should Know:** Avoidance — Banker's algorithm (conceptual)
- **Should Know:** Detection — wait-for graph, cycle detection
- **Should Know:** Recovery — process termination, resource preemption

### 3.9 Futex
- **Should Know:** Fast Userspace Mutex — no syscall in uncontended case
- **Should Know:** `futex()` — FUTEX_WAIT, FUTEX_WAKE
- **Should Know:** Building higher-level primitives on futex (mutex, semaphore, cond var)

### ✅ Checklist – Synchronization & Deadlocks
- [ ] Mutex + RAII locking pattern applied consistently
- [ ] Condition variable with predicate loop — spurious wakeup handling
- [ ] Reader-writer lock used for read-heavy scenarios
- [ ] Deadlock conditions identified and prevention strategies applied
- [ ] Lock-free concepts explored (CAS, memory ordering)
- [ ] Priority inversion scenario understood
- [ ] Futex concept grasped

---

## 4. Memory Management

### 4.1 Virtual Memory
- **Must Know:** Virtual address space — each process has its own
- **Must Know:** Page tables — virtual-to-physical address translation
- **Must Know:** TLB (Translation Lookaside Buffer) — page table cache, TLB miss cost
- **Must Know:** Page faults — minor (soft) vs major (hard), demand paging
- **Must Know:** Copy-on-write (CoW) — efficient `fork()`, shared pages until write

### 4.2 Memory Layout
- **Must Know:** Process memory layout — text, data, BSS, heap, stack
- **Must Know:** Stack — grows downward, automatic allocation, stack overflow
- **Must Know:** Heap — dynamic allocation, fragmentation
- **Should Know:** Memory-mapped regions — `mmap()`, shared libraries, file mapping
- **Should Know:** Kernel space vs user space — upper/lower address space split

### 4.3 Paging
- **Must Know:** Page replacement algorithms — LRU, Clock (second chance), FIFO
- **Must Know:** Working set model — pages actively in use
- **Must Know:** Thrashing — excessive paging, CPU spending time on page faults
- **Should Know:** Multi-level page tables — reducing memory overhead
- **Should Know:** Inverted page tables (concept)
- **Nice to Have:** Page table walks — hardware vs software

### 4.4 Segmentation
- **Should Know:** Segment tables, segment selectors (x86 legacy)
- **Must Know:** Segmentation faults — accessing invalid memory
- **Should Know:** Segmentation vs paging — modern OSes primarily use paging

### 4.5 Heap Memory Management
- **Must Know:** `malloc()` / `free()` internals — free lists, bins, splitting, coalescing
- **Must Know:** `sbrk()` — extending data segment (legacy)
- **Must Know:** `mmap()` — large allocations, anonymous mapping
- **Must Know:** Fragmentation — internal (wasted within allocation) and external (gaps between)
- **Should Know:** Memory allocators — ptmalloc (glibc default), jemalloc, tcmalloc
- **Should Know:** Allocator tuning — `MALLOC_ARENA_MAX`, thread-local arenas

### 4.6 Memory-Mapped Files
- **Must Know:** `mmap()` — map file into address space, lazy loading via page faults
- **Should Know:** `msync()` — flush changes to disk
- **Should Know:** Shared memory via `mmap()` — IPC mechanism
- **Should Know:** Private vs shared mappings — `MAP_PRIVATE`, `MAP_SHARED`

### 4.7 Huge Pages
- **Should Know:** Transparent Huge Pages (THP) — automatic 2MB pages
- **Should Know:** Explicit huge pages — `hugetlbfs`, reserved at boot
- **Should Know:** Performance impact — fewer TLB entries needed, less TLB misses
- **Nice to Have:** THP pitfalls — latency spikes from compaction

### 4.8 NUMA
- **Should Know:** Non-Uniform Memory Access — local vs remote memory latency
- **Should Know:** NUMA-aware allocation — `numactl`, `mbind()`, `set_mempolicy()`
- **Should Know:** NUMA topology — `lscpu`, `/sys/devices/system/node/`
- **Nice to Have:** NUMA impact on multi-threaded applications

### 4.9 OOM Killer & Memory Limits
- **Must Know:** Linux OOM killer — invoked when system runs out of memory
- **Should Know:** `oom_score`, `oom_score_adj` — tuning OOM priority
- **Should Know:** cgroup memory limits — `memory.max`, `memory.high`
- **Should Know:** Overcommit settings — `vm.overcommit_memory`

### 4.10 Memory Protection
- **Must Know:** ASLR — Address Space Layout Randomization
- **Must Know:** Stack canaries — buffer overflow detection
- **Must Know:** NX bit (DEP) — non-executable memory pages
- **Should Know:** RELRO — read-only relocations
- **Should Know:** PIE — Position Independent Executables

### ✅ Checklist – Memory Management
- [ ] Virtual memory — page tables, TLB, page faults explained
- [ ] Process memory layout diagrammed (text, data, BSS, heap, stack)
- [ ] Page replacement algorithms compared (LRU, Clock, FIFO)
- [ ] Thrashing identified and mitigation strategies known
- [ ] malloc internals understood (free lists, mmap threshold)
- [ ] mmap used for file mapping and shared memory
- [ ] Huge pages configured and performance impact measured
- [ ] NUMA topology inspected and allocation tuned
- [ ] OOM killer behavior understood and tuned
- [ ] Memory protection mechanisms listed (ASLR, canaries, NX, RELRO)

---

## 5. File Systems

### 5.1 File System Concepts
- **Must Know:** Inodes — metadata storage (permissions, timestamps, block pointers)
- **Must Know:** Directory entries — name-to-inode mapping
- **Must Know:** Hard links vs symbolic links — inode sharing vs path reference
- **Must Know:** File permissions — owner/group/other, chmod, umask

### 5.2 VFS (Virtual File System)
- **Must Know:** VFS layer — abstraction over different file systems
- **Should Know:** File operations — `struct file_operations` (conceptual)
- **Should Know:** Dentry cache — directory entry caching for path lookups
- **Should Know:** Inode cache — caching metadata

### 5.3 Common File Systems
- **Must Know:** ext4 — journaling, extents, features (most common Linux FS)
- **Should Know:** XFS — high-performance, scalable, delayed allocation
- **Should Know:** Btrfs — copy-on-write, snapshots, checksums
- **Nice to Have:** ZFS — pooled storage, snapshots, send/receive (not mainline Linux)
- **Nice to Have:** Comparison criteria — max file size, journaling, features, performance

### 5.4 File I/O
- **Must Know:** System calls — `open()`, `read()`, `write()`, `close()`, `lseek()`
- **Must Know:** File descriptors — integer handles, per-process FD table
- **Must Know:** `pread()` / `pwrite()` — positional I/O without seek
- **Should Know:** `dup()` / `dup2()` — duplicating file descriptors
- **Should Know:** FD limits — `ulimit -n`, `/proc/sys/fs/file-max`

### 5.5 Buffered vs Direct I/O
- **Must Know:** Page cache — kernel caches file data in memory
- **Must Know:** Buffered I/O — reads/writes go through page cache (default)
- **Must Know:** `fsync()` / `fdatasync()` — flush dirty pages to disk
- **Should Know:** `O_DIRECT` — bypass page cache, application manages caching
- **Should Know:** `O_SYNC` — synchronous writes
- **Should Know:** When to use direct I/O — databases, applications with own cache

### 5.6 File Locking
- **Should Know:** `flock()` — file-level advisory locking
- **Should Know:** `fcntl()` locks — byte-range locking, read/write locks
- **Should Know:** Advisory vs mandatory locking — Linux uses advisory by default
- **Nice to Have:** Lock contention in multi-process scenarios

### 5.7 Journaling & Crash Consistency
- **Must Know:** Journaling — write-ahead logging for crash recovery
- **Should Know:** Journal modes — data, ordered (default), writeback
- **Should Know:** Crash consistency — what happens on power loss
- **Nice to Have:** Log-structured file systems, copy-on-write consistency

### 5.8 Storage Stack
- **Should Know:** Block devices — `/dev/sda`, partitions
- **Should Know:** I/O schedulers — mq-deadline, BFQ, none (for NVMe)
- **Should Know:** Sequential vs random I/O — performance implications
- **Should Know:** Read-ahead — kernel prefetching sequential reads

### 5.9 Special File Systems
- **Should Know:** `tmpfs` — RAM-based file system
- **Should Know:** `procfs` (`/proc`) — process and kernel information
- **Should Know:** `sysfs` (`/sys`) — device and driver information
- **Nice to Have:** FUSE — filesystem in userspace

### ✅ Checklist – File Systems
- [ ] Inodes, hard links, soft links explained
- [ ] VFS abstraction understood
- [ ] ext4 / XFS features compared
- [ ] File I/O syscalls used (open, read, write, pread, pwrite)
- [ ] Page cache vs O_DIRECT trade-offs articulated
- [ ] fsync/fdatasync semantics understood
- [ ] Journaling and crash consistency explained
- [ ] I/O schedulers identified for different workloads
- [ ] procfs / sysfs explored for system introspection

---

## 6. I/O & Device Management

### 6.1 I/O Models
- **Must Know:** Blocking I/O — thread blocks until data available
- **Must Know:** Non-blocking I/O — returns immediately, poll for readiness
- **Must Know:** Synchronous vs asynchronous I/O — who initiates completion

### 6.2 I/O Multiplexing
- **Must Know:** `select()` — FD_SETSIZE limit, O(n) scanning
- **Must Know:** `poll()` — no FD limit, still O(n) scanning
- **Must Know:** `epoll()` — O(1) for ready events, edge-triggered vs level-triggered
- **Should Know:** `io_uring` — true async I/O, submission/completion queues, zero-copy
- **Should Know:** Evolution: select → poll → epoll → io_uring

### 6.3 Asynchronous I/O
- **Should Know:** POSIX AIO — `aio_read()`, `aio_write()` (limited adoption)
- **Should Know:** Signal-driven I/O — `SIGIO` (rarely used)
- **Must Know:** `io_uring` — modern Linux async I/O (preferred)

### 6.4 Zero-Copy I/O
- **Should Know:** `sendfile()` — file to socket without user-space copy
- **Should Know:** `splice()` — pipe-based zero-copy between FDs
- **Nice to Have:** `vmsplice()` — user-space buffer to pipe
- **Nice to Have:** DMA — Direct Memory Access, device-to-memory without CPU

### 6.5 Device Drivers (Concepts)
- **Should Know:** Character devices vs block devices
- **Should Know:** `/dev` entries, major/minor numbers
- **Nice to Have:** Interrupt handling — top half (ISR), bottom half (softirqs, tasklets, workqueues)

### ✅ Checklist – I/O & Device Management
- [ ] I/O models compared (blocking, non-blocking, sync, async)
- [ ] epoll used for scalable event-driven I/O
- [ ] io_uring explored for async I/O
- [ ] select → poll → epoll → io_uring evolution understood
- [ ] Zero-copy I/O mechanisms known (sendfile, splice)

---

## 7. Inter-Process Communication (IPC)

### 7.1 Pipes
- **Must Know:** Anonymous pipes — `pipe()`, unidirectional, parent-child communication
- **Must Know:** Named pipes (FIFOs) — `mkfifo()`, unrelated process communication
- **Should Know:** Pipe buffer sizes — default 64KB on Linux, `F_SETPIPE_SZ`

### 7.2 Message Queues
- **Should Know:** POSIX message queues — `mq_open()`, `mq_send()`, `mq_receive()`
- **Should Know:** System V message queues — `msgget()`, `msgsnd()`, `msgrcv()`
- **Should Know:** Comparison — POSIX vs System V

### 7.3 Shared Memory
- **Must Know:** Fastest IPC — no kernel involvement after setup
- **Must Know:** POSIX — `shm_open()`, `mmap()`, `shm_unlink()`
- **Should Know:** System V — `shmget()`, `shmat()`, `shmdt()`
- **Must Know:** Synchronization requirement — shared memory needs explicit locking

### 7.4 Sockets for IPC
- **Must Know:** Unix domain sockets — `AF_UNIX`, faster than TCP loopback
- **Must Know:** `SOCK_STREAM` vs `SOCK_DGRAM` — stream vs datagram over Unix sockets
- **Should Know:** Passing file descriptors over Unix sockets — `SCM_RIGHTS`

### 7.5 Signals
- **Must Know:** Signal handling — `signal()` (legacy), `sigaction()` (preferred)
- **Must Know:** Common signals — SIGTERM, SIGKILL, SIGINT, SIGCHLD, SIGSEGV, SIGPIPE
- **Must Know:** Signal masks — blocking signals during critical sections
- **Should Know:** Async-signal safety — only certain functions safe to call in handlers
- **Should Know:** Real-time signals — queued, with data payload
- **Nice to Have:** `signalfd()` — signal delivery via file descriptor

### 7.6 Linux-Specific IPC
- **Should Know:** `eventfd` — lightweight event notification
- **Should Know:** `inotify` — file system event monitoring
- **Nice to Have:** D-Bus — desktop/system message bus
- **Nice to Have:** `memfd_create()` — anonymous shared memory

### ✅ Checklist – IPC
- [ ] Pipes (anonymous & named) used for inter-process data flow
- [ ] Shared memory (POSIX) set up with proper synchronization
- [ ] Unix domain sockets used for efficient local IPC
- [ ] Signal handling with sigaction() implemented
- [ ] Async-signal safety rules understood
- [ ] eventfd / inotify explored

---

## 8. Process Scheduling (Advanced)

### 8.1 CFS (Completely Fair Scheduler)
- **Must Know:** Red-black tree of runnable tasks, ordered by virtual runtime (vruntime)
- **Must Know:** Nice values — -20 (highest priority) to 19 (lowest priority)
- **Should Know:** Weight calculation — nice value to weight mapping
- **Should Know:** Time slice calculation — proportional to weight

### 8.2 Real-Time Scheduling
- **Should Know:** `SCHED_FIFO` — fixed priority, no time quantum, runs until blocked
- **Should Know:** `SCHED_RR` — round-robin within same priority
- **Should Know:** `SCHED_DEADLINE` — earliest deadline first (EDF)
- **Should Know:** Real-time priority range — 1-99 (above all CFS tasks)

### 8.3 CPU Affinity & Isolation
- **Must Know:** `sched_setaffinity()` / `taskset` — pin process/thread to CPUs
- **Should Know:** `isolcpus` — kernel parameter to remove CPUs from general scheduling
- **Should Know:** CPU pinning for latency-sensitive workloads
- **Nice to Have:** `cpuset` cgroups — partition CPUs between workloads

### 8.4 cgroups for CPU
- **Should Know:** CPU shares — proportional allocation (`cpu.shares`)
- **Should Know:** CPU quota — hard limits (`cpu.max` in cgroup v2)
- **Should Know:** Bandwidth throttling — CFS bandwidth control
- **Nice to Have:** cpuset — restricting which CPUs a cgroup can use

### 8.5 Advanced Scheduling Topics
- **Nice to Have:** Energy-aware scheduling — power efficiency, heterogeneous CPUs (big.LITTLE)
- **Nice to Have:** Tickless kernels — `NO_HZ`, reduced timer interrupts
- **Nice to Have:** Scheduling latency — measuring and minimizing

### ✅ Checklist – Process Scheduling (Advanced)
- [ ] CFS internals understood (vruntime, nice values, red-black tree)
- [ ] Real-time scheduling policies compared (FIFO, RR, DEADLINE)
- [ ] CPU affinity applied for latency-sensitive tasks
- [ ] cgroups CPU limits configured
- [ ] Scheduling latency measured

---

## 9. Security & Protection

### 9.1 Access Control
- **Must Know:** DAC (Discretionary Access Control) — file permissions, ACLs
- **Must Know:** Unix permissions — owner/group/other, read/write/execute
- **Should Know:** MAC (Mandatory Access Control) — SELinux, AppArmor
- **Should Know:** RBAC (Role-Based Access Control)
- **Should Know:** Linux capabilities — fine-grained root privileges

### 9.2 Linux Security Modules
- **Should Know:** SELinux — type enforcement, contexts, policies, permissive vs enforcing
- **Should Know:** AppArmor — path-based, profiles, complain vs enforce
- **Should Know:** seccomp — syscall filtering
- **Should Know:** seccomp-bpf — BPF programs for syscall filtering

### 9.3 Privilege Management
- **Must Know:** setuid / setgid — executable runs with owner's privileges
- **Must Know:** Least privilege principle
- **Should Know:** Capabilities — `CAP_NET_ADMIN`, `CAP_SYS_ADMIN`, etc.
- **Should Know:** Dropping privileges — `setuid()`, `setgid()`, `setgroups()`
- **Nice to Have:** Ambient capabilities

### 9.4 Namespaces
- **Must Know:** PID namespace — isolated process ID trees
- **Must Know:** Network namespace — isolated network stacks
- **Must Know:** Mount namespace — isolated filesystem views
- **Should Know:** User namespace — unprivileged container creation
- **Should Know:** IPC namespace, UTS namespace, cgroup namespace
- **Should Know:** Namespace creation — `unshare()`, `clone()` with flags

### 9.5 Sandboxing
- **Should Know:** seccomp-bpf — restrict syscalls for untrusted code
- **Nice to Have:** Landlock (Linux) — unprivileged access control
- **Nice to Have:** `pledge()` / `unveil()` (OpenBSD)

### 9.6 Address Space Protection
- **Must Know:** ASLR — randomize stack, heap, mmap addresses
- **Must Know:** DEP/NX — prevent code execution from data pages
- **Must Know:** Stack canaries — detect stack buffer overflows
- **Should Know:** RELRO — protect GOT from overwrite attacks
- **Should Know:** PIE — position-independent executables

### ✅ Checklist – Security & Protection
- [ ] Unix permissions and ACLs configured
- [ ] SELinux / AppArmor basics understood
- [ ] seccomp filters applied
- [ ] Namespaces created and explored
- [ ] Capabilities model understood (vs monolithic root)
- [ ] ASLR, NX, stack canaries, RELRO — all explained

---

## 10. Containers & Virtualization

### 10.1 Containers
- **Must Know:** Containers = namespaces + cgroups + union filesystems
- **Must Know:** Process isolation without full OS virtualization
- **Must Know:** Lightweight compared to VMs — shared kernel

### 10.2 Docker
- **Must Know:** Docker images — layered, Dockerfile, build cache
- **Must Know:** Docker containers — running instances, lifecycle
- **Should Know:** Overlay filesystem — UnionFS, layered writes
- **Should Know:** Docker networking — bridge, host, overlay modes
- **Should Know:** Docker volumes — persistent storage

### 10.3 Kubernetes (OS-Level View)
- **Should Know:** Pods — one or more containers sharing namespaces
- **Should Know:** Resource limits — CPU/memory requests and limits via cgroups
- **Should Know:** Node scheduling — kubelet, resource accounting
- **Nice to Have:** Container runtime interface (CRI)

### 10.4 Virtual Machines
- **Must Know:** Hypervisor concept — virtual machine monitor (VMM)
- **Must Know:** Type 1 (bare-metal): KVM, Xen, VMware ESXi
- **Must Know:** Type 2 (hosted): VirtualBox, QEMU, VMware Workstation
- **Should Know:** Hardware virtualization — VT-x (Intel), AMD-V
- **Should Know:** EPT (Extended Page Tables) — hardware-assisted memory virtualization
- **Nice to Have:** SR-IOV — direct device assignment to VMs

### 10.5 Containers vs VMs
- **Must Know:** Trade-offs — isolation level, performance, startup time, density
- **Should Know:** When to use containers vs VMs
- **Nice to Have:** Kata Containers, Firecracker — micro-VMs bridging the gap

### 10.6 Container Runtimes
- **Should Know:** runc — OCI-compliant low-level runtime
- **Should Know:** containerd — high-level runtime, Docker uses it
- **Nice to Have:** crun — C-based, lighter alternative

### ✅ Checklist – Containers & Virtualization
- [ ] Container building blocks explained (namespaces, cgroups, union FS)
- [ ] Docker image build and container lifecycle mastered
- [ ] Docker networking modes understood
- [ ] Kubernetes pod scheduling (OS-level) grasped
- [ ] VM hypervisor types compared
- [ ] Containers vs VMs trade-offs articulated

---

## 11. System Calls & Kernel Interface

### 11.1 System Call Mechanism
- **Must Know:** User mode to kernel mode transition — software interrupt / `syscall` instruction
- **Must Know:** System call table — mapping numbers to kernel functions
- **Must Know:** Overhead — mode switch, parameter validation
- **Should Know:** vDSO (virtual Dynamic Shared Object) — fast syscalls without mode switch (gettimeofday)

### 11.2 Common System Calls
- **Must Know:** Process — `fork()`, `execve()`, `wait4()`, `exit()`
- **Must Know:** File — `open()`, `read()`, `write()`, `close()`, `stat()`, `lseek()`
- **Must Know:** Memory — `mmap()`, `munmap()`, `brk()`
- **Must Know:** IPC — `pipe()`, `socket()`, `shmget()`
- **Should Know:** Network — `socket()`, `bind()`, `listen()`, `accept()`, `connect()`

### 11.3 Tracing & Debugging
- **Must Know:** `strace` — trace system calls, timing, filtering
- **Should Know:** `ltrace` — trace library calls
- **Should Know:** `strace -c` — syscall statistics summary
- **Should Know:** `strace -e trace=network` — filter by category

### 11.4 eBPF
- **Should Know:** Extended Berkeley Packet Filter — programmable kernel instrumentation
- **Should Know:** Use cases — tracing, networking, security, observability
- **Should Know:** `bpftrace` — one-liners for kernel tracing
- **Should Know:** BCC tools — `biolatency`, `tcplife`, `execsnoop`, `opensnoop`
- **Nice to Have:** Writing custom eBPF programs

### 11.5 Kernel Tuning
- **Should Know:** `/proc` filesystem — process info, kernel parameters
- **Should Know:** `/sys` filesystem — device and driver info
- **Should Know:** `sysctl` — runtime kernel parameter tuning
- **Should Know:** Key sysctls — `vm.swappiness`, `net.core.somaxconn`, `fs.file-max`, `vm.overcommit_memory`

### ✅ Checklist – System Calls & Kernel Interface
- [ ] System call mechanism explained (user→kernel transition)
- [ ] strace used to debug application issues
- [ ] Common syscalls categorized (process, file, memory, IPC)
- [ ] eBPF / bpftrace / BCC tools explored
- [ ] Key sysctl parameters identified and tuned

---

## 12. Performance & Observability

### 12.1 CPU Performance
- **Must Know:** `perf stat` — hardware counters, IPC, cache misses
- **Must Know:** `perf record` + `perf report` — CPU profiling
- **Must Know:** Flame graphs — visualizing CPU time distribution
- **Should Know:** Context switch analysis — `perf sched`, `pidstat -w`
- **Should Know:** CPU frequency scaling — `cpufreq`, governor settings

### 12.2 Memory Performance
- **Must Know:** `/proc/meminfo` — total, free, available, buffers, cached
- **Must Know:** `vmstat` — memory, swap, I/O, CPU statistics
- **Should Know:** `valgrind --tool=memcheck` — memory error detection
- **Should Know:** `valgrind --tool=massif` — heap profiling
- **Nice to Have:** DHAT — dynamic heap analysis tool

### 12.3 I/O Performance
- **Must Know:** `iostat` — disk I/O statistics, utilization, latency
- **Should Know:** `iotop` — per-process I/O usage
- **Should Know:** `blktrace` — block-layer I/O tracing
- **Should Know:** `fio` — flexible I/O benchmarking tool
- **Nice to Have:** Block layer latency histograms

### 12.4 System-Wide Monitoring
- **Must Know:** `top` / `htop` — process-level CPU, memory, threads
- **Should Know:** `sar` — historical system statistics
- **Should Know:** `dstat` / `nmon` — comprehensive system monitoring
- **Should Know:** Brendan Gregg's USE method — Utilization, Saturation, Errors

### 12.5 Tracing
- **Should Know:** `ftrace` — kernel function tracing, function_graph
- **Should Know:** `perf_events` — hardware/software events
- **Should Know:** eBPF / `bpftrace` — programmable tracing
- **Nice to Have:** SystemTap — scripted kernel tracing

### 12.6 Latency Analysis
- **Should Know:** Scheduling latency — time from runnable to running
- **Should Know:** Interrupt latency — time to handle an interrupt
- **Should Know:** I/O latency histograms — bpftrace / BCC `biolatency`
- **Nice to Have:** Tail latency analysis — identifying p99/p999 outliers

### 12.7 Performance Anti-Patterns
- **Must Know:** Lock contention — excessive mutex/spinlock waiting
- **Must Know:** False sharing — cache line bouncing between cores
- **Should Know:** TLB shootdowns — inter-processor interrupts from memory operations
- **Should Know:** Context switch storms — too many threads, thrashing

### ✅ Checklist – Performance & Observability
- [ ] perf used for CPU profiling and flame graph generation
- [ ] vmstat / free / /proc/meminfo used for memory analysis
- [ ] iostat / fio used for I/O performance measurement
- [ ] USE method applied for systematic performance analysis
- [ ] eBPF tools used for dynamic tracing
- [ ] Performance anti-patterns identified (lock contention, false sharing)

---

## 13. Boot Process & System Initialization

### 13.1 Boot Sequence
- **Must Know:** BIOS/UEFI → bootloader (GRUB) → kernel → init/systemd
- **Should Know:** Kernel initialization — hardware detection, driver loading, rootfs mount
- **Should Know:** initramfs/initrd — temporary root filesystem for early boot

### 13.2 systemd
- **Must Know:** Units — service, socket, timer, mount, target
- **Must Know:** Targets — runlevel equivalents (`multi-user.target`, `graphical.target`)
- **Should Know:** Dependencies — `Requires`, `Wants`, `After`, `Before`
- **Should Know:** `systemctl` — start, stop, enable, disable, status, journal
- **Should Know:** Socket activation — start service on connection
- **Should Know:** cgroups integration — resource management per service

### 13.3 Kernel Modules
- **Should Know:** Module loading — `modprobe`, `insmod`, `rmmod`
- **Should Know:** Module dependencies — `depmod`, `/etc/modules`
- **Should Know:** `/proc/modules`, `lsmod` — list loaded modules
- **Nice to Have:** Kernel command line parameters — `/proc/cmdline`

### ✅ Checklist – Boot Process & Initialization
- [ ] Boot sequence explained (BIOS/UEFI → bootloader → kernel → init)
- [ ] systemd units and targets understood
- [ ] systemctl operations practiced
- [ ] Kernel module management explored
- [ ] initramfs purpose understood
