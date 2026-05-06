/**
 * * Non-Const global variables are evil :
 * ! - Non const. varibales are discouraged because due to their nature i.e external linkage, meaning any function of any translation unit can change the 
 * !value of that varibales in a way that make it difficult to debug -> This can be rectified by using local variables
 * ! - Initialization order problem of global variables
 * *
 */

 #include <iostream>

int g_mode; // declare global variable (will be zero-initialized by default)

void doSomething()
{
    g_mode = 2; // set the global g_mode variable to 2
}

int main()
{
    g_mode = 1; // note: this sets the global g_mode variable to 1.  It does not declare a local g_mode variable!

    doSomething();

    // Programmer still expects g_mode to be 1
    // But doSomething changed it to 2!

    if (g_mode == 1)
    {
        std::cout << "No threat detected.\n";
    }
    else
    {
        std::cout << "Launching nuclear missiles...\n";
    }

    return 0;
}

/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                    CONCEPT ANALYSIS — Global-Evil.cpp                      ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. Why Non-Const Global Variables Are Dangerous
Non-const global variables have **external linkage** by default, meaning any
function in any translation unit can read/modify them without restriction.

**Code walkthrough:**
- `int g_mode;` (line 11) — non-const global, zero-initialized, external linkage.
- `main()` sets `g_mode = 1` (line 20).
- `doSomething()` sets `g_mode = 2` (line 15) — silently mutating shared state.
- After `doSomething()` returns, the programmer expects `g_mode == 1` but it's
  now `2`, leading to launching nuclear missiles (line 33).

**Key Takeaway:** Non-const globals create invisible coupling between functions,
making bugs extremely hard to track. Use local variables or pass state explicitly.

### 2. Initialization Order Problem (SIOF)
The **Static Initialization Order Fiasco**: when non-local static objects in
different translation units depend on each other, their initialization order is
**undefined** across TUs. This can cause use-before-initialization bugs.

#### Alternatives / Idiomatic C++
- Replace globals with **function-local statics** (Meyers' Singleton pattern):
  ```cpp
  int& getMode() {
      static int mode{1};
      return mode;
  }
  ```
  This guarantees initialization on first use.
- Pass state via function parameters or dependency injection.
- If a global is truly needed, make it `const` or `constexpr`.
- C++20 modules help with initialization ordering.

#### Real-World Usage
- **Google C++ Style Guide**: Explicitly bans non-const global/static variables
  of class type due to initialization order issues.
- **LLVM**: Uses `ManagedStatic<>` to control initialization order of globals.
- **Chromium**: Enforces no non-trivial global constructors via tooling.

---

## 🔁 Quick Revision
- Non-const globals = shared mutable state = hard-to-trace bugs.
- Any function can silently modify them → invisible side effects.
- Static Initialization Order Fiasco: undefined init order across TUs.

### 💡 Remember
- "Global variables are the `goto` of data" — avoid them.
- If you must use global state, make it `const`/`constexpr` or wrap in a function.

### ⚠️ Gotchas
- Zero-initialization of globals happens before `main()`, but dynamic
  initialization order across TUs is unspecified.
- Thread safety: multiple threads accessing a non-const global = data race (UB).
*/