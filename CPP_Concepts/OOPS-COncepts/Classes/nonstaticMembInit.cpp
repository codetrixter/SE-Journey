/**
 * @file nonstaticMembInit.cpp
 * @author Abhishek 
 * @brief non static member initializer list
 * @version 0.1
 * @date 2022-05-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

class square
{
    private:
    //non static member initializer list.
    int val_a{ 10 };
    int val_b{ 20 };    //brace init
    int val_d = 40;     //copy initi
    //int val_c( 30 );        //parenthesis cannot be used for non static member init.

    public:
    square(int valA, int valB):
    val_a{valA}, val_b{valB}
    {
        std::cout << "ctor" << val_a << val_b;
    }
};

int main(int argc, char const *argv[])
{
    square sq{10, 20};
    square sqNew(30, 40);     
    return 0;
}

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Non-static member initializers (NSDMI)** | `int val_a{ 10 }` — default value in class |
| 2 | **Brace vs copy initialization** | `int val_a{ 10 }` vs `int val_d = 40` |
| 3 | **Parenthesis not allowed for NSDMI** | `int val_c( 30 )` is invalid |
| 4 | **Constructor overrides NSDMI** | Init list takes precedence over in-class default |

### 🔄 Alternatives & Modern C++ Idioms:
- NSDMI (C++11) is preferred for providing sensible defaults
- Use `= default` constructor when NSDMI provides all defaults
- Brace initialization preferred (narrowing conversion protection)

### 🏭 Real-World Usage:
- NSDMI reduces constructor count — great for config/settings classes
- Makes class self-documenting: defaults visible at declaration
- Used extensively in modern codebases to simplify maintenance

### ⚡ Quick Revision:
- NSDMI: `int x{ val }` or `int x = val` — NOT `int x(val)`
- If member init list provides a value, NSDMI is ignored for that member
- Brace init prevents narrowing; copy init does not
*/
