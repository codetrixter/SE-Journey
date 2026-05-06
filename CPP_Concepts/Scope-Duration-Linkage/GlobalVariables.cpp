/**
 * *GLOBAL VARIABLES:
 * - These are the variables define at the start of the file
 * - These can also be defined in a namesapce.
 * !Scope
 * - These have global scope or file scope.
 * !Duration
 * - These have static duration meaning starts when main begins and ends when program is destroyed.
 * 
 * !- Prefer defining global vriables inside a namespace.
 */

 // Non-constant global variables
int g_x;                 // defines non-initialized global variable (zero initialized by default)
// int g_x {};              // defines explicitly value-initialized global variable
// int g_x { 1 };           // defines explicitly initialized global variable

// Const global variables
//const int g_y;           // error: const variables must be initialized
const int g_y { 2 };     // defines initialized global const

// Constexpr global variables
// constexpr int g_y;       // error: constexpr variables must be initialized
// constexpr int g_y { 3 }; // defines initialized global constexpr

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                  CONCEPT ANALYSIS — GlobalVariables.cpp                    ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. Non-Constant Global Variables
Declared outside any function at file scope. Zero-initialized by default.
- `int g_x;` → zero-initialized.
- `int g_x{};` → explicitly value-initialized (same result, clearer intent).
- `int g_x{1};` → explicitly initialized to 1.

**Key Takeaway:** Non-const globals have external linkage by default (visible
across translation units). They should be avoided (see Global-Evil.cpp).

### 2. Const Global Variables
`const int g_y{2};` — Must be initialized. Has **internal linkage** by default
in C++ (unlike C), meaning each translation unit gets its own copy.

### 3. Constexpr Global Variables
`constexpr int g_y{3};` — Must be initialized with a compile-time constant.
Also has **internal linkage** by default. Evaluated at compile time.

**Note:** `constexpr int g_y;` without an initializer is ill-formed.

#### Alternatives / Idiomatic C++
- C++17 `inline constexpr` allows a single definition across translation units:
  ```cpp
  inline constexpr int g_value{42}; // OK in headers, one definition
  ```
- Prefer `constexpr` over `const` for compile-time constants.
- Prefer namespaced constants over raw globals.

#### Real-World Usage
- **Abseil** (https://github.com/abseil/abseil-cpp): Uses `inline constexpr`
  extensively for library-wide constants.
- **folly** (https://github.com/facebook/folly): Defines constants in
  namespaces to avoid polluting the global namespace.

---

## 🔁 Quick Revision
- Non-const globals: zero-initialized, external linkage, static duration.
- `const` globals: internal linkage by default in C++.
- `constexpr` globals: internal linkage, must have compile-time initializer.
- C++17 `inline constexpr` = best practice for shared constants.

### 💡 Remember
- Why do const globals have internal linkage? So they can be placed in headers
  and included in multiple TUs without ODR violations.

### ⚠️ Gotchas
- This file has intentional compilation errors (redefinitions of `g_x`, `g_y`).
  Each variable name must be unique within the same scope.
- `constexpr` without initializer = compile error.
*/
