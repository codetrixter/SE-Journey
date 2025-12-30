/**
 * You are given an array of integers nums containing n + 1 integers. Each integer in nums is in the range [1, n] inclusive.
    Every integer appears exactly once, except for one integer which appears two or more times. Return the integer that appears 
    more than once.

    Example 1:
    Input: nums = [1,2,3,2,2]
    Output: 2

    Example 2:
    Input: nums = [1,2,3,4,4]
    Output: 4
    Follow-up: Can you solve the problem without modifying the array nums and using O(1) extra space?
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
    int findDuplicate(vector<int> nums)
    {
        int max = 0;
        
        //find the element in the array which has the max value
        for(auto i : nums)
        {
            if(i > max)
                max = i;
        }

        vector<int> newarr(max+1, 0);
        /// create an array with size equal to max element and store each element of nums in new array where array[nums[i]] = 1
        /// if already 0
        for(int i{}; i < nums.size(); i++)
        {
            if(newarr[nums[i]] == 0)
                newarr[nums[i]] = 1;
            else
                return nums[i];
        }

        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution s1;
    cout << "\n" << s1.findDuplicate({1, 3, 4, 2, 2}) << "\n";
    return 0;
}
