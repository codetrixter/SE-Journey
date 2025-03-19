/**
 * @file typecastOverloading.cpp
 * @author Abhishek
 * @brief Here we see how type casts can be overloaded to support castinf one user defined type to another fundamental or user defined type:
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

    // Overloaded int cast
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
    int m_cents;
public:
    Cents(int cents=0)
        : m_cents{ cents }
    {
    }

    // Overloaded int cast
    operator int() const { return m_cents; }

    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }
};

class Dollars
{
private:
    int m_dollars;
public:
    Dollars(int dollars=0)
        : m_dollars{ dollars }
    {
    }

    // Allow us to convert Dollars into Cents
    operator Cents() const { return Cents { m_dollars * 100 }; }
};

void printCents(Cents cents)
{
    std::cout << cents; // cents will be implicitly cast to an int here
}

int main()
{
    Dollars dollars{ 9 };
    //printCents(dollars); // dollars will be implicitly cast to a Cents here
    std::cout << static_cast<Cents>(dollars);   //we can cast explicitly as well
    std::cout << '\n';

    return 0;
}
//*******************Converting Dollars to Cents***