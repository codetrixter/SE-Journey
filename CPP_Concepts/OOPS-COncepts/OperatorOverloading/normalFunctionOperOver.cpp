/**
 * @file normalFunctionOperOver.cpp
 * @author Abhishek
 * @brief Here we discuss about how to overload operator without using fried functions.
 * ***normal functions should be preferred instead of friend functions if it's possible to do so without
 * adding functions to the class.
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

class Cents
{
    private:
    int m_cents{};

    public:
    Cents(int val): m_cents{val}
    {}

    int getCents() const
    {
        return m_cents;
    }
};

//// Need to explicitly provide prototype for operator+ so uses of operator+ in other files know 
//this overload exists
//Cents operator+(const Cents& lhs, const Cents& rhs);

Cents operator+(const Cents& lhs, const Cents& rhs)
{
    // use the Cents constructor and operator+(int, int)
    // we don't need direct access to private members here
    return Cents{ lhs.getCents() + rhs.getCents() };
}

int main(int argc, char const *argv[])
{
    Cents someChange{10};
    Cents otherChange{20};
    Cents extraChange{ someChange + otherChange };

    std::cout << extraChange.getCents();
    return 0;
}
