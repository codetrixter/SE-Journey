# Design Patterns — Coverage Analysis

> **Last Analyzed:** April 7, 2026
> **Source Folder:** `DesignPatterns/`
> **Reference:** `design-patterns-scope.md`

---

## 📊 Coverage Summary

| Section | Must Know | Should Know | Nice to Have | Status |
|---------|-----------|-------------|--------------|--------|
| Creational Patterns | 🟡 Partial | 🔴 Not Started | 🔴 Not Started | In Progress |
| Structural Patterns | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Behavioral Patterns | 🟡 Partial | 🔴 Not Started | 🔴 Not Started | In Progress |
| Concurrency Patterns | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Architectural Patterns | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Modern C++ Patterns | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Anti-Patterns & Misuse | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| SOLID Principles | 🟢 Done | 🟡 Partial | N/A | Mostly Complete |

---

## 1. Creational Patterns

### 1.1 Singleton
- [x] **Must Know:** Intent — ensure a class has only one instance with global access — *Covered in `Singleton/singletonPattern.cpp`*
- [x] **Must Know:** Thread-safe implementations — Meyers Singleton — *Covered in `Singleton/singletonPattern.cpp`*
- [ ] **Must Know:** Anti-pattern arguments — hidden dependencies, testing difficulty
- [ ] **Should Know:** Dependency injection as alternative
- [ ] **Should Know:** Singleton registry, monostate alternative
- [ ] **Nice to Have:** Singleton in shared libraries, DLL boundary issues

### 1.2 Factory Method
- [x] **Must Know:** Intent — defer instantiation to subclasses — *Covered in `Factory/factoyPatterns.cpp`*
- [x] **Must Know:** Virtual constructors, parameterized factories — *Covered in `Factory/factoyPatterns.cpp`*
- [ ] **Should Know:** Factory registry patterns (self-registering factories)
- [ ] **Should Know:** `std::unique_ptr` as factory return type
- [ ] **Nice to Have:** Template-based factory methods

### 1.3 Abstract Factory
- [ ] **Must Know:** Intent — create families of related objects
- [ ] **Must Know:** Platform-independent creation
- [ ] **Should Know:** Factory of factories
- [ ] **Should Know:** Combining with Singleton

### 1.4 Builder
- [ ] **Must Know:** Intent — separate construction from representation
- [ ] **Must Know:** Step-by-step construction, fluent interfaces
- [ ] **Should Know:** Director vs self-building
- [ ] **Should Know:** Builder + move semantics
- [ ] **Nice to Have:** Compile-time builder validation

### 1.5 Prototype
- [ ] **Should Know:** Intent — clone existing objects
- [ ] **Should Know:** Deep copy, clone registries
- [ ] **Should Know:** Polymorphic copying in C++
- [ ] **Nice to Have:** Copy-on-write optimization

### 1.6 Object Pool
- [ ] **Should Know:** Intent — reuse expensive-to-create objects
- [ ] **Should Know:** Thread-safe pool implementations
- [ ] **Should Know:** Connection pools, thread pools
- [ ] **Nice to Have:** Growing/shrinking pool strategies

### ✅ Checklist – Creational Patterns
- [x] Singleton — thread-safe implementation covered
- [x] Factory Method — parameterized factory implemented
- [ ] Abstract Factory — family-of-products design applied
- [ ] Builder — fluent builder with validation implemented
- [ ] Prototype — polymorphic clone in C++ implemented
- [ ] Object Pool — thread-safe pool designed

---

## 2. Structural Patterns

### 2.1 Adapter (Class & Object)
- [ ] **Must Know:** Intent — convert interface of a class to one clients expect
- [ ] **Must Know:** Class adapter (inheritance) vs Object adapter (composition)
- [ ] **Should Know:** Legacy integration use cases
- [ ] **Should Know:** Compile-time adapter (templates) vs runtime adapter (virtual)

### 2.2 Bridge
- [ ] **Must Know:** Intent — decouple abstraction from implementation
- [ ] **Must Know:** pImpl idiom in C++
- [ ] **Should Know:** Bridge vs Adapter
- [ ] **Should Know:** Runtime implementation switching

### 2.3 Composite
- [ ] **Must Know:** Intent — compose objects into tree structures
- [ ] **Must Know:** Recursive composition
- [ ] **Should Know:** File system / UI widget tree examples
- [ ] **Should Know:** Safety vs transparency trade-off

### 2.4 Decorator
- [ ] **Must Know:** Intent — attach additional responsibilities dynamically
- [ ] **Must Know:** Streaming/IO wrappers
- [ ] **Should Know:** Decorator vs inheritance explosion
- [ ] **Should Know:** Decorator chains
- [ ] **Nice to Have:** Compile-time decorators (CRTP mixin)

### 2.5 Facade
- [ ] **Must Know:** Intent — simplified interface to complex subsystem
- [ ] **Must Know:** API gateway pattern
- [ ] **Should Know:** Facade vs Mediator

### 2.6 Flyweight
- [ ] **Should Know:** Intent — share common state to reduce memory
- [ ] **Should Know:** Intrinsic vs extrinsic state
- [ ] **Should Know:** String interning
- [ ] **Nice to Have:** Flyweight factory

### 2.7 Proxy
- [ ] **Must Know:** Intent — provide a surrogate or placeholder
- [ ] **Must Know:** Smart pointers as proxy
- [ ] **Should Know:** Virtual proxy, Protection proxy, Caching proxy
- [ ] **Nice to Have:** Remote proxy

### ✅ Checklist – Structural Patterns
- [ ] Adapter — class & object variants implemented
- [ ] Bridge / pImpl — ABI-stable interface designed
- [ ] Composite — tree structure built
- [ ] Decorator — dynamic behavior extension applied
- [ ] Facade — subsystem simplification implemented
- [ ] Flyweight — memory optimization applied
- [ ] Proxy — at least 2 proxy variants implemented

---

## 3. Behavioral Patterns

### 3.1 Chain of Responsibility
- [ ] **Must Know:** Intent — pass request along a chain of handlers
- [ ] **Should Know:** Middleware patterns, logging pipelines
- [ ] **Should Know:** Event bubbling

### 3.2 Command
- [ ] **Must Know:** Intent — encapsulate a request as an object
- [ ] **Must Know:** Undo/redo implementation
- [ ] **Should Know:** Macro commands, transactional behavior
- [ ] **Should Know:** Command queues, deferred execution

### 3.3 Iterator
- [ ] **Must Know:** Intent — sequential access without exposing underlying representation
- [ ] **Must Know:** C++ iterators, iterator categories
- [ ] **Should Know:** External vs internal iteration
- [ ] **Should Know:** C++20 Ranges as modern iterator evolution
- [ ] **Nice to Have:** Generator pattern with coroutines

### 3.4 Mediator
- [ ] **Should Know:** Intent — reduce direct communication between objects
- [ ] **Should Know:** Event bus / message broker
- [ ] **Should Know:** GUI component coordination
- [ ] **Nice to Have:** Mediator vs Observer

### 3.5 Memento
- [ ] **Should Know:** Intent — capture and restore object state
- [ ] **Should Know:** Undo stacks, checkpointing
- [ ] **Should Know:** Serialization considerations

### 3.6 Observer
- [x] **Must Know:** Intent — one-to-many dependency for state changes — *Covered in `Observer/` folder (main.cpp, observable.hpp, observer.hpp)*
- [x] **Must Know:** Publish-subscribe pattern — *Covered in `Observer/observable.hpp`*
- [ ] **Must Know:** Signal-slot mechanism (Qt-style)
- [ ] **Should Know:** Weak references to avoid leaks
- [ ] **Should Know:** Thread-safe observer lists
- [ ] **Nice to Have:** Reactive extensions concepts

### 3.7 State
- [ ] **Must Know:** Intent — alter behavior when internal state changes
- [ ] **Must Know:** Finite state machines
- [ ] **Should Know:** State vs Strategy
- [ ] **Should Know:** State transition tables
- [ ] **Nice to Have:** Hierarchical state machines

### 3.8 Strategy
- [ ] **Must Know:** Intent — define a family of interchangeable algorithms
- [ ] **Must Know:** Policy-based design in C++
- [ ] **Should Know:** `std::function` for runtime strategy
- [ ] **Should Know:** Comparators, sorting strategies

### 3.9 Template Method
- [ ] **Must Know:** Intent — define algorithm skeleton, defer steps to subclasses
- [ ] **Must Know:** NVI (Non-Virtual Interface) idiom
- [ ] **Should Know:** Hook methods, optional steps

### 3.10 Visitor
- [ ] **Should Know:** Intent — add operations without modifying element classes
- [ ] **Should Know:** Double dispatch mechanism
- [ ] **Should Know:** `std::variant` + `std::visit` as modern alternative
- [ ] **Nice to Have:** Acyclic Visitor

### 3.11 Interpreter
- [ ] **Nice to Have:** Intent — define grammar representation and interpreter

### 3.12 Null Object
- [ ] **Should Know:** Intent — provide default "do nothing" behavior
- [ ] **Should Know:** `std::optional` as alternative

### ✅ Checklist – Behavioral Patterns
- [x] Observer — publish-subscribe implemented
- [ ] Strategy — compile-time (policy) and runtime variants
- [ ] Command — undo/redo system built
- [ ] State — FSM implemented
- [ ] Template Method / NVI — applied
- [ ] Visitor — `std::variant` + `std::visit` applied
- [ ] Iterator — custom iterator or range adaptor written
- [ ] Chain of Responsibility — handler chain designed

---

## 4. Concurrency Patterns

### 4.1 Active Object
- [ ] **Should Know:** Intent — decouple method execution from invocation
- [ ] **Should Know:** Message passing, async interfaces
- [ ] **Should Know:** Command queue + worker thread

### 4.2 Monitor Object
- [ ] **Must Know:** Intent — synchronize access through encapsulated locking
- [ ] **Must Know:** Mutex + condition variable encapsulation
- [ ] **Should Know:** Monitor vs raw mutex

### 4.3 Half-Sync/Half-Async
- [ ] **Should Know:** Intent — separate sync and async processing layers
- [ ] **Should Know:** Async I/O with synchronous business logic
- [ ] **Nice to Have:** Queue-based decoupling

### 4.4 Reactor & Proactor
- [ ] **Must Know:** Reactor — synchronous event demultiplexing
- [ ] **Must Know:** Proactor — asynchronous completion handlers
- [ ] **Should Know:** Trade-offs: reactor vs proactor

### 4.5 Thread-Safe Singleton
- [ ] **Must Know:** Meyers Singleton (C++11 thread-safe static local)
- [ ] **Must Know:** `std::call_once` for lazy initialization
- [ ] **Should Know:** Double-checked locking — why it's broken without atomics
- [ ] **Should Know:** Atomic singletons

### 4.6 Producer-Consumer
- [ ] **Must Know:** Bounded buffer with mutex + condition variable
- [ ] **Must Know:** Work queues, thread pool task submission
- [ ] **Should Know:** Back-pressure mechanisms
- [ ] **Should Know:** Lock-free producer-consumer queues

> **Note:** Thread-safe queue and condition variable patterns are partially covered in `Concurrency/Section_Three/` — see `Cpp-concepts-covered.md` for details.

### ✅ Checklist – Concurrency Patterns
- [ ] Monitor Object — encapsulated synchronization implemented
- [ ] Reactor / Proactor — async I/O pattern applied
- [ ] Producer-Consumer — bounded buffer with proper signaling
- [ ] Active Object — message-based async interface built
- [ ] Thread-safe initialization — `call_once` / Meyers Singleton used

---

## 5. Architectural Patterns

### 5.1 MVC / MVP / MVVM
- [ ] **Must Know:** Separation of concerns in UI architecture
- [ ] **Should Know:** Trade-offs between MVC, MVP, MVVM
- [ ] **Should Know:** Testability improvements

### 5.2 Repository Pattern
- [ ] **Should Know:** Data access abstraction
- [ ] **Should Know:** Unit of Work, persistence ignorance

### 5.3 Service Locator vs Dependency Injection
- [x] **Must Know:** Dependency Injection — *Covered in `SOLID-DP/dependencyInversion.cpp`*
- [ ] **Must Know:** Trade-offs: DI vs Service Locator
- [ ] **Should Know:** Compile-time DI in C++
- [ ] **Nice to Have:** DI containers in C++

### 5.4 Event Sourcing & CQRS
- [ ] **Should Know:** Event stores, event replay
- [ ] **Should Know:** CQRS
- [ ] **Nice to Have:** Eventual consistency handling

### 5.5 Layered Architecture
- [ ] **Must Know:** Presentation → Business Logic → Data Access
- [ ] **Must Know:** Dependency rules

### 5.6 Microkernel / Plugin
- [ ] **Should Know:** Stable core with extensible plugins
- [ ] **Should Know:** Dynamic loading
- [ ] **Should Know:** Plugin interfaces, versioning

### 5.7 Pipe and Filter
- [ ] **Should Know:** Data transformation pipelines
- [ ] **Should Know:** Unix philosophy
- [ ] **Should Know:** C++20 Ranges as pipe-and-filter

### ✅ Checklist – Architectural Patterns
- [x] DI — dependency inversion principle covered
- [ ] Layered architecture — dependency rules enforced
- [ ] Plugin architecture — dynamic loading implemented
- [ ] Pipe and Filter — pipeline built
- [ ] CQRS / Event Sourcing concepts understood

---

## 6. Modern C++ & Pattern Evolution

### 6.1 CRTP
- [ ] **Must Know:** Static polymorphism
- [ ] **Should Know:** Mixin classes
- [ ] **Should Know:** CRTP vs concepts [C++20]

### 6.2 Policy-Based Design
- [ ] **Must Know:** Compile-time strategy selection
- [ ] **Should Know:** Alexandrescu-style designs
- [ ] **Should Know:** `std::allocator` as policy example

### 6.3 Type Erasure
- [ ] **Must Know:** `std::function` — callable type erasure
- [ ] **Should Know:** `std::any` [C++17]
- [ ] **Should Know:** Custom type erasure
- [ ] **Nice to Have:** Sean Parent's technique

### 6.4 RAII as a Pattern
- [x] **Must Know:** Resource management via scope — *Covered in `CPP_Concepts/OOPS-COncepts/Classes/RAIIDestructor.cpp`*
- [ ] **Must Know:** Scope guards, lock guards, file handles
- [ ] **Should Know:** Custom RAII wrappers for C APIs

### 6.5 Expression Templates
- [ ] **Nice to Have:** Lazy evaluation for expression trees
- [ ] **Nice to Have:** DSL construction

### 6.6 Monostate vs Singleton
- [ ] **Should Know:** Shared state through static members
- [ ] **Should Know:** When monostate is preferred

### ✅ Checklist – Modern C++ Patterns
- [ ] CRTP — static polymorphism implemented
- [ ] Policy-based design — template policies applied
- [ ] Type erasure — custom type-erased wrapper built
- [x] RAII — destructor-based resource management covered
- [ ] Expression templates explored

---

## 7. Anti-Patterns & Pattern Misuse
- [ ] **Must Know:** Over-engineering / YAGNI — **Not Started**
- [ ] **Must Know:** God Object / Blob — **Not Started**
- [ ] **Should Know:** Spaghetti / Lasagna Code — **Not Started**
- [ ] **Should Know:** Golden Hammer — **Not Started**
- [ ] **Should Know:** Lava Flow — **Not Started**
- [ ] **Must Know:** When NOT to use a pattern — **Not Started**

### ✅ Checklist – Anti-Patterns
- [ ] Can identify over-engineering in code reviews
- [ ] God Object detection and splitting strategies known
- [ ] "When NOT to use" articulated for each major pattern
- [ ] Codebase audit for anti-patterns completed

---

## 8. SOLID Principles in Practice

### 8.1 Single Responsibility Principle (SRP)
- [x] **Must Know:** One reason to change per class — *Covered in `SOLID-DP/SingleResposibility.cpp`*
- [ ] **Must Know:** Cohesion metrics, class splitting strategies
- [ ] **Should Know:** SRP applied to functions and modules too

### 8.2 Open/Closed Principle (OCP)
- [x] **Must Know:** Open for extension, closed for modification — *Covered in `SOLID-DP/open-closed.cpp`*
- [ ] **Must Know:** Extension points: virtual methods, templates, callbacks
- [ ] **Should Know:** Plugin architecture as OCP application

### 8.3 Liskov Substitution Principle (LSP)
- [x] **Must Know:** Subtypes must be substitutable for base types — *Covered in `SOLID-DP/listkov_substitution.cpp`*
- [ ] **Must Know:** Behavioral subtyping, contract adherence
- [ ] **Should Know:** Invariant, precondition, postcondition rules
- [ ] **Should Know:** Classic violations: Square/Rectangle problem

### 8.4 Interface Segregation Principle (ISP)
- [x] **Must Know:** Clients should not depend on methods they don't use — *Covered in `SOLID-DP/interface-segregation.cpp`*
- [ ] **Should Know:** Fat interfaces → role-based interfaces
- [ ] **Should Know:** C++ pure virtual design, multiple inheritance of interfaces

### 8.5 Dependency Inversion Principle (DIP)
- [x] **Must Know:** Depend on abstractions, not concretions — *Covered in `SOLID-DP/dependencyInversion.cpp`*
- [ ] **Must Know:** Constructor injection, interface-based programming
- [ ] **Should Know:** Compile-time DI via templates/concepts [C++20]

### ✅ Checklist – SOLID Principles
- [x] SRP — single responsibility implemented
- [x] OCP — open/closed principle implemented
- [x] LSP — Liskov substitution implemented
- [x] ISP — interface segregation implemented
- [x] DIP — dependency inversion implemented

---

## 📈 Overall Progress Estimate

| Priority Level | Covered | Total (est.) | Percentage |
|---------------|---------|--------------|------------|
| Must Know | ~12 | ~45 | ~27% |
| Should Know | ~1 | ~45 | ~2% |
| Nice to Have | 0 | ~15 | 0% |
| **Overall** | **~13** | **~105** | **~12%** |

> **Key Gaps:** All Structural Patterns, most Behavioral Patterns (only Observer covered), all Concurrency Patterns, Architectural Patterns, Modern C++ Patterns (CRTP, Policy-based, Type Erasure), Anti-Patterns awareness. **Strengths:** SOLID principles fully covered, Singleton, Factory, and Observer implemented.
