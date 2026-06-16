/**
 * @file exceptionsAndStackUnwinding.cpp
 * @author Abhishek
 * @brief Here we discuss about the stack unwinding that happens when an exception is resolved.
 * 
 * //! When en exception is thrown, the program first check if it can be handled within the same function,
 * //! if not, the the functions caller is checked to see if the handling is done there or not. This process of checking
 * //! continues till a handler is found or stack is exhausted, if a match is found then the control jumps from
 * //! the point of exception to the top of matching catch block. THis process involves unwinding of the
 * //! stack and making sure the handling function is at the top of the stack.
 * 
 * @version 0.1
 * @date 2022-09-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

void last() // called by third()
{
    std::cout << "Start last\n";
    std::cout << "last throwing int exception\n";

    throw -1;   //stack unwinding happens here and execution goes to third(), since exception not caught.

    std::cout << "End last\n";
}

void third() // called by second()
{
    std::cout << "Start third\n";
    last();     //stack unwinding happens here and execution goes to second(), since exception not caught.
    std::cout << "End third\n";
}

void second() // called by first()
{
    std::cout << "Start second\n";
    try
    {
        third();    //stack unwinding happens here and execution goes to first(), since matching exception not found.
    }
    catch (double)
    {
         std::cerr << "second caught double exception\n";
    }
    std::cout << "End second\n";
}

void first() // called by main()
{
    std::cout << "Start first\n";
    try
    {
        second();       //exception match found, last print is executed.
    }
    catch (int)
    {
         std::cerr << "first caught int exception\n";
    }
    catch (double)
    {
         std::cerr << "first caught double exception\n";
    }
    std::cout << "End first\n";     //goes ot main() from here.
}

int main()
{
    std::cout << "Start main\n";
    try
    {
        first();
    }
    catch (int)
    {
         std::cerr << "main caught int exception\n";
    }
    std::cout << "End main\n";

    return 0;
}

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Stack unwinding** | Exception propagates up call stack until caught |
| 2 | **Exception propagation** | last→third→second→first (caught in first) |
| 3 | **Unmatched catch skipped** | `catch(double)` in second doesn't match int |
| 4 | **Execution resumes after handler** | "End first" prints after catch |

### 🔄 Alternatives & Modern C++ Idioms:
- `std::nested_exception` for exception chaining
- RAII ensures resources cleaned up during unwinding
- `noexcept` prevents unwinding (calls `std::terminate` instead)

### 🏭 Real-World Usage:
- Stack unwinding triggers destructors — RAII guarantees cleanup
- Deep call stacks in servers: exception caught at request handler level
- Without RAII, stack unwinding causes resource leaks

### ⚡ Quick Revision:
- Exception searches up the call stack for matching catch
- Stack frames are unwound (local objects destructed) during propagation
- First matching catch block handles the exception
- Execution continues AFTER the catch block (not after throw point)
- If no match found → `std::terminate()` called
*/