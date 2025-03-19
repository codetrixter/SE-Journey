/**
 * @file monotoniArray.cpp
 * @author Abhishek
 * @brief 
 * @version 0.1
 * @date 2022-10-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>

bool isMonotonic(std::vector<int>& nums)
{
    return std::is_sorted(nums.begin(),nums.end()) || std::is_sorted(nums.begin(),nums.end(),std::greater<int>());
}
int main(int argc, char const *argv[])
{
    std::vector<int> vec{6, 5, 4, 4, 10};
    std::cout << std::boolalpha << isMonotonic(vec);
    return 0;
}
