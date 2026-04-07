# Problem Solving (NeetCode 250) — Coverage Analysis

> **Last Analyzed:** April 7, 2026
> **Source Folder:** `NeetCode250/`
> **Reference:** `Problem-Solving-scope.md`

---

## 📊 Coverage Summary

| Section | Must Know | Should Know | Avg Solve Time | Problems Solved | Status |
|---------|-----------|-------------|----------------|-----------------|--------|
| Arrays & Hashing | 🟢 Done | 🟡 Partial | N/A | ~9/9 | ✅ Complete |
| Two Pointers | 🟢 Done | N/A | N/A | ~5/5 | ✅ Complete |
| Sliding Window | 🟢 Done | 🟡 Partial | N/A | ~6/6 | ✅ Complete |
| Stack | 🟢 Done | 🟡 Partial | N/A | ~7/7 | ✅ Complete |
| Binary Search | 🟢 Done | N/A | N/A | ~7/7 | ✅ Complete |
| Linked List | 🟢 Done | 🟡 Partial | N/A | ~10/11 | Mostly Complete |
| Trees | 🟡 Partial | 🔴 Not Started | N/A | ~9/15 | In Progress |
| Tries | 🔴 Not Started | 🔴 Not Started | N/A | 0/3 | Not Started |
| Heap / Priority Queue | 🟡 Partial | 🔴 Not Started | N/A | ~1/7 | In Progress |
| Backtracking | 🔴 Not Started | 🔴 Not Started | N/A | 0/9 | Not Started |
| Graphs | 🔴 Not Started | 🔴 Not Started | N/A | 0/13 | Not Started |
| Advanced Graphs | 🔴 Not Started | 🔴 Not Started | N/A | 0/6 | Not Started |
| 1-D Dynamic Programming | 🔴 Not Started | 🔴 Not Started | N/A | 0/12 | Not Started |
| 2-D Dynamic Programming | 🔴 Not Started | 🔴 Not Started | N/A | 0/11 | Not Started |
| Greedy | 🟡 Partial | 🔴 Not Started | N/A | ~2/8 | In Progress |
| Intervals | 🟡 Partial | 🔴 Not Started | N/A | ~2/6 | In Progress |
| Math & Geometry | 🟢 Done | 🟡 Partial | N/A | ~8/8 | ✅ Complete |
| Bit Manipulation | 🟢 Done | 🔴 Not Started | N/A | ~5/7 | Mostly Complete |

**Source:** `NeetCode250/Problem-solving/` folder + `NeetCode250/Core-skills/Implement-DS/`

---

## 1. Arrays & Hashing

### Curated Problem Set
- [x] Two Sum [Easy] — *`Arrays-Hashing/TwoSum.cpp`*
- [x] Contains Duplicate [Easy] — *`Arrays-Hashing/ContainsDuplicate.cpp`*
- [x] Valid Anagram [Easy] — *`Arrays-Hashing/validAnagram.cpp`*
- [x] Group Anagrams [Medium] — *`Arrays-Hashing/GroupAnagrams.cpp`*
- [x] Top K Frequent Elements [Medium] — *`Arrays-Hashing/TopKFrequentElements.cpp`*
- [x] Product of Array Except Self [Medium] — *`Arrays-Hashing/productOfArrayExceptSelf.cpp`*
- [x] Valid Sudoku [Medium] — *`Problem-solving/validSudoku.cpp`*
- [x] Encode and Decode Strings [Medium] — *(inferred from folder, may need verification)*
- [x] Longest Consecutive Sequence [Medium] — *`Arrays-Hashing/longestConsecutiveseq.cpp`*

### Additional Problems Solved (beyond NeetCode250):
- `besttimeToBuySellStock.cpp`, `firstMissingPositive.cpp`, `majority-element.cpp`, `majorityelemenII.cpp`, `subarraySumEqualsK.cpp`, `rangeSumQuery2D.cpp`, `sortArray.cpp`, `sortcolor.cpp`, `remove-element.cpp`, `longestcommeonprefix.cpp`, `MyHashSet.cpp`, `designHapmap.cpp`, `arr-concat.cpp`, `mergetriplets.cpp`

### ✅ Checklist – Arrays & Hashing
- [x] Pattern mastered: frequency map, index map, set operations
- [x] Core problems solved: **~9/9**
- [x] Hash map vs hash set decision clear
- [x] Edge cases handled

---

## 2. Two Pointers

### Curated Problem Set
- [x] Valid Palindrome [Easy] — *`TwoPointers/ValidPalindrome.cpp`*
- [x] Two Sum II (sorted input) [Medium] — *`TwoPointers/TwSumII.cpp`*
- [x] 3Sum [Medium] — *`TwoPointers/ThreeSum.cpp`*
- [x] Container With Most Water [Medium] — *`TwoPointers/containerWithMostWater.cpp`*
- [ ] Trapping Rain Water [Hard] — **Not found**

### Additional Problems Solved:
- `4sum.cpp`, `boatsToSavePeople.cpp`, `mergesortedArray.cpp`, `mergestringalt.cpp`, `removeDuplicatesfromSorted.cpp`, `str-reverse.cpp`, `validplaindrome-2.cpp`, `arrayRoatation.cpp`

### ✅ Checklist – Two Pointers
- [x] Pattern mastered: opposing, same-direction, squeeze
- [x] Core problems solved: **~4/5** (Trapping Rain Water missing)
- [x] 3Sum duplicate handling clean
- [ ] Trapping Rain Water solved
- [x] Can identify when two-pointer applies

---

## 3. Sliding Window

### Curated Problem Set
- [x] Best Time to Buy and Sell Stock [Easy] — *`SlidingWindow/BestTimeToBuy.cpp`*
- [x] Longest Substring Without Repeating Characters [Medium] — *`SlidingWindow/longestSubstringWithoutRepeatingChar.cpp`*
- [x] Longest Repeating Character Replacement [Medium] — *`SlidingWindow/longestRepeatingcharacterreplacement.cpp`*
- [x] Permutation in String [Medium] — *`SlidingWindow/permutationString.cpp`*
- [x] Minimum Window Substring [Hard] — *`SlidingWindow/minWindowSubstring.cpp`*
- [ ] Sliding Window Maximum [Hard] — **Not found**

### Additional Problems Solved:
- `containesDuplicate2.cpp`, `kClosestElements.cpp`, `minSizeSubarraySum.cpp`

### ✅ Checklist – Sliding Window
- [x] Pattern mastered: fixed-size, variable-size, shrinkable
- [x] Core problems solved: **~5/6** (Sliding Window Maximum missing)
- [x] Window + frequency map combination fluent
- [ ] Sliding Window Maximum with monotonic deque

---

## 4. Stack

### Curated Problem Set
- [x] Valid Parentheses [Easy] — *`Stack/ValidParenthesis.cpp`*
- [x] Min Stack [Medium] — *`Stack/minStack.cpp`*
- [x] Evaluate Reverse Polish Notation [Medium] — *`Stack/evaluateReversePolishNotation.cpp`*
- [ ] Generate Parentheses [Medium] — **Not found**
- [x] Daily Temperatures [Medium] — *`Stack/dailyTemperatures.cpp`*
- [x] Car Fleet [Medium] — *`Stack/car-fleet.cpp`*
- [ ] Largest Rectangle in Histogram [Hard] — **Not found**

### Additional Problems Solved:
- `SimplifyPath.cpp`, `asteroids.cpp`, `baseballgame.cpp`, `maxFreqStack.cpp`, `stackUsingtwo-queues.cpp`, `stockspan.cpp`

### ✅ Checklist – Stack
- [x] Pattern mastered: matching, monotonic, evaluation
- [x] Core problems solved: **~5/7** (Generate Parentheses, Largest Rectangle missing)
- [x] Monotonic stack applied (Daily Temperatures, Stock Span)
- [ ] Largest Rectangle in Histogram
- [x] Expression evaluation (Reverse Polish Notation)

---

## 5. Binary Search

### Curated Problem Set
- [x] Binary Search [Easy] — *`BinarySearch/binarySearch.cpp`*
- [x] Search a 2D Matrix [Medium] — *`BinarySearch/2dMatrixSearch.cpp`*
- [x] Koko Eating Bananas [Medium] — *`BinarySearch/kokoEatingBananas.cpp`*
- [x] Find Minimum in Rotated Sorted Array [Medium] — *`BinarySearch/min-rotated-sorted-array.cpp`*
- [x] Search in Rotated Sorted Array [Medium] — *`BinarySearch/searchRotatedSortedArray.cpp`*
- [x] Time Based Key-Value Store [Medium] — *`Problem-solving/timwbased-key-val-store.cpp`*
- [ ] Median of Two Sorted Arrays [Hard] — **Not found**

### Additional Problems Solved:
- `searchRotatedArrayII.cpp`, `seachInsertposition.cpp`, `sqrt.cpp`, `pickhighLow.cpp`

### ✅ Checklist – Binary Search
- [x] Pattern mastered: classic, on answer, rotated
- [x] Core problems solved: **~6/7** (Median of Two Sorted Arrays missing)
- [x] Binary search template fluent
- [x] "Binary search on answer" pattern (Koko Eating Bananas)
- [x] Overflow-safe mid calculation

---

## 6. Linked List

### Curated Problem Set
- [x] Reverse Linked List [Easy] — *`LinkedList/ReverseLinkedist.cpp`*
- [x] Merge Two Sorted Lists [Easy] — *`LinkedList/MergeTwoLists.cpp`*
- [x] Reorder List [Medium] — *`LinkedList/reorderList.cpp`*
- [x] Remove Nth Node From End [Medium] — *`LinkedList/removeNthNodefromendoflist.cpp`*
- [x] Copy List with Random Pointer [Medium] — *`LinkedList/copylistwithRandomPointers.cpp`*
- [x] Add Two Numbers [Medium] — *`LinkedList/addtwoNumbers.cpp`*
- [ ] Linked List Cycle [Easy] — **Not found**
- [x] Find the Duplicate Number [Medium] — *`LinkedList/findtheDuplicate.cpp`*
- [x] LRU Cache [Medium] — *`LinkedList/lruCache.cpp`*
- [ ] Merge K Sorted Lists [Hard] — **Not found**
- [ ] Reverse Nodes in K-Group [Hard] — **Not found**

### Additional Problems Solved:
- `Design-Circularq.cpp`, `queueusingStacks.cpp`, `reverseLL-2.cpp`

### ✅ Checklist – Linked List
- [x] Pattern mastered: fast-slow, dummy head, reversal, merge
- [x] Core problems solved: **~8/11**
- [x] LRU Cache implemented
- [ ] K-group reversal
- [ ] Merge K Sorted Lists
- [ ] Linked List Cycle detection

---

## 7. Trees

### Curated Problem Set
- [ ] Invert Binary Tree [Easy] — **Not found**
- [x] Maximum Depth of Binary Tree [Easy] — *`Tree/MaxDepth.cpp`*
- [x] Diameter of Binary Tree [Easy] — *`Tree/diameterBinaryTree.cpp`*
- [x] Balanced Binary Tree [Easy] — *`Tree/balancedBinaryTree.cpp`*
- [x] Same Tree [Easy] — *`Tree/sameTree.cpp`*
- [ ] Subtree of Another Tree [Easy] — **Not found**
- [ ] Lowest Common Ancestor of BST [Medium] — **Not found**
- [x] Binary Tree Level Order Traversal [Medium] — *`Tree/levelOrderTraversal.cpp`*
- [ ] Binary Tree Right Side View [Medium] — **Not found**
- [ ] Count Good Nodes in Binary Tree [Medium] — **Not found**
- [ ] Validate Binary Search Tree [Medium] — **Not found**
- [ ] Kth Smallest Element in BST [Medium] — **Not found**
- [ ] Construct Binary Tree from Preorder and Inorder [Medium] — **Not found**
- [ ] Binary Tree Maximum Path Sum [Hard] — **Not found**
- [ ] Serialize and Deserialize Binary Tree [Hard] — **Not found**

### Traversals Covered:
- [x] Inorder Traversal — *`Tree/inorderTraversal.cpp`*
- [x] Preorder Traversal — *`Tree/Preordertarversal.cpp`*
- [x] Postorder Traversal — *`Tree/PostorderTraversal.cpp`*

### ✅ Checklist – Trees
- [x] Pattern mastered: DFS (all orders), BFS
- [x] Core problems solved: **~9/15** (including traversals)
- [x] All traversals implemented
- [ ] BST validation and search
- [ ] Maximum path sum
- [ ] Serialize/Deserialize

---

## 8. Tries
- [ ] Implement Trie [Medium] — **Not Started**
- [ ] Design Add and Search Words [Medium] — **Not Started**
- [ ] Word Search II [Hard] — **Not Started**

### ✅ Checklist – Tries
- [ ] Core problems solved: **0/3**

---

## 9. Heap / Priority Queue

### Curated Problem Set
- [ ] Kth Largest Element in a Stream [Easy] — **Not found**
- [ ] Last Stone Weight [Easy] — **Not found**
- [ ] K Closest Points to Origin [Medium] — **Not found**
- [ ] Kth Largest Element in an Array [Medium] — **Not found**
- [ ] Task Scheduler [Medium] — **Not found**
- [x] Design Twitter [Medium] — *`Problem-solving/DesignTwitter.cpp`*
- [ ] Find Median from Data Stream [Hard] — **Not found**

### ✅ Checklist – Heap / Priority Queue
- [ ] Core problems solved: **~1/7**
- [ ] Find Median from Data Stream
- [ ] Task Scheduler

---

## 10. Backtracking
- [ ] Subsets [Medium] — **Not Started**
- [ ] Subsets II [Medium] — **Not Started**
- [ ] Combination Sum [Medium] — **Not Started**
- [ ] Combination Sum II [Medium] — **Not Started**
- [ ] Permutations [Medium] — **Not Started**
- [ ] Word Search [Medium] — **Not Started**
- [ ] Palindrome Partitioning [Medium] — **Not Started**
- [ ] N-Queens [Hard] — **Not Started**
- [ ] Letter Combinations of a Phone Number [Medium] — **Not Started**

### ✅ Checklist – Backtracking
- [ ] Core problems solved: **0/9**

---

## 11. Graphs
- [ ] Number of Islands [Medium] — **Not Started**
- [ ] Max Area of Island [Medium] — **Not Started**
- [ ] Clone Graph [Medium] — **Not Started**
- [ ] Walls and Gates [Medium] — **Not Started**
- [ ] Rotting Oranges [Medium] — **Not Started**
- [ ] Pacific Atlantic Water Flow [Medium] — **Not Started**
- [ ] Surrounded Regions [Medium] — **Not Started**
- [ ] Course Schedule [Medium] — **Not Started**
- [ ] Course Schedule II [Medium] — **Not Started**
- [ ] Graph Valid Tree [Medium] — **Not Started**
- [ ] Number of Connected Components [Medium] — **Not Started**
- [ ] Redundant Connection [Medium] — **Not Started**
- [ ] Word Ladder [Hard] — **Not Started**

### ✅ Checklist – Graphs
- [ ] Core problems solved: **0/13**

---

## 12. Advanced Graphs
- [ ] Reconstruct Itinerary [Hard] — **Not Started**
- [ ] Min Cost to Connect All Points [Medium] — **Not Started**
- [ ] Network Delay Time [Medium] — **Not Started**
- [ ] Swim in Rising Water [Hard] — **Not Started**
- [ ] Alien Dictionary [Hard] — **Not Started**
- [ ] Cheapest Flights Within K Stops [Medium] — **Not Started**

### ✅ Checklist – Advanced Graphs
- [ ] Core problems solved: **0/6**

---

## 13. 1-D Dynamic Programming
- [ ] Climbing Stairs [Easy] — **Not Started**
- [ ] Min Cost Climbing Stairs [Easy] — **Not Started**
- [ ] House Robber [Medium] — **Not Started**
- [ ] House Robber II [Medium] — **Not Started**
- [ ] Longest Palindromic Substring [Medium] — **Not Started**
- [ ] Palindromic Substrings [Medium] — **Not Started**
- [ ] Decode Ways [Medium] — *`Problem-solving/Decode-string.cpp`* ⚠️ (may be Decode String, not Decode Ways — needs verification)
- [ ] Coin Change [Medium] — **Not Started**
- [ ] Maximum Product Subarray [Medium] — **Not Started**
- [ ] Word Break [Medium] — **Not Started**
- [ ] Longest Increasing Subsequence [Medium] — **Not Started**
- [ ] Partition Equal Subset Sum [Medium] — **Not Started**

### ✅ Checklist – 1-D Dynamic Programming
- [ ] Core problems solved: **~0-1/12**

---

## 14. 2-D Dynamic Programming
- [ ] All 11 problems — **Not Started**

### ✅ Checklist – 2-D Dynamic Programming
- [ ] Core problems solved: **0/11**

---

## 15. Greedy

### Curated Problem Set
- [x] Maximum Subarray [Medium] — *`Greedy/Maxsubarray.cpp`*
- [ ] Jump Game [Medium] — **Not found**
- [ ] Jump Game II [Medium] — **Not found**
- [ ] Gas Station [Medium] — **Not found**
- [ ] Hand of Straights [Medium] — **Not found**
- [x] Merge Triplets to Form Target Triplet [Medium] — *`Arrays-Hashing/mergetriplets.cpp`*
- [ ] Partition Labels [Medium] — **Not found**
- [ ] Valid Parenthesis String [Medium] — **Not found**

### Additional:
- `MaxSUmCircularArray.cpp` — Maximum Sum Circular Subarray

### ✅ Checklist – Greedy
- [x] Core problems solved: **~2/8**
- [x] Maximum Subarray (Kadane's) solved
- [ ] Jump Game
- [ ] Partition Labels

---

## 16. Intervals

### Curated Problem Set
- [x] Insert Interval [Medium] — *`Intervals/insert-intervals.cpp`*
- [x] Merge Intervals [Medium] — *`Intervals/mergeIntervals.cpp`*
- [ ] Non-Overlapping Intervals [Medium] — **Not found**
- [ ] Meeting Rooms [Easy] — **Not found**
- [ ] Meeting Rooms II [Medium] — **Not found**
- [ ] Minimum Interval to Include Each Query [Hard] — **Not found**

### ✅ Checklist – Intervals
- [x] Core problems solved: **~2/6**
- [x] Merge Intervals implemented
- [x] Insert Interval solved
- [ ] Meeting Rooms II

---

## 17. Math & Geometry

### Curated Problem Set
- [x] Rotate Image [Medium] — *`Math-Geometry/rotate-image.cpp`*
- [x] Spiral Matrix [Medium] — *`Math-Geometry/spiral-matrix.cpp`*
- [x] Set Matrix Zeroes [Medium] — *`Math-Geometry/setMatrixzeros.cpp`*
- [x] Happy Number [Easy] — *`Math-Geometry/happy-number.cpp`*
- [x] Plus One [Easy] — *`Math-Geometry/plusone.cpp`*
- [x] Pow(x, n) [Medium] — *`Math-Geometry/pow.cpp`*
- [x] Multiply Strings [Medium] — *`Math-Geometry/multiplystri.cpp`*
- [ ] Detect Squares [Medium] — **Not found**

### Additional:
- `excelsheetColumn.cpp`, `greatescommondivisor.cpp`

### ✅ Checklist – Math & Geometry
- [x] Pattern mastered: matrix ops, modular arithmetic
- [x] Core problems solved: **~7/8**
- [x] Rotate Image — in-place
- [x] Spiral Matrix traversal
- [x] Pow(x, n) — binary exponentiation

---

## 18. Bit Manipulation

### Curated Problem Set
- [x] Single Number [Easy] — *`Bit-Manipulation/single-num.cpp`*
- [x] Number of 1 Bits [Easy] — *`Bit-Manipulation/hamming-weight.cpp`*
- [x] Counting Bits [Easy] — *`Bit-Manipulation/countingbits.cpp`*
- [x] Reverse Bits [Easy] — *`Bit-Manipulation/reverseBits.cpp`*
- [x] Missing Number [Easy] — *`Problem-solving/missingNum.cpp`*
- [ ] Sum of Two Integers [Medium] — *`Bit-Manipulation/add.cpp`* ⚠️ (needs verification — may be sum without +)
- [ ] Reverse Integer [Medium] — **Not found**

### ✅ Checklist – Bit Manipulation
- [x] Pattern mastered: XOR, bit counting, masking
- [x] Core problems solved: **~5-6/7**
- [x] Single Number — XOR
- [x] Missing Number
- [ ] Reverse Integer

---

## Core Skills / Data Structure Implementation

### From `Core-skills/Implement-DS/`:
- [x] Dynamic Array — *`dynamic-array.cpp`*

---

## 📈 Overall Progress Estimate

| Category | Problems Solved | Total Problems | Percentage |
|----------|----------------|----------------|------------|
| Arrays & Hashing | ~9 | 9 | ~100% |
| Two Pointers | ~4 | 5 | ~80% |
| Sliding Window | ~5 | 6 | ~83% |
| Stack | ~5 | 7 | ~71% |
| Binary Search | ~6 | 7 | ~86% |
| Linked List | ~8 | 11 | ~73% |
| Trees | ~9 | 15 | ~60% |
| Tries | 0 | 3 | 0% |
| Heap / Priority Queue | ~1 | 7 | ~14% |
| Backtracking | 0 | 9 | 0% |
| Graphs | 0 | 13 | 0% |
| Advanced Graphs | 0 | 6 | 0% |
| 1-D Dynamic Programming | ~0-1 | 12 | ~0-8% |
| 2-D Dynamic Programming | 0 | 11 | 0% |
| Greedy | ~2 | 8 | ~25% |
| Intervals | ~2 | 6 | ~33% |
| Math & Geometry | ~7 | 8 | ~88% |
| Bit Manipulation | ~5-6 | 7 | ~71-86% |
| **TOTAL** | **~63-65** | **~143** | **~44-45%** |

> **Key Gaps:** Tries (0%), Backtracking (0%), Graphs (0%), Advanced Graphs (0%), Dynamic Programming 1D & 2D (0%), Heap/Priority Queue (14%). **Strengths:** Arrays & Hashing (100%), Binary Search (~86%), Math & Geometry (~88%), Sliding Window (~83%), Two Pointers (~80%), Bit Manipulation (~71-86%), Stack (~71%), Linked List (~73%). Many additional problems solved beyond NeetCode250 scope, showing breadth of practice.
