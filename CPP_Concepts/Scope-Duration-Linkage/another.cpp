/**
 * ! This file just acts as an example for testing external linkages
 */
#include <iostream>

void sayHi() // this function has external linkage, and can be seen by other files
{
    std::cout << "Hi!\n";
}