/**
 * @file exceptionsAndStackUnwinding.cpp
 * @author Abhishek
 * @brief Here we discuss about the stack unwinding that happens when an exception is resolved:
 * 1- 
 * @version 0.1
 * @date 2022-09-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

void last() // called by third()
{
    std::cout << "Start last\n";
    std::cout << "last throwing int exception\n";

    throw -1;   //stack unwinding happens here and execution goes to third(), since exception not caught.

    std::cout << "End last\n";
}

void third() // called by second()
{
    std::cout << "Start third\n";
    last();     //stack unwinding happens here and execution goes to second(), since exception not caught.
    std::cout << "End third\n";
}

void second() // called by first()
{
    std::cout << "Start second\n";
    try
    {
        third();    //stack unwinding happens here and execution goes to first(), since matching exception not found.
    }
    catch (double)
    {
         std::cerr << "second caught double exception\n";
    }
    std::cout << "End second\n";
}

void first() // called by main()
{
    std::cout << "Start first\n";
    try
    {
        second();       //exception match found, last print is executed.
    }
    catch (int)
    {
         std::cerr << "first caught int exception\n";
    }
    catch (double)
    {
         std::cerr << "first caught double exception\n";
    }
    std::cout << "End first\n";     //goes ot main() from here.
}

int main()
{
    std::cout << "Start main\n";
    try
    {
        first();
    }
    catch (int)
    {
         std::cerr << "main caught int exception\n";
    }
    std::cout << "End main\n";

    return 0;
}
/**
 * @brief Output:
 * Start main
 * Start first
 * Start second
 * Start third
 * Start last
 * last throwing int exception
 * first caught int exception
 * End first
 * End main
 */