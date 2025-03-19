/**
 * @file orderOfInstantiation.cpp
 * @author Abhishek
 * @brief here we define the order in which the classes gets instantiated if they are inheriting 
 * from bases classes.
 * - The classes get instantiated from base to derived.
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "Instantiating A\n";
    }
};

class B: public A
{
public:
    B()
    {
        std::cout << "Instantiating B\n";
    }
};

class C: public B
{
public:
    C()
    {
        std::cout << "Instantiating C\n";
    }
};

class D: public C
{
public:
    D()
    {
        std::cout << "Instantiating D\n";
    }
};

int main(int argc, char const *argv[])
{
    //A a();  //what happens in this cases as nothing is printed.
    A a;
    B b;
    C c;
    D d;
    return 0;
}
