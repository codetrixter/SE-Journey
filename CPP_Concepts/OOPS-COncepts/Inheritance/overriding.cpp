/**
 * @file overriding.cpp
 * @author Abhishek
 * @brief Here we see how can we override the functionalities of base class when using them in the derived class.
 * 
 * Imp point -> When we inherit the members of the base class, we do not inherit the access 
 * specifiers of the base class.
 * 
 * Imp point -> When using friend functions inside base class, we cannot call that friend function using
 * Base class scope, we have to use casting.
 * @version 0.1
 * @date 2022-06-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

/* class Base
{
    public:
    Base()
    {}

    void identify()
    {
        std::cout << "This is base class" << std::endl;
    }
};

class Derived: public Base
{
    public:
    Derived(): Base{}
    {}

    /// overriden method that is extending the functionality of the identify method of the base class.
    void identify()
    {
        /// we can also call base class method to do that first and then this .
        Base::identify();
        std::cout << "This is derived class" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Base b;
    b.identify();

    Derived d;
    d.identify();
    return 0;
} */

//*****************Access specifiers are not inherted***
/* class Base
{
private:
	void print() const
	{
		std::cout << "Base";
	}
};

class Derived : public Base
{
public:
	void print() const
	{
		std::cout << "Derived ";
	}
};

int main()
{
	Derived derived;
	derived.print(); // calls derived::print(), which is public
	return 0;
} */
//*****************Access specifiers are not inherted***

class Base
{
private:
	int m_value {};

public:
	Base(int value)
		: m_value{ value }
	{
	}

	friend std::ostream& operator<< (std::ostream& out, const Base& b)
	{
		out << "In Base\n";
		out << b.m_value << '\n';
		return out;
	}
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	friend std::ostream& operator<< (std::ostream& out, const Derived& d)
	{
		out << "In Derived\n";
		/// static_cast Derived to a Base object, so we call the right version of operator<<
		out << static_cast<const Base&>(d);
		return out;
	}
};

int main()
{
	Derived derived { 7 };

	std::cout << derived << '\n';

	return 0;
}

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Function hiding/overriding** | Derived `identify()` hides Base version |
| 2 | **Calling base version explicitly** | `Base::identify()` inside derived |
| 3 | **Access specifiers not inherited** | Private `print()` in Base, public in Derived — OK |
| 4 | **Friend functions with inheritance** | `operator<<` uses `static_cast<const Base&>(d)` |

### 🔄 Alternatives & Modern C++ Idioms:
- Use `virtual` + `override` for runtime polymorphism (not just hiding)
- Without `virtual`, this is name hiding — not true polymorphism
- NVI (Non-Virtual Interface) pattern for controlled extension points

### 🏭 Real-World Usage:
- Extending logging/tracing in derived classes while preserving base behavior
- `operator<<` chaining through hierarchy via static_cast to base
- Name hiding is a common source of bugs — use `override` to catch mistakes

### ⚡ Quick Revision:
- Without `virtual`: derived function HIDES base (no polymorphism)
- `Base::func()` explicitly calls base version from derived
- Access specifiers in derived are independent of base
- Friend functions need `static_cast` to call base version (can't use scope resolution)
*/