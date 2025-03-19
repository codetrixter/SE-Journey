/**
 * @file indirectRecursion.cpp
 * @author Abhishek
 * @brief implementation of indirect recursion
 * @version 0.1
 * @date 2022-05-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
void funB(int n);

void funA(int n)
{
    if(n > 0)
    {
        std::cout << n;
        funB(n-1);  //indirectly calling funA which calls funB
    }
}

void funB(int n)
{
    if(n > 1)
    {
        std::cout << n;
        funA(n/2);
    }
}

int main(int argc, char const *argv[])
{
    int x = 20;
    funA(x);
    return 0;
}
