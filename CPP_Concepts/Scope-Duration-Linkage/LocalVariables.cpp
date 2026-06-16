/**
 * *SCOPE:
 * - Scope (of an identifier) referes to the availablity of that identifier during the course of the program execution.
 * - If the identifer can be accessed, then it is (in scope), else (out of scope).
 * 
 * *Duration:
 * - This refers to the rules that govern when and how a variable is created(instantiated) or when it is destroyed.
 * - usually it referes to the varibales lifetime.
 * 
 * *LINKAGE:
 * - An identifier’s linkage determines whether a declaration of that same identifier in a different scope refers to the 
 * same object (or function).
 * 
 * !importanat points to rem.:
 * - Local vairable have block scope.
 * - All varibale names within a scope must be unique.
 * - Local variables have automatic storage duration.
 * - Local variabels have no linkage.
 * 
 * *NOTE: Local variables must be defined in the most limited scope.
 */

 #include <iostream>

 int main(int argc, char const *argv[])
 {
    int small = 0, large = 0;   //uninitialized by default
    std::cout << "Enter an Integer:" << std::endl;
    std::cin >> small;

    std::cout << "Enter a larger no: " << std::endl;
    std::cin >> large;

    //if the user did it incorrectly.
    if(large < small)
    {
        std::cout << "Swapping the values..." << std::endl;
        int temp = 0;
        temp = large;
        large = small;
        small = temp;
    }   //scope of temp ends here
       
    std::cout << "The smaller value is : " << small << std::endl;
    std::cout << "The larger value is : " << large << std::endl;
    return 0;
 }
 
/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                  CONCEPT ANALYSIS — LocalVariables.cpp                     ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. Scope — Block Scope of Local Variables
Local variables are only accessible within the block `{}` where they are
declared, from the point of declaration to the end of the block.

**Code walkthrough:**
- `small` and `large` (line 28) have scope from declaration to end of `main`.
- `temp` (line 39) is declared inside the `if` block and goes out of scope at
  line 42 (`}`). Accessing `temp` after line 42 would be a compile error.

**Key Takeaway:** Declare variables in the most limited scope to minimize
lifetime and prevent accidental misuse.

### 2. Duration — Automatic Storage Duration
Local variables have **automatic storage duration**: they are created at the
point of definition and destroyed when they go out of scope. The stack manages
this automatically.

### 3. Linkage — No Linkage
Local variables have **no linkage**, meaning their names cannot be referred to
from other scopes or translation units.

#### Alternatives / Idiomatic C++
- The swap logic (lines 39-42) can be replaced with `std::swap(small, large);`
  which is more idiomatic and handles move semantics for complex types.
- C++17 structured bindings and `if`-init could tighten scope further in more
  complex scenarios.

#### Real-World Usage
- **Every C++ project** relies on automatic storage duration for stack-based
  RAII patterns.
- **Chromium** (https://github.com/nicknash/chromium): Enforces strict scoping
  rules via their style guide to prevent dangling references.

---

## 🔁 Quick Revision
- Local variables: block scope, automatic duration, no linkage.
- Define variables in the smallest scope possible.
- `std::swap` is preferable to manual swap logic.

### 💡 Remember
- Scope = where accessible; Duration = when alive; Linkage = cross-scope visibility.
- All three are independent axes of a variable's properties.

### ⚠️ Gotchas
- Uninitialized local variables contain indeterminate values (UB to read them).
  Always initialize: `int x{};` or `int x{0};`.
*/
