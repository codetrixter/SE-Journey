# Prompt for fetching the scope of preparation of topics:
1. ***OPERATING SYSTEMS CONCEPTS***

- Role & Goal
You are an expert Systems Engineer and curriculum designer with deep expertise in operating systems internals, systems programming, and OS-level performance engineering. Create a comprehensive, industry-ready list of OS concepts, mechanisms, and practices that a software engineer with 10 years of experience should master. The output must be well-structured, exhaustive, and actionable, with checklists and tracking metadata for mastery.

Audience Context

Experience: 10 years in software engineering
Platforms: Linux (primary), Windows (secondary), with POSIX focus
Languages: C/C++ for systems programming
Focus: understanding OS internals to write better application code, debug production issues, and design performant systems
Scale: high-performance, multi-threaded, latency-sensitive production systems

Scope (cover all sections)

## Process Management

Process concepts: PCB, process states, context switching costs
Process creation: fork(), exec(), clone(), posix_spawn()
Process termination: exit codes, zombie processes, orphan processes, wait()/waitpid()
Process scheduling: FIFO, Round Robin, CFS (Linux), priority scheduling, real-time scheduling
Process hierarchy: init/systemd, process groups, sessions, daemons
Inter-process relationships: parent-child, process groups, job control

## Threads & Concurrency

Thread models: kernel threads, user threads, hybrid (M:N)
POSIX threads (pthreads): creation, joining, detaching
Thread scheduling: thread priorities, CPU affinity, NUMA awareness
Thread-local storage (TLS): __thread, thread_local (C++11)
Green threads, fibers, coroutines — comparison with OS threads
Concurrency vs parallelism: multi-core utilization, Amdahl's law, Gustafson's law

## Synchronization & Deadlocks

Mutex: implementation, recursive mutex, robust mutex, priority inversion
Semaphores: counting, binary, named (POSIX), producer-consumer
Condition variables: spurious wakeups, predicate checking, signaling patterns
Read-write locks: rwlock, shared_mutex, reader-writer problem variants
Spinlocks: when to use, busy-waiting, adaptive spinning
Barriers, latches: thread synchronization points
Lock-free & wait-free data structures: CAS, atomic operations, ABA problem, memory ordering
Deadlock: conditions, prevention, avoidance (Banker's algorithm), detection, recovery
Priority inversion: priority inheritance, priority ceiling protocol
Futex: fast userspace mutex, Linux implementation

## Memory Management

Virtual memory: page tables, TLB, page faults, demand paging, copy-on-write
Memory layout: text, data, BSS, heap, stack, memory-mapped regions
Paging: page replacement algorithms (LRU, Clock, FIFO), working set model, thrashing
Segmentation: segment tables, segmentation faults, protection
malloc/free internals: sbrk, mmap, free-list management, fragmentation (internal/external)
Memory allocators: ptmalloc, jemalloc, tcmalloc — comparison and tuning
Memory-mapped files: mmap(), msync(), shared memory via mmap
Huge pages: THP (transparent huge pages), explicit huge pages, performance impact
NUMA: non-uniform memory access, NUMA-aware allocation, topology
OOM killer: Linux OOM behavior, oom_score, cgroup memory limits
Address space layout randomization (ASLR), stack canaries, NX bit

## File Systems

File system concepts: inodes, directory entries, hard links, symbolic links
VFS (Virtual File System): abstraction layer, file operations, dentry cache
Common file systems: ext4, XFS, Btrfs, ZFS — features and trade-offs
File I/O: open(), read(), write(), close(), lseek(), pread()/pwrite()
Buffered vs direct I/O: page cache, O_DIRECT, fsync(), fdatasync()
File locking: flock(), fcntl() locks, advisory vs mandatory locking
File descriptors: fd table, dup()/dup2(), file descriptor limits, /proc/fd
Journaling: write-ahead logging, crash consistency, ordered/writeback/journal modes
Storage stack: block devices, I/O schedulers (CFQ, deadline, mq-deadline, BFQ, none)
FUSE: filesystem in userspace
tmpfs, procfs, sysfs: special file systems
Disk I/O patterns: sequential vs random, read-ahead, write-back caching

## I/O & Device Management

I/O models: blocking, non-blocking, synchronous, asynchronous
I/O multiplexing: select(), poll(), epoll(), io_uring — evolution and trade-offs
Signal-driven I/O, POSIX AIO
DMA: direct memory access, zero-copy I/O (sendfile, splice, vmsplice)
Device drivers: character devices, block devices, /dev, major/minor numbers (concepts)
Interrupt handling: top half, bottom half, softirqs, tasklets, workqueues (Linux kernel concepts)

## Inter-Process Communication (IPC)

Pipes: anonymous pipes, named pipes (FIFOs), pipe buffer sizes
Message queues: POSIX message queues, System V message queues
Shared memory: shmget/shmat (System V), shm_open/mmap (POSIX), synchronization requirements
Sockets: Unix domain sockets vs TCP loopback, SOCK_STREAM vs SOCK_DGRAM
Signals: signal handling, signal masks, sigaction(), real-time signals, async-signal safety
D-Bus, eventfd, inotify (Linux-specific IPC)
Memory-mapped files for IPC: synchronization, consistency

## Process Scheduling (Advanced)

Completely Fair Scheduler (CFS): red-black tree, vruntime, nice values
Real-time scheduling: SCHED_FIFO, SCHED_RR, SCHED_DEADLINE
CPU affinity: sched_setaffinity(), isolcpus, CPU pinning for latency
cgroups: CPU shares, CPU quota, cpuset, bandwidth throttling
Priority inversion in scheduling, latency-sensitive workloads
Energy-aware scheduling, tickless kernels (NO_HZ)

## Security & Protection

Access control: DAC, MAC, RBAC, capabilities
Linux security modules: SELinux, AppArmor, seccomp
Privilege escalation: setuid, setgid, capabilities (CAP_NET_ADMIN, etc.)
Namespaces: PID, network, mount, user, IPC, cgroup — container building blocks
Sandboxing: seccomp-bpf, pledge/unveil (OpenBSD), Landlock (Linux)
Address space protection: ASLR, DEP/NX, stack canaries, RELRO
System call filtering, audit logging

## Containers & Virtualization

Containers: namespaces + cgroups + union filesystems = containers
Docker: layered images, overlay filesystem, container networking
Kubernetes: pods, scheduling, resource limits, node management (OS-level view)
Virtual machines: hypervisors (Type 1: KVM, Xen; Type 2: VirtualBox, QEMU)
Hardware virtualization: VT-x, EPT, SR-IOV
OS-level virtualization vs hardware virtualization: trade-offs
Container runtimes: runc, containerd, crun

## System Calls & Kernel Interface

System call mechanism: user mode to kernel mode transition, syscall table
Common syscalls: process (fork, exec, wait), file (open, read, write, stat), memory (mmap, brk), IPC
strace, ltrace: tracing system calls and library calls
eBPF: programmable kernel tracing, networking, security (bpftrace, BCC tools)
procfs, sysfs: kernel tuning, system introspection
sysctl: kernel parameter tuning (vm.swappiness, net.core.somaxconn, etc.)

## Performance & Observability

CPU performance: perf, flame graphs, CPU profiling, context switch analysis
Memory performance: /proc/meminfo, vmstat, valgrind, massif, DHAT
I/O performance: iostat, iotop, blktrace, fio benchmarking
System-wide: top/htop, sar, dstat, nmon, Brendan Gregg's USE method
Tracing: ftrace, perf_events, eBPF/bpftrace, SystemTap
Latency analysis: scheduling latency, interrupt latency, I/O latency histograms
Performance anti-patterns: lock contention, false sharing, TLB shootdowns, context switch storms

## Boot Process & System Initialization

BIOS/UEFI → bootloader → kernel → init/systemd
Kernel initialization: device detection, rootfs mounting, init execution
systemd: units, targets, dependencies, socket activation, cgroups integration
Kernel modules: loading, dependencies, modprobe, /etc/modules
Kernel command line parameters, initramfs/initrd

Output Requirements

Table of Contents with deep linking
Each section must include:
  - What & Why (1–2 concise paragraphs)
  - Key Topics (bullet list)
  - "Gotchas & Pitfalls" (bullet list)
  - Diagrams/Illustrations descriptions (where helpful: process state diagram, memory layout, I/O flow)
  - Code Snippets (C/C++ system call examples where applicable, minimal, compilable; do not put code inside tables)
  - Checklist (Markdown checkboxes with tracking fields)
  - Self‑Assessment (3–5 questions; 1 scenario-based debugging/design question)
  - References (OSTEP, Tanenbaum, Linux kernel docs, man pages, Brendan Gregg; prefer stable links)

Master Progress Tracker at the top (aggregating all checklists).
Separate "Must Know / Should Know / Nice to Have" per section.
Keep explanations concise but industry-practical (trade-offs, production debugging scenarios).

Checklist Template (use in every section)

```markdown
### ✅ Checklist – {Section Name}
- [ ] Concept mastered: {Item}
      Owner: {name}  Target Date: {YYYY-MM-DD}  Last Reviewed: {YYYY-MM-DD}
      Evidence: {PR link / doc / lab exercise}
- [ ] Pitfall avoided: {Describe common bug/misconfiguration and prevention}
- [ ] Tooling applied: {strace / perf / valgrind / specific tool}
- [ ] Hands-on lab completed: {syscall tracing / memory analysis / scheduling experiment}
- [ ] Applied in production context (if applicable)
- [ ] Knowledge shared: {brown-bag / wiki / runbook}
```

Master Progress Tracker (top of document)

```markdown
## 📊 Master Progress Tracker
| Section                         | Must Know Done | Should Know Done | Nice to Have Done | Last Reviewed | Notes |
|---------------------------------|----------------|------------------|-------------------|---------------|-------|
| Process Management              |                |                  |                   |               |       |
| Threads & Concurrency           |                |                  |                   |               |       |
| Synchronization & Deadlocks     |                |                  |                   |               |       |
| Memory Management               |                |                  |                   |               |       |
| File Systems                    |                |                  |                   |               |       |
| I/O & Device Management         |                |                  |                   |               |       |
| Inter-Process Communication     |                |                  |                   |               |       |
| Process Scheduling (Advanced)   |                |                  |                   |               |       |
| Security & Protection           |                |                  |                   |               |       |
| Containers & Virtualization     |                |                  |                   |               |       |
| System Calls & Kernel Interface |                |                  |                   |               |       |
| Performance & Observability     |                |                  |                   |               |       |
| Boot Process & Initialization   |                |                  |                   |               |       |
```

Style & Constraints

- Use Markdown, descriptive headings, and consistent formatting.
- Keep code outside tables.
- Mark advanced concepts clearly as such.
- Focus on Linux as the primary OS with Windows/macOS comparisons where relevant.
- Include practical debugging and troubleshooting scenarios.
- Tie OS concepts to application-level software engineering decisions.
- Include hands-on exercises using real system tools (strace, perf, /proc, etc.).
- Prefer POSIX-portable guidance; highlight Linux-specific features explicitly.
