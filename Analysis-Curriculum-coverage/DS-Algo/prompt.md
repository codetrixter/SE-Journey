# Prompt for fetching the scope of preparation of topics:
1. ***DATA STRUCTURES & ALGORITHMS***

- Role & Goal
You are an expert algorithms engineer and curriculum designer with deep expertise in data structures, algorithms, and competitive problem-solving. Create a comprehensive, industry-ready list of DS & Algo concepts, techniques, and problem patterns that a software engineer with 10 years of experience should master. The output must be well-structured, exhaustive, and actionable, with checklists and tracking metadata for mastery.

Audience Context

Experience: 10 years in software engineering
Languages: C++ (primary, using STL extensively)
Focus: interview readiness (FAANG/top-tier), system design data structure choices, and production code optimization
Problem platforms: LeetCode, NeetCode, Codeforces (for advanced)
Codebase scale: large-scale systems where algorithmic choices impact latency, memory, and scalability

Scope (cover all sections)

## Arrays & Strings

Static & dynamic arrays, std::vector internals, amortized O(1) push_back
Two-pointer techniques: same-direction, opposing, fast-slow
Sliding window: fixed-size, variable-size, shrinkable window
Prefix sums, difference arrays, Kadane's algorithm
String manipulation: KMP, Rabin-Karp, Z-algorithm, suffix arrays, tries
In-place operations, rotation, spiral traversal, matrix operations

## Hashing & Hash Maps

Hash functions, collision resolution: chaining, open addressing, Robin Hood
std::unordered_map internals, load factor, rehashing, custom hashers
Frequency counting, anagram detection, two-sum patterns
Rolling hash, Bloom filters, consistent hashing (system design tie-in)
Hash set operations: intersection, union, difference

## Linked Lists

Singly, doubly, circular linked lists
Fast-slow pointer: cycle detection (Floyd's), middle finding, intersection
Reversal techniques: iterative, recursive, k-group reversal
Merge operations: merge sorted lists, merge k-sorted lists
LRU Cache implementation using doubly-linked list + hashmap
Skip lists (advanced)

## Stacks & Queues

Stack applications: expression evaluation, parenthesis matching, monotonic stack
Next greater/smaller element patterns
Queue variants: circular queue, deque, priority queue
Monotonic queue for sliding window maximum/minimum
Implementing stack with queues and vice versa
Min-stack, max-stack designs

## Trees

Binary trees: traversals (inorder, preorder, postorder, level-order), construction from traversals
Binary Search Trees: insertion, deletion, balancing, successor/predecessor
Balanced BSTs: AVL, Red-Black tree concepts, std::set/std::map internals
Segment trees: range queries, lazy propagation, persistent segment trees
Fenwick trees (Binary Indexed Trees): prefix sums, point updates
Tries: prefix matching, autocomplete, word search
B-Trees & B+ Trees: disk-based data structures, database indexing
Tree DP, LCA (Lowest Common Ancestor), Euler tour, heavy-light decomposition (advanced)

## Heaps & Priority Queues

Min-heap, max-heap, std::priority_queue
Heap operations: heapify, sift-up, sift-down, build-heap in O(n)
Top-K problems, median maintenance (two-heap technique)
Merge K sorted streams
D-ary heaps, Fibonacci heaps (concepts)
Custom comparators, indexed priority queues

## Graphs

Representations: adjacency list, adjacency matrix, edge list
Traversals: BFS, DFS, iterative deepening
Shortest paths: Dijkstra, Bellman-Ford, Floyd-Warshall, A* (heuristic search)
Minimum spanning tree: Kruskal's (Union-Find), Prim's
Topological sort: Kahn's algorithm, DFS-based
Strongly connected components: Tarjan's, Kosaraju's
Bipartite checking, graph coloring
Articulation points, bridges, Euler/Hamiltonian paths
Network flow: Ford-Fulkerson, max-flow min-cut (advanced)
Disjoint Set Union (Union-Find): path compression, union by rank

## Recursion & Backtracking

Recursion fundamentals: base case, recursive case, call stack, tail recursion
Divide and conquer: merge sort, quick sort, closest pair of points
Backtracking: N-queens, Sudoku solver, permutations, combinations, subsets
Constraint satisfaction, pruning techniques, branch and bound
Memoization as bridge to DP

## Dynamic Programming

1D DP: Fibonacci, climbing stairs, house robber, coin change
2D DP: grid paths, longest common subsequence, edit distance
Knapsack variants: 0/1, unbounded, fractional
Interval DP: matrix chain multiplication, burst balloons
DP on trees, DP on graphs, DP with bitmask (TSP)
String DP: palindromic subsequences, regex matching, interleaving
State machine DP: stock buy-sell problems
Optimization: space reduction, Knuth's optimization, Convex Hull Trick (advanced)
Top-down vs bottom-up trade-offs, state transition diagrams

## Sorting & Searching

Comparison sorts: merge sort, quick sort (Lomuto/Hoare), heap sort — complexity & stability
Non-comparison sorts: counting sort, radix sort, bucket sort
Binary search: classic, on answer (minimize maximum), rotated arrays, search space reduction
Quickselect, order statistics, median of medians
External sorting, multi-way merge
Custom comparators, partial_sort, nth_element in C++ STL

## Greedy Algorithms

Activity selection, interval scheduling, interval partitioning
Huffman coding, fractional knapsack
Greedy vs DP: proving greedy choice property, exchange arguments
Job scheduling with deadlines, minimum platforms
Kruskal's & Prim's as greedy algorithms
Task assignment, gas station problem

## Bit Manipulation

Bitwise operators: AND, OR, XOR, NOT, shifts
Common tricks: check/set/clear/toggle bits, power of 2, counting set bits
XOR properties: single number, missing number, swap without temp
Bitmask DP, subset enumeration
Bit manipulation in system programming: flags, permissions, protocol parsing

## Advanced Data Structures

Disjoint Set Union (Union-Find): path compression, union by rank/size
Sparse tables: static RMQ in O(1)
Suffix arrays & suffix trees: pattern matching, longest repeated substring
Balanced BSTs: treaps, splay trees (concepts)
Persistent data structures: persistent segment trees, fat nodes
Bloom filters, Count-Min Sketch (probabilistic)
Interval trees, k-d trees (spatial queries)

## Complexity Analysis & Problem-Solving Strategies

Big-O, Big-Theta, Big-Omega: formal definitions, amortized analysis
Master theorem, recurrence relations
Space-time trade-offs, auxiliary space vs in-place
Problem decomposition: identify subproblems, state representation
Pattern recognition: sliding window, two-pointer, monotonic stack, binary search on answer
Stress testing & brute-force validation for competitive programming

Output Requirements

Table of Contents with deep linking
Each section must include:
  - What & Why (1–2 concise paragraphs)
  - Key Topics (bullet list)
  - Core Problems to Solve (curated problem list with difficulty tags: Easy/Medium/Hard)
  - "Gotchas & Pitfalls" (bullet list)
  - Code Snippets (idiomatic C++ with STL, minimal, compilable; do not put code inside tables)
  - Checklist (Markdown checkboxes with tracking fields)
  - Self‑Assessment (3–5 questions; 1 scenario/design question)
  - References (CLRS, cp-algorithms, LeetCode patterns, talks; prefer stable links)

Master Progress Tracker at the top (aggregating all checklists).
Separate "Must Know / Should Know / Nice to Have" per section.
Tag problems by pattern and difficulty.
Keep explanations concise but industry-practical (trade-offs, when to use which DS/algorithm).

Checklist Template (use in every section)

```markdown
### ✅ Checklist – {Section Name}
- [ ] Concept mastered: {Item}
      Owner: {name}  Target Date: {YYYY-MM-DD}  Last Reviewed: {YYYY-MM-DD}
      Evidence: {PR link / doc / solved problems}
- [ ] Core problems solved: {X/Y problems from curated list}
- [ ] Pitfall avoided: {Describe common bug and prevention}
- [ ] Time & space complexity analyzed and justified
- [ ] Code sample written & reviewed (idiomatic C++ with STL)
- [ ] Applied in a real or practice project / system design context
- [ ] Knowledge shared: {brown-bag / wiki / snippet}
```

Master Progress Tracker (top of document)

```markdown
## 📊 Master Progress Tracker
| Section                       | Must Know Done | Should Know Done | Nice to Have Done | Last Reviewed | Notes |
|-------------------------------|----------------|------------------|-------------------|---------------|-------|
| Arrays & Strings              |                |                  |                   |               |       |
| Hashing & Hash Maps           |                |                  |                   |               |       |
| Linked Lists                  |                |                  |                   |               |       |
| Stacks & Queues               |                |                  |                   |               |       |
| Trees                         |                |                  |                   |               |       |
| Heaps & Priority Queues       |                |                  |                   |               |       |
| Graphs                        |                |                  |                   |               |       |
| Recursion & Backtracking      |                |                  |                   |               |       |
| Dynamic Programming           |                |                  |                   |               |       |
| Sorting & Searching           |                |                  |                   |               |       |
| Greedy Algorithms             |                |                  |                   |               |       |
| Bit Manipulation              |                |                  |                   |               |       |
| Advanced Data Structures      |                |                  |                   |               |       |
| Complexity Analysis           |                |                  |                   |               |       |
```

Style & Constraints

- Use Markdown, descriptive headings, and consistent formatting.
- Keep code outside tables.
- Mark advanced concepts clearly as such.
- For each data structure, discuss: operations, time complexity, space complexity, real-world use cases.
- For each algorithm, discuss: correctness, complexity, when to prefer over alternatives.
- Include curated problem sets (LeetCode/NeetCode numbers where applicable).
- Prefer C++ STL usage but also show manual implementations where understanding internals matters.
