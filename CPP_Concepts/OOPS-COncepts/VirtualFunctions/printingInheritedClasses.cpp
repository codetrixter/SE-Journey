/**
 * Here we are going to learn how to overload "<<"" using inherited classes.
 * 
 * 
 */

//------------------overloading "<<" operator for base and derived classes-----------

#include <iostream>

/* class Base
{
public:
	virtual void print() const { std::cout << "Base"; }

	friend std::ostream& operator<<(std::ostream& out, const Base& b)
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	void print() const override { std::cout << "Derived"; }

	friend std::ostream& operator<<(std::ostream& out, const Derived& d)
	{
		out << "Derived";
		return out;
	}
};

int main()
{
	Base b{};
	std::cout << b << '\n';

	Derived d{};
	std::cout << d << '\n';

    /// This creates a problem here since base class operator is called which is not virtual hence prints Base
    /// this can be tackeld by calling a virtual function from withing the base classes operator overloaded function like below.
    Base& bb = d;
    std::cout << bb << "\n";
	return 0;
} */

//------------------virtual func called from with operator overloaded function of base class.------------

class Base
{
public:
	// Here's our overloaded operator<<
	friend std::ostream& operator<<(std::ostream& out, const Base& b)
	{
		// Delegate printing responsibility for printing to virtual member function print()
		return b.print(out);
	}

	// We'll rely on member function print() to do the actual printing
	// Because print() is a normal member function, it can be virtualized
	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

// Some class or struct with an overloaded operator<<
struct Employee
{
	std::string name{};
	int id{};

	friend std::ostream& operator<<(std::ostream& out, const Employee& e)
	{
		out << "Employee(" << e.name << ", " << e.id << ")";
		return out;
	}
};

class Derived : public Base
{
private:
	Employee m_e{}; // Derived now has an Employee member

public:
	Derived(const Employee& e)
		: m_e{ e }
	{
	}

	// Here's our override print() function to handle the Derived case
	std::ostream& print(std::ostream& out) const override
	{
		out << "Derived: ";

		// Print the Employee member using the stream object
		out << m_e;

		return out;
	}
};

int main()
{
	Base b{};
	std::cout << b << '\n';

	Derived d{ Employee{"Jim", 4}};
	std::cout << d << '\n'; // note that this works even with no operator<< that explicitly handles Derived objects

    // It works inthis way:
    // d is upcasted to base type and base's operator overload is called, the that in turn calls virtual print(), which 
    // in turn handles the object type based on class heirarchy.
	Base& bref{ d };
	std::cout << bref << '\n';

	return 0;
}