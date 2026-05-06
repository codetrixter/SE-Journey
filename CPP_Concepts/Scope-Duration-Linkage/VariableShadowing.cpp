/**
 * *SHADOWING:
 * - This referes to hiding the local varible when a globale variable is defined with same name
 * 
 * !GCC and Clang support the flag -Wshadow that will generate warnings if a variable is shadowed.
 * !There are several subvariants of this flag (-Wshadow=global, -Wshadow=local, and -Wshadow=compatible-local. Consult the GCC documentation 
 * !for an explanation of the differences.
 */

 #include <iostream>
int value { 5 }; // global variable

int main()
{
    int value { 7 }; // hides the global variable value
    ++value; // increments local value, not global value

    --(::value); // decrements global value, not local value (parenthesis added for readability)

    std::cout << "local variable value: " << value << '\n';
    std::cout << "global variable value: " << ::value << '\n';

    return 0;
} // local value is destroyed

/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                 CONCEPT ANALYSIS — VariableShadowing.cpp                   ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. Variable Shadowing
When a local variable has the same name as a global (or outer-scope) variable,
the local variable **shadows** the outer one within its scope.

**Code walkthrough:**
- `int value{5};` (line 11) — global variable.
- `int value{7};` (line 15) — local in `main`, shadows the global.
- `++value;` (line 16) — increments the local (now 8).
- `--(::value);` (line 18) — the `::` scope resolution operator accesses the
  global, decrementing it to 4.

**Key Takeaway:** Use `::` to access the global when shadowed. Better yet,
avoid shadowing by using distinct names.

#### Alternatives / Idiomatic C++
- Use `-Wshadow` (GCC/Clang) to get compiler warnings on shadowing.
- Prefix globals: `g_value` to avoid name collisions.
- Best practice: just don't shadow; use descriptive, distinct names.

#### Real-World Usage
- **GCC/Clang** provide `-Wshadow` flags specifically because this is a common
  source of bugs in real codebases.

---

## 🔁 Quick Revision
- Inner-scope variable with same name hides the outer-scope variable.
- `::variable` accesses the global namespace version.
- Enable `-Wshadow` to catch shadowing at compile time.

### 💡 Remember
- Shadowing is legal but almost always a bug source.

### ⚠️ Gotchas
- Shadowing can happen between any nested scopes, not just global vs local.
*/