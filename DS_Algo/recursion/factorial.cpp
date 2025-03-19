/**
 * @file factorial.cpp
 * @author Abhishek
 * @brief Implementing factorial of a number using recursion.
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>

int fact(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * fact(n-1);
    }
}
int main(int argc, char const *argv[])
{
    int num = 6;
    std::cout << fact(num);
    return 0;
}
