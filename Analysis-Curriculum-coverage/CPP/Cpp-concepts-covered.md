# C++ Concepts — Coverage Analysis

> **Last Analyzed:** April 7, 2026
> **Source Folders:** `Concurrency/`, `CPP_Concepts/`
> **Reference:** `Cpp-concepts-scope.md`

---

## 📊 Coverage Summary

| Section | Must Know | Should Know | Nice to Have | Status |
|---------|-----------|-------------|--------------|--------|
| Core Language & STL | 🟡 Partial | 🟡 Partial | 🔴 Not Started | In Progress |
| Concurrency & Parallelism | 🟡 Partial | 🟡 Partial | 🔴 Not Started | In Progress |
| Performance Engineering | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Memory Management | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| API & ABI Design | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Tooling & Build Systems | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Testing & Quality | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Security & Reliability | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Architecture & Design | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Cross-Platform & Systems | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Domain Libraries & Ecosystem | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| DevEx & Scale | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |

---

## 1. Core Language & Standard Library

### 1.1 Value Categories & Move Semantics [C++11+]
- [x] **Must Know:** lvalues, rvalues, xvalues, prvalues, glvalues — *Covered in `lValue-rValueReferences/lVal-rValCherno.cpp`*
- [x] **Must Know:** `std::move`, `std::forward`, perfect forwarding — *Covered in `MoveSemantics-SmartPointers/STDmove.cpp`*
- [x] **Must Know:** Move constructors, move assignment operators — *Covered in `MoveSemantics-SmartPointers/moveCtorAndassign.cpp`*
- [ ] **Must Know:** Rule of 0 / Rule of 3 / Rule of 5
- [ ] **Must Know:** Copy elision, NRVO, guaranteed copy elision [C++17]
- [ ] **Should Know:** Ref-qualifiers on member functions
- [ ] **Should Know:** Moved-from state — valid but unspecified

> 🛠 **Project: `SmartString` — A custom string class**
> - *Size: Small (~200 LOC)*
> - Implement a `String` class with Rule of 5 (copy ctor, copy assign, move ctor, move assign, destructor)
> - Add ref-qualified `data()` method (lvalue returns `const char*`, rvalue returns moved buffer)
> - Write tests demonstrating copy elision / NRVO by logging constructors
> - **Covers:** Rule of 5, copy elision, ref-qualifiers, moved-from state

### 1.2 RAII & Ownership Models [C++11+]
- [x] **Must Know:** RAII principle — *Covered in `OOPS-COncepts/Classes/RAIIDestructor.cpp`*
- [x] **Must Know:** Scope-based resource management — *Covered in `Scope-Duration-Linkage/` folder*
- [x] **Must Know:** `std::unique_ptr` — sole ownership, custom deleters — *Covered in `MoveSemantics-SmartPointers/unique-pointer.cpp`*
- [x] **Must Know:** `std::shared_ptr` — shared ownership, reference counting — *Covered in `MoveSemantics-SmartPointers/shared-ptr.cpp`*
- [x] **Must Know:** `std::weak_ptr` — breaking cycles, observer pattern — *Covered in `MoveSemantics-SmartPointers/weak-ptr-issues-with-sharedptr.cpp`*
- [ ] **Should Know:** Aliasing constructor of `shared_ptr`
- [ ] **Should Know:** `enable_shared_from_this`
- [ ] **Nice to Have:** Custom allocators for smart pointers

> 🛠 **Project: `ResourcePool` — A generic object pool**
> - *Size: Small (~150 LOC)*
> - Implement an object pool that returns `shared_ptr` with custom deleters (return-to-pool instead of delete)
> - Use `enable_shared_from_this` for pooled objects to hand out references to themselves
> - Demonstrate aliasing constructor for sub-object access
> - **Covers:** Aliasing constructor, `enable_shared_from_this`, custom deleters

### 1.3 Templates & Metaprogramming [C++11/14/17/20]
- [x] **Must Know:** Function templates, class templates, template argument deduction — *Covered in `Templates-generics/tempateClasses.cpp`*
- [ ] **Must Know:** Template specialization (full & partial)
- [ ] **Must Know:** `constexpr` functions & variables [C++11/14/17]
- [ ] **Must Know:** `consteval`, `constinit` [C++20]
- [ ] **Must Know:** `if constexpr` [C++17]
- [ ] **Must Know:** Variadic templates, fold expressions [C++17]
- [ ] **Must Know:** Concepts & requires-clauses [C++20]
- [ ] **Should Know:** SFINAE, `std::enable_if`, detection idiom
- [ ] **Should Know:** Type traits (`std::is_same`, `std::decay`, `std::remove_reference`, etc.)
- [ ] **Should Know:** CRTP (Curiously Recurring Template Pattern)
- [ ] **Should Know:** Tag dispatch
- [ ] **Nice to Have:** Template template parameters
- [ ] **Nice to Have:** Expression templates

> 🛠 **Project: `TypeSafeUnits` — A compile-time units library**
> - *Size: Medium (~400 LOC)*
> - Use class templates with partial specialization for units (meters, seconds, kg)
> - `constexpr` conversion functions between compatible units
> - Variadic templates for compound units (e.g., m/s²)
> - Concepts to constrain arithmetic only between compatible dimensions
> - SFINAE/`enable_if` for backward-compatible overloads
> - CRTP base for shared operator logic
> - **Covers:** Specialization, `constexpr`, `if constexpr`, variadic templates, fold expressions, concepts, SFINAE, type traits, CRTP, tag dispatch

### 1.4 Error Handling [C++11/17/23]
- [x] **Must Know:** Exceptions — throw, catch, exception hierarchy, `noexcept` — *Covered in `Exceptions/` folder (8+ files: basics, stack unwinding, rethrow, no-except, destructors, class/inheritance, function try block, catch-all)*
- [ ] **Must Know:** `std::optional` [C++17] — nullable value semantics
- [ ] **Must Know:** `std::variant` [C++17] — type-safe union, `std::visit`
- [ ] **Must Know:** Exception safety guarantees (basic, strong, nothrow)
- [ ] **Should Know:** `std::expected` [C++23]
- [ ] **Should Know:** Error codes vs exceptions — trade-offs
- [ ] **Should Know:** `std::error_code`, `std::error_category` [C++11]
- [ ] **Nice to Have:** Monadic operations on `optional`/`expected` [C++23]

> 🛠 **Project: `ConfigParser` — A configuration file parser**
> - *Size: Small (~250 LOC)*
> - Parse key-value config files; return `std::optional<Value>` for missing keys
> - Use `std::variant<int, double, string, bool>` for heterogeneous values with `std::visit`
> - Provide both error-code and exception-based APIs to compare trade-offs
> - Define exception safety guarantees (strong guarantee on parse failure)
> - **Covers:** `optional`, `variant`, `std::visit`, exception safety, error codes vs exceptions, `std::error_code`

### 1.5 Ranges, Iterators & Algorithms [C++17/20/23]
- [ ] **Must Know:** Iterator categories
- [ ] **Must Know:** STL algorithms — sort, find, transform, accumulate, etc.
- [ ] **Must Know:** Range-based for loops
- [ ] **Must Know:** Ranges library [C++20]
- [ ] **Should Know:** Projections [C++20]
- [ ] **Should Know:** `std::ranges::to` [C++23]
- [ ] **Should Know:** Custom iterators, sentinel types [C++20]
- [ ] **Nice to Have:** Range adaptors closure objects

> 🛠 **Project: `DataPipeline` — A CSV data processing pipeline**
> - *Size: Medium (~350 LOC)*
> - Read CSV, filter/transform/sort rows using STL algorithms and ranges
> - Implement a custom iterator for streaming rows from file (lazy I/O)
> - Use projections for sorting by specific columns
> - Chain range views: `filter | transform | take`
> - **Covers:** Iterator categories, STL algorithms, ranges, projections, custom iterators, sentinels

### 1.6 Coroutines [C++20]
- [ ] **Should Know:** `co_await`, `co_yield`, `co_return`
- [ ] **Should Know:** Promise type, coroutine handle, coroutine frame
- [ ] **Should Know:** Generator pattern, lazy evaluation
- [ ] **Nice to Have:** Async coroutine patterns, cancellation
- [ ] **Nice to Have:** Coroutine-based task systems

> 🛠 **Project: `LazyGenerator` — A coroutine-based sequence generator**
> - *Size: Small (~200 LOC)*
> - Implement a `Generator<T>` type with `co_yield`
> - Build lazy Fibonacci, prime sieve, and file-line-reader generators
> - Add a simple `Task<T>` type with `co_await` for async composition
> - **Covers:** `co_await`, `co_yield`, `co_return`, promise type, coroutine handle, generator pattern

### 1.7 Modules [C++20]
- [ ] **Should Know:** Module units, interface units, implementation units
- [ ] **Should Know:** `export`, `import`, module partitions
- [ ] **Should Know:** Modules vs headers — trade-offs, migration
- [ ] **Nice to Have:** Build system integration

> 🛠 **Project: `MathLib-Modules` — Refactor a math library to use modules**
> - *Size: Small (~150 LOC)*
> - Create a `math` module with interface/implementation units and partitions (`math:linear`, `math:stats`)
> - Set up CMake with module support; compare compile times vs header-based version
> - **Covers:** Module units, `export`/`import`, partitions, build system integration

### 1.8 Modern Vocabulary Types & Utilities [C++17/20/23]
- [ ] **Must Know:** `std::string_view` [C++17]
- [ ] **Must Know:** `std::span` [C++20]
- [ ] **Must Know:** Structured bindings [C++17]
- [ ] **Should Know:** `std::any` [C++17]
- [ ] **Should Know:** `std::filesystem` [C++17]
- [ ] **Should Know:** `std::chrono`
- [ ] **Should Know:** `std::format` [C++20], `std::print` [C++23]
- [ ] **Nice to Have:** `std::mdspan` [C++23]
- [ ] **Nice to Have:** `std::stacktrace` [C++23]

> 🛠 **Project: `MiniFileManager` — A CLI file manager**
> - *Size: Medium (~300 LOC)*
> - Use `std::filesystem` to list/copy/move/search files
> - Accept commands as `string_view`, parse with structured bindings
> - Display file sizes/dates with `std::chrono` and `std::format`
> - Use `std::span` to pass directory entry batches to display functions
> - **Covers:** `string_view`, `span`, structured bindings, `filesystem`, `chrono`, `format`

### 1.9 Containers & Data Structures
- [x] **Must Know:** `vector`, `array` — *Covered in `STL-IMPL/` (myInt) and `FunctionDynamics/vector-stackBehaviour.cpp`*
- [ ] **Must Know:** `deque`, `list`, `forward_list`
- [ ] **Must Know:** `map`, `set`, `unordered_map`, `unordered_set`
- [ ] **Must Know:** `string`, `string_view`
- [ ] **Should Know:** `flat_map`, `flat_set` [C++23]
- [ ] **Should Know:** Container adaptors: `stack`, `queue`, `priority_queue`
- [ ] **Should Know:** Node-based vs contiguous containers — performance trade-offs

> 🛠 **Project: `ContainerBenchmark` — Performance comparison tool**
> - *Size: Small (~250 LOC)*
> - Benchmark insert/find/erase on `vector`, `list`, `deque`, `map`, `unordered_map`, `set`
> - Use `std::chrono` for timing; output results as a table
> - Implement a simple LRU cache using `list` + `unordered_map`
> - **Covers:** All container types, container adaptors, node-based vs contiguous trade-offs

### ✅ Checklist – Core Language & STL
- [x] Value categories & move semantics mastered [C++11]
- [x] RAII & smart pointers — all three types understood and applied
- [x] Templates — basic class/function templates covered (advanced: SFINAE, variadic, concepts NOT yet)
- [x] Error handling — exceptions covered thoroughly (optional/variant/expected NOT yet)
- [ ] Ranges & algorithms [C++20] used in practice
- [ ] Coroutines [C++20] basics understood
- [ ] Modules [C++20] explored
- [ ] Modern vocabulary types used (`string_view`, `span`, `optional`, `variant`)

---

## 2. Concurrency & Parallelism

### 2.1 Threads & Thread Management [C++11+]
- [x] **Must Know:** `std::thread` — creation, joining, detaching — *Covered in `Concurrency/helloThreads.cpp`, `Section_One/joinAndDetach.cpp`*
- [ ] **Must Know:** `std::jthread` [C++20] — auto-joining, cooperative cancellation
- [x] **Must Know:** Thread arguments — passing by value, reference (`std::ref`), move — *Covered in `Section_One/PassingParamToTherads.cpp`, `problemsWithPassingParam.cpp`*
- [x] **Must Know:** Thread-local storage — `thread_local` — *Covered in `Section_One/threadLocal.cpp`*

### 2.2 Mutexes & Locking [C++11/14/17]
- [x] **Must Know:** `std::mutex`, `std::recursive_mutex` — *Covered in `Section_Two/mutex.cpp`*
- [x] **Must Know:** `std::lock_guard`, `std::unique_lock` — *Covered in `Section_Two/uniqueLocks.cpp`*
- [ ] **Must Know:** `std::scoped_lock` [C++17], `std::shared_mutex`, `std::shared_lock`
- [ ] **Should Know:** `std::call_once`, `std::once_flag`
- [x] **Should Know:** Lock ordering, deadlock avoidance strategies — *Covered in `Section_Two/deadLocks.cpp`*

> 🛠 **Project: `ReadWriteCache` — A thread-safe read-heavy cache**
> - *Size: Small (~200 LOC)*
> - Implement a concurrent cache with `shared_mutex` (many readers, exclusive writer)
> - Use `scoped_lock` for multi-lock operations, `call_once` for lazy initialization
> - **Covers:** `scoped_lock`, `shared_mutex`, `shared_lock`, `call_once`

### 2.3 Condition Variables & Synchronization [C++11/20]
- [x] **Must Know:** `std::condition_variable` — wait, notify_one, notify_all — *Covered in `Section_Three/conditionVariables.cpp`*
- [x] **Must Know:** Spurious wakeups, predicate-based waiting — *Covered in `Section_Three/introduction.cpp`*
- [ ] **Should Know:** `std::barrier`, `std::latch` [C++20]
- [ ] **Should Know:** `std::counting_semaphore`, `std::binary_semaphore` [C++20]

> 🛠 **Project: `ParallelMapReduce` — A multi-phase computation**
> - *Size: Small (~200 LOC)*
> - Split work into phases; use `std::latch` for one-shot synchronization and `std::barrier` for iterative phases
> - Use semaphores to limit concurrent access to a resource (e.g., max 3 DB connections)
> - **Covers:** `barrier`, `latch`, `counting_semaphore`, `binary_semaphore`

### 2.4 Atomics & Memory Model [C++11]
- [ ] **Must Know:** `std::atomic<T>` — load, store, exchange, compare_exchange
- [ ] **Must Know:** Memory ordering — `relaxed`, `acquire`, `release`, `seq_cst`
- [ ] **Should Know:** `std::atomic_ref` [C++20]
- [ ] **Should Know:** False sharing, cache line alignment
- [ ] **Nice to Have:** Lock-free data structures, ABA problem

> 🛠 **Project: `LockFreeCounter` — Atomic operations & a lock-free stack**
> - *Size: Medium (~350 LOC)*
> - Build a multi-threaded stats counter using `std::atomic` with different memory orderings
> - Benchmark `relaxed` vs `seq_cst` to observe performance differences
> - Implement a lock-free stack with `compare_exchange_weak`
> - Demonstrate false sharing and fix with `alignas(64)`
> - **Covers:** `atomic`, all memory orderings, `atomic_ref`, false sharing, lock-free structures

### 2.5 Futures, Promises & Async [C++11]
- [x] **Must Know:** `std::future`, `std::promise` — *Covered in `Section_Three/futures.cpp`*
- [x] **Must Know:** `std::async` — launch policies — *Covered in `Section_Three/async.cpp`*
- [ ] **Should Know:** `std::packaged_task`
- [ ] **Should Know:** Thread pools
- [ ] **Nice to Have:** Work stealing, fork-join patterns

> 🛠 **Project: `ThreadPool` — A general-purpose thread pool**
> - *Size: Medium (~300 LOC)*
> - Accept callables via `std::packaged_task`, return `std::future` for results
> - Support task priorities and graceful shutdown
> - Bonus: implement work-stealing between worker threads
> - **Covers:** `packaged_task`, thread pools, work stealing, `jthread` with stop tokens

### 2.6 Parallel STL [C++17]
- [ ] **Should Know:** Execution policies: `seq`, `par`, `par_unseq`, `unseq`
- [ ] **Should Know:** Parallel algorithms

> 🛠 **Project: `ImageProcessor` — Parallel image transformations**
> - *Size: Small (~200 LOC)*
> - Load a PPM image, apply grayscale/blur/edge-detect using `std::transform` and `std::for_each` with execution policies (`par`, `par_unseq`)
> - Compare sequential vs parallel performance
> - **Covers:** Execution policies, parallel algorithms

### 2.7 Coroutines vs Threads [C++20]
- [ ] **Should Know:** Cooperative vs preemptive multitasking trade-offs
- [ ] **Should Know:** When to use coroutines vs threads vs async I/O

### ✅ Checklist – Concurrency & Parallelism
- [x] Thread creation, joining, detaching — covered (NOT `jthread` [C++20])
- [x] Mutex hierarchy — `mutex`, `unique_lock` covered (`shared_mutex`, `scoped_lock` NOT yet)
- [x] Condition variables used correctly (predicate pattern)
- [ ] Atomics & memory ordering applied
- [x] Futures/promises/async patterns used
- [ ] Parallel STL applied with execution policies
- [x] Deadlock scenarios identified and prevented

---

## 3. Performance Engineering
- [ ] Profiling & Measurement — **Not Started**
- [ ] CPU Architecture & Optimization — **Not Started**
- [ ] Compiler Optimizations — **Not Started**
- [ ] SIMD & Vectorization — **Not Started**

> 🛠 **Project: `MatrixMul` — Optimized matrix multiplication**
> - *Size: Medium (~400 LOC)*
> - Naive → cache-friendly (loop tiling) → SIMD-intrinsics → compiler auto-vectorization
> - Profile with `perf`/`valgrind --tool=cachegrind`; analyze with `-O2` vs `-O3` vs `-march=native`
> - **Covers:** Profiling, cache optimization, compiler flags, SIMD basics

---

## 4. Memory Management
- [ ] Allocators & Memory Strategies — **Not Started**
- [ ] Memory Layout & Alignment — **Not Started**
- [ ] Memory Diagnostics — **Not Started**

> 🛠 **Project: `ArenaAllocator` — A custom memory arena**
> - *Size: Medium (~300 LOC)*
> - Implement a linear/arena allocator conforming to the `Allocator` concept
> - Use it with `std::vector<T, ArenaAlloc<T>>`
> - Add alignment support (`alignas`, `std::align`)
> - Run under AddressSanitizer and Valgrind to validate correctness
> - **Covers:** Custom allocators, memory layout, alignment, memory diagnostics

---

## 5. API & ABI Design
- [ ] Interface Design — **Not Started**
- [ ] ABI Stability & Versioning — **Not Started**
- [ ] Exception Safety & Contracts — **Not Started**

> 🛠 **Project: `PluginSystem` — A shared library plugin framework**
> - *Size: Medium (~400 LOC)*
> - Define a stable C ABI plugin interface with versioning
> - Use pImpl idiom to hide implementation details and maintain ABI stability
> - Document exception safety guarantees; use `noexcept` boundaries at ABI edges
> - Load plugins with `dlopen`/`dlsym`
> - **Covers:** Interface design, ABI stability, pImpl, exception safety, versioning

---

## 6. Tooling & Build Systems
- [ ] Compilers — **Not Started**
- [ ] Static Analysis & Formatting — **Not Started**
- [ ] Build Systems & Package Managers — **Not Started**

> 🛠 **Project: `CMakeStarter` — A modern CMake project template**
> - *Size: Small (~100 LOC config + existing code)*
> - Set up CMake with targets, presets, `FetchContent` for dependencies
> - Integrate `clang-tidy`, `clang-format`, and compiler warnings (`-Wall -Wextra -Werror`)
> - Add Conan/vcpkg for a third-party library
> - **Covers:** CMake, static analysis, formatting, package managers, compiler options

---

## 7. Testing & Quality
- [ ] Unit & Integration Testing — **Not Started**
- [ ] Advanced Testing — **Not Started**
- [ ] Test Infrastructure — **Not Started**

> 🛠 **Project: `TestThePool` — Unit-test the ThreadPool project**
> - *Size: Small (~250 LOC)*
> - Use Google Test + Google Mock for unit/integration tests
> - Add fuzz testing with libFuzzer for the ConfigParser
> - Set up CTest and code coverage with `gcov`/`lcov`
> - **Covers:** Unit testing, mocking, fuzz testing, coverage, CTest integration

---

## 8. Security & Reliability
- [ ] Undefined Behavior & Safety — **Not Started**
- [ ] Secure Coding Practices — **Not Started**
- [ ] Hardening — **Not Started**

> 🛠 **Project: `SafeBuffer` — A bounds-checked buffer class**
> - *Size: Small (~200 LOC)*
> - Implement a buffer with bounds checking, overflow protection, and sanitizer annotations
> - Compile with UBSan, ASan, and `-fstack-protector`
> - Write tests that intentionally trigger UB and verify sanitizers catch them
> - **Covers:** UB detection, secure coding, hardening flags, sanitizers

---

## 9. Architecture & Design

### 9.2 Design Patterns in C++
- [x] **Must Know:** RAII (as a pattern) — *Covered in `OOPS-COncepts/Classes/RAIIDestructor.cpp`*
- [ ] **Must Know:** pImpl
- [ ] **Must Know:** Observer, Strategy, Visitor (Observer covered in `DesignPatterns/Observer/`)
- [ ] **Should Know:** Builder, Factory, Singleton
- [ ] **Should Know:** Reactor/Proactor
- [ ] **Should Know:** Policy-based design
- [ ] **Nice to Have:** Type erasure patterns

> **Note:** SOLID principles and some design patterns are covered in the `DesignPatterns/` folder — see `design-patterns-covered.md` for full details.

> 🛠 **Project: `EventBus` — A type-safe event system**
> - *Size: Medium (~350 LOC)*
> - Use type erasure (`std::any` or `std::function`) for handlers
> - Implement Observer for subscriptions, Strategy for dispatch policies, Visitor for event processing
> - Use pImpl to hide internals; apply policy-based design for threading (single vs multi-threaded bus)
> - **Covers:** pImpl, Observer, Strategy, Visitor, type erasure, policy-based design

---

## 10. Cross-Platform & Systems
- [ ] Platform Abstractions — **Not Started**
- [ ] Systems Programming — **Not Started**

> 🛠 **Project: `MiniShell` — A simple cross-platform command shell**
> - *Size: Medium (~500 LOC)*
> - Implement command parsing, process spawning (`fork/exec` on Linux, `CreateProcess` on Windows)
> - Abstract platform differences behind interfaces; use `#ifdef` and CMake platform detection
> - Add pipe support and signal handling
> - **Covers:** Platform abstractions, process management, system calls, cross-platform build

---

## 11. Domain Libraries & Ecosystem
- [ ] Networking & I/O — **Not Started**
- [ ] Serialization — **Not Started**
- [ ] Utility Libraries — **Not Started**

> 🛠 **Project: `ChatServer` — A TCP chat application**
> - *Size: Medium (~400 LOC)*
> - Use Boost.Asio (or standalone asio) for async TCP I/O
> - Serialize messages with Protocol Buffers or nlohmann/json
> - Support multiple clients with async accept/read/write
> - **Covers:** Networking, async I/O, serialization, third-party libraries

---

## 12. DevEx & Scale
- [ ] Code Review & Collaboration — **Not Started**
- [ ] CI/CD & Infrastructure — **Not Started**

> 🛠 **Project: `CI-Pipeline` — Set up CI/CD for the above projects**
> - *Size: Small (config files)*
> - GitHub Actions workflow: build matrix (GCC/Clang, Debug/Release), run tests, coverage upload
> - Add pre-commit hooks for `clang-format` and `clang-tidy`
> - **Covers:** CI/CD, code review automation, build infrastructure

---

## Additional Topics Covered (Not in Scope but Valuable)

### OOP Foundations (from `CPP_Concepts/OOPS-COncepts/`)
- [x] Classes — constructors, destructors, member init lists, static members, const classes, `this` pointer, friend classes, RAII, anonymous objects, delegating constructors
- [x] Inheritance — access specifiers, order of instantiation, overriding, multiple inheritance, hiding inherited functionality
- [x] Virtual Functions — early/late binding, vtable, virtual destructors, pure virtual/abstract/interfaces, covariant return types, object slicing, dynamic casts
- [x] Operator Overloading — member/friend/normal function overloading, copy constructor, shallow/deep copy, assignment, I/O, subscript, parenthesis, typecast, comparison, increment/decrement, templates

### Scope, Duration & Linkage (from `CPP_Concepts/Scope-Duration-Linkage/`)
- [x] Local variables, global variables, variable shadowing, namespaces, internal/external linkage, storage classes

### Type Conversions & Deductions (from `CPP_Concepts/TypeConversions-aliasingandDeductions/`)
- [x] Implicit/explicit conversions, narrowing, promotions, arithmetic conversion, type deduction (auto, functions), typedefs & aliases, function overloading

### Function Dynamics (from `CPP_Concepts/FunctionDynamics/`)
- [x] Function pointers, lambdas, lambda captures, anonymous functions, stack/heap, command-line arguments, ellipses

### Object Relationships (from `CPP_Concepts/ObjectRelationships/`)
- [x] Association, aggregation, composition, dependencies, initializer lists

### Effective C++/STL/EMC++ (from `CPP_Concepts/EffectiveC++/`, `EffectiveSTL/`, `EMC++/`)
- [x] Effective C++ Items 1–7 covered
- [x] Effective STL Items 2–8 covered
- [x] Effective Modern C++ Items 1, 7, 8 covered

### Compound Types (from `CPP_Concepts/Compoundtypes-references-and-pointers/`)
- [x] L-value and R-value expressions, references and pointers introduction

---

## 📈 Overall Progress Estimate

| Priority Level | Covered | Total (est.) | Percentage |
|---------------|---------|--------------|------------|
| Must Know | ~18 | ~55 | ~33% |
| Should Know | ~3 | ~50 | ~6% |
| Nice to Have | 0 | ~20 | 0% |
| **Overall** | **~21** | **~125** | **~17%** |

> **Key Gaps:** Modern C++ (C++17/20/23 features), Atomics & Memory Model, Performance Engineering, Memory Management, Tooling, Testing, Security, API/ABI Design. Strong foundation in OOP, basic concurrency, move semantics, and smart pointers.
