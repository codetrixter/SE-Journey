/**
 * !- L value expressions evaluate to an idetifible object.
 * !- R value expressions evaluate to a temporary object or a value not associated with an identifiable object.
 * !- An lvalue expression can be converted to an rvalue expression.
 * !- An rvalue expression cannot be converted to an lvalue expression.
 */

 int main() 
 {
    int x = 10; // x is an lvalue
    int y = x;  // x is converted to an rvalue to assign to y

    int* p = &x; // &x is an rvalue (address of x)
    // int& r = 20; // Error: cannot bind non-const lvalue reference to an rvalue
    const int& r = 20; // OK: can bind const lvalue reference to an rvalue

    int z = x + 5; // (x + 5) is an rvalue, sice it resolves to  temporary value, which immidiately looses scope bwyond this expression


    /*********Lvalue to Rvalue coversion */

    int a{ 1 };
    int b{ 2 };

    a = b; // y is not an rvalue, but this is legal. Here conversion is happenening and b is evaluated to 2 by the compiler.

    a = a + 3; //Here the + overloaded operator operates on the converted rvalue of a (which is 1) and r value 
    // 3, producing a new rvalue (which is 4). This new rvalue is then assigned to a.
    /*********************************** */

    return 0;
 }

/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                    CONCEPT ANALYSIS — Lvalue-RvalueExpr.cpp                ║
╚══════════════════════════════════════════════════════════════════════════════╝

## Concepts

### 1. Lvalue Expressions
An **lvalue** (locator value) is an expression that refers to a memory location —
it has an identifiable address you can take with `&`. Variables with names are
the canonical lvalues.

**Code walkthrough:**
- Line 10: `int x = 10;` — `x` is an lvalue; it occupies a named memory slot.
- Line 11: `int y = x;` — `x` on the RHS is an lvalue that undergoes
  **lvalue-to-rvalue conversion** so its stored value (10) can be copied into `y`.
- Line 13: `int* p = &x;` — `&x` takes the address of lvalue `x`. You cannot
  do `&10` because 10 is an rvalue.

**Key Takeaway:** An lvalue designates a persistent object whose address you can
obtain; it lives beyond the expression that created it.

#### Alternatives / Idiomatic C++
- The approach here is already best practice for demonstrating the concept.
- C++17 adds **prvalue materialization**: temporaries are now directly
  constructed into their target, reducing unnecessary copies.
- C++11/14/17 value categories are actually a trinity: lvalue, xvalue, prvalue
  (glvalue = lvalue ∪ xvalue; rvalue = xvalue ∪ prvalue). For interview depth,
  learn the full taxonomy.

---

### 2. Rvalue Expressions
An **rvalue** is a temporary value that does not persist beyond the expression
that uses it. Literals like `10`, results of arithmetic like `x + 5`, and
unnamed temporaries are rvalues.

**Code walkthrough:**
- Line 14: `// int& r = 20;` — Fails because a non-const lvalue reference
  cannot bind to an rvalue. The temporary `20` has no lasting address.
- Line 15: `const int& r = 20;` — A `const` lvalue reference **can** bind to
  an rvalue, extending the temporary's lifetime to that of `r`.
- Line 17: `int z = x + 5;` — `(x + 5)` produces a temporary (rvalue).

**Key Takeaway:** Rvalues are temporaries; `const&` can bind to them and extend
their lifetime, which is fundamental to how pass-by-const-reference works.

#### Alternatives / Idiomatic C++
- C++11 introduced **rvalue references** (`int&&`) which can bind to rvalues
  and allow modification — the basis of move semantics.
  ```cpp
  int&& rref = 20; // OK in C++11+, rref is modifiable
  ```
- Common pitfall: forgetting that `const int& r = 20;` extends lifetime but
  only for the immediate binding — returning a `const&` to a local temporary
  from a function still dangles.

---

### 3. Lvalue-to-Rvalue Conversion
When an lvalue appears in a context that requires a value (not an address), the
compiler reads the stored value — this is the lvalue-to-rvalue conversion.

**Code walkthrough:**
- Line 24: `a = b;` — `b` is an lvalue, but on the RHS of assignment the
  compiler reads its value (2) and writes it into `a`. The comment correctly
  notes this conversion.
- Line 26-27: `a = a + 3;` — `a` is converted to its value (1), added to
  literal `3` producing rvalue `4`, then assigned back to `a`.

**Key Takeaway:** The compiler silently converts lvalues to rvalues whenever it
needs the stored value rather than the object identity.

#### Alternatives / Idiomatic C++
- This is standard behavior; no alternative needed.
- In C++17, the prvalue/glvalue model makes this conversion more precisely
  defined — a prvalue is an initializer, not an object.

---

#### Real-World Usage
- **LLVM/Clang** (https://github.com/llvm/llvm-project): The Clang frontend
  performs lvalue-to-rvalue conversions explicitly in its AST
  (`ImplicitCastExpr` with `LValueToRValue` kind) — understanding this concept
  is essential for compiler development.
- **GCC** (https://gcc.gnu.org/): GCC's middle-end (GIMPLE IR) represents
  lvalue-to-rvalue loads explicitly as memory reads.
- **cppcheck** (https://github.com/danmar/cppcheck): Static analyzers track
  value categories to detect dangling references and use-after-move bugs.

---

## 🔁 Quick Revision
- Lvalue = identifiable object with persistent address.
- Rvalue = temporary value, no persistent address.
- `const&` can bind to rvalues, extending their lifetime.
- Lvalue-to-rvalue conversion: compiler reads stored value when needed.

### 💡 Remember
- "Can I take its address with `&`?" → Yes = lvalue, No = rvalue.
- `const T&` binds to BOTH lvalues and rvalues — that's why it's the universal
  function parameter for read-only access.
- C++11 value categories: lvalue, xvalue, prvalue (know the full taxonomy for
  senior interviews).

### ⚠️ Gotchas
- `int& r = 20;` is ill-formed — non-const lvalue ref cannot bind to rvalue.
- A named rvalue reference (e.g., `int&& rr = 5;`) is itself an **lvalue**
  because it has a name and address.
- Returning `const&` to a local variable or temporary → dangling reference.
*/