# Exception Handling in C++

## Exception HISTORY

Before C++11, and until C++17, dynamic exception specifications were used in place of noexcept. The dynamic exception specifications syntax uses the throw keyword to list which exception types a function might directly or indirectly throw:

```c++
int doSomething() throw(); // does not throw exceptions
int doSomething() throw(std::out_of_range, int*); // may throw either std::out_of_range or a pointer to an integer
int doSomething() throw(...); // may throw anything
```
Due to factors such as incomplete compiler implementations, some incompatibility with template functions, common misunderstandings about how they worked, and the fact that the standard library mostly didn’t use them, the dynamic exception specifications were deprecated in C++11 and removed from the language in C++17 and C++20. See [this paper](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0003r0.html#2.0) for more context.

---

## Table of Contents

1. [Basic Exception Handling](exceptionHandlingBasics.cpp)
2. [Exceptions, Functions and Stack Unwinding](exceptionsAndStackUnwinding.cpp)
3. [Uncaught Exceptions and Catch-All Handlers](uncaughtExcCatchAllhandler.cpp)
4. [Exceptions, Classes and Inheritance](classAndInheritanceExceptions.cpp)
5. [Rethrowing Exceptions](rethrowExceptions.cpp)
6. [Function Try Blocks](functionTryBlock.cpp)
7. [Exceptions in Destructors](exceptionsWithDestructors.cpp)

---

## Exception Dangers and Downsides

### Key Downsides
- **Resource Management**: Requires careful cleanup of resources
- **Performance Impact**: Increases executable size and significant overhead when exceptions are thrown

### When to Use Exceptions
Use exceptions when:
- Errors occur infrequently
- Errors are serious enough to halt normal execution
- Errors cannot be handled locally at the point of occurrence
- No good alternative exists for returning error codes

---

## The `noexcept` Specifier

The `noexcept` qualifier indicates whether a function may throw exceptions, helping both the compiler and programmers reason about exception safety.

---

## Exception Safety Guarantees

Exception safety guarantees define how functions/classes behave when exceptions occur:

### 1. **No Guarantee**
- No promises about program state if an exception is thrown
- Objects may be left in an unusable state

### 2. **Basic Guarantee**
- No memory leaks
- Object remains usable but program state may be modified

### 3. **Strong Guarantee**
- No memory leaks
- Program state remains unchanged (all-or-nothing semantics)
- Achieved by either succeeding completely or rolling back changes

### 4. **No-Throw / No-Fail Guarantee**

**No-Throw**: Function won't throw exceptions; returns error codes or ignores problems
- Required during stack unwinding
- Examples: destructors, memory deallocation functions

**No-Fail**: Function always succeeds (stronger than no-throw)
- Examples: move constructors/assignment, swap functions, container clear/erase/reset operations, `std::unique_ptr` operations

---

## When to Use `noexcept`

### Key Principles
- Don't apply `noexcept` indiscriminately—functions calling potentially-throwing functions are themselves potentially-throwing
- Standard library policy: use `noexcept` only on functions that **must not** throw or fail

### Benefits of `noexcept`
1. **Safety**: Can be called from exception-unsafe contexts (e.g., destructors)
2. **Optimization**: Compiler doesn't need to maintain unwindable stack state
3. **Efficiency**: STL containers (like `std::vector`) use `noexcept` to choose move vs. copy semantics

### Always Mark as `noexcept`
- Move constructors
- Move assignment operators
- Swap functions

### Consider Marking as `noexcept`
- Functions with explicit no-throw/no-fail guarantees
- No-throw copy constructors and copy assignment operators
- Destructors (implicitly `noexcept` if all members have `noexcept` destructors)
