/**
 * @file thisPointer.cpp
 * @author Abhishek
 * @brief Here we will see the puspose this pointer in c++
 * 1- this is a hidden pointer which is sent along with function param when a member func. is called on an instance
 * of a class.
 * 2- It can also be used to create member function chaining.
 * 3- "this" is a pointer and not a reference since references were not invented when "this" pointer was created.
 * 4- "this" pointer is a const pointer to a on-const object, meaning we cannot change the object pointed to by "this" pointer but can modify the pointed object.
 * @version 0.1
 * @date 2022-06-03
 * @copyright Copyright (c) 2022
 */

#include <iostream>
/**
 * @brief Whenever a member function is called with the object then there is a hidden class pointer is sent 
 * to that function via parameters which helps the function in calling the correct instances members
 */
/* class Simple
{
private:
    int m_id;

public:
    Simple(int id)
        : m_id{ id }
    {
    }

    void setID(int id) { m_id = id; }
    /// consecutively this line is also updated as 
    /// void setID(Simple* const this, int id){this->m_id = id};
    int getID() { return m_id; }
};
int main()
{
    Simple simple{1};
    simple.setID(2);
    /// above line is written as 
    /// simple.setID(&simple, 2);
    std::cout << simple.getID() << '\n';

    return 0;
} */
//**************Function chaining************* */

class Calc
{
private:
    int m_value{};

public:
    Calc& add(int value) { m_value += value; return *this; }
    Calc& sub(int value) { m_value -= value; return *this; }
    Calc& mult(int value) { m_value *= value; return *this; }

    int getValue() const { return m_value; }

    void reset() { *this = {}; }
};


int main()
{
    Calc calc{};
    calc.add(5).sub(3).mult(4);

    std::cout << calc.getValue() << '\n'; // prints 8

    calc.reset();

    std::cout << calc.getValue() << '\n'; // prints 0

    return 0;
}
//**************Function chaining************* */

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **`this` pointer** | Hidden param passed to all non-static member functions |
| 2 | **Method chaining / fluent interface** | `calc.add(5).sub(3).mult(4)` via `return *this` |
| 3 | **`this` is const pointer** | `T* const this` — cannot reassign, can modify pointee |
| 4 | **Object reset via `*this = {}`** | Assigns default-constructed object |

### 🔄 Alternatives & Modern C++ Idioms:
- C++23 deducing `this` (`this auto& self`) makes explicit `this` usage cleaner
- Builder pattern is the production-grade version of method chaining
- Named parameter idiom uses chaining for readable object configuration

### 🏭 Real-World Usage:
- Fluent APIs: iostream (`cout << x << y`), query builders, config objects
- `*this` dereferencing used in operator overloading (`operator=` returns `*this`)
- Builder pattern in game engines, UI frameworks

### ⚡ Quick Revision:
- `this` = `T* const` (const pointer to non-const object)
- `return *this` enables chaining when return type is `T&`
- In const methods, `this` is `const T* const`
- `*this = {}` resets object to default state
*/