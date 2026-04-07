# Data Structures & Algorithms — Mastery Scope for 10+ Years Experience

---

## 📊 Master Progress Tracker

| Section | Must Know Done | Should Know Done | Nice to Have Done | Last Reviewed | Notes |
|-------------------------------|----------------|------------------|-------------------|---------------|-------|
| Arrays & Strings | | | | | |
| Hashing & Hash Maps | | | | | |
| Linked Lists | | | | | |
| Stacks & Queues | | | | | |
| Trees | | | | | |
| Heaps & Priority Queues | | | | | |
| Graphs | | | | | |
| Recursion & Backtracking | | | | | |
| Dynamic Programming | | | | | |
| Sorting & Searching | | | | | |
| Greedy Algorithms | | | | | |
| Bit Manipulation | | | | | |
| Advanced Data Structures | | | | | |
| Complexity Analysis | | | | | |

---

## Table of Contents

1. [Arrays & Strings](#1-arrays--strings)
2. [Hashing & Hash Maps](#2-hashing--hash-maps)
3. [Linked Lists](#3-linked-lists)
4. [Stacks & Queues](#4-stacks--queues)
5. [Trees](#5-trees)
6. [Heaps & Priority Queues](#6-heaps--priority-queues)
7. [Graphs](#7-graphs)
8. [Recursion & Backtracking](#8-recursion--backtracking)
9. [Dynamic Programming](#9-dynamic-programming)
10. [Sorting & Searching](#10-sorting--searching)
11. [Greedy Algorithms](#11-greedy-algorithms)
12. [Bit Manipulation](#12-bit-manipulation)
13. [Advanced Data Structures](#13-advanced-data-structures)
14. [Complexity Analysis & Problem-Solving Strategies](#14-complexity-analysis--problem-solving-strategies)

---

## 1. Arrays & Strings

### 1.1 Array Fundamentals
- **Must Know:** Static arrays, dynamic arrays, `std::vector` internals
- **Must Know:** Amortized O(1) `push_back`, capacity vs size, reallocation
- **Must Know:** `std::array` for fixed-size, cache-friendly contiguous memory

### 1.2 Two-Pointer Techniques
- **Must Know:** Opposing pointers (e.g., palindrome check, two-sum on sorted)
- **Must Know:** Same-direction pointers (e.g., remove duplicates, partition)
- **Must Know:** Fast-slow pointer (e.g., cycle detection in sequences)

### 1.3 Sliding Window
- **Must Know:** Fixed-size window (e.g., max sum subarray of size k)
- **Must Know:** Variable-size window (e.g., longest substring without repeating chars)
- **Should Know:** Shrinkable window with constraints (e.g., minimum window substring)

### 1.4 Prefix Sums & Difference Arrays
- **Must Know:** Prefix sum array — O(1) range sum queries
- **Must Know:** Kadane's algorithm — maximum subarray sum
- **Should Know:** Difference arrays — range update in O(1)
- **Should Know:** 2D prefix sums — submatrix sum queries

### 1.5 String Algorithms
- **Must Know:** String matching — brute-force O(nm)
- **Should Know:** KMP (Knuth-Morris-Pratt) — O(n+m) pattern matching
- **Should Know:** Rabin-Karp — rolling hash-based matching
- **Nice to Have:** Z-algorithm — all occurrences in O(n+m)
- **Nice to Have:** Suffix arrays, suffix trees — advanced pattern matching

### 1.6 Matrix Operations
- **Must Know:** In-place rotation, transposition
- **Must Know:** Spiral traversal
- **Should Know:** Matrix multiplication, Strassen's algorithm (concept)

### ✅ Checklist – Arrays & Strings
- [ ] Two-pointer patterns mastered (opposing, same-direction, fast-slow)
- [ ] Sliding window — fixed & variable size implemented
- [ ] Prefix sums applied for range queries
- [ ] Kadane's algorithm implemented
- [ ] KMP / Rabin-Karp string matching implemented
- [ ] Matrix rotation & spiral traversal solved

---

## 2. Hashing & Hash Maps

### 2.1 Hash Fundamentals
- **Must Know:** Hash functions — properties (deterministic, uniform distribution)
- **Must Know:** Collision resolution — chaining, open addressing (linear/quadratic probing)
- **Should Know:** Robin Hood hashing
- **Should Know:** Load factor, rehashing, amortized complexity

### 2.2 Standard Library Hash Containers
- **Must Know:** `std::unordered_map`, `std::unordered_set` — O(1) average operations
- **Must Know:** Custom hashers for user-defined types
- **Should Know:** Hash combining techniques (`boost::hash_combine` pattern)

### 2.3 Hash Patterns
- **Must Know:** Frequency counting (character frequency, word count)
- **Must Know:** Two-sum pattern with hash map
- **Must Know:** Anagram detection / grouping
- **Should Know:** Rolling hash for substring matching
- **Nice to Have:** Consistent hashing (system design tie-in)

### 2.4 Probabilistic Data Structures
- **Nice to Have:** Bloom filters — membership testing with false positives
- **Nice to Have:** Count-Min Sketch — frequency estimation

### ✅ Checklist – Hashing & Hash Maps
- [ ] Hash collision resolution strategies understood
- [ ] Custom hasher for `unordered_map` implemented
- [ ] Two-sum, frequency counting, anagram patterns solved
- [ ] Rolling hash applied
- [ ] Bloom filter concept understood

---

## 3. Linked Lists

### 3.1 Linked List Types
- **Must Know:** Singly linked list — insert, delete, traverse
- **Must Know:** Doubly linked list — bidirectional traversal, O(1) delete with node pointer
- **Should Know:** Circular linked list — ring buffer, round-robin scheduling

### 3.2 Pointer Techniques
- **Must Know:** Fast-slow pointer — cycle detection (Floyd's tortoise and hare)
- **Must Know:** Finding middle element
- **Must Know:** Finding intersection point of two lists

### 3.3 Reversal Techniques
- **Must Know:** Iterative reversal
- **Must Know:** Recursive reversal
- **Should Know:** K-group reversal (reverse nodes in groups of k)
- **Should Know:** Partial reversal (reverse between positions m and n)

### 3.4 Merge Operations
- **Must Know:** Merge two sorted lists
- **Should Know:** Merge K sorted lists (using min-heap)

### 3.5 Advanced Linked List
- **Must Know:** LRU Cache — doubly linked list + hash map
- **Nice to Have:** Skip lists — probabilistic balanced structure

### ✅ Checklist – Linked Lists
- [ ] Singly & doubly linked list operations implemented
- [ ] Floyd's cycle detection applied
- [ ] Iterative & recursive reversal mastered
- [ ] Merge two sorted lists implemented
- [ ] LRU Cache designed and implemented

---

## 4. Stacks & Queues

### 4.1 Stack Applications
- **Must Know:** Parenthesis / bracket matching
- **Must Know:** Expression evaluation (infix, postfix)
- **Must Know:** Monotonic stack — next greater/smaller element
- **Should Know:** Min-stack (O(1) getMin)

### 4.2 Queue Variants
- **Must Know:** FIFO queue, circular queue
- **Must Know:** Double-ended queue (`std::deque`)
- **Must Know:** Priority queue (`std::priority_queue`)
- **Should Know:** Monotonic queue — sliding window maximum/minimum

### 4.3 Stack/Queue Interconversion
- **Should Know:** Implementing stack with two queues
- **Should Know:** Implementing queue with two stacks

### ✅ Checklist – Stacks & Queues
- [ ] Monotonic stack pattern mastered (next greater/smaller)
- [ ] Expression evaluation implemented
- [ ] Min-stack / Max-stack designed
- [ ] Monotonic queue for sliding window applied
- [ ] Priority queue used for top-K problems

---

## 5. Trees

### 5.1 Binary Tree Fundamentals
- **Must Know:** Traversals — inorder, preorder, postorder (recursive & iterative)
- **Must Know:** Level-order traversal (BFS with queue)
- **Must Know:** Tree construction from traversal pairs (preorder+inorder, inorder+postorder)
- **Must Know:** Height, depth, diameter, balanced check

### 5.2 Binary Search Trees (BST)
- **Must Know:** Insertion, deletion, search — O(h) operations
- **Must Know:** In-order successor / predecessor
- **Must Know:** Validate BST property
- **Should Know:** Kth smallest/largest element

### 5.3 Balanced BSTs
- **Must Know:** AVL trees — rotations (LL, RR, LR, RL), balance factor
- **Must Know:** Red-Black trees — properties, color rules (conceptual)
- **Must Know:** `std::set`, `std::map` internals (Red-Black tree in most STL implementations)
- **Should Know:** Self-balancing guarantees — O(log n) worst case

### 5.4 Segment Trees
- **Should Know:** Range query + point update — O(log n)
- **Should Know:** Build, query, update operations
- **Should Know:** Lazy propagation for range updates
- **Nice to Have:** Persistent segment trees

### 5.5 Fenwick Trees (Binary Indexed Trees)
- **Should Know:** Prefix sum queries + point updates — O(log n)
- **Should Know:** Comparison with segment trees — when to prefer

### 5.6 Tries (Prefix Trees)
- **Must Know:** Insert, search, prefix matching
- **Must Know:** Autocomplete, word dictionary applications
- **Should Know:** Compressed tries (radix trees)
- **Should Know:** Trie vs hash map trade-offs for prefix operations

### 5.7 B-Trees & B+ Trees
- **Should Know:** Multi-way balanced trees for disk-based storage
- **Should Know:** B+ tree — all data in leaves, linked leaf nodes
- **Should Know:** Database indexing use case

### 5.8 Advanced Tree Topics
- **Should Know:** Lowest Common Ancestor (LCA) — naive, binary lifting, Euler tour + RMQ
- **Should Know:** Tree DP — subtree problems, path problems
- **Nice to Have:** Heavy-Light Decomposition
- **Nice to Have:** Euler tour for subtree queries

### ✅ Checklist – Trees
- [ ] All traversals implemented (recursive & iterative)
- [ ] BST operations mastered (insert, delete, search, validate)
- [ ] AVL / Red-Black tree concepts understood
- [ ] Segment tree with lazy propagation implemented
- [ ] Fenwick tree implemented
- [ ] Trie implemented for prefix matching
- [ ] LCA algorithm implemented
- [ ] Tree DP problems solved

---

## 6. Heaps & Priority Queues

### 6.1 Heap Fundamentals
- **Must Know:** Min-heap, max-heap — properties, array representation
- **Must Know:** Sift-up, sift-down operations
- **Must Know:** Build-heap in O(n) — bottom-up construction
- **Must Know:** `std::priority_queue` — default max-heap, custom comparator

### 6.2 Heap Patterns
- **Must Know:** Top-K elements (min-heap of size K)
- **Must Know:** Kth largest / smallest element
- **Must Know:** Merge K sorted streams (min-heap of iterators)
- **Should Know:** Two-heap technique — median maintenance (max-heap + min-heap)

### 6.3 Advanced Heaps
- **Should Know:** D-ary heaps — trade-offs with binary heaps
- **Nice to Have:** Fibonacci heaps — O(1) decrease-key (conceptual)
- **Nice to Have:** Indexed priority queues — update priority by key

### ✅ Checklist – Heaps & Priority Queues
- [ ] Min-heap / max-heap implemented from scratch
- [ ] Top-K pattern with `priority_queue` applied
- [ ] Two-heap median technique implemented
- [ ] Merge K sorted lists using min-heap solved
- [ ] Custom comparator with `priority_queue` used

---

## 7. Graphs

### 7.1 Graph Representations
- **Must Know:** Adjacency list — `vector<vector<int>>` or `vector<vector<pair<int,int>>>`
- **Must Know:** Adjacency matrix — when to use (dense graphs)
- **Should Know:** Edge list — for Kruskal's algorithm

### 7.2 Graph Traversals
- **Must Know:** BFS — shortest path in unweighted graphs, level-order
- **Must Know:** DFS — connectivity, cycle detection, topological ordering
- **Should Know:** Iterative DFS — explicit stack to avoid recursion limits
- **Should Know:** Multi-source BFS — simultaneous expansion from multiple sources
- **Nice to Have:** Iterative deepening DFS (IDDFS)

### 7.3 Shortest Path Algorithms
- **Must Know:** Dijkstra's — non-negative weighted shortest path, O((V+E) log V)
- **Must Know:** BFS — unweighted shortest path
- **Should Know:** Bellman-Ford — handles negative weights, O(VE)
- **Should Know:** Floyd-Warshall — all-pairs shortest path, O(V³)
- **Nice to Have:** A* — heuristic-guided search
- **Nice to Have:** 0-1 BFS — for graphs with edge weights 0 or 1

### 7.4 Minimum Spanning Tree
- **Must Know:** Kruskal's algorithm — sort edges + Union-Find
- **Must Know:** Prim's algorithm — greedy expansion with priority queue
- **Should Know:** When to prefer Kruskal's vs Prim's

### 7.5 Topological Sort
- **Must Know:** Kahn's algorithm — BFS with in-degree tracking
- **Must Know:** DFS-based topological sort
- **Must Know:** Applications — dependency resolution, course scheduling

### 7.6 Union-Find (Disjoint Set Union)
- **Must Know:** Find with path compression
- **Must Know:** Union by rank / union by size
- **Must Know:** Applications — connectivity, Kruskal's, cycle detection in undirected graphs

### 7.7 Advanced Graph Algorithms
- **Should Know:** Strongly connected components — Tarjan's algorithm, Kosaraju's
- **Should Know:** Articulation points and bridges
- **Should Know:** Bipartite checking (2-coloring)
- **Nice to Have:** Graph coloring
- **Nice to Have:** Euler paths and circuits
- **Nice to Have:** Network flow — Ford-Fulkerson, max-flow min-cut

### ✅ Checklist – Graphs
- [ ] BFS & DFS implemented (recursive & iterative)
- [ ] Dijkstra's algorithm implemented with priority queue
- [ ] Bellman-Ford implemented
- [ ] Kruskal's & Prim's MST implemented
- [ ] Topological sort (BFS & DFS variants) implemented
- [ ] Union-Find with path compression & union by rank implemented
- [ ] Cycle detection — directed (DFS coloring) & undirected (Union-Find)
- [ ] SCC / Articulation points explored

---

## 8. Recursion & Backtracking

### 8.1 Recursion Fundamentals
- **Must Know:** Base case, recursive case, call stack mechanics
- **Must Know:** Recursion vs iteration trade-offs
- **Should Know:** Tail recursion, tail call optimization
- **Should Know:** Stack overflow prevention — depth limits, iterative conversion

### 8.2 Divide and Conquer
- **Must Know:** Merge sort — O(n log n), stable
- **Must Know:** Quick sort — O(n log n) average, partitioning schemes (Lomuto, Hoare)
- **Should Know:** Closest pair of points — O(n log n)
- **Should Know:** Karatsuba multiplication (concept)

### 8.3 Backtracking
- **Must Know:** Generate permutations, combinations, subsets
- **Must Know:** N-Queens problem
- **Must Know:** Sudoku solver
- **Should Know:** Constraint satisfaction, pruning techniques
- **Should Know:** Duplicate handling via sorting + skip logic
- **Nice to Have:** Branch and bound optimization

### 8.4 Memoization
- **Must Know:** Memoization as bridge from recursion to DP
- **Must Know:** Top-down DP via recursive + cache
- **Should Know:** Memoization with hash maps vs arrays

### ✅ Checklist – Recursion & Backtracking
- [ ] Recursion fundamentals solid (base case, stack, complexity)
- [ ] Merge sort & quick sort implemented
- [ ] Permutations, combinations, subsets generated
- [ ] N-Queens / Sudoku solver implemented
- [ ] Memoization applied to convert recursion to DP

---

## 9. Dynamic Programming

### 9.1 1D Dynamic Programming
- **Must Know:** Fibonacci, climbing stairs, min cost climbing stairs
- **Must Know:** House robber (I & II)
- **Must Know:** Coin change — minimum coins
- **Must Know:** Longest increasing subsequence (LIS) — O(n log n) with patience sorting
- **Should Know:** Word break, decode ways
- **Should Know:** Maximum product subarray
- **Should Know:** Partition equal subset sum (0/1 knapsack)

### 9.2 2D Dynamic Programming
- **Must Know:** Grid unique paths
- **Must Know:** Longest common subsequence (LCS)
- **Must Know:** Edit distance (Levenshtein)
- **Should Know:** Coin change II (counting combinations)
- **Should Know:** Interleaving string
- **Should Know:** Target sum (subset sum with +/-)
- **Nice to Have:** Distinct subsequences

### 9.3 Knapsack Variants
- **Must Know:** 0/1 Knapsack — include/exclude, space optimization
- **Must Know:** Unbounded knapsack — coin change style
- **Should Know:** Fractional knapsack (greedy, not DP)
- **Nice to Have:** Multi-dimensional knapsack

### 9.4 Interval DP
- **Should Know:** Matrix chain multiplication
- **Should Know:** Burst balloons
- **Nice to Have:** Optimal BST construction

### 9.5 DP on Trees & Graphs
- **Should Know:** Tree DP — subtree size, tree diameter, max path sum
- **Nice to Have:** DP on DAG — shortest/longest path
- **Nice to Have:** DP with bitmask — Traveling Salesman Problem (TSP)

### 9.6 String DP
- **Must Know:** Palindromic subsequences / substrings
- **Should Know:** Regular expression matching
- **Should Know:** Wildcard matching
- **Nice to Have:** Interleaving string

### 9.7 State Machine DP
- **Should Know:** Stock buy-sell problems (with cooldown, transaction limits)
- **Should Know:** State transition diagrams for DP

### 9.8 DP Optimization
- **Should Know:** Space optimization — rolling array, 1D from 2D
- **Nice to Have:** Knuth's optimization
- **Nice to Have:** Convex Hull Trick
- **Nice to Have:** Divide and conquer DP optimization

### ✅ Checklist – Dynamic Programming
- [ ] 1D DP: coin change, LIS, house robber, word break solved
- [ ] 2D DP: LCS, edit distance, grid paths solved
- [ ] Knapsack variants (0/1, unbounded) mastered
- [ ] Interval DP: matrix chain multiplication / burst balloons solved
- [ ] Tree DP applied
- [ ] State machine DP (stock problems) solved
- [ ] Space optimization techniques applied
- [ ] Top-down vs bottom-up trade-offs understood

---

## 10. Sorting & Searching

### 10.1 Comparison-Based Sorting
- **Must Know:** Merge sort — O(n log n), stable, divide and conquer
- **Must Know:** Quick sort — O(n log n) average, in-place, Lomuto vs Hoare partition
- **Must Know:** Heap sort — O(n log n), in-place, not stable
- **Must Know:** Stability concept — preserving relative order of equal elements

### 10.2 Non-Comparison Sorting
- **Should Know:** Counting sort — O(n+k), integer keys
- **Should Know:** Radix sort — O(d(n+k)), digit-by-digit
- **Should Know:** Bucket sort — O(n) average for uniform distribution

### 10.3 Binary Search
- **Must Know:** Classic binary search — sorted array, O(log n)
- **Must Know:** Binary search on answer — minimize/maximize under constraint
- **Must Know:** Search in rotated sorted array
- **Must Know:** `std::lower_bound`, `std::upper_bound` — bisect left/right
- **Should Know:** Binary search on real numbers (floating-point)

### 10.4 Selection Algorithms
- **Should Know:** Quickselect — O(n) average for kth element
- **Should Know:** `std::nth_element` — partial sorting
- **Nice to Have:** Median of medians — O(n) worst-case selection

### 10.5 C++ STL Sorting
- **Must Know:** `std::sort` (introsort), `std::stable_sort` (merge sort)
- **Should Know:** `std::partial_sort`, `std::nth_element`
- **Should Know:** Custom comparators — lambda, function objects

### ✅ Checklist – Sorting & Searching
- [ ] Merge sort, quick sort, heap sort implemented from scratch
- [ ] Stability and complexity for all major sorts known
- [ ] Binary search — classic, on answer, rotated array mastered
- [ ] Quickselect implemented
- [ ] Counting sort / radix sort implemented
- [ ] STL sort functions used with custom comparators

---

## 11. Greedy Algorithms

### 11.1 Classic Greedy Problems
- **Must Know:** Activity selection / interval scheduling
- **Must Know:** Fractional knapsack
- **Should Know:** Huffman coding
- **Should Know:** Job scheduling with deadlines

### 11.2 Greedy Proof Techniques
- **Must Know:** Greedy choice property — local optimal leads to global optimal
- **Should Know:** Exchange argument — prove no better solution exists
- **Should Know:** Matroid theory (conceptual)

### 11.3 Greedy vs DP
- **Must Know:** When greedy works vs when DP is needed
- **Must Know:** Identifying greedy-compatible problems
- **Should Know:** Counter-examples showing greedy failure

### 11.4 Graph-Based Greedy
- **Must Know:** Kruskal's & Prim's as greedy MST algorithms
- **Must Know:** Dijkstra's as greedy shortest path
- **Should Know:** Minimum platforms, gas station problem

### ✅ Checklist – Greedy Algorithms
- [ ] Activity selection / interval scheduling solved
- [ ] Huffman coding implemented
- [ ] Greedy choice property articulated and proved for key problems
- [ ] Greedy vs DP distinction clear with examples
- [ ] MST & shortest path as greedy applications

---

## 12. Bit Manipulation

### 12.1 Bitwise Operators
- **Must Know:** AND, OR, XOR, NOT, left/right shift
- **Must Know:** Check if bit is set, set/clear/toggle a bit
- **Must Know:** Check if power of 2 — `n & (n-1) == 0`

### 12.2 XOR Properties
- **Must Know:** `a ^ a = 0`, `a ^ 0 = a` — finding single number
- **Must Know:** XOR for finding missing number
- **Should Know:** XOR swap trick

### 12.3 Counting Bits
- **Must Know:** `__builtin_popcount()`, Brian Kernighan's algorithm
- **Should Know:** Counting bits for all numbers 0..n (DP approach)

### 12.4 Bitmask Techniques
- **Should Know:** Bitmask DP — subset enumeration
- **Should Know:** Subset iteration — `for (int s = mask; s; s = (s-1) & mask)`
- **Nice to Have:** Bit manipulation in system programming — flags, permissions, protocol fields

### ✅ Checklist – Bit Manipulation
- [ ] Bitwise operations fluent (set, clear, toggle, check)
- [ ] XOR single number / missing number solved
- [ ] Bit counting techniques known
- [ ] Bitmask DP applied (subset problems)
- [ ] Power of 2 checks and tricks memorized

---

## 13. Advanced Data Structures

### 13.1 Disjoint Set Union (Union-Find)
- **Must Know:** Path compression + union by rank
- **Must Know:** Nearly O(α(n)) amortized operations
- **Must Know:** Applications — connectivity, MST, cycle detection

### 13.2 Sparse Tables
- **Should Know:** Static Range Minimum Query (RMQ) in O(1) after O(n log n) preprocessing
- **Should Know:** Idempotent operations (min, max, gcd)

### 13.3 Suffix Structures
- **Nice to Have:** Suffix arrays — O(n log n) construction, pattern matching
- **Nice to Have:** Suffix trees — all occurrences, longest repeated substring
- **Nice to Have:** Suffix automaton (SAM)

### 13.4 Advanced Balanced BSTs
- **Nice to Have:** Treaps — randomized BST with heap property
- **Nice to Have:** Splay trees — amortized O(log n) with move-to-root

### 13.5 Persistent Data Structures
- **Nice to Have:** Persistent segment trees — version history
- **Nice to Have:** Fat node technique

### 13.6 Spatial Data Structures
- **Nice to Have:** Interval trees — overlapping interval queries
- **Nice to Have:** K-D trees — multidimensional range queries

### ✅ Checklist – Advanced Data Structures
- [ ] Union-Find with path compression + union by rank implemented
- [ ] Sparse table for RMQ implemented
- [ ] Suffix array concept understood
- [ ] At least one advanced BST variant explored
- [ ] Persistent segment tree concept understood

---

## 14. Complexity Analysis & Problem-Solving Strategies

### 14.1 Asymptotic Analysis
- **Must Know:** Big-O (upper bound), Big-Ω (lower bound), Big-Θ (tight bound)
- **Must Know:** Common complexities: O(1), O(log n), O(n), O(n log n), O(n²), O(2ⁿ), O(n!)
- **Should Know:** Amortized analysis — aggregate, accounting, potential methods
- **Should Know:** Master theorem for recurrence relations

### 14.2 Space-Time Trade-offs
- **Must Know:** Hash map for O(1) lookup at cost of O(n) space
- **Must Know:** Sorting to enable binary search or two-pointer
- **Should Know:** Auxiliary space vs in-place algorithms

### 14.3 Problem-Solving Methodology
- **Must Know:** Pattern recognition — identify which DS/algorithm fits
- **Must Know:** Brute-force → optimize approach
- **Must Know:** Constraint analysis — derive time complexity from input size
- **Should Know:** Stress testing — validate against brute-force with random inputs
- **Should Know:** Edge case identification — empty, single, large, negative, overflow

### ✅ Checklist – Complexity Analysis
- [ ] Big-O for all standard algorithms known
- [ ] Amortized analysis understood (vector push_back, Union-Find)
- [ ] Master theorem applied to recurrences
- [ ] Problem-solving methodology internalized
- [ ] Constraint-to-complexity mapping memorized (n≤10⁵ → O(n log n), etc.)
