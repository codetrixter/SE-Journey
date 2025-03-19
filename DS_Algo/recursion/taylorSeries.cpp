/**
 * @file tailerSeries.cpp
 * @author Abhishek
 * @brief Implementing a recursive solution to finding the taylor series.
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

int taylor(int x, int n)
{
    static int p = 1, f = 1;
    int r = 0;

    if(n == 0)
    {
        return 1;
    }
    
    r = taylor(x, n-1);
    p = p*x;
    f = f*n;
    return r + p/f;

}


int main(int argc, char const *argv[])
{
    int x = 4, n = 2;
    std::cout << taylor(4, 2);
    return 0;
}
