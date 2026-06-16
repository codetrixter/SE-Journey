/**
 * @file explicitTypeConversion.cpp
 * @author Abhsihek
 * @brief Here we discuss types of casting and what are those:
 * 1- There are total five types of casting supported by c++:
 *  a- c-style cast. :: Deep into this follow->https://anteru.net/blog/2007/c-background-static-reinterpret-and-c-style-casts/
 *  b- const cast.-> rarely used
 *  c- static cast.
 *  d- dynamic cast.
 *  e- reinterpret cast.-> rarely used
 * 2- We should avoid using c-style casts.
 * 3- use static_cast for narrowing conversions explicitly, else the compiler will give warning.
 * 
 * Casting vs list initialization of temp object:
 * 1- Casting is usually preferred over the other.
 * 2- List initialization of temp object is preferred when we want to avoid narrowing conversions.
 * 3- Direct-list-initializion of a temporary only allows single-word type names.
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
//***************c-style casts***
/* int main(int argc, char const *argv[])
{
    int x{3};
    int y{4};

    ///Here 3 is converted to type double which converts the 4 into double as well
    ///(due to priority arithmetic promotion)
    double d{ (double)3/4};
    std::cout << d;

    return 0;
} */
//***************c-style casts***
int main(int argc, char const *argv[])
{
    double dd{4.5};

    int i = static_cast<int>(3/dd);
    std::cout << i << '\n';
    
    //***Direct-list-initializion of a temporary only allows single-word type names***
    unsigned char c {'a'};
    using uint = unsigned int;
    std::cout << uint {c} << '\n';

    return 0;
}


/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **C-style cast** | `(double)3/4` — avoid in C++ |
| 2 | **static_cast** | `static_cast<int>(3/dd)` — safe, explicit narrowing |
| 3 | **Direct-list-init of temporary** | `uint{c}` — only single-word type names |
| 4 | **Type alias for list-init** | `using uint = unsigned int` enables `uint{c}` |

### 🔄 Alternatives & Modern C++ Idioms:
- Always prefer `static_cast` over C-style casts
- `dynamic_cast` for polymorphic downcasting
- `std::bit_cast` (C++20) for type punning

### 🏭 Real-World Usage:
- `static_cast` is the most common cast in production C++
- Compiler warnings on implicit narrowing caught by `-Wconversion`

### ⚡ Quick Revision:
- C-style cast: `(type)expr` — dangerous, no compile-time safety
- `static_cast<T>(expr)` — compile-time checked, preferred
- List-init temp: `int{x}` prevents narrowing (use type alias for multi-word types)
*/

