/**
 * @file arrayAsParam.cpp
 * @author Abhishek
 * @brief 
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

void functioncall(int a[])
{
    std::cout << a[0];
}
int main(int argc, char const *argv[])
{
    int a[10];
    a[0] = 10;
    functioncall(a);
    return 0;
}
