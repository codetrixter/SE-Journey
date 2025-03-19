/**
 * @file exceptionHandlingBasics.cpp
 * @author Abhishek Mishra
 * @brief Here we discuss about the exception and how they are caught and thrown:
 * 1- Exceptions handling are just a way to handle errors during runtime, error handling is usually doen using return codes, however return codes
 * can be often cryptic and unclear.
 * 2- A throw statement acts like a signal, which tells that an error condition has occurred, an exption can be thrown using any variable:
 *  a. throw -1; // throw a literal integer value
    b. throw ENUM_INVALID_INDEX; // throw an enum value
    c. throw "Can not take square root of negative number"; // throw a literal C-style (const char*) string
    d. throw dX; // throw a double variable that was previously defined
    e. throw MyException("Fatal Error"); // Throw an object of class MyException
 * 3- Basic use of try, catch and throw shown below.
 * 4- Compiler does not perdorms any implicit conversions or promotions while matching exception with respective catch blocks, however casts from 
 * derived class to one of its parent classes will be performed. 
 * 5- What catch blocks typically do after execution goes to them:
 *      a. May print an error.
 *      b. May return an error code back to the caller.
 *      c. May throw another exception which would be handled by succeeding try block.
 * @version 0.1
 * @date 2022-09-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <string_view>
//******************************************try, catch, and throw***

// Here erro code -1 is not very informative about the purpose/output of the function
/* int findFirstChar(std::string_view string, char ch)
{
    // Step through each character in string
    for (std::size_t index{ 0 }; index < string.length(); ++index)
        // If the character matches ch, return its index
        if (string[index] == ch)
            return index;

    // If no match was found, return -1
    return -1;
}

int main(int argc, char const *argv[])
{
    try
    {
        // Statements that may throw exceptions you want to handle go here
        throw -1; // here's a trivial example
    }
    catch (int x)
    {
        // Any exceptions of type int thrown within the above try block get sent here
        std::cerr << "We caught an int exception with value: " << x << '\n';
    }
    catch (double) // no variable name since we don't use the exception itself in the catch block below
    {
        // Any exceptions of type double thrown within the above try block get sent here
        std::cerr << "We caught an exception of type double" << '\n';
    }
    catch (const std::string&) // catch classes by const reference
    {
        // Any exceptions of type std::string thrown within the above try block get sent here
        std::cerr << "We caught an exception of type std::string" << '\n';
    }

    std::cout << "Continuing on our merry way\n";
    return 0;
} */
//******************************************try, catch, and throw***
//******************************************Another example***
#include <cmath>

int main()
{
    std::cout << "Enter a number: ";
    double x {};
    std::cin >> x;

    try // Look for exceptions that occur within try block and route to attached catch block(s)
    {
        // If the user entered a negative number, this is an error condition
        if (x < 0.0)
            throw "Can not take sqrt of negative number"; // throw exception of type const char*

        // Otherwise, print the answer
        std::cout << "The sqrt of " << x << " is " << std::sqrt(x) << '\n';
    }
    catch (const char* exception) // catch exceptions of type const char*
    {
        std::cerr << "Error: " << exception << '\n';
    }
}
//******************************************Another example***