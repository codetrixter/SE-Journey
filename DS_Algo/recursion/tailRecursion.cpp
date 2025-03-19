/**
 * @file tailRecursion.cpp
 * @author Abhishek
 * @brief Here we implemet the tail recursion:
 * which means the recusive functionin which the recursive call is the last statement of the function.
 * @version 0.1
 * @date 2022-05-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
void tail(int n)
{
    if(n > 0)
    {
        std::cout << n << " ";
        tail(n-1);      //last statement in the function call
    }
}
int main(int argc, char const *argv[])
{
    int num = 10;
    tail(10);

    return 0;
}
