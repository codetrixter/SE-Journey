/**
 *You are given an unsorted integer array nums. Return the smallest positive integer that is not present
 in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:
Input: nums = [-2,-1,0]
Output: 1

Example 2:
Input: nums = [1,2,4]
Output: 3

Example 3:
Input: nums = [1,2,4,5,6,3,1]
Output: 7

Constraints:
1 <= nums.length <= 100,000
-(2^31) <= nums[i] <= ((2^31)-1)
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/// @brief O(nlogn) solution.
/// @param nums 
/// @return 
int firstMissingPositive(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    set<int> temp(nums.begin(), nums.end());

    int expected = 1;
    bool found = false;

    std::for_each(temp.begin(), temp.end(), [&expected, &found](int val) 
    {
        if(found) return;
        if(val > 0)
        {
            if(val == expected)
                expected++;
            else if(val > expected)
                found = true;
        }
    });

    return expected;
}

int firstMissingPositiveII(vector<int> &nums)
{
}

int main(int argc, char const *argv[])
{
    vector<int> inp1 = {1, 2, 4, 5, 6, 3, 1}; 
    cout << firstMissingPositive(inp1) << "\n";
    
    return 0;
}
