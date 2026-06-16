/**
 * @file STDmove.cpp
 * @author Abhishek
 * @brief Here we discuss about the std::move and how to use it:
 * 1- We can invoke move copy contructor and move assignement on l-values by using std::move, which casts l-value to r-value reference.
 * 2- We should not use std::move on any persistent object we don't want to modify.
 * 
 * CONCLUSION:
 * //!std::move can be used whenever we want to treat an l-value like an r-value for the purpose of invoking move semantics instead of copy semantics.
 * //!std::move can alsobe used in a lot of sorting algorithms since thise involve a lot of swapping.
 * @version 0.1
 * @date 2022-09-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <utility>

// copy version of the swap, this leads to excessive string creation and destruction which is slow.
// template<class T>
// void myswap(T& a, T& b)
// {
// 	T tmp { a }; // invokes copy constructor
// 	a = b; // invokes copy assignment
// 	b = tmp; // invokes copy assignment
// } 

//Move version of swap
/* template<class T>
void myswap(T& a, T& b)
{
	T tmp { std::move(a) }; // invokes move constructor
	a = std::move(b); // invokes move assignment
	b = std::move(tmp); // invokes move assignment
}

int main()
{
	std::string x{ "abc" };
	std::string y{ "de" };

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	myswap(x, y);

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	return 0;
} */
//*******************Alternate ex***
#include <vector>

int main()
{
	std::vector<std::string> v;
	std::string str = "Knock";

	std::cout << "Copying str\n";
	v.push_back(str); // calls l-value version of push_back, which copies str into the array element

	std::cout << "str: " << str << '\n';
	std::cout << "vector: " << v[0] << '\n';

	std::cout << "\nMoving str\n";

	v.push_back(std::move(str)); // calls r-value version of push_back, which moves str into the array element

	// Here str is  a moved from object, these objects are in a valid but indeterminate state hence should be avoided for any use after move operation.
	std::cout << "str: " << str << '\n';
	std::cout << "vector:" << v[0] << ' ' << v[1] << '\n';
}

/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                     CONCEPT ANALYSIS — STDmove.cpp                        ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. `std::move` — Casting Lvalue to Rvalue
`std::move(x)` is a **cast** (not a move itself). It produces an rvalue
reference to `x`, enabling the move constructor/assignment to be selected.

### 2. Move-Based Swap (Efficient)
```cpp
T tmp{std::move(a)};  // move ctor
a = std::move(b);     // move assign
b = std::move(tmp);   // move assign
```
Three moves vs three copies — significant for expensive-to-copy types like
`std::string` with large buffers.

### 3. Moved-From State
After `std::move(str)` and using it in `push_back`, `str` is in a **valid but
indeterminate state**. Only safe operations: assign new value or destroy.

**Key Takeaway:** `std::move` enables move semantics on lvalues. Never use a
moved-from object except to reassign or destroy it.

#### Alternatives / Idiomatic C++
- `std::swap` already uses move semantics internally (since C++11).
- `std::exchange` (C++14) is useful in move ctors:
  ```cpp
  m_ptr = std::exchange(other.m_ptr, nullptr);
  ```

#### Real-World Usage
- **All STL containers**: Use move semantics in `push_back`, `emplace_back`,
  `insert`, and internal reallocation.
- **Sorting algorithms**: `std::sort` uses moves for element swapping.

---

## 🔁 Quick Revision
- `std::move` = unconditional cast to `T&&`.
- Enables move ctor/assignment selection on lvalues.
- Moved-from objects: valid but indeterminate — reassign or destroy only.
- `std::swap` uses moves internally since C++11.

### ⚠️ Gotchas
- Don't `std::move` const objects — results in a copy (const T&& matches const T&).
- Don't use moved-from objects without reassigning first.
*/

