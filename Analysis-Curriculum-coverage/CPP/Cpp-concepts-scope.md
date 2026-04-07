# C++ Concepts — Mastery Scope for 10+ Years Experience

---

## 📊 Master Progress Tracker

| Section | Must Know Done | Should Know Done | Nice to Have Done | Last Reviewed | Notes |
|--------|----------------|------------------|-------------------|---------------|-------|
| Core Language & STL | | | | | |
| Concurrency & Parallelism | | | | | |
| Performance Engineering | | | | | |
| Memory Management | | | | | |
| API & ABI Design | | | | | |
| Tooling & Build Systems | | | | | |
| Testing & Quality | | | | | |
| Security & Reliability | | | | | |
| Architecture & Design | | | | | |
| Cross-Platform & Systems | | | | | |
| Domain Libraries & Ecosystem | | | | | |
| DevEx & Scale | | | | | |

---

## Table of Contents

1. [Core Language & Standard Library](#1-core-language--standard-library)
2. [Concurrency & Parallelism](#2-concurrency--parallelism)
3. [Performance Engineering](#3-performance-engineering)
4. [Memory Management](#4-memory-management)
5. [API & ABI Design](#5-api--abi-design)
6. [Tooling & Build Systems](#6-tooling--build-systems)
7. [Testing & Quality](#7-testing--quality)
8. [Security & Reliability](#8-security--reliability)
9. [Architecture & Design](#9-architecture--design)
10. [Cross-Platform & Systems](#10-cross-platform--systems)
11. [Domain Libraries & Ecosystem](#11-domain-libraries--ecosystem)
12. [DevEx & Scale](#12-devex--scale)

---

## 1. Core Language & Standard Library

### 1.1 Value Categories & Move Semantics [C++11+]
- **Must Know:** lvalues, rvalues, xvalues, prvalues, glvalues
- **Must Know:** `std::move`, `std::forward`, perfect forwarding
- **Must Know:** Move constructors, move assignment operators
- **Must Know:** Rule of 0 / Rule of 3 / Rule of 5
- **Must Know:** Copy elision, NRVO, guaranteed copy elision [C++17]
- **Should Know:** Ref-qualifiers on member functions
- **Should Know:** Moved-from state — valid but unspecified

### 1.2 RAII & Ownership Models [C++11+]
- **Must Know:** RAII principle — resource acquisition is initialization
- **Must Know:** Scope-based resource management
- **Must Know:** `std::unique_ptr` — sole ownership, custom deleters
- **Must Know:** `std::shared_ptr` — shared ownership, reference counting, control block
- **Must Know:** `std::weak_ptr` — breaking cycles, observer pattern
- **Should Know:** Aliasing constructor of `shared_ptr`
- **Should Know:** `enable_shared_from_this`
- **Nice to Have:** Custom allocators for smart pointers

### 1.3 Templates & Metaprogramming [C++11/14/17/20]
- **Must Know:** Function templates, class templates, template argument deduction
- **Must Know:** Template specialization (full & partial)
- **Must Know:** `constexpr` functions & variables [C++11/14/17]
- **Must Know:** `consteval`, `constinit` [C++20]
- **Must Know:** `if constexpr` [C++17]
- **Must Know:** Variadic templates, fold expressions [C++17]
- **Must Know:** Concepts & requires-clauses [C++20]
- **Should Know:** SFINAE, `std::enable_if`, detection idiom
- **Should Know:** Type traits (`std::is_same`, `std::decay`, `std::remove_reference`, etc.)
- **Should Know:** CRTP (Curiously Recurring Template Pattern)
- **Should Know:** Tag dispatch
- **Nice to Have:** Template template parameters
- **Nice to Have:** Expression templates

### 1.4 Error Handling [C++11/17/23]
- **Must Know:** Exceptions — throw, catch, exception hierarchy, `noexcept`
- **Must Know:** `std::optional` [C++17] — nullable value semantics
- **Must Know:** `std::variant` [C++17] — type-safe union, `std::visit`
- **Must Know:** Exception safety guarantees (basic, strong, nothrow)
- **Should Know:** `std::expected` [C++23]
- **Should Know:** Error codes vs exceptions — trade-offs, org policy
- **Should Know:** `std::error_code`, `std::error_category` [C++11]
- **Nice to Have:** Monadic operations on `optional`/`expected` [C++23]

### 1.5 Ranges, Iterators & Algorithms [C++17/20/23]
- **Must Know:** Iterator categories (input, output, forward, bidirectional, random access, contiguous)
- **Must Know:** STL algorithms — `sort`, `find`, `transform`, `accumulate`, `remove_if`, etc.
- **Must Know:** Range-based for loops
- **Must Know:** Ranges library [C++20] — views, adaptors, pipelines
- **Should Know:** Projections [C++20]
- **Should Know:** `std::ranges::to` [C++23]
- **Should Know:** Custom iterators, sentinel types [C++20]
- **Nice to Have:** Range adaptors closure objects

### 1.6 Coroutines [C++20]
- **Should Know:** `co_await`, `co_yield`, `co_return`
- **Should Know:** Promise type, coroutine handle, coroutine frame
- **Should Know:** Generator pattern, lazy evaluation
- **Nice to Have:** Async coroutine patterns, cancellation
- **Nice to Have:** Coroutine-based task systems

### 1.7 Modules [C++20]
- **Should Know:** Module units, interface units, implementation units
- **Should Know:** `export`, `import`, module partitions
- **Should Know:** Modules vs headers — trade-offs, migration
- **Nice to Have:** Build system integration (CMake support status)

### 1.8 Modern Vocabulary Types & Utilities [C++17/20/23]
- **Must Know:** `std::string_view` [C++17] — non-owning string references
- **Must Know:** `std::span` [C++20] — non-owning contiguous ranges
- **Must Know:** Structured bindings [C++17]
- **Should Know:** `std::any` [C++17]
- **Should Know:** `std::filesystem` [C++17]
- **Should Know:** `std::chrono` — clocks, durations, time points, calendar [C++20]
- **Should Know:** `std::format` [C++20], `std::print` [C++23]
- **Nice to Have:** `std::mdspan` [C++23]
- **Nice to Have:** `std::stacktrace` [C++23]

### 1.9 Containers & Data Structures
- **Must Know:** `vector`, `array`, `deque`, `list`, `forward_list`
- **Must Know:** `map`, `set`, `unordered_map`, `unordered_set`
- **Must Know:** `string`, `string_view`
- **Should Know:** `flat_map`, `flat_set` [C++23]
- **Should Know:** Container adaptors: `stack`, `queue`, `priority_queue`
- **Should Know:** Node-based vs contiguous containers — performance trade-offs

### ✅ Checklist – Core Language & STL
- [ ] Value categories & move semantics mastered [C++11]
- [ ] RAII & smart pointers — all three types understood and applied
- [ ] Templates — concepts, `constexpr`, SFINAE, variadic
- [ ] Error handling strategy chosen and consistently applied
- [ ] Ranges & algorithms [C++20] used in practice
- [ ] Coroutines [C++20] basics understood
- [ ] Modules [C++20] explored
- [ ] Modern vocabulary types used (`string_view`, `span`, `optional`, `variant`)

---

## 2. Concurrency & Parallelism

### 2.1 Threads & Thread Management [C++11+]
- **Must Know:** `std::thread` — creation, joining, detaching
- **Must Know:** `std::jthread` [C++20] — auto-joining, cooperative cancellation
- **Must Know:** Thread arguments — passing by value, reference (`std::ref`), move
- **Must Know:** Thread-local storage — `thread_local`

### 2.2 Mutexes & Locking [C++11/14/17]
- **Must Know:** `std::mutex`, `std::recursive_mutex`
- **Must Know:** `std::lock_guard`, `std::unique_lock`, `std::scoped_lock` [C++17]
- **Must Know:** `std::shared_mutex` [C++17], `std::shared_lock`
- **Should Know:** `std::call_once`, `std::once_flag`
- **Should Know:** Lock ordering, deadlock avoidance strategies

### 2.3 Condition Variables & Synchronization [C++11/20]
- **Must Know:** `std::condition_variable` — wait, notify_one, notify_all
- **Must Know:** Spurious wakeups, predicate-based waiting
- **Should Know:** `std::barrier`, `std::latch` [C++20]
- **Should Know:** `std::counting_semaphore`, `std::binary_semaphore` [C++20]

### 2.4 Atomics & Memory Model [C++11]
- **Must Know:** `std::atomic<T>` — load, store, exchange, compare_exchange
- **Must Know:** Memory ordering — `relaxed`, `acquire`, `release`, `seq_cst`
- **Should Know:** `std::atomic_ref` [C++20]
- **Should Know:** False sharing, cache line alignment
- **Nice to Have:** Lock-free data structures, ABA problem

### 2.5 Futures, Promises & Async [C++11]
- **Must Know:** `std::future`, `std::promise`
- **Must Know:** `std::async` — launch policies (`async`, `deferred`)
- **Should Know:** `std::packaged_task`
- **Should Know:** Thread pools (not in standard — common implementations)
- **Nice to Have:** Work stealing, fork-join patterns

### 2.6 Parallel STL [C++17]
- **Should Know:** Execution policies: `seq`, `par`, `par_unseq`, `unseq` [C++20]
- **Should Know:** Parallel algorithms — `std::sort`, `std::transform_reduce`, `std::for_each`

### 2.7 Coroutines vs Threads [C++20]
- **Should Know:** Cooperative vs preemptive multitasking trade-offs
- **Should Know:** When to use coroutines vs threads vs async I/O

### ✅ Checklist – Concurrency & Parallelism
- [ ] Thread creation, joining, detaching — including `jthread` [C++20]
- [ ] Mutex hierarchy understood — `mutex`, `shared_mutex`, `scoped_lock`
- [ ] Condition variables used correctly (predicate pattern)
- [ ] Atomics & memory ordering applied
- [ ] Futures/promises/async patterns used
- [ ] Parallel STL applied with execution policies
- [ ] Deadlock scenarios identified and prevented

---

## 3. Performance Engineering

### 3.1 Profiling & Measurement
- **Must Know:** CPU profiling — `perf`, flame graphs
- **Must Know:** Sampling vs tracing profilers
- **Should Know:** VTune, Tracy, Optick
- **Should Know:** Microbenchmarking — Google Benchmark library
- **Should Know:** Measuring tail latencies (p50, p95, p99)

### 3.2 CPU Architecture & Optimization
- **Must Know:** CPU cache hierarchy (L1/L2/L3), cache lines
- **Must Know:** Data-oriented design — SoA vs AoS
- **Should Know:** Branch prediction, likely/unlikely hints
- **Should Know:** Inlining, `[[likely]]`/`[[unlikely]]` [C++20]
- **Nice to Have:** Instruction-level parallelism, pipelining concepts

### 3.3 Compiler Optimizations
- **Must Know:** Optimization levels (-O0, -O1, -O2, -O3, -Os, -Oz)
- **Should Know:** Link-Time Optimization (LTO) — thin LTO, full LTO
- **Should Know:** Profile-Guided Optimization (PGO)
- **Should Know:** Symbol visibility (`-fvisibility=hidden`)
- **Nice to Have:** Cold/hot function attributes, `__builtin_expect`

### 3.4 SIMD & Vectorization
- **Nice to Have:** Auto-vectorization, compiler reports
- **Nice to Have:** `std::experimental::simd`
- **Nice to Have:** Vendor intrinsics (SSE, AVX) — when appropriate

### ✅ Checklist – Performance Engineering
- [ ] Profiling tools used (perf, flame graphs)
- [ ] Cache-friendly data layout applied
- [ ] LTO / PGO explored
- [ ] Benchmarking framework set up (Google Benchmark)
- [ ] Hot path optimizations identified and applied

---

## 4. Memory Management

### 4.1 Allocators & Memory Strategies
- **Must Know:** Default allocator, `std::allocator`
- **Must Know:** Stack vs heap allocation trade-offs
- **Should Know:** Custom allocators — arena/pool allocators
- **Should Know:** `std::pmr` (Polymorphic Memory Resource) [C++17]
- **Nice to Have:** `jemalloc`, `tcmalloc`, `mimalloc` — external allocators

### 4.2 Memory Layout & Alignment
- **Must Know:** Object layout, padding, `alignof`, `alignas`
- **Must Know:** Small-buffer optimization (SBO/SSO)
- **Should Know:** Strict aliasing rules, type punning
- **Should Know:** Placement new

### 4.3 Memory Diagnostics
- **Must Know:** AddressSanitizer (ASan) — use-after-free, buffer overflow
- **Must Know:** Valgrind / Memcheck
- **Should Know:** MemorySanitizer (MSan) — uninitialized reads
- **Should Know:** LeakSanitizer (LSan)
- **Nice to Have:** DHAT, Massif — heap profiling

### ✅ Checklist – Memory Management
- [ ] Custom allocators understood (arena, pool, PMR)
- [ ] Alignment and padding rules applied
- [ ] ASan/MSan/Valgrind used in CI pipeline
- [ ] Small-buffer optimization understood (SSO in std::string)

---

## 5. API & ABI Design

### 5.1 Interface Design
- **Must Know:** Header-only vs compiled libraries
- **Must Know:** Forward declarations, include-what-you-use
- **Must Know:** pImpl idiom — ABI stability, compile-time firewall
- **Should Know:** Hourglass pattern for C/C++ interop
- **Should Know:** Dependency boundaries, layering

### 5.2 ABI Stability & Versioning
- **Should Know:** Symbol visibility (`__attribute__((visibility("default")))`)
- **Should Know:** Inline namespaces for versioning [C++11]
- **Should Know:** ABI breakage scenarios — vtable layout, member reordering
- **Nice to Have:** `extern "C"` interfaces, dlopen/dlsym

### 5.3 Exception Safety & Contracts
- **Must Know:** Exception-safety guarantees (nothrow, basic, strong)
- **Should Know:** Contracts (preconditions, postconditions, assertions) — P2900 status
- **Should Know:** `noexcept` specification and its effects

### ✅ Checklist – API & ABI Design
- [ ] pImpl idiom applied for ABI-stable interfaces
- [ ] Symbol visibility managed
- [ ] Exception-safety guarantees documented per API
- [ ] Versioning strategy in place

---

## 6. Tooling & Build Systems

### 6.1 Compilers
- **Must Know:** GCC, Clang, MSVC — differences in behavior, extensions
- **Must Know:** Warnings-as-errors (`-Werror`, `-Wall`, `-Wextra`)
- **Must Know:** Sanitizers: ASan, UBSan, TSan, MSan

### 6.2 Static Analysis & Formatting
- **Must Know:** `clang-tidy` — checks, custom rules, CI integration
- **Should Know:** `cppcheck`, `PVS-Studio`
- **Must Know:** `clang-format` — style configuration, pre-commit hooks
- **Should Know:** `include-what-you-use`

### 6.3 Build Systems & Package Managers
- **Must Know:** CMake — modern targets, `target_link_libraries`, generator expressions
- **Must Know:** CMake presets [CMake 3.19+]
- **Should Know:** Conan, vcpkg — dependency management
- **Should Know:** Reproducible builds, SBOM (Software Bill of Materials)
- **Nice to Have:** Bazel, Meson

### ✅ Checklist – Tooling & Build Systems
- [ ] Multi-compiler CI (GCC + Clang + MSVC)
- [ ] Sanitizers enabled in CI (ASan, UBSan, TSan)
- [ ] clang-tidy + clang-format enforced
- [ ] Modern CMake practices adopted
- [ ] Package manager integrated (Conan/vcpkg)

---

## 7. Testing & Quality

### 7.1 Unit & Integration Testing
- **Must Know:** Google Test (GTest) — test fixtures, assertions, parameterized tests
- **Must Know:** Google Mock (GMock) — mocking, matchers, actions
- **Should Know:** Catch2, doctest — alternatives
- **Should Know:** Integration testing strategies

### 7.2 Advanced Testing
- **Should Know:** Property-based testing — RapidCheck
- **Should Know:** Fuzzing — libFuzzer, AFL/AFL++
- **Should Know:** Coverage — `llvm-cov`, `gcov`, `lcov`
- **Nice to Have:** Mutation testing
- **Nice to Have:** Contract testing for APIs

### 7.3 Test Infrastructure
- **Should Know:** Deterministic tests, flake reduction
- **Should Know:** Test data management, fixtures, factories
- **Should Know:** Test pyramid — unit > integration > e2e ratio

### ✅ Checklist – Testing & Quality
- [ ] GTest/GMock used for unit testing
- [ ] Code coverage measured and tracked
- [ ] Fuzzing integrated for parsing/serialization code
- [ ] Test determinism ensured (no flaky tests)

---

## 8. Security & Reliability

### 8.1 Undefined Behavior & Safety
- **Must Know:** Common UB — signed overflow, null deref, dangling pointers, out-of-bounds
- **Must Know:** Lifetime issues — use-after-free, dangling references, iterator invalidation
- **Must Know:** UBSan — runtime UB detection

### 8.2 Secure Coding Practices
- **Should Know:** CERT C++ Secure Coding Standard
- **Should Know:** Input validation, bounds checking
- **Should Know:** Integer overflow/underflow — safe integer libraries
- **Should Know:** Format string vulnerabilities (legacy `printf`)

### 8.3 Hardening
- **Nice to Have:** Stack canaries, ASLR, RELRO, PIE
- **Nice to Have:** Hardened allocators, `_FORTIFY_SOURCE`

### ✅ Checklist – Security & Reliability
- [ ] Common UB sources identified and mitigated
- [ ] Iterator invalidation rules memorized per container
- [ ] UBSan enabled in CI
- [ ] CERT C++ guidelines reviewed

---

## 9. Architecture & Design

### 9.1 Software Architecture Principles
- **Must Know:** SOLID principles applied in C++
- **Must Know:** Dependency inversion, interface segregation
- **Must Know:** Layering, module boundaries
- **Should Know:** Immutability where practical

### 9.2 Design Patterns in C++
- **Must Know:** RAII (as a pattern)
- **Must Know:** pImpl
- **Must Know:** Observer, Strategy, Visitor
- **Should Know:** Builder, Factory, Singleton (and why to avoid)
- **Should Know:** Reactor/Proactor (async I/O patterns)
- **Should Know:** Policy-based design (Alexandrescu-style)
- **Nice to Have:** Type erasure patterns

### ✅ Checklist – Architecture & Design
- [ ] SOLID principles applied consistently
- [ ] Key design patterns implemented in C++
- [ ] Policy-based design explored
- [ ] Module boundaries clearly defined in projects

---

## 10. Cross-Platform & Systems

### 10.1 Platform Abstractions
- **Must Know:** Filesystem operations — `std::filesystem` [C++17]
- **Must Know:** Endianness — `std::endian` [C++20], byte-swapping
- **Should Know:** OS differences — Windows (Win32 API), Linux (POSIX), macOS
- **Should Know:** Unicode & UTF-8 handling, `char8_t` [C++20]

### 10.2 Systems Programming
- **Should Know:** Socket programming basics (POSIX sockets, Winsock)
- **Should Know:** Time zones — `std::chrono::time_zone` [C++20]
- **Nice to Have:** Android NDK nuances, cross-compilation

### ✅ Checklist – Cross-Platform & Systems
- [ ] `std::filesystem` used for portable file operations
- [ ] Endianness handling applied
- [ ] UTF-8 / Unicode strategy in place
- [ ] Cross-platform builds tested (Linux + Windows)

---

## 11. Domain Libraries & Ecosystem

### 11.1 Networking & I/O
- **Must Know:** Boost.Asio / standalone Asio — async I/O, event loops
- **Should Know:** gRPC — service definitions, code generation, streaming

### 11.2 Serialization
- **Must Know:** Protocol Buffers (protobuf)
- **Should Know:** FlatBuffers, JSON libraries (nlohmann/json, rapidjson, simdjson)

### 11.3 Utility Libraries
- **Should Know:** `fmt` library (now `std::format`)
- **Should Know:** `range-v3` (precursor to std::ranges)
- **Should Know:** Boost basics — `Boost.Optional`, `Boost.Variant`, `Boost.Filesystem` (legacy)
- **Nice to Have:** Abseil, Folly

### ✅ Checklist – Domain Libraries & Ecosystem
- [ ] Asio-based async I/O implemented
- [ ] Protobuf / FlatBuffers used for serialization
- [ ] JSON library integrated
- [ ] fmt / std::format adopted

---

## 12. DevEx & Scale

### 12.1 Code Review & Collaboration
- **Must Know:** Code review best practices, diff hygiene
- **Must Know:** Refactoring large codebases — incremental, safe transformations
- **Should Know:** Deprecation plans, API migration strategies

### 12.2 CI/CD & Infrastructure
- **Must Know:** CI pipelines — build, test, lint, sanitize
- **Should Know:** Jenkins, GitHub Actions, Azure Pipelines — C++ specific
- **Should Know:** Artifact caching, ccache, sccache
- **Should Know:** Binary compatibility across releases

### ✅ Checklist – DevEx & Scale
- [ ] CI pipeline includes build + test + sanitizers + static analysis
- [ ] ccache/sccache configured for fast rebuilds
- [ ] Code review checklist established
- [ ] Deprecation workflow documented

---

## Optional Domain Tracks

### Embedded / RTOS
- [ ] Bare-metal C++, `-fno-exceptions`, `-fno-rtti`
- [ ] RTOS task management, interrupt-safe code

### Low-Latency Trading
- [ ] Lock-free queues, kernel bypass, DPDK
- [ ] Deterministic memory allocation, pre-warming

### Game Engines
- [ ] ECS (Entity Component System), frame budgets
- [ ] Custom allocators, SIMD math libraries

### HPC
- [ ] MPI, OpenMP, GPU offloading (CUDA/SYCL)
- [ ] Vectorization, memory bandwidth optimization

### Networking Backends
- [ ] epoll/io_uring, connection handling at scale
- [ ] Protocol implementation, zero-copy I/O

### Distributed Systems
- [ ] Consensus protocols, RPC frameworks
- [ ] Failure handling, partition tolerance
