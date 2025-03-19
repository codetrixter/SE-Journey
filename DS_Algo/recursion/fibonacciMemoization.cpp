/**
 * @file fibonacciMemoization.cpp
 * @author Abhishek
 * @brief Implementing fibonacci using dp
 * @version 0.1
 * @date 2022-05-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

int fib(int n)
{
    static int arr[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    if(n == 0 || n == 1)
    {
        arr[n] = n;
        return n;
    }
    
    if(arr[n-2] == -1)
        arr[n-2] = fib(n-2);

    if(arr[n-1] == -1)
        arr[n-1] = fib(n-1);

    return arr[n-2] + arr[n-1];
}

int main(int argc, char const *argv[])
{
    int x = 5;
    std::cout << fib(7);
    return 0;
}
