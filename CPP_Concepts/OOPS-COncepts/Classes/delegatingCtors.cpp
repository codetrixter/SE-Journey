/**
 * @file delegatingCtors.cpp
 * @author Abhishek 
 * @brief overlapng and delegating constructors/constructor chaining 
 * Rules for delegating:
 * 1- the contructor that delegates to another constructor cannot initialize the member variables of the class,
 * it can do either delegation or initialization but not both.
 * 2- make sure that while creating a constructor delegation chain, there are no loops.
 * @version 0.1
 * @date 2022-06-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
/// If there is a common code that is required to be executed by both ctors then
// class dummy
// {
//     public:
//     dummy()
//     {
//         std::cout << "inside default ctor.";
//     }

//     dummy(int a)
//     {
//         /**
//          * This will compile without error but might sometimes behave un-expectedly,
//          * because dummy obj that is created by this call will be destroyed after returning from the default ctor
//          * as it is not stored in any variable.
//          */
//         dummy();    
//         std::cout << "inside param. ctor." ;
//     }
// };

class Employee
{
private:
    int m_id{};
    std::string m_name{};

public:
    Employee(int id=0, const std::string& name=""):
        m_id{ id }, m_name{ name }
    {
        std::cout << "Employee " << m_name << " created.\n";
    }

    // Use a constructor delegation to minimize redundant code
    Employee(const std::string& name) : Employee{ 0, name }
    { }
};

/**
 * Reseting a class, there may be use case where we want to reset the class to it default values via 
 * a member function.
 */

class Foo
{
private:
    int m_a{ 5 };
    int m_b{ 6 };
public:
    Foo()
    {
    }
    Foo(int a, int b)
        : m_a{ a }, m_b{ b }
    {
    }
    void print()
    {
        std::cout << m_a << ' ' << m_b << '\n';
    }
    void reset()
    {
        // consider this a bit of magic for now
        *this = Foo(); // create new Foo object, then use assignment to overwrite our implicit object
    }
};

int main(int argc, char const *argv[])
{
    Employee em(20);
    Foo a{1, 2};
    a.print();
    a.reset();
    a.print();
    return 0;
}

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Delegating constructors** | `Employee(const std::string& name) : Employee{ 0, name }` |
| 2 | **Constructor chaining rules** | Cannot init members AND delegate simultaneously |
| 3 | **Object reset via assignment** | `*this = Foo()` creates default then assigns |
| 4 | **Default arguments in ctors** | `Employee(int id=0, const std::string& name="")` |
| 5 | **Avoiding redundant code** | Single "master" ctor handles initialization |

### 🔄 Alternatives & Modern C++ Idioms:
- Use in-class member initializers (NSDMI) to reduce ctor count
- Factory functions or `std::optional` for complex initialization
- For reset: consider a named `static` factory returning fresh object

### 🏭 Real-World Usage:
- Delegating ctors reduce duplication in classes with many constructors (e.g., std::string has ~7 ctors)
- Reset pattern (`*this = {}`) common in state machines, builders, game objects

### ⚡ Quick Revision:
- Delegating ctor: must delegate OR initialize, not both
- No circular delegation chains
- `*this = Foo()` resets object to default state
- Prefer one "primary" ctor that others delegate to
*/
