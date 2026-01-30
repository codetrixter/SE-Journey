/**
 * @file TwoSum.cpp
 * @author Abhishek
 * @brief 
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    You can return the answer in any order.
    Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]
 * @version 0.1
 * @date 2022-07-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        //using map as hask table to store the vector elements, and then checking for another number by finding the subtracting current number
        // with target, if the res is part of map, then that number and map numbers are the pair.
        std::unordered_map<int, int> hash;
        std::vector<int> resultInd;

        for(int i = 0; i < nums.size(); i++)
        {
            int res = target - nums[i];
            if(hash.find(res) != hash.end())
            {
                resultInd.push_back(hash[res]);
                resultInd.push_back(i);
            }
            else
            {
                //hash.insert({nums[i], i});
                hash[nums[i]] = i;
            }
        }
        return resultInd;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    std::vector<int> input = {2, 3, 11, 7, 15};     //o/p -> 03
    std::vector<int> result = sol.twoSum(input, 9);

    for(auto i : result)
    {
        std::cout << i;
    }
    return 0;
}
