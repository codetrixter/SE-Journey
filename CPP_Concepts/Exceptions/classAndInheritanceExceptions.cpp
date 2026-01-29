/**
 * @file classAndInheritanceExceptions.cpp
 * @author Abhishek
 * @brief Here we discuss about the exceptional scenarios related to following:
 * 1- member functions: Exceptions can be used to indicate error conditions that may occur during the execution of out member function.
 * 2- Inheritance: 
 * 3- User defined exceptions
 * 4- Exception can be caught of derived and base types.
 * 		NOTE: Handlers for derived exception classes should be listed before those for the base classes.
 * 5- std::exception is the base class of all the types of exceptions that c++ standard provides.
 * @version 0.1
 * @date 2022-09-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
//*************In operator overloaded subscript***
/* int& IntArray::operator[](const int index)
{
    if (index < 0 || index >= getLength())
        throw index;

    return m_data[index];
} */
//*************In operator overloaded subscript***
//***************Excetion Inheritance***
/* #include <iostream>

class Member
{
public:
	Member()
	{
		std::cerr << "Member allocated some resources\n";
	}

	~Member()
	{
		std::cerr << "Member cleaned up\n";
	}
};

class A
{
private:
	int m_x {};
	Member m_member;

public:
	A(int x) : m_x{x}
	{
		if (x <= 0)
			throw 1;    //when an exception is thown here, the destructor of already allocated Member object is called and resource is freed.
	}

	~A()
	{
		std::cerr << "~A\n"; // should not be called, since the object is never constructed properly when exception occurs.
	}
};


int main()
{
	try
	{
		A a{1};
	}
	catch (int)
	{
		std::cerr << "Oops\n";
	}

	return 0;
} */
//***************Excetion Inheritance***
//***************User defined Exceptions***
#include <iostream>
#include <string>
#include <string_view>

/* class ArrayException
{
private:
	std::string m_error;

public:
	ArrayException(std::string_view error)
		: m_error{ error }
	{
	}

	const std::string& getError() const { return m_error; }
};

class IntArray
{
private:
	int m_data[3]{}; // assume array is length 3 for simplicity

public:
	IntArray() {}

	int getLength() const { return 3; }

	int& operator[](const int index)
	{
		if (index < 0 || index >= getLength())
			throw ArrayException{ "Invalid index" };

		return m_data[index];
	}

};

int main()
{
	IntArray array;

	try
	{
		int value{ array[5] }; // out of range subscript
	}
	catch (const ArrayException& exception)
	{
		std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
	}
} */
//***************User defined Excetion***
//***************Exception with inheritance relation***
/* class Base
{
public:
    Base() {}
};

class Derived: public Base
{
public:
    Derived() {}
};

int main()
{
    try
    {
        throw Derived();
    }
    catch (const Derived& derived)
    {
        std::cerr << "caught Derived";
    }
    catch (const Base& base)
    {
        std::cerr << "caught Base";
    }

    return 0;
} */
//***************Exception with inheritance relation***
//***************std::Exception***
#include <cstddef> // for std::size_t
#include <exception> // for std::exception
#include <limits>

int main()
{
    try
    {
        // Your code using standard library goes here
        // We'll trigger one of these exceptions intentionally for the sake of the example
        std::string s;
        s.resize(std::numeric_limits<std::size_t>::max()); // will trigger a std::length_error or allocation exception
    }
	// This handler will catch std::length_error (and any exceptions derived from it) here
	catch (const std::length_error& exception)
	{
		std::cerr << "You ran out of memory!" << '\n';
	}
	// This handler will catch std::exception (and any exception derived from it) that fall
	// through here
	catch (const std::exception& exception)
	{
		std::cerr << "Standard exception: " << exception.what() << '\n';
	}

    return 0;
}
//***************std::Exception***

