/**
 * Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.

A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element.
The elements do not have to be consecutive in the original array.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [2,20,4,10,3,4,5]
Output: 4
Explanation: The longest consecutive sequence is [2, 3, 4, 5].

Example 2:
Input: nums = [0,3,2,5,4,6,1,1]
Output: 7

Constraints:
0 <= nums.length <= 1000
-10^9 <= nums[i] <= 10^9
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> numSet(nums.begin(), nums.end());
    int longest = 0;

    for(int num : numSet)
    {
        if(numSet.find(num-1) == numSet.end())
        {
            int length = 1;
            while(numSet.find(num+length) != numSet.end())
            {
                length++;
            }
            longest = max(longest, length);
        }
    }

    return longest;
}

int main(int argc, char const *argv[])
{
    vector<int> inp = {2,20,4,10,3,4,5};
    cout << longestConsecutive(inp);
    return 0;
}
