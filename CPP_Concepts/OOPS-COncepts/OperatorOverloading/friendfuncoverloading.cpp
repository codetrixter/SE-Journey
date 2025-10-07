/**
 * @file friendfuncoverloading.cpp
 * @author Abhishek
 * @brief Here we discuss about the friend function way of overloading operators:
 * 1- Overlaoding arithmetic operators to work with user defned types.
 * 1- Overloading operators of diferent types:
 *  a. In this case we generally need to write two versions of the operator overloaded function.
 *      I. One with operator(user-defined, fundamental)
 *      II. Other with operator(fundamental, user-defined)
 * @version 0.1
 * @date 2022-08-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
//**************************Overloading Arithmetic operators***
/* class Cents
{
    private:
    int m_cents{};

    public:
    Cents(int val): m_cents{val}
    {}

    friend Cents operator+(const Cents& lhsVal, const Cents& rhsVal);
    int getCents()
    {
        return m_cents;
    }
};

/// note: this function is not a member function!
Cents operator+(const Cents& lhsVal, const Cents& rhsVal)
{
    /// use the Cents constructor and operator+(int, int)
	/// we can access m_cents directly because this is a friend function
    return Cents{ lhsVal.m_cents + rhsVal.m_cents };
}

int main(int argc, char const *argv[])
{
    Cents someChange{10};
    Cents otherChange{20};
    Cents extraChange{ someChange + otherChange };

    std::cout << extraChange.getCents();
    return 0;
} */
//**************************Overloading Arithmetic operators***
//**************************point-2***
/* class Cents
{
    private:
    int m_cents{};

    public:
    Cents(int val): m_cents{val}
    {}

    friend Cents operator+(const Cents& lhsVal, const int rhsVal);
    friend Cents operator+(const int lhsVal, const Cents& rhsVal);

    int getCents()
    {
        return m_cents;
    }
};

/// note: this function is not a member function!
Cents operator+(const Cents& lhsVal, const int rhsVal)
{
    /// use the Cents constructor and operator+(int, int)
	/// we can access m_cents directly because this is a friend function
    return Cents{ lhsVal.m_cents + rhsVal };
}

Cents operator+(const int lhsVal, const Cents& rhsVal)
{
    /// use the Cents constructor and operator+(int, int)
	/// we can access m_cents directly because this is a friend function
    return Cents{ lhsVal + rhsVal.m_cents };
}

int main(int argc, char const *argv[])
{
    Cents someChange{10};
    Cents otherChange{20};
    Cents extraChange{ someChange + 300 };
    Cents extra2Change{ 400 + someChange };

    std::cout << extraChange.getCents();
    std::cout << extra2Change.getCents();
    return 0;
} */
//--------------------Alternate example--------------
/* class MinMax
{
private:
	int m_min {}; // The min value seen so far
	int m_max {}; // The max value seen so far

public:
	MinMax(int min, int max)
		: m_min { min }, m_max { max }
	{ }

	int getMin() const { return m_min; }
	int getMax() const { return m_max; }

	friend MinMax operator+(const MinMax& m1, const MinMax& m2);
	friend MinMax operator+(const MinMax& m, int value);
	friend MinMax operator+(int value, const MinMax& m);
};

MinMax operator+(const MinMax& m1, const MinMax& m2)
{
    int min{ m1.m_min < m2.m_min? m1.m_min : m2.m_min };
    int max{ m1.m_max > m2.m_max? m1.m_max : m2.m_max };

    return { min, max };
}

MinMax operator+(const MinMax& m, int value)
{
    int min{ m.m_min < value? m.m_min : value };
    int max{ m.m_max > value? m.m_max : value };
    
    return { min, max };
}

MinMax operator+(int value, const MinMax& m)
{   
    /// call operator+(MinMax, int)
    return { m + value };
}

int main()
{
	MinMax m1{ 10, 15 };
	MinMax m2{ 8, 11 };
	MinMax m3{ 3, 12 };

	MinMax mFinal{ m1 + m2 + 5 + 8 + m3 + 16 };

	std::cout << "Result: (" << mFinal.getMin() << ", " <<
		mFinal.getMax() << ")\n";

	return 0;
} */
//**************************point-2***
//**************************QUIZ-1***
/* class Fraction
{
    private:
    int numerator{};
    int denominator{};

    public:
    Fraction(int num, int denom): numerator{num}, denominator{denom}
    {}

    void print()
    {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    /// friend Fraction operator/(const int& lhs, const int& rhs)
    /// {
    ///     return Fraction{ lhs, rhs };
    /// }
};
int main()
{
    Fraction f1{ 1, 4 };
    f1.print();

    Fraction f2{ 1, 2 };
    f2.print();

    return 0;
} */
//**************************QUIZ-1***
//**************************QUIZ-2***
#include <numeric>  //for std::gcd
 class Fraction
{
    private:
    int numerator{ 0 };
    int denominator{ 1 };

    public:
    Fraction(int num, int denom = 1): numerator{num}, denominator{denom}
    {}

    void print()
    {
        reduce();
        std::cout << numerator << "/" << denominator << std::endl;
    }

    friend Fraction operator*( const Fraction& lhs, const Fraction& rhs)
    {
        int num{ lhs.numerator*rhs.numerator };
        int den{ lhs.denominator*rhs.denominator };
        return { num, den };
    }

    friend Fraction operator*(const Fraction& lhs, const int& rhs)
    {
        int num{ lhs.numerator*rhs };
        return { num, lhs.denominator };
    }

    friend Fraction operator*(const int& lhs, const Fraction& rhs)
    {
        return {rhs*lhs};
    }

    void reduce()
	{
		int gcd{ std::gcd(numerator, denominator) };
		if (gcd)
		{
			numerator /= gcd;
			denominator /= gcd;
		}
	}
};
int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();
    
    /// @brief This error will come if we remove the const references from operator overloaded functions
    /// error: cannot bind non-const lvalue reference of type ‘Fraction&’ to an rvalue of type ‘Fraction’
    /// Fraction f4{ f1 * 2 };
     
    Fraction f4{ f1 * 2 };
    f4.print();

    /// @brief This works even after commenting the specific operator overloaded function.
    /// because f5{ 2 * f2 } uses Fraction(int, int) constructor to created new Fraction object and then uses it to 
    /// calculate the multiplication with f2. Since this requires an extra conversion hence it is slower.

    Fraction f5{ 2 * f2 };
    f5.print();

    /// @brief This line wont compile if we dont use const version of the operator overloading, since we are passing 
    /// temporary fraction objects and non-cont references cannot bind to temporaries
    /// error: cannot bind non-const lvalue reference of type ‘Fraction&’ to an rvalue of type ‘Fraction’

    /// Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
     
    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}
//**************************QUIZ-2***