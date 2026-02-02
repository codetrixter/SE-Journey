/**
 *  You are given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would 
 * be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [-1,0,2,4,6,8], target = 5

Output: 4
Example 2:

Input: nums = [-1,0,2,4,6,8], target = 10

Output: 6
Constraints:

1 <= nums.length <= 10,000.
-10,000 < nums[i], target < 10,000
nums contains distinct values sorted in ascending order.
 */
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

//basic algo for this problem
/* int searchInsert(vector<int> &nums, int target)
{
    int s = 0, e = nums.size() - 1, m = 0;

    while (s <= e)
    {
        m = s + ((e - s) / 2);
        if (target < nums[m])
            e = m - 1;
        else if (target > nums[m])
            s = m + 1;
        else
            return m;
    }
    if (target < nums[m])
        return m;
    else
        return m + 1;
} */

//using inbuild function
int searchInsert(vector<int>& nums, int target)
{
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}

int main(int argc, char const *argv[])
{
    vector<int> inp = {1, 3, 5, 6};
    cout << searchInsert(inp, 0);
    return 0;
}
