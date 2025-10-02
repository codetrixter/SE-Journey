/**
 * @file accessSpecifiersInInheritance.cpp
 * @author Abhishek
 * @brief 
 * - The protected members of a base class can only be inherited and used by classes of the same inheritance hierarchy.
 * 
 * - Access specifier in base class	    Access specifier when inherited publicly	Access specifier when inherited privately	Access specifier when inherited protectedly
        Public	                         Public	                                        Private	                                    Protected
        Protected	                     Protected	                                    Private	                                    Protected
        Private	                         Inaccessible	                                Inaccessible	                            Inaccessible
 * @version 0.1
 * @date 2022-06-14
 * 
 * @copyright Copyright (c) 2022
 */

#include <iostream>
//*************Private Inheritance***
class Base
{
    private:
    int m_private {};

    public:
    int m_public {};

    protected:
    int m_protected {};
};

class Derived: private Base
{
    private:
    int m_private_derived;

    public:
    int m_public_derived;

    int get()
    {
        m_protected = 20;
        return m_protected;
    }

    protected:
    int m_protected_derived;
};

int main(int argc, char const *argv[])
{
    Derived d;
    /// d.m_public = 10;        //inaccessible withing this context
    d.get();                //protected is alos not accessible, hence has to accessed via member function.
    return 0;
}
//*************Private Inheritance***
