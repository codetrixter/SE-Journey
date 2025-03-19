/**
 * @file nestedRecursion.cpp
 * @author Abhishek
 * @brief Implementation of nested recursion
 * @version 0.1
 * @date 2022-05-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

int nested(int n)
{
    if(n >100)
        return (n-10);
    else
        return (nested(nested(n+11)));
}

int main(int argc, char const *argv[])
{
    int x = 10;
    std::cout << nested(x);
    return 0;
}
