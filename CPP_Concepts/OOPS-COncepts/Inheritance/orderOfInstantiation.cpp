/**
 * @file orderOfInstantiation.cpp
 * @author Abhishek
 * @brief here we define the order in which the classes gets instantiated if they are inheriting 
 * from bases classes.
 * - The classes get instantiated from base to derived.
 * - Calling of the base class constructor is done using initialiser list of the derived class default constructor.
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "Instantiating A\n";
    }
};

class B: public A
{
public:
    B()
    {
        std::cout << "Instantiating B\n";
    }
};

class C: public B
{
public:
    C()
    {
        std::cout << "Instantiating C\n";
    }
};

class D: public C
{
public:
    D()
    {
        std::cout << "Instantiating D\n";
    }
};

int main(int argc, char const *argv[])
{
    //A a();  //what happens in this cases as nothing is printed.
    std::cout << "Creating object of A... \n";
    A a;
    std::cout << "Creating object of B... \n";
    B b;
    std::cout << "Creating object of C... \n";
    C c;
    std::cout << "Creating object of D... \n";
    D d;
    return 0;
}

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Construction order** | Base → Derived (A→B→C→D) |
| 2 | **Implicit base ctor call** | Each derived ctor implicitly calls base default ctor |
| 3 | **Most vexing parse** | `A a()` declares function, not object |

### 🔄 Alternatives & Modern C++ Idioms:
- Use `A a{}` (brace init) to avoid most vexing parse
- Virtual inheritance changes construction order (virtual bases first)

### 🏭 Real-World Usage:
- Understanding construction order critical for resource management in hierarchies
- Destruction is reverse: D→C→B→A (LIFO)
- Logging constructors is a debugging technique for complex hierarchies

### ⚡ Quick Revision:
- Construction: base-to-derived | Destruction: derived-to-base
- `A a()` = function declaration (most vexing parse) — use `A a{}` instead
- Each level's ctor completes before next level begins
*/
