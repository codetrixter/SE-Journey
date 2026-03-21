/**
 * You are given an integer array nums of size n, find all elements that appear more than ⌊ n/3 ⌋ times. You can return the result in any order.
Example 1:
Input: nums = [5,2,3,2,2,2,2,5,5,5]
Output: [2,5]

Example 2:
Input: nums = [4,4,4,4,4]
Output: [4]

Example 3:
Input: nums = [1,2,3]
Output: []

Constraints:
1 <= nums.length <= 50,000.
-1,000,000,000 <= nums[i] <= 1,000,000,000
Follow up: Could you solve the problem in linear time and in O(1) space?
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/// @brief create a map of elements and then return keys having values > n/3
/// @param nums 
/// @return 
vector<int> majorityElement(vector<int> &nums)
{
    unordered_map<int, int> lmap;
    vector<int> result;

    for(auto i : nums)
    {
        lmap[i]++;
    }

    int threshold = (int)nums.size() / 3;

    for(auto i : lmap)
    {
        if(i.second > threshold)
        {
            result.push_back(i.first);
        }
    }
    return result;

}

/// @brief //TODO: Boyer Moore Voting algo.
/// @param nums 
/// @return 
vector<int> majorityElement(vector<int> &nums)
{
}

int main(int argc, char const *argv[])
{
    vector<int> inp = {5, 2, 3, 2, 2, 2, 2, 5, 5, 5};

    auto out = majorityElement(inp);

    for(auto i : out)
    {
        cout << i << " ";
    }
    return 0;
}
