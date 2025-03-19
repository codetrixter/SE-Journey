/**
 * @file headRecursion.cpp
 * @author Abhishek
 * @brief Here we implemet the head recursion:
 * which means the recusive functionin which the recursive call is the first statement of the function.
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
        tail(n-1);      //first statement in the function call
        std::cout << n << " ";
    }
}
int main(int argc, char const *argv[])
{
    int num = 10;
    tail(10);

    return 0;
}
