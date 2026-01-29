/**
 * @file uncaughtExcCatchAllhandler.cpp
 * @author Abhishek
 * @brief Here we discuss about the effects of not catching an exception:
 * 1- If an exception is not caught then the behaviour might range from crash to printiing error message.
 * 2- Ellipses can be used to catch any kind of excetion, and must be used as the last catch.
 * @version 0.1
 * @date 2022-09-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cmath> // for sqrt() function

// A modular square root function
double mySqrt(double x)
{
    // If the user entered a negative number, this is an error condition
    if (x < 0.0)
        throw "Can not take sqrt of negative number"; // throw exception of type const char*

    return std::sqrt(x);
}

int main()
{
    std::cout << "Enter a number: ";
    double x;
    std::cin >> x;

    // Look ma, no exception handler!, sue to which Abort happened.
    //terminate called after throwing an instance of 'char const*'
    //Aborted (core dumped)
    std::cout << "The sqrt of " << x << " is " << mySqrt(x) << '\n';

    return 0;
}
//**********************Catch all handler***
/* int main()
{
	try
	{
		throw 5; // throw an int exception
	}
	catch (double x)
	{
		std::cout << "We caught an exception of type double: " << x << '\n';
	}
	catch (...) // catch-all handler, must be used as the last catch so that respective catch blocks can execute first.
	{
		std::cout << "We caught an exception of an undetermined type\n";
	}
} */
//**********************Catch all handler***