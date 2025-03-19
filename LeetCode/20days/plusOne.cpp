/**
 * @file plusOne.cpp
 * @author Abhishek
 * @brief You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
    Increment the large integer by one and return the resulting array of digits.

    Example 1:
    Input: digits = [1,2,3]
    Output: [1,2,4]
    Explanation: The array represents the integer 123.
    Incrementing by one gives 123 + 1 = 124.
    Thus, the result should be [1,2,4].

    Example 2:
    Input: digits = [4,3,2,1]
    Output: [4,3,2,2]
    Explanation: The array represents the integer 4321.
    Incrementing by one gives 4321 + 1 = 4322.
    Thus, the result should be [4,3,2,2].

    Example 3:
    Input: digits = [9]
    Output: [1,0]
    Explanation: The array represents the integer 9.
    Incrementing by one gives 9 + 1 = 10.
    Thus, the result should be [1,0].

    Constraints:
    1 <= digits.length <= 100
    0 <= digits[i] <= 9
    digits does not contain any leading 0's.
 * @version 0.1
 * @date 2022-10-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>

std::vector<int> plusOne(std::vector<int>& digits)
{
    int size = digits.size();
    int carry = 0, count = 0;
    for(int i = size-1; i >= 0; i--)
    {
        if(digits[i] == 9)
        {
            carry = 1;
            count++;
            digits[i] = 0;
        }
        else
        {
            digits[i] += 1;
            break;
        }
    }
    if(count == size)
    {
        std::vector<int> vect(size+1);
        vect[0] = 1;
        return vect;
    }
    return digits;
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec{9, 9, 9};
    auto result = plusOne(vec);
    for(auto i : result)
    {
        std::cout << i << " ";
    }
    return 0;
}
