/**
 * @file exponentialRecursion.cpp
 * @author Abhishek
 * @brief Implementing exponential operations via recursion.
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

int exp(int m, int n)
{
    if(n == 0)
        return 1;
    else if(m == 0)
        return 0;
    else
        return exp(m, n-1) * m;
}

int expFast(int m, int n)
{
    if(n == 0)
        return 1;
    else if(m == 0)
        return 0;
    else if(n%2 == 0)
        return expFast(m*m, n/2);
    else
        return expFast(m*m, (n-1)/2) * m;
}

int main(int argc, char const *argv[])
{
    int m = 5, n = 2;
    //std::cout << exp(m, n);

    std::cout << expFast(m, n);
    return 0;
}
