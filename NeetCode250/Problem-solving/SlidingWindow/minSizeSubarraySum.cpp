/**
 *You are given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum
 is greater than or equal to target. If there is no such subarray, return 0 instead.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: target = 10, nums = [2,1,5,1,5,3]

Output: 3
Explanation: The subarray [5,1,5] has the minimal length under the problem constraint.

Example 2:

Input: target = 5, nums = [1,2,1]

Output: 0
Constraints:

1 <= nums.length <= 100,000
1 <= nums[i] <= 10,000
1 <= target <= 1,000,000,000
Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
 */

#include <iostream>
#include <vector>

using namespace std;

// brute force....
int minSubArrayLen1(int target, vector<int> &nums)
{
    int mc = 10000, c = 0, s = 0, size = nums.size() - 1;

    for (int i{}; i <= size; i++)
    {
        for (int j = i; j <= size; j++)
        {
            if (s < target)
            {
                s += nums[j];
                c++;
            }
            if (s >= target)
                mc = min(mc, c);
        }
        // mc = min(mc, c);
        c = 0;
        s = 0;
    }
    if (mc == 10000)
        mc = 0;
    return mc;
}

// optimized - O(n)
int minSubArrayLen(int target, vector<int> &nums)
{
    int b = 0, e = 0, w = __INT_MAX__, sum = 0;

    for(; e < nums.size(); e++)
    {
        sum += nums[e];
        while(sum >= target)
        {
            w = min(e-b+1, w);
            sum -= nums[b];
            ++b;
        }
    }
    return (w == __INT_MAX__)? 0 : w ;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 1, 5, 1, 5, 3};
    int target = 10;

    cout << minSubArrayLen(target, arr);
    return 0;
}
