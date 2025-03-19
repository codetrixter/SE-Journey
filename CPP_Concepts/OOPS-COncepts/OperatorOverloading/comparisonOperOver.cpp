/**
 * @file comparisonOperOver.cpp
 * @author Abhishek
 * @brief Here we discuss about the comparison operator overloading scenarios:
 * 1- Overlaoding equals and not equal operators(== & != ).
 * 2- Overloading all comparison operators.
 * 3- Optimizing overlaoding operators functions.
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <string_view>

//**********************Point-1***
/* class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(std::string_view make, std::string_view model)
        : m_make{ make }, m_model{ model }
    {
    }

    friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator!= (const Car& c1, const Car& c2);
};

bool operator== (const Car& c1, const Car& c2)
{
    return (c1.m_make == c2.m_make &&
            c1.m_model == c2.m_model);
}

bool operator!= (const Car& c1, const Car& c2)
{
    return (c1.m_make != c2.m_make ||
            c1.m_model != c2.m_model);
}

int main()
{
    Car corolla{ "Toyota", "Corolla" };
    Car camry{ "Toyota", "Corolla" };

    if (corolla == camry)
        std::cout << "a Corolla and Camry are the same.\n";

    if (corolla != camry)
        std::cout << "a Corolla and Camry are not the same.\n";

    return 0;
} */
//**********************Point-1***
//**********************Point-2***
/* class Cents
{
private:
    int m_cents;

public:
    Cents(int cents)
	: m_cents{ cents }
	{}

    friend bool operator== (const Cents& c1, const Cents& c2);
    friend bool operator!= (const Cents& c1, const Cents& c2);

    friend bool operator< (const Cents& c1, const Cents& c2);
    friend bool operator> (const Cents& c1, const Cents& c2);

    friend bool operator<= (const Cents& c1, const Cents& c2);
    friend bool operator>= (const Cents& c1, const Cents& c2);
};
bool operator== (const Cents& c1, const Cents& c2)
{
    return (c1.m_cents == c2.m_cents);
}
bool operator!= (const Cents& c1, const Cents& c2)
{
    return (c1.m_cents != c2.m_cents);
}
bool operator< (const Cents& c1, const Cents& c2)
{
    return (c1.m_cents < c2.m_cents);
}
bool operator> (const Cents& c1, const Cents& c2)
{
    return (c1.m_cents > c2.m_cents);
}
bool operator<= (const Cents& c1, const Cents& c2)
{
    return (c1.m_cents <= c2.m_cents);
}
bool operator>= (const Cents& c1, const Cents& c2)
{
    return (c1.m_cents >= c2.m_cents);
}
int main(int argc, char const *argv[])
{
    Cents dime{ 10 };
    Cents nickel{ 5 };

    if (nickel > dime)
        std::cout << "a nickel is greater than a dime.\n";
    if (nickel >= dime)
        std::cout << "a nickel is greater than or equal to a dime.\n";
    if (nickel < dime)
        std::cout << "a dime is greater than a nickel.\n";
    if (nickel <= dime)
        std::cout << "a dime is greater than or equal to a nickel.\n";
    if (nickel == dime)
        std::cout << "a dime is equal to a nickel.\n";
    if (nickel != dime)
        std::cout << "a dime is not equal to a nickel.\n";

    return 0;
} */
//**********************Point-2***
//**********************Point-3***
/* class Cents
{
private:
    int m_cents;

public:
    Cents(int cents)
	: m_cents{ cents }
	{}

    friend bool operator== (const Cents& c1, const Cents& c2);
    friend bool operator!= (const Cents& c1, const Cents& c2);

    friend bool operator< (const Cents& c1, const Cents& c2);
    friend bool operator> (const Cents& c1, const Cents& c2);

    friend bool operator<= (const Cents& c1, const Cents& c2);
    friend bool operator>= (const Cents& c1, const Cents& c2);
};
bool operator== (const Cents& c1, const Cents& c2)
{
    return (c1.m_cents == c2.m_cents);
}
bool operator!= (const Cents& c1, const Cents& c2)
{
    return !(c1 == c2);
}
bool operator< (const Cents& c1, const Cents& c2)
{
    return (c1.m_cents < c2.m_cents);
}
bool operator> (const Cents& c1, const Cents& c2)
{
    return (c2 < c1);
}
bool operator<= (const Cents& c1, const Cents& c2)
{
    return !(c1 > c2);
}
bool operator>= (const Cents& c1, const Cents& c2)
{
    return !(c1 < c2);
}
int main(int argc, char const *argv[])
{
    Cents dime{ 10 };
    Cents nickel{ 5 };

    if (nickel > dime)
        std::cout << "a nickel is greater than a dime.\n";
    if (nickel >= dime)
        std::cout << "a nickel is greater than or equal to a dime.\n";
    if (nickel < dime)
        std::cout << "a dime is greater than a nickel.\n";
    if (nickel <= dime)
        std::cout << "a dime is greater than or equal to a nickel.\n";
    if (nickel == dime)
        std::cout << "a dime is equal to a nickel.\n";
    if (nickel != dime)
        std::cout << "a dime is not equal to a nickel.\n";

    return 0;
} */
//**********************Point-3***
//**********************QUIZ***
#include <numeric> // for std::gcd

/* class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
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

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
    
    //comparison operators
    friend bool operator== (const Fraction& f1, const Fraction& f2);
    friend bool operator!= (const Fraction& f1, const Fraction& f2);
    friend bool operator< (const Fraction& f1, const Fraction& f2);
    friend bool operator> (const Fraction& f1, const Fraction& f2);
    friend bool operator<= (const Fraction& f1, const Fraction& f2);
    friend bool operator>= (const Fraction& f1, const Fraction& f2);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

bool operator== (const Fraction& f1, const Fraction& f2)
{
    return ((f1.m_numerator == f2.m_numerator) && (f1.m_denominator == f2.m_denominator));
}
bool operator!= (const Fraction& f1, const Fraction& f2)
{
    return !(f1 == f2);
}
bool operator< (const Fraction& f1, const Fraction& f2)
{
    return ((f1.m_numerator * f2.m_denominator) < (f2.m_numerator * f1.m_denominator));
}
bool operator> (const Fraction& f1, const Fraction& f2)
{
    return (f2 < f1);
}
bool operator<= (const Fraction& f1, const Fraction& f2)
{
    return !(f1 > f2);
}
bool operator>= (const Fraction& f1, const Fraction& f2)
{
    return !(f1 < f2);
}

int main()
{
	Fraction f1{ 3, 2 };
	Fraction f2{ 5, 8 };

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
	return 0;
} */
//**********************QUIZ***
//**********************QUIZ***
#include <algorithm>
#include <vector>
class Car
{
private:
    std::string m_make;
    std::string m_model;

public:
    Car(std::string_view make, std::string_view model)
        : m_make{ make }, m_model{ model }
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Car& c2);
    friend bool operator< (const Car& c1, const Car& c2);

};

std::ostream& operator<< (std::ostream& out, const Car& c2)
{
    return out << "(" << c2.m_make << ", " << c2.m_model << ")";
}

bool operator< (const Car& c1, const Car& c2)
{
    if(c1.m_make == c2.m_make)
        return c1.m_model < c2.m_model;
    else
        return c1.m_make < c2.m_make;
    
}
int main()
{
  std::vector<Car> cars{
    { "Toyota", "Corolla" },
    { "Honda", "Accord" },
    { "Toyota", "Camry" },
    { "Honda", "Civic" }
  };

  std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

  for (const auto& car : cars)
    std::cout << car << '\n'; // requires an overloaded operator<<

  return 0;
}
//**********************QUIZ***