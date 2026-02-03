/**
 * @file rethrowExceptions.cpp
 * @author Abhishek
 * @brief Here we discuss about rethrowing exceptions:
 * 1- This is used when, you may run into a case where you want to catch an exception, but not want to (or have the ability to) fully handle 
 * it at the point where you catch it.
 * 2- When rethrowing the same exceptions, use the throw keyword by itself.
 * @version 0.1
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
class Base
{
public:
    Base() {}
    virtual void print() { std::cout << "Base"; }
};

class Derived: public Base
{
public:
    Derived() {}
    void print() override { std::cout << "Derived"; }
};

int main()
{
    try
    {
        try
        {
            throw Derived{};
        }
        catch (Base& b)
        {
            std::cout << "Caught Base b, which is actually a ";
            b.print();
            std::cout << '\n';
            //throw b;  this is an incorrect way of throwing exception since the object gets sliced here, since b is now copy-initialized from derived exception.
            throw; // note: We're now rethrowing the object here
        }
    }
    catch (Base& b)
    {
        std::cout << "Caught Base b, which is actually a ";
        b.print();
        std::cout << '\n';
    }

    return 0;
}