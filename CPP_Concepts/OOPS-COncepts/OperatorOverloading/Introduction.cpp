/**
 * @file Introduction.cpp
 * @author Abhishek
 * @brief Here we do the introduction to the operator overloading
 * 1- During Resolving operator overloads the compiler does the following:
 *  a.If all of the operands are of fundamental types then compiler will look for in-build routine, if one one does 
 * exists then the compiler will issue an error.
 *  b. If any of the operands are of user defined type, then the compiler looks for the operator overloaded
 * function of that type, if it can't find one then it tries to convert one or more user defined types into 
 * fundamental types so that it can use a matching built in operator(via overlaod type cast). If all the above 
 * it will issue an error.
 * 
 * 2- LIMITAITIONS OF OPERATOR OVERLOADING::
 *  a. Almost all existing operators in c++ can be overloaded except these:
 *      I. conditional(?:)
 *      II. sizeof
 *      III. scope(::)
 *      IV. member selection(.)
 *      V. member pointer selecter(.*)
 *      VI. typeid
 *      VII. casting operators
 *  b. You can only overload oprators that exist and cannot create new operators or rename existing ones, 
 * for instance you cannot overload the ** operator.
 *  c. At least one of the operands in the overloaded operator must be user define type, e.g: overloading with 
 * "int and double" is not possible but "int and MyString" is. 
 *  d. It is not possible to change the number of operands an oprator supports.
 *  e. All operatorskeep their default precedence and associtivity(regardless of what they are used for), 
 * and it cannot be changed.
 * 
 * **BEST PRACTICES**
 * - When overloading operators, it’s best to keep the function of the operators as close to the original 
 * intent of the operators as possible.
 * - If the meaning of an overloaded operator is not clear and intuitive, use a named function instead.
 * 
 * ***WAYS OF OERLOADING OPERATORS***
 * 1- via Member functions
 * 2- via Friend functions
 * 3- via Normal functions
 * ***WAYS OF OERLOADING OPERATORS***
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string s1{ "abhishek" };
    std::string s2{ "Mishra" };

    //Here the "+" operator is overloaded to concatenate two strings.
    std::cout << s1+s2;    
    return 0;
}

