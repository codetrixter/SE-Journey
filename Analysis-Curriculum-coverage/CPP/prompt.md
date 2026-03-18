# Prompt for fetching the scope of preparation of topics:
1. ***CPP TOPICS ***

- Role & Goal
You are an expert C++ Staff Engineer and curriculum designer. Create a comprehensive, industry-ready list of C++ concepts, practices, and tools that a software engineer with 10 years of experience should master. The output must be well-structured, exhaustive, and actionable, with checklists and tracking metadata for mastery.
Audience Context (customize if needed)

Experience: 10 years in software engineering
Platforms: Linux + Windows (and optional Android NDK)
Standards focus: C++17, C++20, C++23 (note which items are version-specific)
Codebase scale: large, multi-module, CI/CD, code reviews, performance-sensitive
Org policy (customize): {exceptions=allowed|disallowed}, {RTTI=allowed|disallowed}, {dynamic_cast=discouraged}, {C++ standard baseline=C++20}

Scope (cover all sections)

Core Language & Standard Library

RAII, value categories, move semantics, rule of 0/3/5/0, ownership models
Smart pointers & lifetime: unique_ptr, shared_ptr, weak ownership, cycles
Templates & metaprogramming: SFINAE, type traits, CRTP, concepts (C++20), requires-clauses, constexpr/consteval
Error handling strategies: exceptions vs status codes, std::expected (C++23), std::optional, std::variant
Ranges (C++20), iterators, algorithms, views, projections
Coroutines (C++20): design patterns, pitfalls, cancellation
Modules (C++20): partitioning, interface units, build integration
std::string_view, std::span, chrono, filesystem, format, print (C++23), mdspan (C++23)


Concurrency & Parallelism

Threads, mutexes, shared_mutex, atomics & memory model, condition_variable, barriers/latches/semaphores
Futures/promises, async patterns, thread pools, work stealing
Parallel STL, fork-join patterns, false sharing, lock contention
Coroutines vs threads trade-offs


Performance Engineering

Profiling: perf/VTune/Tracy, flamegraphs, sample vs trace
CPU cache, data-oriented design, branch prediction, inlining, codegen basics
LTO, PGO, symbol visibility, cold/hot paths, measuring tail latencies
SIMD: std::experimental::simd or vendor intrinsics (when appropriate)


Memory Management

Allocators, custom allocators, pools/arenas, fragmentation
Alignment, aliasing rules, small-buffer optimization, memory diagnostics (ASan/MSan)


API & ABI Design

Stable interfaces, pImpl, symbol visibility, versioning, dependency boundaries
Exception-safety guarantees, error taxonomies, contracts (state of the art & policies)


Tooling & Build Systems

Compilers: GCC/Clang/MSVC differences, warnings-as-errors, sanitizers (ASan/UBSan/TSan)
Static analysis: clang-tidy, cppcheck, PVS-Studio; formatting: clang-format
Build systems: CMake (modern targets), Conan/vcpkg, reproducible builds, SBOM


Testing & Quality

Unit (GTest/GMock), integration, property-based (RapidCheck), fuzzing (libFuzzer/AFL)
Determinism, flake reduction, test data management, coverage (llvm-cov)


Security & Reliability

Undefined behavior, lifetime & iterator invalidation, integer overflow
CERT C++ guidelines, secure-by-default patterns, input validation


Architecture & Design

Layering, boundaries, dependency inversion, SOLID-in-C++ (nuanced), immutability where practical
Patterns: RAII, pImpl, Observer, Strategy, Visitor, Builder, Reactor/Proactor (async I/O)


Cross-Platform & Systems

Filesystems, sockets, endianness, Unicode/UTF-8, time zones
OS differences (Windows/Linux/macOS), Android NDK nuances


Domain Libraries & Ecosystem

Asio/Boost.Asio, gRPC, protobuf/FlatBuffers, JSON libs, fmt, range-v3, Boost basics


DevEx & Scale

Code review practices, diff hygiene, refactoring large codebases, deprecation plans
CI/CD (Jenkins/GH Actions/Azure Pipelines), artifact caching, binary compatibility


Optional Domain Tracks (select as relevant)

Embedded/RTOS, low-latency trading, game engines, HPC, networking backends, distributed systems



Output Requirements

Table of Contents with deep linking
Each section must include:

What & Why (1–2 concise paragraphs)
Key Topics (bullet list)
“Gotchas & Pitfalls” (bullet list)
Code Snippets (idiomatic, minimal, compilable; do not put code inside tables)
Checklist (Markdown checkboxes with tracking fields)
Self‑Assessment (3–5 questions; 1 scenario)
References (standards docs, cppreference, vendor docs, talks; prefer stable links)


Master Progress Tracker at the top (aggregating all checklists).
Use C++ version tags: [C++17], [C++20], [C++23] next to each item.
Separate “Must Know / Should Know / Nice to Have” per section.
Be explicit where organization policies affect recommendations (exceptions/RTTI).
Keep explanations concise but industry-practical (trade-offs, when not to use).
Checklist Template (use in every section)
Markdown### ✅ Checklist – {Section Name}- [ ] Concept mastered: {Item}  {Tag(s): [C++20][Concurrency]}      Owner: {name}  Target Date: {YYYY-MM-DD}  Last Reviewed: {YYYY-MM-DD}      Evidence: {PR link / doc / benchmark}- [ ] Pitfall avoided: {Describe common bug/UB and prevention}- [ ] Tooling applied: {clang-tidy rule / sanitizer / profiler}- [ ] Code sample written & reviewed- [ ] Integrated into production (if applicable)- [ ] Knowledge shared: {brown-bag / wiki / snippet}Show more lines
Master Progress Tracker (top of document)
Markdown## 📊 Master Progress Tracker| Section | Must Know Done | Should Know Done | Nice to Have Done | Last Reviewed | Notes ||--------|-----------------|------------------|-------------------|---------------|-------|| Core Language & STL |  |  |  |  |  || Concurrency & Parallelism |  |  |  |  |  || Performance Engineering |  |  |  |  |  || Memory Management |  |  |  |  |  || API & ABI Design |  |  |  |  |  || Tooling & Build |  |  |  |  |  || Testing & Quality |  |  |  |  |  || Security & Reliability |  |  |  |  |  || Architecture & Design |  |  |  |  |  || Cross-Platform & Systems |  |  |  |  |  || Ecosystem |  |  |  |  |  || Domain Track(s) |  |  |  |  |  |Show more lines
Style & Constraints

Use Markdown, descriptive headings, and consistent formatting.
Keep code outside tables.
Mark advanced concepts clearly as such.
Avoid outdated advice (e.g., raw new/delete in app code) unless teaching RAII vs manual.
Call out Non-Standard or TS/Experimental APIs explicitly.
Prefer portable guidance; highlight platform-specific caveats.

Example (one short subsection)
Markdown## Core Language & STL → Move Semantics [C++11+]**What & Why**  Move semantics enable transfer of resources without deep copies, crucial for performance in large objects and containers.**Key Topics**  - `T(T&&)`, `operator=(T&&)`; move vs copy elision; `std::move` vs `std::forward`; noexcept moves and container behavior.**Gotchas & Pitfalls**  - Moved-from objects must be valid but unspecified state.  - Forgetting `noexcept` on move ctor can block optimizations in containers.  - Misusing `std::move` causing dangling references.**Code Snippet**```cppstruct Buffer {  std::unique_ptr<int[]> data; size_t n{};  Buffer(size_t n): data(std::make_unique<int[]>(n)), n(n) {}  Buffer(Buffer&& other) noexcept : data(std::move(other.data)), n(other.n) { other.n = 0; }  Buffer& operator=(Buffer&& other) noexcept {    if (this != &other) { data = std::move(other.data); n = other.n; other.n = 0; }    return *this;  }};``Show more lines
✅ Checklist – Move Semantics

 Implemented move ctor/assign with noexcept
 Reviewed moved-from invariants
 Benchmarked vs copy; documented impact
 Added std::move only at last-use sites; static analysis clean
 Shared pitfalls with team (wiki/PR)

Self‑Assessment

When do containers prefer move over copy?
Why does noexcept matter for vector reallocation?
When should you avoid std::move?

References

cppreference: Move semantics
ISO C++ papers overview for move semantics rationale