/**
 * @file accessSpecifiersInInheritance.cpp
 * @author Abhishek
 * @brief 
 * - The protected members of a base class can only be inherited and used by classes of the same inheritance hierarchy.
 * 
 * - Access specifier in base class	    Access specifier when inherited publicly	Access specifier when inherited privately	Access specifier when inherited protectedly
        Public	                         Public	                                        Private	                                    Protected
        Protected	                     Protected	                                    Private	                                    Protected
        Private	                         Inaccessible	                                Inaccessible	                            Inaccessible
 * @version 0.1
 * @date 2022-06-14
 * 
 * @copyright Copyright (c) 2022
 */

#include <iostream>
//*************Private Inheritance***
class Base
{
    private:
    int m_private {};

    public:
    int m_public {};

    protected:
    int m_protected {};
};

class Derived: private Base
{
    private:
    int m_private_derived;

    public:
    int m_public_derived;

    int get()
    {
        m_protected = 20;
        return m_protected;
    }

    protected:
    int m_protected_derived;
};

int main(int argc, char const *argv[])
{
    Derived d;
    /// d.m_public = 10;        //inaccessible withing this context
    d.get();                //protected is alos not accessible, hence has to accessed via member function.
    return 0;
}
//*************Private Inheritance***

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Private inheritance** | `class Derived: private Base` — all base members become private |
| 2 | **Access specifier mapping** | Public→Private, Protected→Private under private inheritance |
| 3 | **Protected members** | Accessible in derived but not externally |
| 4 | **Inaccessibility of private base members** | `m_private` never accessible in derived |

### 🔄 Alternatives & Modern C++ Idioms:
- Private inheritance = "implemented-in-terms-of" (prefer composition instead)
- Protected inheritance is rare; public inheritance is the default for IS-A
- Use `using` declarations to selectively expose base members

### 🏭 Real-World Usage:
- Private inheritance used in EBO (Empty Base Optimization) — e.g., `std::allocator`
- Policy-based design sometimes uses private inheritance
- Generally: prefer composition over private/protected inheritance

### ⚡ Quick Revision:
- Public inheritance: IS-A | Private: implemented-in-terms-of | Protected: rare
- Private inheritance makes ALL base members private in derived
- Protected members: derived can access, outside world cannot
- Base private members are NEVER accessible in derived (regardless of inheritance type)
*/
