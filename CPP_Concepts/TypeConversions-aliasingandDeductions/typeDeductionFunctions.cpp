/**
 * @file typeDeductionFunctions.cpp
 * @author Abhishek
 * @brief Here we discuss about the use of auto keyword for return type deductions:
 * 1- Since C++14 auto is allowed for return type deductions.
 * 2- All return values should be of same type or else the compiler will give error.
 * 3- functions must be fully defined in order for type deduction to work.
 * 4- Trailing return type syntax is something that can be achieved using auto.
 * @version 0.1
 * @date 2022-07-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
//auto fun(); //error: use of ‘auto fun()’ before deduction of ‘auto’

/* auto functionOne(bool b)
{
    if(b)
        return 5;
    else
        return 10;
        //return 10.0;    //error: inconsistent deduction for auto return type: ‘int’ and then ‘double
} */

//New way of defining function using auto keyword -> also known as Trailing return syntax.
auto functionOne(bool b)->int
{
    return 25;
}
int main(int argc, char const *argv[])
{
    std::cout << functionOne(true);
    //std::cout << fun();
    return 0;

    //****Tyoe deduction cant be used for function parameter types */
    {
        //void func(auto a); //error: ‘auto’ not allowed in function prototype, allowed in C++20 using templates
        //void func1(int a, auto b); //error: ‘auto’ not allowed in function prototype
    }
}
