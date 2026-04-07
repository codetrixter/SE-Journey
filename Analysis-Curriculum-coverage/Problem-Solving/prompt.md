# Prompt for fetching the scope of preparation of topics:
1. ***PROBLEM SOLVING (NeetCode 250 / Coding Interview Preparation)***

- Role & Goal
You are an expert competitive programmer, algorithm specialist, and coding interview coach with deep expertise in structured problem-solving methodology. Create a comprehensive, industry-ready list of problem-solving patterns, techniques, and problem categories that a software engineer with 10 years of experience should master for top-tier coding interviews (FAANG/MAANG level). The output must be well-structured, exhaustive, and actionable, with checklists and tracking metadata for mastery.

Audience Context

Experience: 10 years in software engineering
Languages: C++ (primary, with STL mastery)
Goal: systematic mastery of NeetCode 250 / Blind 75 / top interview patterns
Focus: pattern recognition, optimal solution derivation, time management, edge case handling
Interview target: 45-minute coding rounds at top-tier companies
Benchmark: solve Medium in < 20 min, Hard in < 35 min consistently

Scope (cover all sections)

## Arrays & Hashing

Two Sum, Contains Duplicate, Valid Anagram, Group Anagrams
Top K Frequent Elements, Product of Array Except Self
Valid Sudoku, Encode and Decode Strings, Longest Consecutive Sequence
Patterns: frequency maps, index maps, set operations, prefix products
Edge cases: empty arrays, single element, duplicates, negative numbers, overflow

## Two Pointers

Valid Palindrome, Two Sum II (sorted), 3Sum, Container With Most Water
Trapping Rain Water
Patterns: opposing pointers, same-direction pointers, squeeze technique
When to sort first, when order matters
Edge cases: duplicates in multi-sum, empty/single-element input

## Sliding Window

Best Time to Buy and Sell Stock, Longest Substring Without Repeating Characters
Longest Repeating Character Replacement, Permutation in String
Minimum Window Substring, Sliding Window Maximum
Patterns: fixed-size window, variable-size window, shrinkable window, window with constraints
Edge cases: empty string, window larger than input, all same characters

## Stack

Valid Parentheses, Min Stack, Evaluate Reverse Polish Notation
Generate Parentheses, Daily Temperatures, Car Fleet
Largest Rectangle in Histogram
Patterns: monotonic stack (increasing/decreasing), stack for matching, stack for history
Edge cases: empty stack, nested structures, single element

## Binary Search

Binary Search, Search a 2D Matrix, Koko Eating Bananas
Find Minimum in Rotated Sorted Array, Search in Rotated Sorted Array
Time Based Key-Value Store, Median of Two Sorted Arrays
Patterns: classic binary search, binary search on answer, search in rotated, bisect left/right
Edge cases: single element, all same, not found, overflow in mid calculation

## Linked List

Reverse Linked List, Merge Two Sorted Lists, Reorder List
Remove Nth Node From End, Copy List with Random Pointer
Add Two Numbers, Linked List Cycle (detection & start), Find the Duplicate Number
Merge K Sorted Lists, Reverse Nodes in K-Group, LRU Cache
Patterns: fast-slow pointers, dummy head, recursive vs iterative reversal, merge technique
Edge cases: empty list, single node, cycle at head/tail

## Trees

Invert Binary Tree, Maximum Depth, Diameter, Balanced Binary Tree
Same Tree, Subtree of Another Tree, Lowest Common Ancestor
Level Order Traversal, Right Side View, Count Good Nodes
Validate BST, Kth Smallest in BST, BST Construction from Preorder/Inorder
Binary Tree Maximum Path Sum, Serialize and Deserialize Binary Tree
Patterns: DFS (preorder/inorder/postorder), BFS (level-order), recursive vs iterative
Tree DP, path problems, ancestor problems, construction problems
Edge cases: empty tree, skewed tree, single node, negative values

## Tries

Implement Trie, Design Add and Search Words, Word Search II
Patterns: prefix matching, character-by-character traversal, wildcard search
Trie vs hashmap trade-offs, memory optimization
Edge cases: empty string, single character, overlapping prefixes

## Heap / Priority Queue

Kth Largest Element in a Stream, Last Stone Weight, K Closest Points to Origin
Kth Largest Element in an Array, Task Scheduler
Design Twitter, Find Median from Data Stream
Patterns: min-heap for top-K, max-heap for bottom-K, two-heap for median
Lazy deletion, custom comparators
Edge cases: K larger than array, single element, all same values

## Backtracking

Subsets, Subsets II, Combination Sum, Combination Sum II
Permutations, Word Search, Palindrome Partitioning
N-Queens, Letter Combinations of Phone Number
Patterns: include/exclude decisions, permutation vs combination, constraint propagation
Pruning strategies, duplicate handling with sorting
Edge cases: empty input, single element, all duplicates, no valid solution

## Graphs

Number of Islands, Max Area of Island, Clone Graph
Walls and Gates, Rotting Oranges, Pacific Atlantic Water Flow
Surrounded Regions, Course Schedule (I & II), Graph Valid Tree
Number of Connected Components, Redundant Connection
Word Ladder
Patterns: BFS for shortest path, DFS for connectivity, topological sort for dependencies
Union-Find for connectivity, multi-source BFS
Cycle detection: directed (DFS coloring) vs undirected (Union-Find)
Edge cases: disconnected graph, self-loops, single node, no edges

## Advanced Graphs

Reconstruct Itinerary, Min Cost to Connect All Points
Network Delay Time, Swim in Rising Water, Alien Dictionary
Cheapest Flights Within K Stops
Patterns: Dijkstra, Bellman-Ford, Kruskal/Prim, topological sort with constraints
Modified BFS/DFS with state, graph DP
Edge cases: negative weights (Bellman-Ford), unreachable nodes, multiple valid orderings

## 1-D Dynamic Programming

Climbing Stairs, Min Cost Climbing Stairs, House Robber (I & II)
Longest Palindromic Substring, Palindromic Substrings
Decode Ways, Coin Change, Maximum Product Subarray
Word Break, Longest Increasing Subsequence, Partition Equal Subset Sum
Patterns: state definition, transition formula, base cases, space optimization
Top-down (memoization) vs bottom-up (tabulation), state machine DP
Edge cases: empty input, single element, all negative, overflow

## 2-D Dynamic Programming

Unique Paths, Longest Common Subsequence, Best Time to Buy and Sell Stock with Cooldown
Coin Change II, Target Sum, Interleaving String
Longest Increasing Path in Matrix, Distinct Subsequences
Edit Distance, Burst Balloons, Regular Expression Matching
Patterns: grid DP, string DP, interval DP, knapsack variants
State compression, rolling array optimization
Edge cases: empty strings, zero dimensions, large state spaces

## Greedy

Maximum Subarray, Jump Game (I & II), Gas Station
Hand of Straights, Merge Triplets to Form Target Triplet
Partition Labels, Valid Parenthesis String
Patterns: greedy choice property, local optimal → global optimal, exchange argument
Greedy vs DP: when greedy works, how to prove correctness
Edge cases: empty input, single element, no valid solution, ties

## Intervals

Insert Interval, Merge Intervals, Non-Overlapping Intervals
Meeting Rooms (I & II), Minimum Interval to Include Each Query
Patterns: sort by start/end, sweep line, merge overlapping, gap analysis
Edge cases: single interval, fully overlapping, no overlap, point intervals

## Math & Geometry

Rotate Image, Spiral Matrix, Set Matrix Zeroes
Happy Number, Plus One, Pow(x, n)
Multiply Strings, Detect Squares
Patterns: matrix manipulation, number theory, coordinate geometry
Modular arithmetic, fast exponentiation, overflow handling
Edge cases: negative numbers, zero, overflow, precision

## Bit Manipulation

Single Number, Number of 1 Bits, Counting Bits
Reverse Bits, Missing Number, Sum of Two Integers, Reverse Integer
Patterns: XOR properties, bit counting, bit masking, bit shifting
Relationship to sets: bitmask DP, subset enumeration
Edge cases: negative numbers, zero, INT_MIN, overflow

Output Requirements

Table of Contents with deep linking
Each section must include:
  - What & Why (1–2 concise paragraphs on the pattern/category)
  - Key Patterns & Techniques (bullet list)
  - Curated Problem Set (with LeetCode/NeetCode numbers, difficulty tags: Easy/Medium/Hard)
  - Solution Templates (pseudocode/C++ skeleton showing the pattern structure)
  - "Gotchas & Pitfalls" (bullet list of common mistakes in interviews)
  - Time & Space Complexity Summary Table
  - Checklist (Markdown checkboxes with tracking fields)
  - Self‑Assessment (3–5 questions; 1 mock interview scenario)
  - References (NeetCode, LeetCode discuss, algorithm textbooks; prefer stable links)

Master Progress Tracker at the top (aggregating all checklists).
Separate "Must Know / Should Know / Nice to Have" per section.
Tag each problem: [Easy], [Medium], [Hard], [Blind75], [NeetCode250].
Include timing benchmarks: target solve time for each difficulty level.
Keep explanations concise but interview-practical (how to explain approach to interviewer).

Checklist Template (use in every section)

```markdown
### ✅ Checklist – {Pattern/Section Name}
- [ ] Pattern mastered: {Pattern Name}
      Owner: {name}  Target Date: {YYYY-MM-DD}  Last Reviewed: {YYYY-MM-DD}
      Evidence: {LeetCode submission link / time taken}
- [ ] Core problems solved: {X/Y from curated list}
- [ ] Can solve Medium in < 20 min: {Yes/No}
- [ ] Can explain approach clearly (mock interview tested)
- [ ] Edge cases identified and handled
- [ ] Optimal time & space complexity achieved
- [ ] Common pitfall avoided: {Describe}
- [ ] Similar problems attempted for reinforcement
```

Master Progress Tracker (top of document)

```markdown
## 📊 Master Progress Tracker
| Section                  | Must Know Done | Should Know Done | Nice to Have Done | Avg Solve Time | Last Reviewed | Notes |
|--------------------------|----------------|------------------|-------------------|----------------|---------------|-------|
| Arrays & Hashing         |                |                  |                   |                |               |       |
| Two Pointers             |                |                  |                   |                |               |       |
| Sliding Window           |                |                  |                   |                |               |       |
| Stack                    |                |                  |                   |                |               |       |
| Binary Search            |                |                  |                   |                |               |       |
| Linked List              |                |                  |                   |                |               |       |
| Trees                    |                |                  |                   |                |               |       |
| Tries                    |                |                  |                   |                |               |       |
| Heap / Priority Queue    |                |                  |                   |                |               |       |
| Backtracking             |                |                  |                   |                |               |       |
| Graphs                   |                |                  |                   |                |               |       |
| Advanced Graphs          |                |                  |                   |                |               |       |
| 1-D Dynamic Programming  |                |                  |                   |                |               |       |
| 2-D Dynamic Programming  |                |                  |                   |                |               |       |
| Greedy                   |                |                  |                   |                |               |       |
| Intervals                |                |                  |                   |                |               |       |
| Math & Geometry          |                |                  |                   |                |               |       |
| Bit Manipulation         |                |                  |                   |                |               |       |
```

Style & Constraints

- Use Markdown, descriptive headings, and consistent formatting.
- Keep code outside tables.
- Mark Hard problems clearly as advanced.
- Focus on pattern recognition over memorization — teach HOW to identify which pattern to apply.
- Include "How to approach in interview" guidance for each section.
- Show brute-force → optimized progression for key problems.
- Prefer C++ with STL (std::vector, std::unordered_map, std::priority_queue, etc.).
- Include time management tips for interview settings.
- Cross-reference problems that use multiple patterns (e.g., binary search + sliding window).
