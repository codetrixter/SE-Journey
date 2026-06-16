/**
 * @file memberInitList.cpp
 * @author Abhishek Mishra      
 * @brief C++11 provideas a way to initialize the member variables of the class, It is called member initializer list.
 * 1- In the the member initializer list, the member variables are initialized before the body of the constructor is executed.
 * 2- The member initializer list is more efficient than assignment in the constructor body.
 * 3- The member initializer list is the only way to initialize the const and reference member variables.
 * @version 0.1
 * @date 2022-05-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

class A
{
    private:
    int val_a;

    public:
    A(int val): val_a{val}
    {
        std::cout << "inside A ctor" << val_a << "\n";
    }
};

class B
{
    private:
    A mem_A;
    const int Arr[5];
    int sum;

    public:
    B(int valA, int valB):
    mem_A{valA}, Arr{1, 2, 3, 4, 5}, sum{valB}      /// initilaizing the A's class member variables and array
    {
        std::cout << "inside B ctor" << sum;
    }

};

int main(int argc, char const *argv[])
{
    B nObj(5, 10);

    return 0;
}

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Member initializer list** | `B(int valA, int valB): mem_A{valA}, Arr{...}, sum{valB}` |
| 2 | **Initializing composition members** | `mem_A{valA}` calls A's constructor |
| 3 | **Const array initialization** | `const int Arr[5]` initialized via list |
| 4 | **Order of initialization** | Members initialized in declaration order, not list order |

### 🔄 Alternatives & Modern C++ Idioms:
- Use `std::array` instead of C-style arrays for safer, more flexible initialization
- In-class member initializers (NSDMI) for default values, override in init list when needed
- `= default` for trivial constructors

### 🏭 Real-World Usage:
- Member init lists are mandatory for const members, references, and base classes
- Performance: avoids default-construct-then-assign for complex members
- All production C++ code uses init lists as standard practice

### ⚡ Quick Revision:
- Init list runs BEFORE constructor body
- Only way to initialize `const` and `&` members
- Order of init = order of declaration in class, NOT order in list
- More efficient than assignment in body (one construction vs construct + assign)
*/
