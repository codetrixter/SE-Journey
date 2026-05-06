/**
 * @file rethrowExceptions.cpp
 * @author Abhishek
 * @brief Here we discuss about rethrowing exceptions:
 * 1- This is used when, you may run into a case where you want to catch an exception, but not want to (or have the ability to) fully handle 
 * it at the point where you catch it.
 * 2- When rethrowing the same exceptions, use the throw keyword by itself.
 * @version 0.1
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
class Base
{
public:
    Base() {}
    virtual void print() { std::cout << "Base"; }
};

class Derived: public Base
{
public:
    Derived() {}
    void print() override { std::cout << "Derived"; }
};

int main()
{
    try
    {
        try
        {
            throw Derived{};
        }
        catch (Base& b)
        {
            std::cout << "Caught Base b, which is actually a ";
            b.print();
            std::cout << '\n';
            //throw b;  this is an incorrect way of throwing exception since the object gets sliced here, since b is now copy-initialized from derived exception.
            throw; // note: We're now rethrowing the object here
        }
    }
    catch (Base& b)
    {
        std::cout << "Caught Base b, which is actually a ";
        b.print();
        std::cout << '\n';
    }

    return 0;
}

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Rethrowing exceptions** | `throw;` preserves original exception type |
| 2 | **Object slicing in exceptions** | `throw b;` slices Derived to Base |
| 3 | **Catch by reference** | `catch (Base& b)` avoids slicing on catch |
| 4 | **Nested try-catch** | Inner catch rethrows to outer catch |

### 🏭 Real-World Usage:
- Middleware: catch, log, rethrow to let upper layer handle
- Exception translation: catch low-level, throw high-level

### ⚡ Quick Revision:
- `throw;` (no operand) rethrows current exception without slicing
- `throw b;` copy-initializes new exception → SLICES if b is base ref to derived
- Always use `throw;` to rethrow, never `throw exceptionVariable;`
*/