# Data Structures & Algorithms — Coverage Analysis

> **Last Analyzed:** April 7, 2026
> **Source Folder:** `DS_Algo/`
> **Reference:** `DS-ALGO-concepts-scope.md`

---

## 📊 Coverage Summary

| Section | Must Know | Should Know | Nice to Have | Status |
|---------|-----------|-------------|--------------|--------|
| Arrays & Strings | 🟡 Partial | 🟡 Partial | 🔴 Not Started | In Progress |
| Hashing & Hash Maps | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Linked Lists | 🟢 Done | 🔴 Not Started | 🔴 Not Started | In Progress |
| Stacks & Queues | 🟡 Partial | 🟡 Partial | N/A | In Progress |
| Trees | 🟡 Partial | 🔴 Not Started | 🔴 Not Started | In Progress |
| Heaps & Priority Queues | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Graphs | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Recursion & Backtracking | 🟡 Partial | 🔴 Not Started | 🔴 Not Started | In Progress |
| Dynamic Programming | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Sorting & Searching | 🟡 Partial | 🔴 Not Started | 🔴 Not Started | In Progress |
| Greedy Algorithms | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Bit Manipulation | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Advanced Data Structures | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |
| Complexity Analysis | 🔴 Not Started | 🔴 Not Started | 🔴 Not Started | Not Started |

---

## 1. Arrays & Strings

### 1.1 Array Fundamentals
- [ ] **Must Know:** Static arrays, dynamic arrays, `std::vector` internals
- [ ] **Must Know:** Amortized O(1) `push_back`, capacity vs size
- [ ] **Must Know:** `std::array` for fixed-size, cache-friendly contiguous memory

> **Note:** STL containers (`array`, `vector`, `list`, `forward_list`) are practiced in `DS_Algo/STL/` folder with `arraySTL.cpp`, `vectorSTL.cpp`, `listSTL.cpp`, `forwardListSTL.cpp`.

### 1.2 Two-Pointer Techniques
- [ ] **Must Know:** Opposing pointers
- [ ] **Must Know:** Same-direction pointers
- [ ] **Must Know:** Fast-slow pointer

### 1.3 Sliding Window
- [ ] **Must Know:** Fixed-size window
- [ ] **Must Know:** Variable-size window
- [ ] **Should Know:** Shrinkable window with constraints

### 1.4 Prefix Sums & Difference Arrays
- [ ] **Must Know:** Prefix sum array
- [ ] **Must Know:** Kadane's algorithm
- [ ] **Should Know:** Difference arrays
- [ ] **Should Know:** 2D prefix sums

### 1.5 String Algorithms
- [x] **Must Know:** String matching — brute-force — *Covered in `strings/` folder (palindrome, reverse, anagram, findDuplicates, changecase, reverseWordWise, wordsandvowels)*
- [ ] **Should Know:** KMP (Knuth-Morris-Pratt)
- [ ] **Should Know:** Rabin-Karp — rolling hash
- [ ] **Nice to Have:** Z-algorithm
- [ ] **Nice to Have:** Suffix arrays, suffix trees

### 1.6 Matrix Operations
- [x] **Must Know:** In-place operations — *Covered in `matrices/` folder (diagonalMatrix, lowerTriangle, upperTriangle)*
- [ ] **Must Know:** Spiral traversal
- [ ] **Should Know:** Matrix multiplication

### ✅ Checklist – Arrays & Strings
- [ ] Two-pointer patterns mastered
- [ ] Sliding window — fixed & variable size
- [ ] Prefix sums applied
- [ ] Kadane's algorithm implemented
- [ ] KMP / Rabin-Karp string matching
- [x] Basic string operations (palindrome, reverse, anagram, duplicates)
- [x] Matrix diagonal/triangular operations

---

## 2. Hashing & Hash Maps
- [ ] Hash Fundamentals — **Not Started**
- [ ] Standard Library Hash Containers — **Not Started**
- [ ] Hash Patterns — **Not Started**
- [ ] Probabilistic Data Structures — **Not Started**

### ✅ Checklist – Hashing & Hash Maps
- [ ] Hash collision resolution strategies understood
- [ ] Custom hasher for `unordered_map` implemented
- [ ] Two-sum, frequency counting, anagram patterns solved
- [ ] Rolling hash applied
- [ ] Bloom filter concept understood

---

## 3. Linked Lists

### 3.1 Linked List Types
- [x] **Must Know:** Singly linked list — insert, delete, traverse — *Covered in `linkedlists/displayList.cpp`*
- [x] **Must Know:** Doubly linked list — bidirectional traversal — *Covered in `linkedlists/displayDoublyList.cpp`*
- [x] **Should Know:** Circular linked list — *Covered in `linkedlists/displayCircularList.cpp`*

### 3.2 Pointer Techniques
- [ ] **Must Know:** Fast-slow pointer — cycle detection
- [ ] **Must Know:** Finding middle element
- [ ] **Must Know:** Finding intersection point

### 3.3 Reversal Techniques
- [ ] **Must Know:** Iterative reversal
- [ ] **Must Know:** Recursive reversal
- [ ] **Should Know:** K-group reversal
- [ ] **Should Know:** Partial reversal

### 3.4 Merge Operations
- [ ] **Must Know:** Merge two sorted lists
- [ ] **Should Know:** Merge K sorted lists

### 3.5 Advanced Linked List
- [ ] **Must Know:** LRU Cache — doubly linked list + hash map
- [ ] **Nice to Have:** Skip lists

> **Note:** Additional linked list problem (`addTwoNumbers.cpp`) is in `linkedlists/Problems/`. Polynomial representation also covered (`polynomial.cpp`).

### ✅ Checklist – Linked Lists
- [x] Singly, doubly, & circular linked list operations implemented
- [ ] Floyd's cycle detection applied
- [ ] Iterative & recursive reversal mastered
- [ ] Merge two sorted lists implemented
- [ ] LRU Cache designed and implemented

---

## 4. Stacks & Queues

### 4.1 Stack Applications
- [x] **Must Know:** Basic stack operations — *Covered in `stack/stackADT.cpp` and `stack/stackUsingLL.cpp`*
- [ ] **Must Know:** Parenthesis / bracket matching
- [ ] **Must Know:** Expression evaluation (infix, postfix)
- [ ] **Must Know:** Monotonic stack
- [ ] **Should Know:** Min-stack

### 4.2 Queue Variants
- [x] **Must Know:** FIFO queue, circular queue — *Covered in `queue/circularQUsingArrays.cpp`, `circularQUsingLL.cpp`*
- [ ] **Must Know:** Double-ended queue (`std::deque`)
- [ ] **Must Know:** Priority queue
- [ ] **Should Know:** Monotonic queue

### 4.3 Stack/Queue Interconversion
- [x] **Should Know:** Implementing queue with two stacks — *Covered in `queue/qUsingtqoStacks.cpp`*
- [ ] **Should Know:** Implementing stack with two queues

### ✅ Checklist – Stacks & Queues
- [ ] Monotonic stack pattern mastered
- [ ] Expression evaluation implemented
- [ ] Min-stack / Max-stack designed
- [ ] Monotonic queue applied
- [x] Stack ADT and stack using linked list implemented
- [x] Circular queue (array & LL) implemented
- [x] Queue using two stacks implemented

---

## 5. Trees

### 5.1 Binary Tree Fundamentals
- [x] **Must Know:** Traversals — inorder, preorder, postorder (recursive & iterative) — *Covered in `TREES/BinaryTrees/BinaryTreeADT.cpp`, `Iterative-traversal.cpp`*
- [ ] **Must Know:** Level-order traversal (BFS with queue)
- [ ] **Must Know:** Tree construction from traversal pairs
- [x] **Must Know:** Height, depth, diameter, balanced check — *Covered in `TREES/BinaryTrees/countingNodes.cpp`*

### 5.2 Binary Search Trees (BST)
- [x] **Must Know:** Insertion, deletion, search — *Covered in `TREES/BST/BSTADT.cpp`*
- [ ] **Must Know:** In-order successor / predecessor
- [ ] **Must Know:** Validate BST property
- [ ] **Should Know:** Kth smallest/largest element

### 5.3 Balanced BSTs
- [ ] **Must Know:** AVL trees — rotations
- [ ] **Must Know:** Red-Black trees — properties
- [ ] **Must Know:** `std::set`, `std::map` internals
- [ ] **Should Know:** Self-balancing guarantees

### 5.4-5.8 Advanced Tree Topics
- [ ] Segment Trees — **Not Started**
- [ ] Fenwick Trees — **Not Started**
- [ ] Tries — **Not Started**
- [ ] B-Trees & B+ Trees — **Not Started**
- [ ] LCA, Tree DP — **Not Started**

> **Additional:** Tree Inversion covered in `TREES/BinaryTrees/TreeInversion.cpp`.

### ✅ Checklist – Trees
- [x] All traversals implemented (recursive & iterative)
- [x] BST operations mastered (insert, delete, search)
- [x] Tree inversion implemented
- [x] Node counting implemented
- [ ] AVL / Red-Black tree concepts
- [ ] Segment tree with lazy propagation
- [ ] Fenwick tree
- [ ] Trie for prefix matching
- [ ] LCA algorithm
- [ ] Tree DP

---

## 6. Heaps & Priority Queues
- [ ] Heap Fundamentals — **Not Started**
- [ ] Heap Patterns — **Not Started**
- [ ] Advanced Heaps — **Not Started**

### ✅ Checklist – Heaps & Priority Queues
- [ ] Min-heap / max-heap implemented from scratch
- [ ] Top-K pattern applied
- [ ] Two-heap median technique
- [ ] Merge K sorted lists using min-heap
- [ ] Custom comparator with `priority_queue`

---

## 7. Graphs
- [ ] Graph Representations — **Not Started**
- [ ] Graph Traversals — **Not Started**
- [ ] Shortest Path Algorithms — **Not Started**
- [ ] Minimum Spanning Tree — **Not Started**
- [ ] Topological Sort — **Not Started**
- [ ] Union-Find — **Not Started**
- [ ] Advanced Graph Algorithms — **Not Started**

### ✅ Checklist – Graphs
- [ ] BFS & DFS implemented
- [ ] Dijkstra's algorithm
- [ ] Bellman-Ford
- [ ] Kruskal's & Prim's MST
- [ ] Topological sort
- [ ] Union-Find with path compression
- [ ] Cycle detection

---

## 8. Recursion & Backtracking

### 8.1 Recursion Fundamentals
- [x] **Must Know:** Base case, recursive case, call stack mechanics — *Covered in `recursion/` folder (13 files covering: factorial, fibonacci with memoization, head/tail/tree/nested/indirect recursion, exponential, taylor series, sum of n natural numbers, calling and return mechanics)*
- [x] **Must Know:** Recursion vs iteration trade-offs — *Covered in `recursion/headRecursion.cpp`, `tailRecursion.cpp`*
- [x] **Should Know:** Tail recursion — *Covered in `recursion/tailRecursion.cpp`*
- [ ] **Should Know:** Stack overflow prevention

### 8.2 Divide and Conquer
- [x] **Must Know:** Merge sort — *Covered in `SortingAlgorithms/mergeSort.cpp`, `Merging.cpp`*
- [x] **Must Know:** Quick sort — *Covered in `SortingAlgorithms/QuickSort.cpp`*
- [ ] **Should Know:** Closest pair of points
- [ ] **Should Know:** Karatsuba multiplication

### 8.3 Backtracking
- [ ] **Must Know:** Generate permutations, combinations, subsets
- [ ] **Must Know:** N-Queens problem
- [ ] **Must Know:** Sudoku solver
- [ ] **Should Know:** Constraint satisfaction, pruning
- [ ] **Should Know:** Duplicate handling
- [ ] **Nice to Have:** Branch and bound

### 8.4 Memoization
- [x] **Must Know:** Memoization as bridge from recursion to DP — *Covered in `recursion/fibonacciMemoization.cpp`*
- [ ] **Must Know:** Top-down DP via recursive + cache
- [ ] **Should Know:** Memoization with hash maps vs arrays

### ✅ Checklist – Recursion & Backtracking
- [x] Recursion fundamentals solid (base case, stack, all recursion types)
- [x] Merge sort & quick sort implemented
- [x] Fibonacci memoization implemented
- [ ] Permutations, combinations, subsets generated
- [ ] N-Queens / Sudoku solver
- [ ] Memoization applied to convert recursion to DP

---

## 9. Dynamic Programming
- [ ] 1D Dynamic Programming — **Not Started**
- [ ] 2D Dynamic Programming — **Not Started**
- [ ] Knapsack Variants — **Not Started**
- [ ] Interval DP — **Not Started**
- [ ] DP on Trees & Graphs — **Not Started**
- [ ] String DP — **Not Started**
- [ ] State Machine DP — **Not Started**
- [ ] DP Optimization — **Not Started**

### ✅ Checklist – Dynamic Programming
- [ ] 1D DP: coin change, LIS, house robber, word break
- [ ] 2D DP: LCS, edit distance, grid paths
- [ ] Knapsack variants (0/1, unbounded)
- [ ] Interval DP
- [ ] Tree DP
- [ ] State machine DP (stock problems)
- [ ] Space optimization techniques
- [ ] Top-down vs bottom-up trade-offs

---

## 10. Sorting & Searching

### 10.1 Comparison-Based Sorting
- [x] **Must Know:** Merge sort — *Covered in `SortingAlgorithms/mergeSort.cpp`*
- [x] **Must Know:** Quick sort — *Covered in `SortingAlgorithms/QuickSort.cpp`*
- [ ] **Must Know:** Heap sort
- [x] **Must Know:** Stability concept — *Discussed in `SortingAlgorithms/ReadmeSorting.md`*

> **Additional sorts covered:** Bubble Sort (`BubbleSort.cpp`), Insertion Sort (`InsertionSort.cpp`), Selection Sort (`SelectionSort.cpp`), Merging sorted arrays (`Merging.cpp`).

### 10.2 Non-Comparison Sorting
- [ ] **Should Know:** Counting sort
- [ ] **Should Know:** Radix sort
- [ ] **Should Know:** Bucket sort

### 10.3 Binary Search
- [ ] **Must Know:** Classic binary search
- [ ] **Must Know:** Binary search on answer
- [ ] **Must Know:** Search in rotated sorted array
- [ ] **Must Know:** `std::lower_bound`, `std::upper_bound`
- [ ] **Should Know:** Binary search on real numbers

### 10.4 Selection Algorithms
- [ ] **Should Know:** Quickselect
- [ ] **Should Know:** `std::nth_element`
- [ ] **Nice to Have:** Median of medians

### 10.5 C++ STL Sorting
- [ ] **Must Know:** `std::sort`, `std::stable_sort`
- [ ] **Should Know:** `std::partial_sort`, `std::nth_element`
- [ ] **Should Know:** Custom comparators

### ✅ Checklist – Sorting & Searching
- [x] Merge sort, quick sort implemented from scratch
- [x] Bubble sort, insertion sort, selection sort also implemented
- [x] Merging sorted arrays implemented
- [ ] Heap sort implemented
- [ ] Binary search — classic, on answer, rotated array mastered
- [ ] Quickselect implemented
- [ ] Counting sort / radix sort implemented
- [ ] STL sort functions used with custom comparators

---

## 11. Greedy Algorithms
- [ ] Classic Greedy Problems — **Not Started**
- [ ] Greedy Proof Techniques — **Not Started**
- [ ] Greedy vs DP — **Not Started**
- [ ] Graph-Based Greedy — **Not Started**

---

## 12. Bit Manipulation
- [ ] Bitwise Operators — **Not Started**
- [ ] XOR Properties — **Not Started**
- [ ] Counting Bits — **Not Started**
- [ ] Bitmask Techniques — **Not Started**

---

## 13. Advanced Data Structures
- [ ] Disjoint Set Union — **Not Started**
- [ ] Sparse Tables — **Not Started**
- [ ] Suffix Structures — **Not Started**
- [ ] Advanced Balanced BSTs — **Not Started**
- [ ] Persistent Data Structures — **Not Started**
- [ ] Spatial Data Structures — **Not Started**

---

## 14. Complexity Analysis & Problem-Solving Strategies
- [ ] Asymptotic Analysis — **Not Started**
- [ ] Space-Time Trade-offs — **Not Started**
- [ ] Problem-Solving Methodology — **Not Started**

---

## 📈 Overall Progress Estimate

| Priority Level | Covered | Total (est.) | Percentage |
|---------------|---------|--------------|------------|
| Must Know | ~15 | ~65 | ~23% |
| Should Know | ~3 | ~50 | ~6% |
| Nice to Have | 0 | ~20 | 0% |
| **Overall** | **~18** | **~135** | **~13%** |

> **Key Gaps:** Hashing, Heaps, Graphs, Dynamic Programming, Greedy, Bit Manipulation, Advanced DS, Binary Search, Backtracking problems. **Strengths:** Linked lists (all 3 types), recursion fundamentals (comprehensive coverage), sorting algorithms (5 implemented), binary tree traversals + BST, stack/queue implementations.
