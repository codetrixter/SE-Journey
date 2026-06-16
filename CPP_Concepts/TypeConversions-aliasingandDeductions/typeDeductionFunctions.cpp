/**
 * @file typeDeductionFunctions.cpp
 * @author Abhishek
 * @brief Here we discuss about the use of auto keyword for return type deductions:
 * 1- Since C++14 auto is allowed for return type deductions.
 * 2- All return values should be of same type or else the compiler will give error.
 * 3- functions must be fully defined in order for type deduction to work.
 * 4- Trailing return type syntax is something that can be achieved using auto.
 * @version 0.1
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
//auto fun(); //error: use of ‘auto fun()’ before deduction of ‘auto’

/* auto functionOne(bool b)
{
    if(b)
        return 5;
    else
        return 10;
        //return 10.0;    //error: inconsistent deduction for auto return type: ‘int’ and then ‘double
} */

//New way of defining function using auto keyword -> also known as Trailing return syntax.
auto functionOne(bool b)->int
{
    return 25;
}
int main(int argc, char const *argv[])
{
    std::cout << functionOne(true);
    //std::cout << fun();
    return 0;

    //****Tyoe deduction cant be used for function parameter types */
    {
        //void func(auto a); //error: ‘auto’ not allowed in function prototype, allowed in C++20 using templates
        //void func1(int a, auto b); //error: ‘auto’ not allowed in function prototype
    }
}

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **auto return type deduction** | `auto functionOne(bool b)->int` |
| 2 | **Trailing return type** | `auto func() -> int` syntax |
| 3 | **Consistent return types required** | All paths must return same type |
| 4 | **Forward declaration limitation** | Can't use auto before function is defined |

### 🔄 Alternatives & Modern C++ Idioms:
- C++20: `auto` in function params (abbreviated function templates)
- `decltype(auto)` preserves references and cv-qualifiers
- Trailing return useful with `decltype`: `auto f(T a, U b) -> decltype(a+b)`

### 🏭 Real-World Usage:
- Trailing returns common in template metaprogramming
- `decltype(auto)` for perfect forwarding return types
- C++20 auto params simplify generic code

### ⚡ Quick Revision:
- `auto` return: all return statements must deduce to same type
- Function must be fully defined before auto deduction works
- Trailing return: `auto f() -> RetType` — useful with decltype
- C++20: `auto` in params = implicit template
*/
