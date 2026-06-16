/**
 * @file vector-stackBehaviour.cpp
 * @author Abhishek
 * @brief  Here we discuss the vector capacity and its stack behaviour.
 * We usually avoid the vector from resizing itself since it is a very expensive operation
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>

/* void printStack(const std::vector<int>& stack)
{
	for (auto element : stack)
		std::cout << element << ' ';
	std::cout << "(cap " << stack.capacity() << " length " << stack.size() << ")\n";
}

int main()
{
	std::vector<int> stack{};
	stack.reserve(5);

	printStack(stack);

	stack.push_back(5); // push_back() pushes an element on the stack
	printStack(stack);

	stack.push_back(3);
	printStack(stack);

	stack.push_back(2);
	printStack(stack);

	std::cout << "top: " << stack.back() << '\n'; // back() returns the last element

	stack.pop_back(); // pop_back() pops an element off the stack
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	return 0;
} */

/* 
(cap 0 length 0)
5 (cap 1 length 1)
5 3 (cap 2 length 2)
5 3 2 (cap 4 length 3)
top: 2
5 3 (cap 4 length 2)
5 (cap 4 length 1)
(cap 4 length 0)
--------------------------
With reserved size of vector we dont resize at all:

(cap 5 length 0)
5 (cap 5 length 1)
5 3 (cap 5 length 2)
5 3 2 (cap 5 length 3)
top: 2
5 3 (cap 5 length 2)
5 (cap 5 length 1)
(cap 5 length 0)
*/

//**********************vetor resizing value is taken with incremental values to avoid constant resizing.
int main()
{
	std::vector<int> v{ 0, 1, 2, 3, 4 };
	std::cout << "size: " << v.size() << "  cap: " << v.capacity() << '\n';

	v.push_back(5); // add another element
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	//once the size limit is reached for the vector, its capacity is doubled everytime.
	std::cout << "size: " << v.size() << "  cap: " << v.capacity() << '\n';

	return 0;
}
//**********************vetor resizing value is taken with incremental values to avoid constant resizing.

/*
╔══════════════════════════════════════════════════════════════════════════════╗
║              CONCEPT ANALYSIS — vector-stackBehaviour.cpp                  ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. `std::vector` as a Stack
`push_back()` = push; `pop_back()` = pop; `back()` = top.
Vector provides O(1) amortized push/pop at the back.

### 2. Capacity vs Size
- `size()` = number of elements currently stored.
- `capacity()` = allocated storage (≥ size).
- When size exceeds capacity, reallocation occurs (expensive: allocate + copy).

### 3. `reserve()` to Avoid Reallocations
`stack.reserve(5)` pre-allocates capacity. No reallocation until size > 5.

### 4. Growth Strategy
When capacity is exhausted, implementations typically **double** capacity
(GCC's libstdc++ uses factor 2; MSVC uses 1.5).

**Key Takeaway:** `reserve()` when you know the expected size; avoids
reallocations and iterator invalidation.

#### Alternatives / Idiomatic C++
- Use `std::stack<int>` adapter if you only need stack semantics.
- C++23 `std::inplace_vector` for fixed-capacity, no-heap vectors.
- `shrink_to_fit()` can release excess capacity (non-binding request).

#### Real-World Usage
- **Game engines**: Pre-reserve vectors for entity lists to avoid frame hitches.
- **Protobuf** (https://github.com/protocolbuffers/protobuf): Uses
  `RepeatedField` with similar capacity-doubling strategy.

---

## 🔁 Quick Revision
- `reserve(n)` prevents reallocations up to n elements.
- Capacity doubles (typically) on reallocation.
- Reallocation invalidates all iterators, pointers, and references.

### ⚠️ Gotchas
- Never hold iterators/pointers into a vector across `push_back` — they may
  be invalidated by reallocation.
*/