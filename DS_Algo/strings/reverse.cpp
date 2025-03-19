/**
 * @file reverse.cpp
 * @author Abhishek
 * @brief Reversing the string from bothe directions technique:
 * complexityO(n/2)-> O(n) 
 * @version 0.1
 * @date 2022-04-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

void reverse(char *str)
{
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }

    for(int i = 0,j = count-1; i < j; i++,j--)
    {
        char temp = ' ';
        temp = str[i];
        str[i] = str[j];
        str[j] = temp; 
    }

    for(int i = 0; str[i] != '\0'; i++)
    {
        std::cout << str[i];
    }
}

int main(int argc, char const *argv[])
{
    char str[] = "Abhishek";
    reverse(str);
    return 0;
}
