/**
 * *Internal Linkage
 * ! - Global varibales and function identifiers can either have internal or external linkage.
 * ! - An identifier with internal linkage can be seen and used within a single translation unit, but it is not accessible from other translation units. 
 * !   This means that if two source files have identically named identifiers with internal linkage, those identifiers will be treated as independent 
 * !   (and do not result in an ODR violation for having duplicate definitions).
 * ! - Global variables with internal linkage are called internal varibales
 * ! - Functions can also be made to have internal linkage by adding static to their declaration
 * ! - Typically internal linkage is used fro following 2 reasons:
 *      1- Avoid naming collisions
 *      2- Restrict the use of an identifier
 * 
 * NOTE: The C++11 standard (appendix C) provides the rationale for why const variables have internal linkage by default: “Because const objects can be
 *  used as compile-time values in C++, this feature urges programmers to provide explicit initializer values for each const. This feature allows the
 *  user to put const objects in header files that are included in many compilation units.”

The designers of C++ intended two things:

Const objects should be usable in constant expressions. In order to be usable in a constant expression, the compiler must have seen a definition 
(not a declaration) so it be evaluated at compile-time.
Const objects should be able to be propagated via header files.
Objects with external linkage can only be defined in a single translation unit without violating the ODR -- other translation units must access those
 objects via a forward declaration. If const objects had external linkage by default, they would only be usable in constant expressions in the 
 single translation unit containing the definition, and they could not be effectively propagated via header files, as #including the header into
 more than one source file would result in an ODR violation.

Objects with internal linkage can have a definition in each translation unit where they are needed without violating the ODR. This allows const objects
 to be placed in a header file and #included into as many translation units as desired without violating the ODR. And since each translation unit
 has a definition rather than a declaration, this ensures that those constants can be used in constant expressions within the translation unit.

Inline variables (which can have external linkage without causing ODR violations) weren’t introduced until C++17.
 */

 #include <iostream>

// static int g_x{}; // non-constant globals have external linkage by default, but can be given internal linkage via the static keyword

// const int g_y{ 1 }; // const globals have internal linkage by default
// constexpr int g_z{ 2 }; // constexpr globals have internal linkage by default

// int main()
// {
//     std::cout << g_x << ' ' << g_y << ' ' << g_z << '\n';
//     return 0;
// }

//---------------------------------------------------------------------

// This function is declared as static, and can now be used only within this file
// Attempts to access it from another file via a function forward declaration will fail
// In ADD.cpp file:
[[maybe_unused]] static int add(int x, int y)
{
    return x + y;
}

//in main.cpp:

#include <iostream>

int add(int x, int y); // forward declaration for function add

int main()
{
    std::cout << add(3, 4) << '\n';

    return 0;
}   //ERROR: add is outside main's scope

/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                  CONCEPT ANALYSIS — InternalLinkage.cpp                    ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. Internal Linkage via `static` Keyword
An identifier with **internal linkage** is visible only within its translation
unit. Two TUs can have identically-named internal-linkage identifiers without
ODR violations — they are independent entities.

**Code walkthrough:**
- `static int add(int x, int y)` (line 51) — the `static` keyword gives `add`
  internal linkage, making it invisible to other TUs.
- `int add(int x, int y);` (line 58) — forward declaration in "main.cpp" tries
  to access `add` but fails at link time because `add` is file-local.

**Key Takeaway:** `static` on a function/global variable = internal linkage =
visible only in this file.

### 2. `const` and `constexpr` Have Internal Linkage by Default
- `const int g_y{1};` — internal linkage by default in C++.
- `constexpr int g_z{2};` — same.

This allows placing them in headers without ODR violations (each TU gets its
own copy). C++17 `inline` variables provide an alternative with external linkage.

### 3. Reasons to Use Internal Linkage
1. **Avoid naming collisions** across translation units.
2. **Restrict access** — encapsulate implementation details to a single file.

#### Alternatives / Idiomatic C++
- C++11+: Use **anonymous namespaces** instead of `static` for internal linkage:
  ```cpp
  namespace {
      int add(int x, int y) { return x + y; }
  }
  ```
  Anonymous namespaces are the modern preferred idiom.
- `[[maybe_unused]]` attribute (C++17) suppresses unused warnings — used here
  on the static `add` function.

#### Real-World Usage
- **Linux kernel** (C): Uses `static` extensively to limit symbol visibility.
- **Boost** (https://github.com/boostorg): Uses anonymous namespaces for
  implementation details in header-only libraries.
- **abseil-cpp**: Uses internal namespaces (`::absl::internal`) for the same purpose.

---

## 🔁 Quick Revision
- `static` on global variable/function → internal linkage (file-local).
- `const`/`constexpr` globals → internal linkage by default.
- Anonymous namespaces = modern alternative to `static` for internal linkage.

### 💡 Remember
- Internal linkage prevents ODR violations when same-named entities exist in
  multiple TUs.
- The rationale for const having internal linkage: enables use in constant
  expressions across multiple TUs via headers.

### ⚠️ Gotchas
- `static` means different things in different contexts: internal linkage (at
  file scope), static duration (at block scope), class-level (shared member).
- This file has a deliberate linker error: the forward-declared `add` cannot
  find the `static` version.
*/