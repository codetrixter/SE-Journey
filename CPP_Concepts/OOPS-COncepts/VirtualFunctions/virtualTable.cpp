/**
 * @file virtualTable.cpp
 * @author Abhishek
 * @brief Here we discuss about the virtual table and what is it for:
 * In resolving the calls to virtual functions the compiler uses Virtual table. 
 * ******************VIRTUAL TABLE FOR BELOW CLASSES************************
 * link -> https://www.learncpp.com/cpp-tutorial/the-virtual-table/
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

class Base
{
public:
    virtual void function1() { std::cout << "Base function1..."; }
    virtual void function2() { std::cout << "Base function2..."; }
};

class D1: public Base
{
public:
    void function1() override { std::cout << "D1 function1..."; }
};

class D2: public Base
{
public:
    void function2() override { std::cout << "D2 function2..."; }
};
int main(int argc, char const *argv[])
{
    D1 der;
    //This has access to D1 class vptr and hence function2 in D1 vtable is pointing to base version.
    der.function2();

    Base* base{&der};
    //Here D1 vptr is used to resolve the function1 version
    base->function1();
    //base->function2();

    Base baseOnly;
    Base* b{&baseOnly};
    //here since the object is of base class, so vptr of Base is used to resolve function calls.
    b->function1();
    b->function2();

    return 0;
}
