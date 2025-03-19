/**
 * @file anagram.cpp
 * @author Abhishek
 * @brief Below program checks if the given two strings are anagram or not.
 * @version 0.1
 * @date 2022-04-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

bool isAnagram(char *s1, char *s2)
{
    int count1 = 0, count2 = 0;
    for(int i = 0; s1[i] != '\0'; i++)
    {
        count1++;
    }
    for(int i = 0; s2[i] != '\0'; i++)
    {
        count2++;
    }
    if(count1 != count2)
        return false;

    int arr[26] = {0};

    for(int i = 0; s1[i] != '\0'; i++)
    {
        arr[s1[i]-97]++; 
        arr[s2[i]-97]--;
    }

    for(int i = 0; i < 26; i++)
    {
        if(arr[i] != 0)
        {
            return false;
        }
    }
    return true;

}

int main(int argc, char const *argv[])
{
    char str[] = "aa";
    char str2[] = "bb";

    std::cout << isAnagram(str, str2);

    return 0;
}
