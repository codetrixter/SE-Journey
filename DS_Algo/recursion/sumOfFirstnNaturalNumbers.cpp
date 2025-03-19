/**
 * @file sumOfFirstnNaturalNumbers.cpp
 * @author Abhishek
 * @brief implementing sum of first n natural numbers.
 * @version 0.1
 * @date 2022-05-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

int sumN(int n)
{
    if( n == 0)
        return n;
    else    
        return sumN(n-1) + n;
}

int main(int argc, char const *argv[])
{
    int x = 10;
    std::cout << sumN(x);
    return 0;
}
