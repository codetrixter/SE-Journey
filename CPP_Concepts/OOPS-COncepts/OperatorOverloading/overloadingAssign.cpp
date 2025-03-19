/**
 * @file overloadingAssign.cpp
 * @author Abhishek
 * @brief Here we discuss about the assignment operator overloading:
 * 1- assignment overloads are used to assign existing object to another object.
 * 2- self assignments, and how to avoid them.
 * 3- copy and swap idiom -> check : https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
 * @version 0.1
 * @date 2022-08-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <cassert>
#include <iostream>
//***********************assignment overload***
/* class Fraction
{
private:
	int m_numerator { 0 };
	int m_denominator { 1 };

public:
	// Default constructor
	Fraction(int numerator = 0, int denominator = 1 )
		: m_numerator { numerator }, m_denominator { denominator }
	{
		assert(denominator != 0);
	}

	// Copy constructor
	Fraction(const Fraction& copy)
		: m_numerator { copy.m_numerator }, m_denominator { copy.m_denominator }
	{
		// no need to check for a denominator of 0 here since copy must already be a valid Fraction
		std::cout << "Copy constructor called\n"; // just to prove it works
	}

	// Overloaded assignment
	Fraction& operator= (const Fraction& fraction);

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);

};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

// A simplistic implementation of operator= (see better implementation below)
Fraction& Fraction::operator= (const Fraction& fraction)
{
    // do the copy
    m_numerator = fraction.m_numerator;
    m_denominator = fraction.m_denominator;

    // return the existing object so we can chain this operator
    return *this;
}

int main(int argc, char const *argv[])
{
    Fraction f1{5, 3};
    Fraction f2{7, 2};
    Fraction f3{9, 5};

    f1 = f2 = f3; //chain assignmenets can be done sicne the overloaded function return this.
    return 0;
} */
//***********************assignment overload***
//***********************self assignments***
class MyString
{
private:
	char* m_data {};
	int m_length {};

public:
	MyString(const char* data = nullptr, int length = 0 )
		: m_length { length }
	{
		if (length)
		{
			m_data = new char[length];

			for (int i { 0 }; i < length; ++i)
				m_data[i] = data[i];
		}
	}
	~MyString()
	{
		delete[] m_data;
	}

	// Overloaded assignment
	MyString& operator= (const MyString& str);

	friend std::ostream& operator<<(std::ostream& out, const MyString& s);
};

std::ostream& operator<<(std::ostream& out, const MyString& s)
{
	out << s.m_data;
	return out;
}

// A simplistic implementation of operator= (do not use)
/* MyString& MyString::operator= (const MyString& str)
{
	// if data exists in the current string, delete it
	if (m_data) delete[] m_data;

	m_length = str.m_length;

	// copy the data from str to the implicit object
	m_data = new char[str.m_length];

	for (int i { 0 }; i < str.m_length; ++i)
		m_data[i] = str.m_data[i];

	// return the existing object so we can chain this operator
	return *this;
} */

// assignment overloading handling self assignments
MyString& MyString::operator= (const MyString& str)
{
	// avoiding self assignments
	if (&str == this)
        return *this;

    // if data exists in the current string, delete it
    if (m_data) delete[] m_data;
	m_length = str.m_length;

	// copy the data from str to the implicit object
	m_data = new char[str.m_length];

	for (int i { 0 }; i < str.m_length; ++i)
		m_data[i] = str.m_data[i];

	// return the existing object so we can chain this operator
	return *this;
}

int main()
{
	MyString alex("Alex", 5); // Meet Alex
	MyString employee;
    //employee = alex;    // Alex is our newest employee
	alex = alex;    //self assignment, undefined behavviour
	std::cout << alex; // Say your name, employee

	return 0;
}
//***********************self assignments***
