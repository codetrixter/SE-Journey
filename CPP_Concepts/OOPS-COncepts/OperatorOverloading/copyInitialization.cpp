/**
 * @file copyInitialization.cpp
 * @author Abhishek
 * @brief Here we discuss te copy initializations:
 * 1- int x= 5; -> this is copy init for fundamental types.
 * 2- Avoid using copy initialization and use uniform initialization.
 * 3- copy initialization is used when you pass or return class by value.
 * @version 0.1
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <cassert>
#include <iostream>

/* class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    /// Default constructor
    Fraction(int numerator=0, int denominator=1)
        : m_numerator(numerator), m_denominator(denominator)
    {
        assert(denominator != 0);
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

int main(int argc, char const *argv[])
{
    /// This uses copy initialization in a similar way as it is used in below condition, where elision happens.
    Fraction six = Fraction(6);
    /// Fraction six(Fraction(6));
    std::cout << six;
    return 0;
} */
//***********************Point-3***
/* class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
    /// Default constructor
    Fraction(int numerator=0, int denominator=1)
        : m_numerator(numerator), m_denominator(denominator)
    {
        assert(denominator != 0);
    }

        /// Copy constructor
	Fraction(const Fraction& copy) :
		m_numerator(copy.m_numerator), m_denominator(copy.m_denominator)
	{
		/// no need to check for a denominator of 0 here since copy must already be a valid Fraction
		std::cout << "Copy constructor called\n"; // just to prove it works
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
	int getNumerator() { return m_numerator; }
	void setNumerator(int numerator) { m_numerator = numerator; }
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

Fraction makeNegative(Fraction f) // ideally we should do this by const reference
{
    f.setNumerator(-f.getNumerator());
    return f;   //copy ctor is called here again
}

int main()
{
    Fraction fiveThirds(5, 3);
    std::cout << makeNegative(fiveThirds);  //copy ctor is called here

    return 0;
} */
//***********************Point-3***
//***********************Point-3 with elision***
class Something
{
public:
	Something()
    {
        std::cout << "Default ctor called...";
    }
	Something(const Something&)
	{
		std::cout << "Copy constructor called\n";
	}
};

Something foo()
{
	return Something(); // copy constructor normally called here, while returning the copy of Something
}
Something goo()
{
	Something s;
	return s; // copy constructor normally called here
}
/// 
/// @brief Even though copy constructor is called here at 4 places but all those are elised
/// 
/// @return int error code
/// 

int main()
{
	std::cout << "Initializing s1\n";
	Something s1 = foo(); // copy constructor normally called here

	std::cout << "Initializing s2\n";
	Something s2 = goo(); // copy constructor normally called here
}
//***********************Point-3 with elision***

