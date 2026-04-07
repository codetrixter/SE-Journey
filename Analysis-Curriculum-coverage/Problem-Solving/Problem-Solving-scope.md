# Problem Solving (NeetCode 250) — Mastery Scope for 10+ Years Experience

---

## 📊 Master Progress Tracker

| Section | Must Know Done | Should Know Done | Nice to Have Done | Avg Solve Time | Last Reviewed | Notes |
|--------------------------|----------------|------------------|-------------------|----------------|---------------|-------|
| Arrays & Hashing | | | | | | |
| Two Pointers | | | | | | |
| Sliding Window | | | | | | |
| Stack | | | | | | |
| Binary Search | | | | | | |
| Linked List | | | | | | |
| Trees | | | | | | |
| Tries | | | | | | |
| Heap / Priority Queue | | | | | | |
| Backtracking | | | | | | |
| Graphs | | | | | | |
| Advanced Graphs | | | | | | |
| 1-D Dynamic Programming | | | | | | |
| 2-D Dynamic Programming | | | | | | |
| Greedy | | | | | | |
| Intervals | | | | | | |
| Math & Geometry | | | | | | |
| Bit Manipulation | | | | | | |

**Timing Benchmarks:** Easy < 10 min | Medium < 20 min | Hard < 35 min

---

## Table of Contents

1. [Arrays & Hashing](#1-arrays--hashing)
2. [Two Pointers](#2-two-pointers)
3. [Sliding Window](#3-sliding-window)
4. [Stack](#4-stack)
5. [Binary Search](#5-binary-search)
6. [Linked List](#6-linked-list)
7. [Trees](#7-trees)
8. [Tries](#8-tries)
9. [Heap / Priority Queue](#9-heap--priority-queue)
10. [Backtracking](#10-backtracking)
11. [Graphs](#11-graphs)
12. [Advanced Graphs](#12-advanced-graphs)
13. [1-D Dynamic Programming](#13-1-d-dynamic-programming)
14. [2-D Dynamic Programming](#14-2-d-dynamic-programming)
15. [Greedy](#15-greedy)
16. [Intervals](#16-intervals)
17. [Math & Geometry](#17-math--geometry)
18. [Bit Manipulation](#18-bit-manipulation)

---

## 1. Arrays & Hashing

### Key Patterns
- **Must Know:** Hash map for O(1) lookup — frequency counting, index tracking
- **Must Know:** Hash set for duplicate detection
- **Must Know:** Prefix products — product of array except self without division
- **Must Know:** Sorting + hashing combination

### Curated Problem Set
- [ ] Two Sum [Easy] [Blind75] [NeetCode250]
- [ ] Contains Duplicate [Easy] [Blind75] [NeetCode250]
- [ ] Valid Anagram [Easy] [Blind75] [NeetCode250]
- [ ] Group Anagrams [Medium] [Blind75] [NeetCode250]
- [ ] Top K Frequent Elements [Medium] [Blind75] [NeetCode250]
- [ ] Product of Array Except Self [Medium] [Blind75] [NeetCode250]
- [ ] Valid Sudoku [Medium] [NeetCode250]
- [ ] Encode and Decode Strings [Medium] [Blind75] [NeetCode250]
- [ ] Longest Consecutive Sequence [Medium] [Blind75] [NeetCode250]

### Edge Cases
- Empty arrays, single element, all duplicates
- Negative numbers, zero, integer overflow
- Very large input sizes (constraint: n ≤ 10⁵ → O(n) or O(n log n))

### ✅ Checklist – Arrays & Hashing
- [ ] Pattern mastered: frequency map, index map, set operations
- [ ] Core problems solved: ___/9
- [ ] Can solve Medium in < 20 min
- [ ] Hash map vs hash set decision clear
- [ ] Edge cases handled (empty, duplicates, overflow)

---

## 2. Two Pointers

### Key Patterns
- **Must Know:** Opposing pointers — converge from both ends (sorted array)
- **Must Know:** Same-direction pointers — partition, remove duplicates
- **Must Know:** Squeeze technique — maximize/minimize area/distance
- **Should Know:** When to sort first vs preserve order

### Curated Problem Set
- [ ] Valid Palindrome [Easy] [Blind75] [NeetCode250]
- [ ] Two Sum II (sorted input) [Medium] [Blind75] [NeetCode250]
- [ ] 3Sum [Medium] [Blind75] [NeetCode250]
- [ ] Container With Most Water [Medium] [Blind75] [NeetCode250]
- [ ] Trapping Rain Water [Hard] [Blind75] [NeetCode250]

### Edge Cases
- Duplicates in multi-sum problems (skip logic)
- Empty or single-element input
- All same values

### ✅ Checklist – Two Pointers
- [ ] Pattern mastered: opposing, same-direction, squeeze
- [ ] Core problems solved: ___/5
- [ ] 3Sum duplicate handling clean
- [ ] Trapping Rain Water solved (two-pointer + stack approaches)
- [ ] Can identify when two-pointer applies vs hash map

---

## 3. Sliding Window

### Key Patterns
- **Must Know:** Fixed-size window — max sum of k elements
- **Must Know:** Variable-size window — expand right, shrink left based on constraint
- **Must Know:** Shrinkable window — track valid window, update answer
- **Should Know:** Window with frequency map — permutation/anagram matching

### Curated Problem Set
- [ ] Best Time to Buy and Sell Stock [Easy] [Blind75] [NeetCode250]
- [ ] Longest Substring Without Repeating Characters [Medium] [Blind75] [NeetCode250]
- [ ] Longest Repeating Character Replacement [Medium] [Blind75] [NeetCode250]
- [ ] Permutation in String [Medium] [NeetCode250]
- [ ] Minimum Window Substring [Hard] [Blind75] [NeetCode250]
- [ ] Sliding Window Maximum [Hard] [NeetCode250]

### Edge Cases
- Empty string, window larger than input
- All same characters, all unique characters
- Minimum valid window is entire string

### ✅ Checklist – Sliding Window
- [ ] Pattern mastered: fixed-size, variable-size, shrinkable
- [ ] Core problems solved: ___/6
- [ ] Can articulate when sliding window applies (contiguous subarray/substring)
- [ ] Window + frequency map combination fluent
- [ ] Sliding Window Maximum with monotonic deque solved

---

## 4. Stack

### Key Patterns
- **Must Know:** Matching/balancing — parentheses, brackets
- **Must Know:** Monotonic stack — next greater/smaller element in O(n)
- **Must Know:** Stack for expression evaluation — postfix, infix
- **Should Know:** Stack for simulation/history tracking

### Curated Problem Set
- [ ] Valid Parentheses [Easy] [Blind75] [NeetCode250]
- [ ] Min Stack [Medium] [Blind75] [NeetCode250]
- [ ] Evaluate Reverse Polish Notation [Medium] [NeetCode250]
- [ ] Generate Parentheses [Medium] [Blind75] [NeetCode250]
- [ ] Daily Temperatures [Medium] [NeetCode250]
- [ ] Car Fleet [Medium] [NeetCode250]
- [ ] Largest Rectangle in Histogram [Hard] [NeetCode250]

### Edge Cases
- Empty stack operations, single element
- Deeply nested structures
- All increasing / all decreasing sequences (monotonic stack)

### ✅ Checklist – Stack
- [ ] Pattern mastered: matching, monotonic, evaluation
- [ ] Core problems solved: ___/7
- [ ] Monotonic stack template memorized (next greater element)
- [ ] Largest Rectangle in Histogram solved
- [ ] Can explain stack-based approaches clearly in interview

---

## 5. Binary Search

### Key Patterns
- **Must Know:** Classic binary search — sorted array, O(log n)
- **Must Know:** Binary search on answer — minimize/maximize value under constraint
- **Must Know:** Search in rotated sorted array — identify sorted half
- **Should Know:** Bisect left vs bisect right — `lower_bound` / `upper_bound`

### Curated Problem Set
- [ ] Binary Search [Easy] [NeetCode250]
- [ ] Search a 2D Matrix [Medium] [Blind75] [NeetCode250]
- [ ] Koko Eating Bananas [Medium] [NeetCode250]
- [ ] Find Minimum in Rotated Sorted Array [Medium] [Blind75] [NeetCode250]
- [ ] Search in Rotated Sorted Array [Medium] [Blind75] [NeetCode250]
- [ ] Time Based Key-Value Store [Medium] [NeetCode250]
- [ ] Median of Two Sorted Arrays [Hard] [Blind75] [NeetCode250]

### Edge Cases
- Single element, all same elements
- Element not found
- Integer overflow in `mid = (low + high) / 2` → use `low + (high - low) / 2`

### ✅ Checklist – Binary Search
- [ ] Pattern mastered: classic, on answer, rotated
- [ ] Core problems solved: ___/7
- [ ] Binary search template (inclusive/exclusive bounds) memorized
- [ ] "Binary search on answer" pattern identified independently
- [ ] Overflow-safe mid calculation used consistently

---

## 6. Linked List

### Key Patterns
- **Must Know:** Fast-slow pointers — cycle detection, middle finding
- **Must Know:** Dummy head — simplify edge cases for insertion/deletion
- **Must Know:** Iterative vs recursive reversal
- **Must Know:** Merge technique — merge two sorted lists
- **Should Know:** Copy with random pointer — clone with hash map

### Curated Problem Set
- [ ] Reverse Linked List [Easy] [Blind75] [NeetCode250]
- [ ] Merge Two Sorted Lists [Easy] [Blind75] [NeetCode250]
- [ ] Reorder List [Medium] [Blind75] [NeetCode250]
- [ ] Remove Nth Node From End [Medium] [Blind75] [NeetCode250]
- [ ] Copy List with Random Pointer [Medium] [NeetCode250]
- [ ] Add Two Numbers [Medium] [Blind75] [NeetCode250]
- [ ] Linked List Cycle [Easy] [Blind75] [NeetCode250]
- [ ] Find the Duplicate Number [Medium] [NeetCode250]
- [ ] LRU Cache [Medium] [Blind75] [NeetCode250]
- [ ] Merge K Sorted Lists [Hard] [Blind75] [NeetCode250]
- [ ] Reverse Nodes in K-Group [Hard] [NeetCode250]

### Edge Cases
- Empty list, single node
- Cycle at head or tail
- K larger than list length

### ✅ Checklist – Linked List
- [ ] Pattern mastered: fast-slow, dummy head, reversal, merge
- [ ] Core problems solved: ___/11
- [ ] LRU Cache implemented (doubly linked list + hash map)
- [ ] K-group reversal solved
- [ ] Can draw pointer diagrams to explain approach

---

## 7. Trees

### Key Patterns
- **Must Know:** DFS — preorder, inorder, postorder (recursive & iterative)
- **Must Know:** BFS — level-order traversal with queue
- **Must Know:** Recursive tree structure — base case (null), recursive case (left/right)
- **Must Know:** BST property — left < root < right, inorder = sorted
- **Should Know:** Tree construction from traversal pairs
- **Should Know:** Path problems — max path sum, diameter

### Curated Problem Set
- [ ] Invert Binary Tree [Easy] [Blind75] [NeetCode250]
- [ ] Maximum Depth of Binary Tree [Easy] [Blind75] [NeetCode250]
- [ ] Diameter of Binary Tree [Easy] [Blind75] [NeetCode250]
- [ ] Balanced Binary Tree [Easy] [NeetCode250]
- [ ] Same Tree [Easy] [Blind75] [NeetCode250]
- [ ] Subtree of Another Tree [Easy] [Blind75] [NeetCode250]
- [ ] Lowest Common Ancestor of BST [Medium] [Blind75] [NeetCode250]
- [ ] Binary Tree Level Order Traversal [Medium] [Blind75] [NeetCode250]
- [ ] Binary Tree Right Side View [Medium] [NeetCode250]
- [ ] Count Good Nodes in Binary Tree [Medium] [NeetCode250]
- [ ] Validate Binary Search Tree [Medium] [Blind75] [NeetCode250]
- [ ] Kth Smallest Element in BST [Medium] [Blind75] [NeetCode250]
- [ ] Construct Binary Tree from Preorder and Inorder [Medium] [Blind75] [NeetCode250]
- [ ] Binary Tree Maximum Path Sum [Hard] [Blind75] [NeetCode250]
- [ ] Serialize and Deserialize Binary Tree [Hard] [Blind75] [NeetCode250]

### Edge Cases
- Empty tree, single node
- Skewed tree (like a linked list)
- Negative values in path sum problems
- BST with duplicates

### ✅ Checklist – Trees
- [ ] Pattern mastered: DFS (all orders), BFS, recursive structure
- [ ] Core problems solved: ___/15
- [ ] Iterative traversals implemented (using stack)
- [ ] BST validation and search mastered
- [ ] Maximum path sum solved (global variable pattern)
- [ ] Serialize/Deserialize implemented

---

## 8. Tries

### Key Patterns
- **Must Know:** Trie node structure — children array/map, `isEnd` flag
- **Must Know:** Insert, search, prefix search — O(word length)
- **Should Know:** Wildcard search — DFS with backtracking on '.'
- **Should Know:** Trie + backtracking — Word Search II

### Curated Problem Set
- [ ] Implement Trie (Prefix Tree) [Medium] [Blind75] [NeetCode250]
- [ ] Design Add and Search Words Data Structure [Medium] [Blind75] [NeetCode250]
- [ ] Word Search II [Hard] [Blind75] [NeetCode250]

### Edge Cases
- Empty string, single character
- Overlapping prefixes
- Words that are prefixes of other words

### ✅ Checklist – Tries
- [ ] Pattern mastered: trie insert/search/prefix
- [ ] Core problems solved: ___/3
- [ ] Trie node implementation clean (array vs map trade-off)
- [ ] Word Search II solved with trie + backtracking
- [ ] Trie vs hash map trade-offs articulated

---

## 9. Heap / Priority Queue

### Key Patterns
- **Must Know:** Min-heap for top-K largest elements
- **Must Know:** Max-heap for top-K smallest elements
- **Must Know:** Two-heap technique — median maintenance
- **Should Know:** Lazy deletion — mark deleted, skip when popped
- **Should Know:** Custom comparators with `std::priority_queue`

### Curated Problem Set
- [ ] Kth Largest Element in a Stream [Easy] [NeetCode250]
- [ ] Last Stone Weight [Easy] [NeetCode250]
- [ ] K Closest Points to Origin [Medium] [NeetCode250]
- [ ] Kth Largest Element in an Array [Medium] [Blind75] [NeetCode250]
- [ ] Task Scheduler [Medium] [NeetCode250]
- [ ] Design Twitter [Medium] [NeetCode250]
- [ ] Find Median from Data Stream [Hard] [Blind75] [NeetCode250]

### Edge Cases
- K larger than array, single element
- All same values, all equal distances
- Stream with few elements

### ✅ Checklist – Heap / Priority Queue
- [ ] Pattern mastered: top-K, two-heap, custom comparator
- [ ] Core problems solved: ___/7
- [ ] Find Median from Data Stream — two-heap approach clean
- [ ] Task Scheduler solved with greedy + heap
- [ ] `priority_queue` with custom comparator fluent

---

## 10. Backtracking

### Key Patterns
- **Must Know:** Include/exclude decisions — subsets
- **Must Know:** Permutation generation — swap or used-array approach
- **Must Know:** Combination generation — start index to avoid duplicates
- **Must Know:** Constraint checking — prune invalid branches early
- **Should Know:** Duplicate handling — sort + skip adjacent duplicates

### Curated Problem Set
- [ ] Subsets [Medium] [Blind75] [NeetCode250]
- [ ] Subsets II [Medium] [NeetCode250]
- [ ] Combination Sum [Medium] [Blind75] [NeetCode250]
- [ ] Combination Sum II [Medium] [NeetCode250]
- [ ] Permutations [Medium] [NeetCode250]
- [ ] Word Search [Medium] [Blind75] [NeetCode250]
- [ ] Palindrome Partitioning [Medium] [NeetCode250]
- [ ] N-Queens [Hard] [NeetCode250]
- [ ] Letter Combinations of a Phone Number [Medium] [NeetCode250]

### Edge Cases
- Empty input, single element
- All elements identical
- No valid solution exists
- Very deep recursion (stack overflow risk)

### ✅ Checklist – Backtracking
- [ ] Pattern mastered: subsets, combinations, permutations
- [ ] Core problems solved: ___/9
- [ ] Duplicate handling with sort + skip implemented cleanly
- [ ] N-Queens solved with column/diagonal tracking
- [ ] Backtracking template memorized (choose → explore → unchoose)

---

## 11. Graphs

### Key Patterns
- **Must Know:** BFS — shortest path in unweighted graphs, level-by-level exploration
- **Must Know:** DFS — connectivity, cycle detection, exhaustive search
- **Must Know:** Topological sort — dependency ordering (Kahn's BFS / DFS-based)
- **Must Know:** Union-Find — connectivity queries, cycle detection in undirected
- **Should Know:** Multi-source BFS — simultaneous expansion from multiple starting points

### Curated Problem Set
- [ ] Number of Islands [Medium] [Blind75] [NeetCode250]
- [ ] Max Area of Island [Medium] [NeetCode250]
- [ ] Clone Graph [Medium] [Blind75] [NeetCode250]
- [ ] Walls and Gates [Medium] [NeetCode250]
- [ ] Rotting Oranges [Medium] [NeetCode250]
- [ ] Pacific Atlantic Water Flow [Medium] [Blind75] [NeetCode250]
- [ ] Surrounded Regions [Medium] [NeetCode250]
- [ ] Course Schedule [Medium] [Blind75] [NeetCode250]
- [ ] Course Schedule II [Medium] [NeetCode250]
- [ ] Graph Valid Tree [Medium] [Blind75] [NeetCode250]
- [ ] Number of Connected Components [Medium] [Blind75] [NeetCode250]
- [ ] Redundant Connection [Medium] [NeetCode250]
- [ ] Word Ladder [Hard] [NeetCode250]

### Edge Cases
- Disconnected graph, single node, no edges
- Self-loops, multiple edges between same nodes
- Large graphs (constraint-driven: use BFS/DFS not Floyd-Warshall)

### ✅ Checklist – Graphs
- [ ] Pattern mastered: BFS, DFS, topological sort, Union-Find
- [ ] Core problems solved: ___/13
- [ ] Grid-as-graph problems fluent (islands, rotting oranges)
- [ ] Topological sort applied for dependency resolution
- [ ] Cycle detection — directed (3-color DFS) vs undirected (Union-Find)
- [ ] Multi-source BFS applied

---

## 12. Advanced Graphs

### Key Patterns
- **Must Know:** Dijkstra's — weighted shortest path with priority queue
- **Should Know:** Bellman-Ford — handles negative weights, K-stops constraint
- **Should Know:** Kruskal's / Prim's — minimum spanning tree
- **Should Know:** Modified BFS/DFS with additional state dimension

### Curated Problem Set
- [ ] Reconstruct Itinerary [Hard] [NeetCode250]
- [ ] Min Cost to Connect All Points [Medium] [NeetCode250]
- [ ] Network Delay Time [Medium] [NeetCode250]
- [ ] Swim in Rising Water [Hard] [NeetCode250]
- [ ] Alien Dictionary [Hard] [Blind75] [NeetCode250]
- [ ] Cheapest Flights Within K Stops [Medium] [NeetCode250]

### Edge Cases
- Negative weights (use Bellman-Ford, not Dijkstra)
- Unreachable nodes
- Multiple valid topological orderings

### ✅ Checklist – Advanced Graphs
- [ ] Pattern mastered: Dijkstra, Bellman-Ford, MST
- [ ] Core problems solved: ___/6
- [ ] Dijkstra with `priority_queue` implemented cleanly
- [ ] K-stops constraint handled (Bellman-Ford variant)
- [ ] Alien Dictionary — topological sort on characters

---

## 13. 1-D Dynamic Programming

### Key Patterns
- **Must Know:** State definition — what does `dp[i]` represent?
- **Must Know:** Transition formula — `dp[i] = f(dp[i-1], dp[i-2], ...)`
- **Must Know:** Base cases — initial values for smallest subproblems
- **Must Know:** Space optimization — O(n) → O(1) when only previous states needed
- **Should Know:** Top-down (memoization) vs bottom-up (tabulation)
- **Should Know:** State machine DP — stock problems with states

### Curated Problem Set
- [ ] Climbing Stairs [Easy] [Blind75] [NeetCode250]
- [ ] Min Cost Climbing Stairs [Easy] [NeetCode250]
- [ ] House Robber [Medium] [Blind75] [NeetCode250]
- [ ] House Robber II [Medium] [Blind75] [NeetCode250]
- [ ] Longest Palindromic Substring [Medium] [Blind75] [NeetCode250]
- [ ] Palindromic Substrings [Medium] [Blind75] [NeetCode250]
- [ ] Decode Ways [Medium] [Blind75] [NeetCode250]
- [ ] Coin Change [Medium] [Blind75] [NeetCode250]
- [ ] Maximum Product Subarray [Medium] [Blind75] [NeetCode250]
- [ ] Word Break [Medium] [Blind75] [NeetCode250]
- [ ] Longest Increasing Subsequence [Medium] [Blind75] [NeetCode250]
- [ ] Partition Equal Subset Sum [Medium] [NeetCode250]

### Edge Cases
- Empty input, single element
- All negative values (product subarray)
- Very large input (space optimization needed)
- Integer overflow in accumulation

### ✅ Checklist – 1-D Dynamic Programming
- [ ] Pattern mastered: state definition, transition, base case, space optimization
- [ ] Core problems solved: ___/12
- [ ] Coin Change solved (both min coins and counting ways)
- [ ] LIS — O(n log n) patience sorting approach known
- [ ] House Robber circular variant handled
- [ ] Top-down vs bottom-up trade-offs articulated

---

## 14. 2-D Dynamic Programming

### Key Patterns
- **Must Know:** Grid DP — paths, min cost, obstacles
- **Must Know:** String DP — LCS, edit distance, subsequence problems
- **Should Know:** Interval DP — burst balloons, matrix chain
- **Should Know:** Knapsack variants — count vs min/max, bounded vs unbounded
- **Should Know:** State compression — rolling array, reducing 2D to 1D

### Curated Problem Set
- [ ] Unique Paths [Medium] [Blind75] [NeetCode250]
- [ ] Longest Common Subsequence [Medium] [Blind75] [NeetCode250]
- [ ] Best Time to Buy and Sell Stock with Cooldown [Medium] [NeetCode250]
- [ ] Coin Change II [Medium] [NeetCode250]
- [ ] Target Sum [Medium] [NeetCode250]
- [ ] Interleaving String [Medium] [NeetCode250]
- [ ] Longest Increasing Path in Matrix [Hard] [NeetCode250]
- [ ] Distinct Subsequences [Hard] [NeetCode250]
- [ ] Edit Distance [Medium] [Blind75] [NeetCode250]
- [ ] Burst Balloons [Hard] [NeetCode250]
- [ ] Regular Expression Matching [Hard] [NeetCode250]

### Edge Cases
- Empty strings, zero-dimensional grids
- Very large state spaces (memory optimization critical)
- Overlapping subproblems verification

### ✅ Checklist – 2-D Dynamic Programming
- [ ] Pattern mastered: grid DP, string DP, interval DP, knapsack
- [ ] Core problems solved: ___/11
- [ ] Edit distance — insert/delete/replace transitions clear
- [ ] LCS and its variations mastered
- [ ] Burst Balloons — reverse thinking (last balloon popped) understood
- [ ] Regular Expression Matching solved

---

## 15. Greedy

### Key Patterns
- **Must Know:** Greedy choice property — local optimal → global optimal
- **Must Know:** When greedy works vs when DP is needed
- **Should Know:** Exchange argument — prove optimality
- **Should Know:** Sorting as preprocessing for greedy

### Curated Problem Set
- [ ] Maximum Subarray [Medium] [Blind75] [NeetCode250]
- [ ] Jump Game [Medium] [Blind75] [NeetCode250]
- [ ] Jump Game II [Medium] [NeetCode250]
- [ ] Gas Station [Medium] [NeetCode250]
- [ ] Hand of Straights [Medium] [NeetCode250]
- [ ] Merge Triplets to Form Target Triplet [Medium] [NeetCode250]
- [ ] Partition Labels [Medium] [NeetCode250]
- [ ] Valid Parenthesis String [Medium] [NeetCode250]

### Edge Cases
- Empty input, single element
- No valid solution
- Ties between greedy choices

### ✅ Checklist – Greedy
- [ ] Pattern mastered: greedy choice, exchange argument
- [ ] Core problems solved: ___/8
- [ ] Jump Game — farthest-reachable approach clear
- [ ] Greedy vs DP distinction with counter-examples
- [ ] Partition Labels solved with last-occurrence tracking

---

## 16. Intervals

### Key Patterns
- **Must Know:** Sort by start time (or end time depending on problem)
- **Must Know:** Merge overlapping intervals — compare current.start with prev.end
- **Must Know:** Sweep line — event-based processing of starts and ends
- **Should Know:** Gap analysis — non-overlapping intervals, minimum removals

### Curated Problem Set
- [ ] Insert Interval [Medium] [Blind75] [NeetCode250]
- [ ] Merge Intervals [Medium] [Blind75] [NeetCode250]
- [ ] Non-Overlapping Intervals [Medium] [Blind75] [NeetCode250]
- [ ] Meeting Rooms [Easy] [Blind75] [NeetCode250]
- [ ] Meeting Rooms II [Medium] [Blind75] [NeetCode250]
- [ ] Minimum Interval to Include Each Query [Hard] [NeetCode250]

### Edge Cases
- Single interval, fully overlapping, no overlap
- Point intervals (start == end)
- Intervals sorted vs unsorted input

### ✅ Checklist – Intervals
- [ ] Pattern mastered: sort + merge, sweep line, gap analysis
- [ ] Core problems solved: ___/6
- [ ] Merge Intervals template memorized
- [ ] Meeting Rooms II — min-heap approach clear
- [ ] Insert Interval edge cases handled (no overlap, full overlap)

---

## 17. Math & Geometry

### Key Patterns
- **Must Know:** Matrix manipulation — in-place rotation, transposition
- **Must Know:** Spiral traversal — layer-by-layer or direction-based
- **Should Know:** Modular arithmetic — overflow prevention, fast exponentiation
- **Should Know:** Number theory basics — GCD, prime checking

### Curated Problem Set
- [ ] Rotate Image [Medium] [Blind75] [NeetCode250]
- [ ] Spiral Matrix [Medium] [Blind75] [NeetCode250]
- [ ] Set Matrix Zeroes [Medium] [Blind75] [NeetCode250]
- [ ] Happy Number [Easy] [NeetCode250]
- [ ] Plus One [Easy] [NeetCode250]
- [ ] Pow(x, n) [Medium] [NeetCode250]
- [ ] Multiply Strings [Medium] [NeetCode250]
- [ ] Detect Squares [Medium] [NeetCode250]

### Edge Cases
- Negative numbers, zero
- Integer overflow (`INT_MIN`, `INT_MAX`)
- Floating-point precision

### ✅ Checklist – Math & Geometry
- [ ] Pattern mastered: matrix ops, modular arithmetic
- [ ] Core problems solved: ___/8
- [ ] Rotate Image — in-place with transpose + reverse
- [ ] Spiral Matrix traversal clean
- [ ] Pow(x, n) — binary exponentiation, negative exponent handled

---

## 18. Bit Manipulation

### Key Patterns
- **Must Know:** XOR properties — `a ^ a = 0`, `a ^ 0 = a`
- **Must Know:** Bit counting — `__builtin_popcount`, Brian Kernighan's
- **Must Know:** Bit masking — check/set/clear/toggle individual bits
- **Should Know:** Arithmetic with bits — add without +, multiply with shifts
- **Should Know:** Relationship to sets — bitmask for subset enumeration

### Curated Problem Set
- [ ] Single Number [Easy] [Blind75] [NeetCode250]
- [ ] Number of 1 Bits [Easy] [Blind75] [NeetCode250]
- [ ] Counting Bits [Easy] [Blind75] [NeetCode250]
- [ ] Reverse Bits [Easy] [Blind75] [NeetCode250]
- [ ] Missing Number [Easy] [Blind75] [NeetCode250]
- [ ] Sum of Two Integers [Medium] [Blind75] [NeetCode250]
- [ ] Reverse Integer [Medium] [NeetCode250]

### Edge Cases
- Negative numbers (two's complement)
- Zero
- `INT_MIN` — negation causes overflow
- 32-bit vs 64-bit differences

### ✅ Checklist – Bit Manipulation
- [ ] Pattern mastered: XOR, bit counting, masking, shifting
- [ ] Core problems solved: ___/7
- [ ] Sum without + operator — carry propagation with AND + shift
- [ ] Single Number — XOR all elements
- [ ] Missing Number — XOR or sum approach
- [ ] INT_MIN edge case handled in Reverse Integer

---

## Cross-Pattern Problem Index

Problems that combine multiple patterns:
- **Trapping Rain Water** — Two Pointers + Stack
- **LRU Cache** — Linked List + Hash Map
- **Word Search II** — Trie + Backtracking
- **Sliding Window Maximum** — Sliding Window + Monotonic Deque
- **Median from Data Stream** — Heap (Two-Heap)
- **Cheapest Flights** — Graph + DP (Bellman-Ford)
- **Course Schedule** — Graph + Topological Sort
- **Best Time to Buy/Sell with Cooldown** — DP + State Machine
- **Longest Increasing Path in Matrix** — DFS + Memoization (Tree/Graph + DP)
- **Task Scheduler** — Heap + Greedy
