/**
 * @file functionTryBlock.cpp
 * @author Abhishek
 * @brief Here we discuss the concept of function try blocks:
 * 1- function try blocks can catch both base and the current class exceptions.
 * NOTE:
 * ONE: When construction of an object fails, the destructor of the class is not called. Consequently, you may be tempted to use a function try 
 * block as a way to clean up a class that had partially allocated resources before failing. However, referring to members of the failed object 
 * is considered undefined behavior since the object is “dead” before the catch block executes. This means that you can’t use function try to 
 * clean up after a class.
 * SECOND: Function try is useful primarily for either logging failures before passing the exception up the stack, or for changing the type of 
 * exception thrown.
 * 
 *  ╔═══════════════════════════════╦═══════════════════════════╦═══════════════════════════╗
	║ Function type                 ║ Can resolve exceptions    ║ Behavior at end of        ║
	║                               ║ via return statement      ║ catch block               ║
	╠═══════════════════════════════╬═══════════════════════════╬═══════════════════════════╣
	║ Constructor                   ║ No, must throw or rethrow ║ Implicit rethrow          ║
	╠═══════════════════════════════╬═══════════════════════════╬═══════════════════════════╣
	║ Destructor                    ║ Yes                       ║ Implicit rethrow          ║
	╠═══════════════════════════════╬═══════════════════════════╬═══════════════════════════╣
	║ Non-value returning function  ║ Yes                       ║ Resolve exception         ║
	╠═══════════════════════════════╬═══════════════════════════╬═══════════════════════════╣
	║ Value-returning function      ║ Yes                       ║ Undefined behavior        ║
	╚═══════════════════════════════╩═══════════════════════════╩═══════════════════════════╝
 * @version 0.1
 * @date 2022-09-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

class A
{
private:
	int m_x;
public:
	A(int x) : m_x{x}
	{
		/* if (x <= 0)
			throw 1; */
	}
};

/* class B : public A
{
public:
	B(int x) : A{x}
	{
		// What happens if creation of A fails and we want to handle it here?
	}
}; */
class B : public A
{
public:
	B(int x) try : A{x} // note addition of try keyword here
	{
        //exception caught even when thrown from derived class.
        if (x <= 0)
			throw 1;
	}
	catch (...) // note this is at same level of indentation as the function itself
	{
                // Exceptions from member initializer list or constructor body are caught here

                std::cerr << "Exception caught\n";

                // If an exception isn't explicitly thrown here, the current exception will be implicitly rethrown
	}
};

int main()
{
	try
	{
		B b{0};
	}
	catch (int)
	{
		std::cout << "Oops\n";
	}
}