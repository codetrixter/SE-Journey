/**
 * @file findDuplicates.cpp
 * @author Abhishek
 * @brief Finding the duplicates in the string, two ways:
 * 1- Brute force(O(n^2))
 * 2- hashing method(O(n))-> implemented here, using Bitwise operations.
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <unordered_map>

void findDuplicates(char *str)
{
    int hash  = 0, maskBit = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        maskBit = 1;
        maskBit = maskBit<<(str[i]-97);

        if((maskBit & hash) > 0)    //checking of there is a duplicate already found by masking
        {
            std::cout << "Duplicate found and is " << str[i] << std::endl;
        }
        else
        {
            //updating the hash structure on every unique character find.
            hash = hash|maskBit;
        }
    }
}

//------------Alternatively-------------
void findDuplicates(std::string str)
{
    std::unordered_map<char, int> mapp;

    for(int i = 0; i <= str.length()-1; i++)
    {
        mapp[str[i]]++;
    }

    for(auto item : mapp)
    {
        std::cout << item.first << " " << item.second << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    char str[] = "malayalam";

    findDuplicates(str);
    //std::string s = "abhishek";
    //findDuplicates(s);

    return 0;
}
