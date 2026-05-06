/**
 * *External Linkage:
 * ! - An identifier with external linkage can be seen and used both from the file in which it is defined, and from other code files 
 * !(via a forward declaration). In this sense, identifiers with external linkage are truly “global” in that they can be used anywhere 
 * !in your program!
 * ! - Function have external linkage by drfault
 * ! - If you want to define an uninitialized non-const global variable, do not use the extern keyword, otherwise C++ will think 
 * !you’re trying to make a forward declaration for the variable.
 * 
 * Question #1
What’s the difference between a variable’s scope, duration, and linkage? What kind of scope, duration, and linkage do global variables have?

Solution
Scope determines where a variable is accessible. Duration determines when a variable is created and destroyed. Linkage determines whether the
 variable can be exported to another file or not.
Global variables have global scope (a.k.a. file scope), which means they can be accessed from the point of declaration to the end of the file
 in which they are declared.
Global variables have static duration, which means they are created when the program is started, and destroyed when it ends.
Global variables can have either internal or external linkage, via the static and extern keywords respectively.
 */

 #include <iostream>
//-------------summary-------------
// Global variable forward declarations (extern w/ no initializer):
extern int g_y1;                 // forward declaration for non-constant global variable
extern const int g_y2;           // forward declaration for const global variable
//extern constexpr int g_y3;       // not allowed: constexpr variables can't be forward declared

// External global variable definitions (no extern)
int g_x1;                        // defines non-initialized external global variable (zero initialized by default)
int g_x2 { 1 };                  // defines initialized external global variable

// External const global variable definitions (extern w/ initializer)
extern const int g_x3 { 2 };     // defines initialized const external global variable
extern constexpr int g_x4 { 3 }; // defines initialized constexpr external global variable

void sayHi(); // forward declaration for function sayHi, makes sayHi accessible in this file
int main()
{
    sayHi(); // call to function defined in another file, linker will connect this call to the function definition, when this is compiled with another.cpp

    return 0;
}

/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                  CONCEPT ANALYSIS — ExternalLinkage.cpp                    ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. External Linkage
An identifier with **external linkage** can be accessed from other translation
units via a **forward declaration**. Functions have external linkage by default.

**Code walkthrough:**
- `extern int g_y1;` (line 25) — forward declaration for a non-const global
  defined elsewhere. `extern` without initializer = declaration, not definition.
- `int g_x1;` / `int g_x2{1};` (lines 30-31) — definitions of external globals
  (no `extern` keyword needed for definitions of non-const).
- `extern const int g_x3{2};` (line 34) — `extern` + initializer on a `const`
  makes it externally linkable (overriding the default internal linkage of const).
- `void sayHi();` (line 37) — forward declaration of function defined in
  `another.cpp`. The linker resolves this.

### 2. Forward Declarations with `extern`
- Non-const globals: `extern int g_y1;` (declaration only).
- Const globals: `extern const int g_y2;` (declaration only).
- `constexpr` cannot be forward-declared (must be visible at compile time).

**Key Takeaway:** `extern` = "this exists somewhere else, trust me." The linker
connects declarations to definitions across TUs.

#### Alternatives / Idiomatic C++
- C++17 `inline` variables can be defined in headers with external linkage
  without ODR violations:
  ```cpp
  inline constexpr int g_value{42}; // in a header, one entity program-wide
  ```
- Prefer passing values via function parameters over extern globals.
- C++20 modules eliminate much of the need for forward declarations.

#### Real-World Usage
- **Any multi-file C++ project** uses external linkage for cross-TU access.
- **SQLite** (https://github.com/nicknash/sqlite): Uses `extern` declarations
  in headers to share state across compilation units.

---

## 🔁 Quick Revision
- Functions: external linkage by default.
- Non-const globals: external linkage by default.
- `const` globals: internal by default; add `extern` + initializer for external.
- `constexpr` globals: cannot be forward-declared.
- `extern` without initializer = forward declaration.

### 💡 Remember
- Definition vs Declaration: a definition allocates storage; a declaration just
  announces existence.
- Only ONE definition allowed across all TUs (ODR), but unlimited declarations.

### ⚠️ Gotchas
- `extern int g_x;` (no initializer) on a non-const = forward declaration.
  Adding an initializer makes it a definition: `extern int g_x{5};`.
- Don't use `extern` on an uninitialized non-const global definition — the
  compiler thinks it's a forward declaration.
*/