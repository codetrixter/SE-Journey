/**
 * @file quesFour.cpp
 * @author Abhishek
 * @brief Quiz question 4 solution, fin dthe output
 * @version 0.1
 * @date 2022-05-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

int fun(int n)
{
    int x = 1, k;
    if(n == 1)
        return x;
    for(k = 1; k < n; ++k)
    {
        x = x+ fun(k)*fun(n-k);
    }
    return x;
}

int main(int argc, char const *argv[])
{
    std::cout << fun(5);
    return 0;
}
