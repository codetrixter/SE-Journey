/**
 * @file typecastOverloading.cpp
 * @author Abhishek
 * @brief Here we see how type casts can be overloaded to support casting one user defined type to another 
 * fundamental or user defined type:
 * 
 * @version 0.1
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

//*******************Converting Cents to int***
/* class Cents
{
private:
    int m_cents;
public:
    Cents(int cents=0)
        : m_cents{ cents }
    {
    }

    /// Overloaded int cast
    operator int() const { return m_cents; }

    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }
};
void printInt(int cents) { std::cout << cents; }
int main()
{
    Cents cents{ 7 };
    printInt(cents); // print 7, converts cents to int using overloaded function

    std::cout << '\n';

    return 0;
} */
//*******************Converting Cents to int***
//*******************Converting Dollars to Cents***
class Cents
{
private:
    double m_cents;
public:
    Cents(double cents=0)
        : m_cents{ cents }
    {
    }

    /// Overloaded double cast
    operator double() const { return m_cents; }

    double getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }
};

class Dollars
{
private:
    double m_dollars;
public:
    Dollars(double dollars=0)
        : m_dollars{ dollars }
    {
    }

    /// @brief  allows us to covert cents to dollars
    /// @param cent 
    explicit Dollars(const Cents& cent):
    m_dollars { cent.getCents()/100 }
    {}

    operator double() const
    {
        return m_dollars;
    }

    /// Allow us to convert Dollars into Cents
    explicit operator Cents() const { return Cents { m_dollars * 100 }; }
};

void printCents(Cents cents)
{
    std::cout << cents; // cents will be implicitly cast to an int here
}

int main()
{
    Dollars dollars{ 9 };
    Cents cent{ 25 };
    /// printCents(dollars); // could not convert dollars to Dollars, since typecast opertor is marked as explicit
    std::cout << static_cast<Cents>(dollars) << "\n";   //we can cast explicitly as well

    /// Converting Cents to Dollars
    /// we created a converting constructor in Dollars class to avoid curcular dependency od dollars into cents class
    std::cout << static_cast<Dollars>(cent) << "\n";

    return 0;
}
//*******************Converting Dollars to Cents***