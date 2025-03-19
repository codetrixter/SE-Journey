/**
 * @file overloadingInputOutput.cpp
 * @author Abhishek
 * @brief Here we discuss about overloading stream operators:
 * 1- Overloading ostream "<<" operator:
 * 2- Overloading istream ">>"operator: 
 * ***Overloading input and output operators makes it really easy for the user defined classes to output their data
 * to the console or file.
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <numeric>
#include <limits>
//********************operator overloading of istream and ostream***
/* class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x=0.0, double y=0.0, double z=0.0)
      : m_x{x}, m_y{y}, m_z{z}
    {
    }

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }

    friend std::ostream& operator<<(std::ostream& out, const Point& p);
    friend std::istream& operator>>(std::istream& in, Point& p);
};

std::ostream& operator<<(std::ostream& out, const Point& p)
{
    // return std::ostream so we can chain calls to operator<<
    return (out << "Point(" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")");
}

std::istream& operator>>(std::istream& in, Point& p)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    return in >> p.m_x >> p.m_y >> p.m_z;
}

int main(int argc, char const *argv[])
{
    // Point p1{ 10, 20, 30 };
    Point p1{};
    Point p2{ 40, 50, 60 };

    std::cout << "Enter the Points :" << std::endl;
    std::cin >> p1;
    //
    // @brief By returning the out parameter as the return type instead, (std::cout<< p1) returns std::cout. 
    // Then our partially evaluated expression becomes: std::cout << p2; which becomes: std::cout << std::endl; 
    // which then gets evaluated itself!
    //
    
    std::cout << p1 << " " << p2 << std::endl;
    return 0;
} */
//********************operator overloading of istream and ostream***
//********************QUIZ***
class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction(int numerator=0, int denominator=1):
		m_numerator{numerator}, m_denominator{denominator}
	{
		// We put reduce() in the constructor to ensure any new fractions we make get reduced!
		// Any fractions that are overwritten will need to be re-reduced
		reduce();
	}

	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator) };
		if (gcd)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}

	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, int value);
	friend Fraction operator*(int value, const Fraction& f1);
    //overloading i/o operators
    friend std::istream& operator>>(std::istream& in, Fraction& frac);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);

	void print() const
	{
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(const Fraction& f1, int value)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}

Fraction operator*(int value, const Fraction& f1)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}

std::istream& operator>>(std::istream& in, Fraction& frac)
{
    char ch{};
    in >> frac.m_numerator;

    // Ignore the '/' separator, how is this done need to check
	//in.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    //alternative to above this is easy to follow.
    in >> ch;

    in >> frac.m_denominator;

    //simplifying the fractions ater overwriting the values
    frac.reduce();
    return  in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& frac)
{
    return out << frac.m_numerator << "/" << frac.m_denominator;
}

int main()
{
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

	return 0;
}
//********************QUIZ***