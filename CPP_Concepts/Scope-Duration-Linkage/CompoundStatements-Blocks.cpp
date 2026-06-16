/**
 * *Blocks are the code segements with their own scopes
 * *C++ standard only supports 256 levels of nesting
 * *It is generally a good idea to have not more than 3 levels of nested blocks
 */

#include <iostream>

int main()
{ // block 1, nesting level 1
    std::cout << "Enter an integer: ";
    int value {};
    std::cin >> value;

    if (value >  0)
    { // block 2, nesting level 2
        if ((value % 2) == 0)
        { // block 3, nesting level 3
            std::cout << value << " is positive and even\n";
        }
        else
        { // block 4, also nesting level 3
            std::cout << value << " is positive and odd\n";
        }
    }

    return 0;
}
 
/*
╔══════════════════════════════════════════════════════════════════════════════╗
║              CONCEPT ANALYSIS — CompoundStatements-Blocks.cpp              ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. Compound Statements (Blocks) and Nesting
A **block** (compound statement) is a group of zero or more statements enclosed
in `{}`. Each block creates its own **scope** — variables declared inside are
destroyed when the block ends.

**Code walkthrough:**
- Lines 10-28: `main()` is block 1 (nesting level 1). Variable `value` is
  visible from line 12 to line 28.
- Lines 16-19: The `if` body is block 2 (level 2). The inner `if/else` creates
  blocks 3 and 4 (level 3).
- The comment notes C++ supports up to 256 nesting levels per the standard,
  but best practice is ≤3 levels for readability.

**Key Takeaway:** Blocks define scope boundaries; variables are destroyed at
the closing `}`. Keep nesting shallow for maintainable code.

#### Alternatives / Idiomatic C++
- **Early return / guard clauses** reduce nesting:
  ```cpp
  if (value <= 0) return 0;
  if ((value % 2) == 0) std::cout << value << " is positive and even\n";
  else std::cout << value << " is positive and odd\n";
  ```
- C++17 **init-statements in if**: `if (int v = getValue(); v > 0)` scopes the
  variable to the if/else block.
- Current approach is already idiomatic for a simple demo.

#### Real-World Usage
- **All C++ projects** use blocks; this is foundational syntax.
- **Google's C++ Style Guide** recommends keeping functions short and nesting
  shallow — directly related to this concept.

---

## 🔁 Quick Revision
- Blocks `{}` create scopes; variables die at the closing brace.
- C++ standard allows 256 nesting levels; aim for ≤3.
- C++17 `if`-init statements help scope variables tightly.

### 💡 Remember
- Each `{}` is a scope boundary for variable lifetime.
- Deeply nested code is a code smell — refactor into functions.

### ⚠️ Gotchas
- Declaring a variable with the same name in an inner block **shadows** the
  outer one (see VariableShadowing.cpp).
*/
