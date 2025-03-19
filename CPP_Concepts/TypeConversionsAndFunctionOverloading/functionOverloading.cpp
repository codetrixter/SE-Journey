/**
 * @file functionOverloading.cpp
 * @author Abhishek
 * @brief Here we discuss the intrecacies of function overloading:
 * 1- Function differentiation for overloading:
 *  a. Function name.
 *  b. Function param(number and types).
 *  c. const or volatile.
 *  d. Ref. qualifiers.
 * 2- Function overload resolution and ambiguous matches:
 *  a. In case of exact match is found the the respective function is called.
 * 
 * 3- Resolving overloaded function calls-> In this process, the compiler tries to match function argument types to the function parameter
 * types by using various conversion techniques, at the end of all conversion operations following options are left:
 *  a.No match is found.
 *  b. A single match is found and the that function is considered the best match.
 *  c. More than one match was found. It will give ambiguous match error. 
 * 4- The argument matching sequence is as follows:
 * 
 * Step 1)-> The compiler tries to find an exact match. This happens in two phases. 
 * First, the compiler will see if there is an overloaded function where the type of the arguments in the function call exactly
 * matches the type of the parameters in the overloaded functions.
 * Second, the compiler will apply a number of trivial conversions to the arguments in the function call.
 *      - Trivial conversions are:
 *          - non-const type to const type
 *          - non-reference type to reference type
 * 
 * Step 2)-> If no exact match is found, the compiler tries to find a match by applying numeric promotion to the argument(s).
 *  If, after numeric promotion, a match is found, the function call is resolved.
 * 
 * Step 3)-> If no match is found via numeric promotion, the compiler tries to find a match by applying numeric conversions
 *  to the arguments.
 * 
 * Step 4)-> If no match is found via numeric conversion, the compiler tries to find a match through any user-defined conversions.
 * 
 * Step 5)-> If no match is found via user-defined conversion, the compiler will look for a matching function that uses ellipsis.
 * 
 * Step 6)-> If no matches have been found by this point, the compiler gives up and will issue a compile error about not being 
 * able to find a matching function.
 * 
 * 5- Ambiguous matches::
 *  a. An ambiguous match occurs when the compiler finds two or more functions that can be made to match in the same step.
 *  b. One can resolve an ambigupus function match by explicit type conversions.
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
//***********************
/* int add(int a, int b)
{
    return a+b;
}

//error: ambiguating new declaration of ‘double add(int, int)’ , note: old declaration ‘int add(int, int)’
// double add(int a, int b)
// {
//     return a+b;
// }

double add(double da, double db)
{
    return da+db;
}
int main(int argc, char const *argv[])
{
    std::cout << add(4, 5);
    std::cout << add(10.5, 10.0);
    return 0;
}*/
//**********************
//**********************2a***
/* void print(int a)
{
    std::cout << a;
}
void print(double d)
{
    std::cout << d;
}
int main(int argc, char const *argv[])
{
    print(5); // 5 is an int, so this matches print(int)
    print(6.7); // 6.7 is a double, so this matches print(double)

    return 0;
} */
//**********************2a***
//**********************Step-1***
/* void print(const int a)
{}
void print(double &d)
{}

int main(int argc, char const *argv[])
{
    int x{0};
    print(x);   //x trivially converted to const int.
    print(5.5); //double is trivially converted to reference type double.

    return 0;
} */
//**********************Step-1***
//**********************Step-2***
/* void print(int)
{}
void print(double)
{}
int main(int argc, char const *argv[])
{
    print('a'); // promoted to match print(int)
    print(true); // promoted to match print(int)
    print(4.5f); // promoted to match print(double)

    return 0;
} */
//**********************Step-2***
//**********************Step-3***
/* #include <string>
void print(double dd)
{
    std::cout << dd;
}
void print(std::string)
{}
int main(int argc, char const *argv[])
{
    print('a'); // 'a' converted to match print(double)
    return 0;
} */
//**********************Step-3***
//**********************Step-4***
/* class X // this defines a new type called X
{
public:
    operator int() { return 0; } // Here's a user-defined conversion from X to int
};

void print(int)
{
}

void print(double)
{
}

int main()
{
    X x; // Here, we're creating an object of type X (named x)
    print(x); // x is converted to type int using the user-defined conversion from X to int

    return 0;
} */
//**********************Step-4***
//**********************Ambiguous matches***
/* void print(int x) {}
void print(double d) {}
int main()
{
    print(5L);  // error: call of overloaded ‘print(long int)’ is ambiguous, 
                //5L is type long, since long can be narrowly converted to fit either in int or double.
    return 0;
} */
//------------Alternate
/* void print(unsigned int x) {}
void print(float y) {}
int main()
{
    print(0); // int can be numerically converted to unsigned int or to float
    print(3.14159); // double can be numerically converted to unsigned int or to float

    return 0;
} */
//**********************Ambiguous matches***
//**********************Multiple param***
void print(char c, int x)
{
	std::cout << 'a';
}
void print(char c, double x)
{
	std::cout << 'b';
}
void print(char c, float x)
{
	std::cout << 'c';
}
int main()
{
    //In the above program, all functions match the first argument exactly. However, the top function matches the second parameter via  
    //promotion, whereas the other functions  require a conversion. Therefore, print(char, int) is unambiguously the best match.
	print('x', 'a');
    return 0;
}
//**********************Multiple param***