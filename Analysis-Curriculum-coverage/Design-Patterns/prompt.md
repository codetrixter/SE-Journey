# Prompt for fetching the scope of preparation of topics:
1. ***DESIGN PATTERNS***

- Role & Goal
You are an expert Software Architect and curriculum designer with deep expertise in object-oriented and modern design patterns (GoF, enterprise, concurrency, and architectural). Create a comprehensive, industry-ready list of design pattern concepts, practices, and trade-offs that a software engineer with 10 years of experience should master. The output must be well-structured, exhaustive, and actionable, with checklists and tracking metadata for mastery.

Audience Context

Experience: 10 years in software engineering
Languages: C++ (primary), with pattern concepts applicable across languages
Codebase scale: large, multi-module, CI/CD, code reviews, performance-sensitive
Focus: practical application over academic taxonomy; when to use and when NOT to use each pattern

Scope (cover all sections)

## Creational Patterns

Singleton: thread-safe implementations, Meyers singleton, anti-pattern arguments, dependency injection alternatives
Factory Method: virtual constructors, parameterized factories, registry patterns
Abstract Factory: family of related objects, platform-independent creation, factory of factories
Builder: step-by-step construction, fluent interfaces, director vs self-building
Prototype: deep copy, clone registries, polymorphic copying in C++
Object Pool: resource reuse, thread-safe pools, connection pools

## Structural Patterns

Adapter (class & object): interface wrapping, legacy integration, compile-time vs runtime
Bridge: decoupling abstraction from implementation, pImpl idiom in C++, ABI stability
Composite: tree structures, recursive composition, uniform treatment, file system example
Decorator: dynamic behavior extension, streaming/IO wrappers, vs inheritance explosion
Facade: subsystem simplification, API gateway, layered architecture boundaries
Flyweight: shared intrinsic state, memory optimization, string interning, immutable objects
Proxy: virtual proxy, protection proxy, smart references, remote proxy, caching proxy

## Behavioral Patterns

Chain of Responsibility: handler chains, middleware patterns, event bubbling, logging pipelines
Command: encapsulated operations, undo/redo, macro commands, transactional behavior, command queues
Iterator: external vs internal iteration, C++ iterators & ranges, lazy evaluation, generator patterns
Mediator: decoupled communication, event bus, chat room example, GUI component coordination
Memento: state snapshots, undo stacks, serialization considerations, caretaker management
Observer: publish-subscribe, event-driven architecture, signal-slot (Qt), weak observer to avoid leaks
State: finite state machines, state transitions, vs strategy pattern, game AI states
Strategy: interchangeable algorithms, policy-based design in C++, comparators, compression strategies
Template Method: algorithm skeleton, hook methods, NVI (Non-Virtual Interface) idiom in C++
Visitor: double dispatch, adding operations without modifying classes, std::variant + std::visit in modern C++
Interpreter: DSLs, expression trees, rule engines (when appropriate)
Null Object: default behavior, avoiding null checks, logging no-ops

## Concurrency Patterns

Active Object: decoupled method execution, message passing, async interfaces
Monitor Object: synchronized methods, condition variables, encapsulated locking
Half-Sync/Half-Async: layered concurrency, async I/O with sync processing
Reactor & Proactor: event-driven I/O, async completion handlers, Asio patterns
Thread-Safe Interface: double-checked locking (and why it's broken), call_once, atomic singletons
Producer-Consumer: bounded buffers, work queues, back-pressure

## Architectural Patterns

MVC / MVP / MVVM: separation of concerns, UI architecture, testability
Repository: data access abstraction, unit of work, persistence ignorance
Service Locator vs Dependency Injection: trade-offs, testability, compile-time DI in C++
Event Sourcing & CQRS: event stores, projections, eventual consistency (overview)
Layered Architecture: presentation, business logic, data access, dependency rules
Microkernel / Plugin: extensibility, dynamic loading, stable core interfaces
Pipe and Filter: data transformation pipelines, streaming, Unix philosophy

## Modern C++ & Pattern Evolution

CRTP (Curiously Recurring Template Pattern): static polymorphism, mixin classes
Policy-based design: compile-time strategy, Alexandrescu-style, std::allocator model
Type erasure: std::function, std::any, runtime polymorphism without inheritance
RAII as a pattern: resource management, scope guards, lock guards
Expression templates: lazy evaluation, DSLs, Eigen-style
Monostate vs Singleton: shared state without instance control

## Anti-Patterns & Pattern Misuse

Over-engineering: pattern overuse, YAGNI violations
God Object / Blob: single responsibility violations
Spaghetti / Lasagna: coupling and layering gone wrong
Golden Hammer: applying favorite pattern everywhere
Lava Flow: dead code from abandoned patterns
When NOT to use a pattern: simplicity-first, complexity budget

## SOLID Principles in Practice

Single Responsibility Principle: cohesion, class boundaries, splitting strategies
Open/Closed Principle: extension points, plugin architecture, protected variations
Liskov Substitution Principle: behavioral subtyping, contract adherence, invariant preservation
Interface Segregation Principle: fat interfaces, role-based interfaces, C++ pure virtual design
Dependency Inversion Principle: abstractions over concretions, DI containers, compile-time DI

Output Requirements

Table of Contents with deep linking
Each section must include:
  - What & Why (1–2 concise paragraphs)
  - Key Topics (bullet list)
  - "When to Use / When NOT to Use" (bullet list)
  - "Gotchas & Pitfalls" (bullet list)
  - Code Snippets (idiomatic C++, minimal, compilable; do not put code inside tables)
  - Checklist (Markdown checkboxes with tracking fields)
  - Self‑Assessment (3–5 questions; 1 scenario-based design question)
  - References (GoF book, Head First, cppreference, talks; prefer stable links)

Master Progress Tracker at the top (aggregating all checklists).
Separate "Must Know / Should Know / Nice to Have" per section.
Keep explanations concise but industry-practical (trade-offs, real-world use cases).

Checklist Template (use in every section)

```markdown
### ✅ Checklist – {Pattern/Section Name}
- [ ] Concept mastered: {Pattern Name}
      Owner: {name}  Target Date: {YYYY-MM-DD}  Last Reviewed: {YYYY-MM-DD}
      Evidence: {PR link / doc / code sample}
- [ ] "When to use" and "When NOT to use" clearly understood
- [ ] Pitfall avoided: {Describe common misuse and prevention}
- [ ] Code sample written & reviewed (idiomatic C++)
- [ ] Compared with alternative patterns / approaches
- [ ] Applied in a real or practice project
- [ ] Knowledge shared: {brown-bag / wiki / snippet}
```

Master Progress Tracker (top of document)

```markdown
## 📊 Master Progress Tracker
| Section                    | Must Know Done | Should Know Done | Nice to Have Done | Last Reviewed | Notes |
|----------------------------|----------------|------------------|-------------------|---------------|-------|
| Creational Patterns        |                |                  |                   |               |       |
| Structural Patterns        |                |                  |                   |               |       |
| Behavioral Patterns        |                |                  |                   |               |       |
| Concurrency Patterns       |                |                  |                   |               |       |
| Architectural Patterns     |                |                  |                   |               |       |
| Modern C++ Patterns        |                |                  |                   |               |       |
| Anti-Patterns & Misuse     |                |                  |                   |               |       |
| SOLID Principles           |                |                  |                   |               |       |
```

Style & Constraints

- Use Markdown, descriptive headings, and consistent formatting.
- Keep code outside tables.
- Mark advanced concepts clearly as such.
- Show real-world scenarios where patterns solve actual problems.
- Discuss pattern interactions and composition (e.g., Abstract Factory + Singleton, Observer + Mediator).
- Compare related patterns explicitly (e.g., Strategy vs State, Decorator vs Proxy).
- Prefer modern C++ idioms over classical OOP-heavy implementations where appropriate.
