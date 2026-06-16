#include <iostream>
#include "myInt.hpp"

int main()
{
    // Declare an array with 10 elements
    IntArray array(10);

    // Fill the array with numbers 1 through 10
    for (int i{ 0 }; i<10; ++i)
        array[i] = i+1;

    // Resize the array to 8 elements
    array.resize(8);

    // Insert the number 20 before element with index 5
    array.insertBefore(20, 5);

    // Remove the element with index 3
    array.remove(3);

    // Add 30 and 40 to the end and beginning
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    // Print out all the numbers
    for (int i{ 0 }; i<array.getLength(); ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';

    return 0;
}

/*
## 📝 CONCEPT ANALYSIS — STL-IMPL (myInt.hpp + myInt.cpp)

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Dynamic array implementation** | Manual new[]/delete[] management |
| 2 | **RAII** | Destructor frees memory |
| 3 | **Operator[] overloading** | Array-style access with bounds checking |
| 4 | **Resize with element preservation** | Copy to new allocation, then swap |
| 5 | **Insert/remove operations** | Shift elements + reallocate |

### 🔄 Alternatives & Modern C++ Idioms:
- Use `std::vector<int>` — handles all of this automatically
- Rule of Five: this class needs copy ctor, copy assign, move ctor, move assign
- `std::allocator` for custom memory management
- `std::unique_ptr<int[]>` for automatic cleanup

### 🏭 Real-World Usage:
- Understanding how `std::vector` works internally
- Custom allocators for game engines, embedded systems
- Pool allocators for performance-critical paths

### ⚡ Quick Revision:
- resize: allocate new, copy elements, delete old, reassign pointer
- insertBefore: allocate n+1, copy before/after, insert at index
- remove: allocate n-1, skip removed element during copy
- Always delete[] old array before reassigning pointer
- Missing: copy/move operations (Rule of Five violation)
*/