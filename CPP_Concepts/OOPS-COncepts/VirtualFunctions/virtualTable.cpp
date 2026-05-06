/**
 * @file virtualTable.cpp
 * @author Abhishek
 * @brief Here we discuss about the virtual table and what is it used for:
 * In resolving the calls to virtual functions the compiler uses Virtual table. 
 * ******************VIRTUAL TABLE FOR BELOW CLASSES************************
 * link -> https://www.learncpp.com/cpp-tutorial/the-virtual-table/
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022
 * 
 * +------------+        +-------------------+
  |   Base     |------->|   Base VTable     |
  | * __vptr   |        | function1()       |
  | virtual    |<-------| function2()       |
  | function1()|        +-------------------+
  | virtual    |
  | function2()|
  +------------+
       |
       v
  +-------------+        +-------------------+
  | D1:         |------->|   D1 VTable       |
  | public Base |        | function1()       |
  | * __vptr    |        | function2()       |
  | (inherited) |<-------+-------------------+
  | virtual     |
  | function1() |
  +-------------+
       |
       v
  +-------------+        +-------------------+
  | D2:         |------->|   D2 VTable       |
  | public Base |        | function1()       |
  | * __vptr    |        | function2()       |
  | (inherited) |<-------+-------------------+
  | virtual     |
  | function2() |
  +-------------+
 * 
 */

 
#include <iostream>

class Base
{
public:
    virtual void function1() { std::cout << "Base function1... \n"; }
    virtual void function2() { std::cout << "Base function2... \n"; }
};

class D1: public Base
{
public:
    void function1() override { std::cout << "D1 function1... \n"; }
};

class D2: public Base
{
public:
    void function2() override { std::cout << "D2 function2... \n"; }
};
int main(int argc, char const *argv[])
{
    D1 der;
    /// This has access to D1 class vptr and hence function2 in D1 vtable is pointing to base version.
    der.function2();

    Base* base{&der};
    /// Here D1 vptr is used to resolve the function1 version
    base->function1();
    /// base->function2();

    Base baseOnly;
    Base* b{&baseOnly};
    /// here since the object is of base class, so vptr of Base is used to resolve function calls.
    b->function1();
    b->function2();

    return 0;
}

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Virtual table (vtable)** | Each class with virtual functions has its own vtable |
| 2 | **vptr** | Hidden pointer in each object pointing to class's vtable |
| 3 | **Virtual dispatch mechanism** | `base->function1()` looks up vtable via vptr |
| 4 | **Partial override** | D1 overrides function1 only; function2 points to Base version |

### 🔄 Alternatives & Modern C++ Idioms:
- Devirtualization: compiler optimizes away vtable lookup when type is known
- CRTP eliminates vtable overhead for static polymorphism
- `final` keyword helps compiler devirtualize

### 🏭 Real-World Usage:
- Understanding vtable critical for debugging (viewing vptr in debugger)
- ABI compatibility: vtable layout matters for shared libraries
- Performance: vtable = indirect call = potential cache miss

### ⚡ Quick Revision:
- Each polymorphic class has ONE vtable (shared by all instances)
- Each object has ONE vptr (points to its class's vtable)
- Vtable stores function pointers for all virtual functions
- Non-overridden entries point to base class version
- Cost: one pointer per object + one indirect call per virtual dispatch
*/
