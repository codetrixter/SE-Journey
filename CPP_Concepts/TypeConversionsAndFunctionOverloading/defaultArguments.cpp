/**
 * @file defaultArguments.cpp
 * @author Abhishek
 * @brief here we discuss about the default arguments:
 * 1- These cannot be redeclared.
 * 2- overloading with default arguments.
 * 3- brace initialization does not work for default arguments.
 * @version 0.1
 * @date 2022-07-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
//******************point 1***
/* void print(int x, int y=4); // forward declaration

void print(int x, int y=4) // error: redefinition of default argument
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
} */
//******************point 1***
//******************point 2***
/* void print(std::string string) {}
void print(char ch=' ') {}
int main()
{
    print("Hello, world"); // resolves to print(std::string)
    print('a'); // resolves to print(char)
    print(); // resolves to print(char)

    return 0;
} */
//------------------------------------
void print(int x) {}
void print(int x, int y = 10) {}
void print(int x, double y = 20.5) {}

int main(int argc, char const *argv[])
{
    print(1, 2); // will resolve to print(int, int)
    print(1, 2.5); // will resolve to print(int, double)
    print(1); // ambiguous function call
    return 0;
}

//******************point 2***

