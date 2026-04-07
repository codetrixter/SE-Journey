# Design Patterns — Mastery Scope for 10+ Years Experience

---

## 📊 Master Progress Tracker

| Section | Must Know Done | Should Know Done | Nice to Have Done | Last Reviewed | Notes |
|----------------------------|----------------|------------------|-------------------|---------------|-------|
| Creational Patterns | | | | | |
| Structural Patterns | | | | | |
| Behavioral Patterns | | | | | |
| Concurrency Patterns | | | | | |
| Architectural Patterns | | | | | |
| Modern C++ Patterns | | | | | |
| Anti-Patterns & Misuse | | | | | |
| SOLID Principles | | | | | |

---

## Table of Contents

1. [Creational Patterns](#1-creational-patterns)
2. [Structural Patterns](#2-structural-patterns)
3. [Behavioral Patterns](#3-behavioral-patterns)
4. [Concurrency Patterns](#4-concurrency-patterns)
5. [Architectural Patterns](#5-architectural-patterns)
6. [Modern C++ & Pattern Evolution](#6-modern-c--pattern-evolution)
7. [Anti-Patterns & Pattern Misuse](#7-anti-patterns--pattern-misuse)
8. [SOLID Principles in Practice](#8-solid-principles-in-practice)

---

## 1. Creational Patterns

### 1.1 Singleton
- **Must Know:** Intent — ensure a class has only one instance with global access
- **Must Know:** Thread-safe implementations — Meyers Singleton (C++11 magic statics)
- **Must Know:** Anti-pattern arguments — hidden dependencies, testing difficulty
- **Should Know:** Dependency injection as alternative
- **Should Know:** Singleton registry, monostate alternative
- **Nice to Have:** Singleton in shared libraries, DLL boundary issues

### 1.2 Factory Method
- **Must Know:** Intent — defer instantiation to subclasses
- **Must Know:** Virtual constructors, parameterized factories
- **Should Know:** Factory registry patterns (self-registering factories)
- **Should Know:** `std::unique_ptr` as factory return type
- **Nice to Have:** Template-based factory methods

### 1.3 Abstract Factory
- **Must Know:** Intent — create families of related objects without specifying concrete classes
- **Must Know:** Platform-independent creation (e.g., UI toolkit factories)
- **Should Know:** Factory of factories
- **Should Know:** Combining with Singleton for global factory access

### 1.4 Builder
- **Must Know:** Intent — separate construction from representation
- **Must Know:** Step-by-step construction, fluent interfaces
- **Should Know:** Director vs self-building (director-less builder)
- **Should Know:** Builder + move semantics for efficiency
- **Nice to Have:** Compile-time builder validation (template-based)

### 1.5 Prototype
- **Should Know:** Intent — clone existing objects for new instances
- **Should Know:** Deep copy, clone registries
- **Should Know:** Polymorphic copying in C++ (`virtual clone()`)
- **Nice to Have:** Copy-on-write optimization

### 1.6 Object Pool
- **Should Know:** Intent — reuse expensive-to-create objects
- **Should Know:** Thread-safe pool implementations
- **Should Know:** Connection pools, thread pools
- **Nice to Have:** Growing/shrinking pool strategies

### ✅ Checklist – Creational Patterns
- [ ] Singleton — thread-safe implementation mastered, anti-pattern trade-offs understood
- [ ] Factory Method — parameterized factory with registry implemented
- [ ] Abstract Factory — family-of-products design applied
- [ ] Builder — fluent builder with validation implemented
- [ ] Prototype — polymorphic clone in C++ implemented
- [ ] Object Pool — thread-safe pool designed

---

## 2. Structural Patterns

### 2.1 Adapter (Class & Object)
- **Must Know:** Intent — convert interface of a class to one clients expect
- **Must Know:** Class adapter (inheritance) vs Object adapter (composition)
- **Should Know:** Legacy integration use cases
- **Should Know:** Compile-time adapter (templates) vs runtime adapter (virtual)

### 2.2 Bridge
- **Must Know:** Intent — decouple abstraction from implementation
- **Must Know:** pImpl idiom in C++ — ABI stability, compile-time firewall
- **Should Know:** Bridge vs Adapter — when to use which
- **Should Know:** Runtime implementation switching

### 2.3 Composite
- **Must Know:** Intent — compose objects into tree structures, treat uniformly
- **Must Know:** Recursive composition, `shared_ptr` for shared children
- **Should Know:** File system / UI widget tree examples
- **Should Know:** Safety vs transparency trade-off (type checking at compile vs runtime)

### 2.4 Decorator
- **Must Know:** Intent — attach additional responsibilities dynamically
- **Must Know:** Streaming/IO wrappers (classic use case)
- **Should Know:** Decorator vs inheritance explosion
- **Should Know:** Decorator chains, ordering effects
- **Nice to Have:** Compile-time decorators (CRTP mixin)

### 2.5 Facade
- **Must Know:** Intent — provide a simplified interface to a complex subsystem
- **Must Know:** API gateway pattern, layered architecture boundaries
- **Should Know:** Facade vs Mediator — scope differences

### 2.6 Flyweight
- **Should Know:** Intent — share common state to reduce memory
- **Should Know:** Intrinsic vs extrinsic state separation
- **Should Know:** String interning, immutable shared objects
- **Nice to Have:** Flyweight factory, thread-safety considerations

### 2.7 Proxy
- **Must Know:** Intent — provide a surrogate or placeholder
- **Must Know:** Smart pointers as proxy (reference counting)
- **Should Know:** Virtual proxy (lazy initialization)
- **Should Know:** Protection proxy (access control)
- **Should Know:** Caching proxy, logging proxy
- **Nice to Have:** Remote proxy (distributed objects)

### ✅ Checklist – Structural Patterns
- [ ] Adapter — class & object variants implemented
- [ ] Bridge / pImpl — ABI-stable interface designed
- [ ] Composite — tree structure with uniform interface built
- [ ] Decorator — dynamic behavior extension applied
- [ ] Facade — subsystem simplification implemented
- [ ] Flyweight — memory optimization with shared state applied
- [ ] Proxy — at least 2 proxy variants implemented

---

## 3. Behavioral Patterns

### 3.1 Chain of Responsibility
- **Must Know:** Intent — pass request along a chain of handlers
- **Should Know:** Middleware patterns, logging pipelines
- **Should Know:** Event bubbling in UI frameworks

### 3.2 Command
- **Must Know:** Intent — encapsulate a request as an object
- **Must Know:** Undo/redo implementation
- **Should Know:** Macro commands, transactional behavior
- **Should Know:** Command queues, deferred execution

### 3.3 Iterator
- **Must Know:** Intent — sequential access without exposing underlying representation
- **Must Know:** C++ iterators, iterator categories, range-based for
- **Should Know:** External vs internal iteration
- **Should Know:** C++20 Ranges as modern iterator evolution
- **Nice to Have:** Generator pattern with coroutines [C++20]

### 3.4 Mediator
- **Should Know:** Intent — reduce direct communication between objects
- **Should Know:** Event bus / message broker
- **Should Know:** GUI component coordination
- **Nice to Have:** Mediator vs Observer — when to use which

### 3.5 Memento
- **Should Know:** Intent — capture and restore object state
- **Should Know:** Undo stacks, checkpointing
- **Should Know:** Serialization considerations, caretaker management

### 3.6 Observer
- **Must Know:** Intent — one-to-many dependency for state changes
- **Must Know:** Publish-subscribe pattern
- **Must Know:** Signal-slot mechanism (Qt-style)
- **Should Know:** Weak references to avoid leaks
- **Should Know:** Thread-safe observer lists
- **Nice to Have:** Reactive extensions concepts

### 3.7 State
- **Must Know:** Intent — alter behavior when internal state changes
- **Must Know:** Finite state machines
- **Should Know:** State vs Strategy — key differences
- **Should Know:** State transition tables
- **Nice to Have:** Hierarchical state machines

### 3.8 Strategy
- **Must Know:** Intent — define a family of interchangeable algorithms
- **Must Know:** Policy-based design in C++ (compile-time strategy)
- **Should Know:** `std::function` for runtime strategy
- **Should Know:** Comparators, sorting strategies

### 3.9 Template Method
- **Must Know:** Intent — define algorithm skeleton, defer steps to subclasses
- **Must Know:** NVI (Non-Virtual Interface) idiom in C++
- **Should Know:** Hook methods, optional steps

### 3.10 Visitor
- **Should Know:** Intent — add operations without modifying element classes
- **Should Know:** Double dispatch mechanism
- **Should Know:** `std::variant` + `std::visit` as modern alternative [C++17]
- **Nice to Have:** Acyclic Visitor

### 3.11 Interpreter
- **Nice to Have:** Intent — define grammar representation and interpreter
- **Nice to Have:** DSLs, expression trees, rule engines

### 3.12 Null Object
- **Should Know:** Intent — provide default "do nothing" behavior
- **Should Know:** Avoiding null checks, logging no-ops
- **Should Know:** `std::optional` as alternative [C++17]

### ✅ Checklist – Behavioral Patterns
- [ ] Observer — publish-subscribe with weak references implemented
- [ ] Strategy — compile-time (policy) and runtime (`std::function`) variants
- [ ] Command — undo/redo system built
- [ ] State — FSM implemented
- [ ] Template Method / NVI — applied in class hierarchy
- [ ] Visitor — `std::variant` + `std::visit` applied
- [ ] Iterator — custom iterator or range adaptor written
- [ ] Chain of Responsibility — handler chain designed

---

## 4. Concurrency Patterns

### 4.1 Active Object
- **Should Know:** Intent — decouple method execution from invocation
- **Should Know:** Message passing, async interfaces
- **Should Know:** Command queue + worker thread

### 4.2 Monitor Object
- **Must Know:** Intent — synchronize access through encapsulated locking
- **Must Know:** Mutex + condition variable encapsulation
- **Should Know:** Monitor vs raw mutex — abstraction benefits

### 4.3 Half-Sync/Half-Async
- **Should Know:** Intent — separate sync and async processing layers
- **Should Know:** Async I/O with synchronous business logic
- **Nice to Have:** Queue-based decoupling

### 4.4 Reactor & Proactor
- **Must Know:** Reactor — synchronous event demultiplexing (epoll, select)
- **Must Know:** Proactor — asynchronous completion handlers (Asio, io_uring)
- **Should Know:** Trade-offs: reactor vs proactor for scalability

### 4.5 Thread-Safe Singleton
- **Must Know:** Meyers Singleton (C++11 thread-safe static local)
- **Must Know:** `std::call_once` for lazy initialization
- **Should Know:** Double-checked locking — why it's broken without atomics
- **Should Know:** Atomic singletons

### 4.6 Producer-Consumer
- **Must Know:** Bounded buffer with mutex + condition variable
- **Must Know:** Work queues, thread pool task submission
- **Should Know:** Back-pressure mechanisms
- **Should Know:** Lock-free producer-consumer queues

### ✅ Checklist – Concurrency Patterns
- [ ] Monitor Object — encapsulated synchronization implemented
- [ ] Reactor / Proactor — async I/O pattern applied (Asio)
- [ ] Producer-Consumer — bounded buffer with proper signaling
- [ ] Active Object — message-based async interface built
- [ ] Thread-safe initialization — `call_once` / Meyers Singleton used

---

## 5. Architectural Patterns

### 5.1 MVC / MVP / MVVM
- **Must Know:** Separation of concerns in UI architecture
- **Should Know:** Trade-offs between MVC, MVP, MVVM
- **Should Know:** Testability improvements with each variant

### 5.2 Repository Pattern
- **Should Know:** Data access abstraction
- **Should Know:** Unit of Work, persistence ignorance
- **Nice to Have:** Repository + Factory composition

### 5.3 Service Locator vs Dependency Injection
- **Must Know:** Dependency Injection — constructor, setter, interface injection
- **Must Know:** Trade-offs: DI vs Service Locator — testability, coupling
- **Should Know:** Compile-time DI in C++ (templates, concepts)
- **Nice to Have:** DI containers in C++

### 5.4 Event Sourcing & CQRS
- **Should Know:** Event stores, event replay, projections
- **Should Know:** Command Query Responsibility Segregation
- **Nice to Have:** Eventual consistency handling

### 5.5 Layered Architecture
- **Must Know:** Presentation → Business Logic → Data Access
- **Must Know:** Dependency rules — inner layers don't depend on outer

### 5.6 Microkernel / Plugin
- **Should Know:** Stable core with extensible plugins
- **Should Know:** Dynamic loading (`dlopen`/`LoadLibrary`)
- **Should Know:** Plugin interfaces, versioning

### 5.7 Pipe and Filter
- **Should Know:** Data transformation pipelines
- **Should Know:** Unix philosophy, streaming processing
- **Should Know:** C++20 Ranges as pipe-and-filter

### ✅ Checklist – Architectural Patterns
- [ ] DI vs Service Locator — trade-offs articulated
- [ ] Layered architecture — dependency rules enforced
- [ ] Plugin architecture — dynamic loading implemented
- [ ] Pipe and Filter — pipeline with ranges or custom built
- [ ] CQRS / Event Sourcing concepts understood

---

## 6. Modern C++ & Pattern Evolution

### 6.1 CRTP (Curiously Recurring Template Pattern)
- **Must Know:** Static polymorphism, compile-time dispatch
- **Should Know:** Mixin classes, adding functionality without virtual
- **Should Know:** CRTP vs concepts [C++20] — modern alternatives

### 6.2 Policy-Based Design
- **Must Know:** Compile-time strategy selection via template parameters
- **Should Know:** Alexandrescu-style designs (`Modern C++ Design`)
- **Should Know:** `std::allocator` as policy example

### 6.3 Type Erasure
- **Must Know:** `std::function` — callable type erasure
- **Should Know:** `std::any` — any-type erasure [C++17]
- **Should Know:** Custom type erasure — runtime polymorphism without inheritance
- **Nice to Have:** Sean Parent's "Inheritance Is The Base Class of Evil" technique

### 6.4 RAII as a Pattern
- **Must Know:** Resource management via scope
- **Must Know:** Scope guards, lock guards, file handles
- **Should Know:** Custom RAII wrappers for C APIs

### 6.5 Expression Templates
- **Nice to Have:** Lazy evaluation for expression trees
- **Nice to Have:** DSL construction (Eigen-style matrix math)

### 6.6 Monostate vs Singleton
- **Should Know:** Shared state through static members (no instance control)
- **Should Know:** When monostate is preferred over singleton

### ✅ Checklist – Modern C++ Patterns
- [ ] CRTP — static polymorphism implemented
- [ ] Policy-based design — template policies applied
- [ ] Type erasure — custom type-erased wrapper built
- [ ] RAII — custom scope guard implemented
- [ ] Expression templates explored (if relevant domain)

---

## 7. Anti-Patterns & Pattern Misuse

### 7.1 Over-Engineering
- **Must Know:** Pattern overuse — YAGNI violations
- **Must Know:** Complexity budget — simpler is better until proven otherwise

### 7.2 God Object / Blob
- **Must Know:** Single Responsibility violations
- **Must Know:** Symptoms: 1000+ line classes, dozens of methods

### 7.3 Spaghetti / Lasagna Code
- **Should Know:** Spaghetti — no structure, tangled flow
- **Should Know:** Lasagna — too many unnecessary layers

### 7.4 Golden Hammer
- **Should Know:** Applying the same pattern to every problem
- **Should Know:** Solution: analyze problem first, then pick pattern

### 7.5 Lava Flow
- **Should Know:** Dead code from abandoned pattern implementations
- **Should Know:** Regular cleanup, deprecation discipline

### 7.6 When NOT to Use a Pattern
- **Must Know:** Simplicity-first: don't introduce patterns preemptively
- **Must Know:** Patterns add indirection — justify the cost
- **Should Know:** Refactor TO patterns when complexity warrants it

### ✅ Checklist – Anti-Patterns
- [ ] Can identify over-engineering in code reviews
- [ ] God Object detection and splitting strategies known
- [ ] "When NOT to use" articulated for each major pattern
- [ ] Codebase audit for anti-patterns completed

---

## 8. SOLID Principles in Practice

### 8.1 Single Responsibility Principle (SRP)
- **Must Know:** One reason to change per class
- **Must Know:** Cohesion metrics, class splitting strategies
- **Should Know:** SRP applied to functions and modules too

### 8.2 Open/Closed Principle (OCP)
- **Must Know:** Open for extension, closed for modification
- **Must Know:** Extension points: virtual methods, templates, callbacks
- **Should Know:** Plugin architecture as OCP application

### 8.3 Liskov Substitution Principle (LSP)
- **Must Know:** Subtypes must be substitutable for base types
- **Must Know:** Behavioral subtyping, contract adherence
- **Should Know:** Invariant, precondition, postcondition rules
- **Should Know:** Classic violations: Square/Rectangle problem

### 8.4 Interface Segregation Principle (ISP)
- **Must Know:** Clients should not depend on methods they don't use
- **Should Know:** Fat interfaces → role-based interfaces
- **Should Know:** C++ pure virtual design, multiple inheritance of interfaces

### 8.5 Dependency Inversion Principle (DIP)
- **Must Know:** Depend on abstractions, not concretions
- **Must Know:** Constructor injection, interface-based programming
- **Should Know:** Compile-time DI via templates/concepts [C++20]

### ✅ Checklist – SOLID Principles
- [ ] SRP — class responsibilities clearly bounded
- [ ] OCP — extension points designed without modification
- [ ] LSP — inheritance hierarchies reviewed for substitutability
- [ ] ISP — interfaces decomposed by client needs
- [ ] DIP — high-level modules depend on abstractions

---

## Pattern Relationships & Composition

- **Must Know:** Abstract Factory often uses Factory Methods internally
- **Must Know:** Decorator and Composite both use recursive composition
- **Should Know:** Strategy can replace conditional logic that State manages
- **Should Know:** Observer + Mediator — when to centralize vs decentralize
- **Should Know:** Command + Memento — undo/redo systems
- **Should Know:** Builder + Fluent Interface — construction patterns
- **Should Know:** Visitor + Composite — operations on tree structures
- **Nice to Have:** Proxy vs Decorator vs Adapter — structural pattern comparison
