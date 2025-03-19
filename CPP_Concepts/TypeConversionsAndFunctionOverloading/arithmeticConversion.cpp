/**
 * @file arithmeticConversion.cpp
 * @author Abhishek
 * @brief Here we discuss the the type deduction in case if there are multiple types used as part of an expression.
 * 1- These are the operators that require operands to be of same type:
    The binary arithmetic operators: +, -, *, /, %
    The binary relational operators: <, >, <=, >=, ==, !=
    The binary bitwise arithmetic operators: &, ^, |
    The conditional operator ?: (excluding the condition, which is expected to be of type bool)
 * 2- There are two rules followed while doing arithmetic conversions:
    a. If the type of at least one of the operands is on the priority list, the operand with lower priority is 
    conversted to the type of the operand with highr priority,
    b. If the type of neither operands is on the priority list, then operands are numerically promoted.
 * 3- Priority table is as below:
    long double (highest)
    double
    float
    unsigned long long
    long long
    unsigned long
    long
    unsigned int
    int (lowest)
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <typeinfo>

int main(int argc, char const *argv[])
{
    int i{2};
    double d{3.5};
    //the expression is of type double printed as d.
    std::cout << typeid(i+d).name() << " " << i + d << '\n';

    //***************************
    short a{4};
    short b{5};
    //since both the types are not on the priority list hence they are promoted to integer which is printed as i.
    std::cout << typeid(a+b).name() << " " << a+b << "\n";

    //***************************
    //Here since unsigned int has more priority than int so exp. is converted to unsigned int, but (-5) is out of range
    //for uint, hence unexpected result. 
    std::cout << typeid(5u+10).name() << " " << 5u - 10 << "\n";
    
    //here expected output is true but the actual output is false, because of the above reason.
    std::cout << std::boolalpha << typeid(-3 < 5u).name() << (-3 < 5u) << "\n" ;

    return 0;
}
