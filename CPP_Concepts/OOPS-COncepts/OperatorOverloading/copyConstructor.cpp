/**
 * @file copyConstructor.cpp
 * @author Abhishek
 * @brief Here we see the uses of copy constructor:
 * 1- Copy constructor creates a copy of the already created object.
 * 2- It can be made private to prevent copy inititialization.
 * 3- It may be elided.
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <cassert>
#include <iostream>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1)
        : m_numerator{numerator}, m_denominator{denominator}
    {
        assert(denominator != 0);
    }
    /// This is also called Shallow copy 
    /// Copy constructor with member wise initialization
    /// Here we need to pass the parameter as reference, since passing by value would require a copy constructor to copy the variable
    /// in the function parameter, hence will lead to infinite recursion.
    Fraction(const Fraction& fraction)
        : m_numerator{fraction.m_numerator}, m_denominator{fraction.m_denominator}
        /// Note: We can access the members of parameter fraction directly, because we're inside the Fraction class
    {
        /// no need to check for a denominator of 0 here since fraction must already be a valid Fraction
        std::cout << "Copy constructor called\n"; // just to prove it works
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

int main()
{
	/// Fraction fiveThirds { 5, 3 }; // brace initialize a Fraction, calls Fraction(int, int) constructor
	/// Fraction fCopy { fiveThirds }; // brace initialization -- with Fraction copy constructor

    //copy constructor elision

    Fraction fiveThirds { Fraction { 5, 3 }};   
    /// no copy constructor is called here since the compiler optimised this call with below statement hence no copy ctor called.
    /// So compler instead of making two calls, 1- creating anonymous object, 2- calling copy ctor, it made just the former one.
    /// Fraction fiveThirds { 5, 3 };
	std::cout << fiveThirds << '\n';
}

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Copy constructor** | `Fraction(const Fraction&)` — memberwise copy |
| 2 | **Must pass by reference** | Value param → infinite recursion |
| 3 | **Copy elision** | `Fraction f{Fraction{5,3}}` optimized to single construction |
| 4 | **Shallow copy** | Default copy = memberwise copy of values |

### 🔄 Alternatives & Modern C++ Idioms:
- `= default` for trivial copy constructors
- `= delete` to make class non-copyable
- Move constructor for efficient transfers (C++11)
- C++17 guarantees copy elision (mandatory RVO)

### ⚡ Quick Revision:
- Copy ctor param MUST be const reference (avoid infinite recursion)
- Compiler can elide copies (C++17: mandatory in certain cases)
- Shallow copy is fine for non-resource-managing classes
- Classes with pointers need deep copy (Rule of Three/Five)
*/