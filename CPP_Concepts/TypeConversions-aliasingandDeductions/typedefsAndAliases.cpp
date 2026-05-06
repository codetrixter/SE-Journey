/**
 * @file typedefsAndAliases.cpp
 * @author Abhishek
 * @brief Here we discuss the uses of type aliases and typedef and their differences:
 * 1- These are not the new types, just an alternate name for the existing types in c++.
 * 2- The scope of type aliases remains the same as the data type it is refering to.
 * 3- typedef is still used in c++ for historical reasons, but their use is discouraged.
 * 4- type aliases can be used for platform independant coding.
 * 5- type aliases make complex data types, simple to write and understand.
 * 6- type aliases can also be used to give meaning to the return types, since using the types alone will 
 * not tell the user what the return values is for.
 * 7 - type aliases also makes the code maintenance easier in the sense that, if a tyoe needs to be
 * changed/modified it can be done by making chnage at oneplace where the aliasing is done.
 * 8 - type aleases are not type safe, so they can be used interchangably with the original type, hence should be used carefully.
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
//*********** 4th and 5th point ***
//These are used to hide the platform specific details, using int and char on different platforms could mean
// different sizes of int.
/* #ifdef INT_2_BYTES
using int8_t = char;
using int16_t = int;
using int32_t = long;
#else
using int8_t = char;
using int16_t = short;
using int32_t = int;
#endif */
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <utility>

//using aliases we dont have to write the complext type every time we need to define a variable of that type.
using pairlist_t = std::vector<std::pair<std::string, int>>;

int main(int argc, char const *argv[])
{
    //Here int_least8_t is just an aliase of char data type.
    std::int_least8_t x{97};
    std::cout << x;

    pairlist_t pair;
    return 0;
}
//*********** 4th point ***

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Type aliases (using)** | `using pairlist_t = std::vector<...>` |
| 2 | **Platform-independent types** | `int8_t`, `int16_t` via conditional defines |
| 3 | **Simplifying complex types** | `pairlist_t` instead of full vector<pair<...>> |
| 4 | **typedef vs using** | `using` is preferred (clearer, works with templates) |

### 🔄 Alternatives & Modern C++ Idioms:
- `using` over `typedef` — works with templates, more readable
- `auto` reduces need for type aliases in many contexts
- Template aliases: `template<typename T> using Vec = std::vector<T>`

### 🏭 Real-World Usage:
- `<cstdint>` types (`int32_t`, etc.) are aliases for portability
- Complex callback types: `using Callback = std::function<void(int)>`
- API boundaries: meaningful alias names document intent

### ⚡ Quick Revision:
- `using Name = Type` — modern, preferred over `typedef Type Name`
- Not type-safe: alias is interchangeable with original type
- Scope follows normal rules (file, block, namespace)
- Simplifies maintenance: change type in one place
*/