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

### 1.2 RAII & Ownership Models [C++11+]
- [x] **Must Know:** RAII principle — *Covered in `OOPS-COncepts/Classes/RAIIDestructor.cpp`*
- [x] **Must Know:** Scope-based resource management — *Covered in `Scope-Duration-Linkage/` folder*
- [x] **Must Know:** `std::unique_ptr` — sole ownership, custom deleters — *Covered in `MoveSemantics-SmartPointers/unique-pointer.cpp`*
- [x] **Must Know:** `std::shared_ptr` — shared ownership, reference counting — *Covered in `MoveSemantics-SmartPointers/shared-ptr.cpp`*
- [x] **Must Know:** `std::weak_ptr` — breaking cycles, observer pattern — *Covered in `MoveSemantics-SmartPointers/weak-ptr-issues-with-sharedptr.cpp`*
- [ ] **Should Know:** Aliasing constructor of `shared_ptr`
- [ ] **Should Know:** `enable_shared_from_this`
- [ ] **Nice to Have:** Custom allocators for smart pointers

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

### 1.4 Error Handling [C++11/17/23]
- [x] **Must Know:** Exceptions — throw, catch, exception hierarchy, `noexcept` — *Covered in `Exceptions/` folder (8+ files: basics, stack unwinding, rethrow, no-except, destructors, class/inheritance, function try block, catch-all)*
- [ ] **Must Know:** `std::optional` [C++17] — nullable value semantics
- [ ] **Must Know:** `std::variant` [C++17] — type-safe union, `std::visit`
- [ ] **Must Know:** Exception safety guarantees (basic, strong, nothrow)
- [ ] **Should Know:** `std::expected` [C++23]
- [ ] **Should Know:** Error codes vs exceptions — trade-offs
- [ ] **Should Know:** `std::error_code`, `std::error_category` [C++11]
- [ ] **Nice to Have:** Monadic operations on `optional`/`expected` [C++23]

### 1.5 Ranges, Iterators & Algorithms [C++17/20/23]
- [ ] **Must Know:** Iterator categories
- [ ] **Must Know:** STL algorithms — sort, find, transform, accumulate, etc.
- [ ] **Must Know:** Range-based for loops
- [ ] **Must Know:** Ranges library [C++20]
- [ ] **Should Know:** Projections [C++20]
- [ ] **Should Know:** `std::ranges::to` [C++23]
- [ ] **Should Know:** Custom iterators, sentinel types [C++20]
- [ ] **Nice to Have:** Range adaptors closure objects

### 1.6 Coroutines [C++20]
- [ ] **Should Know:** `co_await`, `co_yield`, `co_return`
- [ ] **Should Know:** Promise type, coroutine handle, coroutine frame
- [ ] **Should Know:** Generator pattern, lazy evaluation
- [ ] **Nice to Have:** Async coroutine patterns, cancellation
- [ ] **Nice to Have:** Coroutine-based task systems

### 1.7 Modules [C++20]
- [ ] **Should Know:** Module units, interface units, implementation units
- [ ] **Should Know:** `export`, `import`, module partitions
- [ ] **Should Know:** Modules vs headers — trade-offs, migration
- [ ] **Nice to Have:** Build system integration

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

### 1.9 Containers & Data Structures
- [x] **Must Know:** `vector`, `array` — *Covered in `STL-IMPL/` (myInt) and `FunctionDynamics/vector-stackBehaviour.cpp`*
- [ ] **Must Know:** `deque`, `list`, `forward_list`
- [ ] **Must Know:** `map`, `set`, `unordered_map`, `unordered_set`
- [ ] **Must Know:** `string`, `string_view`
- [ ] **Should Know:** `flat_map`, `flat_set` [C++23]
- [ ] **Should Know:** Container adaptors: `stack`, `queue`, `priority_queue`
- [ ] **Should Know:** Node-based vs contiguous containers — performance trade-offs

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

### 2.3 Condition Variables & Synchronization [C++11/20]
- [x] **Must Know:** `std::condition_variable` — wait, notify_one, notify_all — *Covered in `Section_Three/conditionVariables.cpp`*
- [x] **Must Know:** Spurious wakeups, predicate-based waiting — *Covered in `Section_Three/introduction.cpp`*
- [ ] **Should Know:** `std::barrier`, `std::latch` [C++20]
- [ ] **Should Know:** `std::counting_semaphore`, `std::binary_semaphore` [C++20]

### 2.4 Atomics & Memory Model [C++11]
- [ ] **Must Know:** `std::atomic<T>` — load, store, exchange, compare_exchange
- [ ] **Must Know:** Memory ordering — `relaxed`, `acquire`, `release`, `seq_cst`
- [ ] **Should Know:** `std::atomic_ref` [C++20]
- [ ] **Should Know:** False sharing, cache line alignment
- [ ] **Nice to Have:** Lock-free data structures, ABA problem

### 2.5 Futures, Promises & Async [C++11]
- [x] **Must Know:** `std::future`, `std::promise` — *Covered in `Section_Three/futures.cpp`*
- [x] **Must Know:** `std::async` — launch policies — *Covered in `Section_Three/async.cpp`*
- [ ] **Should Know:** `std::packaged_task`
- [ ] **Should Know:** Thread pools
- [ ] **Nice to Have:** Work stealing, fork-join patterns

### 2.6 Parallel STL [C++17]
- [ ] **Should Know:** Execution policies: `seq`, `par`, `par_unseq`, `unseq`
- [ ] **Should Know:** Parallel algorithms

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

---

## 4. Memory Management
- [ ] Allocators & Memory Strategies — **Not Started**
- [ ] Memory Layout & Alignment — **Not Started**
- [ ] Memory Diagnostics — **Not Started**

---

## 5. API & ABI Design
- [ ] Interface Design — **Not Started**
- [ ] ABI Stability & Versioning — **Not Started**
- [ ] Exception Safety & Contracts — **Not Started**

---

## 6. Tooling & Build Systems
- [ ] Compilers — **Not Started**
- [ ] Static Analysis & Formatting — **Not Started**
- [ ] Build Systems & Package Managers — **Not Started**

---

## 7. Testing & Quality
- [ ] Unit & Integration Testing — **Not Started**
- [ ] Advanced Testing — **Not Started**
- [ ] Test Infrastructure — **Not Started**

---

## 8. Security & Reliability
- [ ] Undefined Behavior & Safety — **Not Started**
- [ ] Secure Coding Practices — **Not Started**
- [ ] Hardening — **Not Started**

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

---

## 10. Cross-Platform & Systems
- [ ] Platform Abstractions — **Not Started**
- [ ] Systems Programming — **Not Started**

---

## 11. Domain Libraries & Ecosystem
- [ ] Networking & I/O — **Not Started**
- [ ] Serialization — **Not Started**
- [ ] Utility Libraries — **Not Started**

---

## 12. DevEx & Scale
- [ ] Code Review & Collaboration — **Not Started**
- [ ] CI/CD & Infrastructure — **Not Started**

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
