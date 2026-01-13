/**
 * @file COntainsDuplicate.cpp
 * @author Abhishek
 * @brief 
 * Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
    Example 1:
    Input: nums = [1,2,3,1]
    Output: true
 * @version 0.1
 * @date 2022-07-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
    /* bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> hTable;
        bool flag = false;
        for(int i = 0; i < nums.size(); i++)
        {
            hTable[nums[i]] += 1;
        }

        for(auto x : hTable)
        {
            if(x.second > 1)
                flag = true;
        }
        return flag;
    } */

    //Alternate way.
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> s;
        
        for (int i = 0; i < nums.size(); i++) 
        {
            //Here find computes in constant time.
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }
        
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    std::vector<int> vec{1, 2, 3, 1};
    std::cout << std::boolalpha << sol.containsDuplicate(vec);
    return 0;
}
