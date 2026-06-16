/**
 * *Purpose: namespaces were originally introduced to prevent naming collisions in a huge project using vast number of 3rd party libraries
 * - Nested namespaces
 * - namespace aliasing
 * - same namespace can be used in multip[le files or multiple places in a file
 * 
 * !namespaces are heavily used by standard library as in, most of the header files of the standard library is using namespace std
 * !this allows them to ditribute the std code into different header files
 */

 /**********nested namespace ************/
 #include <iostream>

 // In c++17 this can also be written as namespace Foo::Goo{ } in a single line
// namespace Foo
// {
//     namespace Goo // Goo is a namespace inside the Foo namespace
//     {
//         int add(int x, int y)
//         {
//             return x + y;
//         }
//     }
// }

// int main1()
// {
//     std::cout << Foo::Goo::add(1, 2) << '\n';
//     return 0;
// }
 /**********nested namespace ************/

 /**********namespaxce aliasing **********/

namespace Foo::Goo  //C++17 compatible syntax for nested namespace
{
    int add(int x, int y)
    {
        return x + y;
    }
}

int main2()
{
    namespace Active = Foo::Goo; // active now refers to Foo::Goo

    std::cout << Active::add(1, 2) << '\n'; // This is really Foo::Goo::add()

    return 0;
} // The Active alias ends here
 /**********namespaxce aliasing **********/

/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                     CONCEPT ANALYSIS — namespaces.cpp                      ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. Namespaces — Purpose and Usage
Namespaces prevent **naming collisions** in large projects with many libraries.
They group identifiers under a named scope accessed via `::`.

### 2. Nested Namespaces
- Pre-C++17: `namespace Foo { namespace Goo { ... } }`
- C++17: `namespace Foo::Goo { ... }` (compact syntax, line 37).

### 3. Namespace Aliasing
`namespace Active = Foo::Goo;` (line 45) creates a short alias for a deeply
nested namespace, improving readability. The alias has the same scope as any
local variable.

**Key Takeaway:** Namespaces organize code and prevent collisions; aliases
shorten verbose namespace paths.

#### Alternatives / Idiomatic C++
- `using namespace Foo::Goo;` — imports all names (avoid in headers).
- `using Foo::Goo::add;` — imports a single name (preferred).
- C++17 nested syntax `namespace A::B::C {}` is always preferred over nesting.
- C++20 modules reduce the need for namespaces to prevent collisions.

#### Real-World Usage
- **std namespace**: The entire C++ standard library lives in `std`.
- **Boost** (https://github.com/boostorg): Uses deeply nested namespaces
  (`boost::asio::ip::tcp`); aliases are essential.
- **Abseil** (https://github.com/abseil/abseil-cpp): Uses `namespace absl`
  with internal sub-namespaces.

---

## 🔁 Quick Revision
- Namespaces prevent naming collisions across libraries.
- C++17: `namespace A::B {}` for nested namespaces.
- `namespace Alias = Long::Nested::Name;` for convenience.
- Never `using namespace X;` in headers.

### 💡 Remember
- `std` is distributed across many headers — same namespace, many files.
- Unnamed (anonymous) namespaces give internal linkage.

### ⚠️ Gotchas
- `using namespace std;` in a header pollutes every file that includes it.
- Namespace aliases are scoped — they end at the closing `}` of their block.
*/
