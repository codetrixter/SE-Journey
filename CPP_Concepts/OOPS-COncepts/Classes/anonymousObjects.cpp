/**
 * @file anonymousObjects.cpp
 * @author Abhishek
 * @brief Here we discuss the use of anonymous objects:
 * 1- These anonymous objects are primarily used to pass or return values without having to create a lot of temporary variables.
 * 2- These can be only used once, in order to increase their life time keep them in lvalue references.
 * @version 0.1
 * @date 2022-06-11
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
    Cents(int cents): m_cents{cents}
    {}

    int getCents() const
    {
        return m_cents;
    }
};

Cents add(const Cents& c1, const Cents& c2)
{
    return c1.getCents() + c2.getCents();   //returns Cents object anonymously
}

int main(int argc, char const *argv[])
{
    //passed anonymous Cents objects and printed anonymously as well.
    std::cout << "I have " << add(Cents{6}, Cents{8}).getCents() << " cents. \n";
    return 0;
}
