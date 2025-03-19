/**
 * @file quesThree.cpp
 * @author Abhishek
 * @brief find the output of the following.
 * @version 0.1
 * @date 2022-05-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

int f(int &x, int c)
{
    static int r = 0;
    c = c-1;

    if (c == 0)
        return 1;

    x = x + 1;

    r = f(x, c) * x;
    return r;
}

int main(int argc, char const *argv[])
{
    int p = 5;
    std::cout << f(p, p);
    return 0;
}
