/**
 * @file RAIIDestructor.cpp
 * @author Abhishek
 * @brief Destructor use and purpose:
 * 1- Whenever a dynamically allocated object goes out of scope the destructor is called for 
 * graceful deallocation of the memory. hence it called just before the memory is deallocated.
 * 2- Destructor does not have any return value or parameters and can only be defined once per class. 
 * 
 * The below example also demostrates RAII(Resource Acquisation Is Initialization)
 * which basicall means that when the resource is acquired then only it is initialized and 
 * it is deallocated when no more in use. We achieve this via contructors and Destructors.
 * @version 0.1
 * @date 2022-06-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

class Simple
{
private:
    int m_nID{};

public:
    Simple(int nID)
        : m_nID{ nID }
    {
        std::cout << "Constructing Simple " << nID << '\n';
    }

    ~Simple()
    {
        std::cout << "Destructing Simple" << m_nID << '\n';
    }

    int getID() { return m_nID; }
};

int main()
{
    // Allocate a Simple on the stack
    Simple simple{ 1 };
    std::cout << simple.getID() << '\n';

    // Allocate a Simple dynamically
    Simple* pSimple{ new Simple{ 2 } };

    std::cout << pSimple->getID() << '\n';

    // We allocated pSimple dynamically, so we have to delete it.
    delete pSimple;

    return 0;
} // simple goes out of scope here

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **RAII (Resource Acquisition Is Initialization)** | Object lifetime manages resource lifetime |
| 2 | **Destructors** | `~Simple()` called automatically at end of scope |
| 3 | **Stack vs Heap allocation** | `Simple simple{1}` vs `new Simple{2}` |
| 4 | **Manual memory management** | `delete pSimple` required for heap objects |
| 5 | **Member initializer list** | `: m_nID{ nID }` |

### 🔄 Alternatives & Modern C++ Idioms:
- **Use `std::unique_ptr`** instead of raw `new`/`delete` — guarantees cleanup even on exceptions
- **Rule of Zero**: If your class doesn't manage a resource, don't write destructor/copy/move
- In modern C++, prefer stack allocation or smart pointers; raw `new` is almost never needed

### 🏭 Real-World Usage:
- RAII is the backbone of C++ resource management: file handles (`std::fstream`), locks (`std::lock_guard`), smart pointers
- Destructors ensure deterministic cleanup — critical for embedded, OS, and systems programming

### ⚡ Quick Revision:
- Destructor is called automatically when stack objects go out of scope
- Heap objects require explicit `delete` (or use smart pointers)
- RAII = tie resource lifetime to object lifetime
- One destructor per class, no params, no return type
*/