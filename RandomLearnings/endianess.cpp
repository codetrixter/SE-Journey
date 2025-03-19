/**
 * @file endianess.cpp
 * @author Abhsihek
 * @brief Checking if the system supports Big endian or little endian format.
 * @version 0.1
 * @date 2022-09-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned int i = 1;
    char *c = (char*)&i;
    if (*c)
        cout<<"Little endian";
    else
        cout<<"Big endian";
    return 0;
}