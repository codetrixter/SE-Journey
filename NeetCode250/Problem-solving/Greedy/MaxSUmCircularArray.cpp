/**
 * You are given a circular integer array nums of length n, return the maximum possible sum of a non-empty
 * subarray of nums.
A circular array means the end of the array connects to the beginning of the array. Formally, the next
 element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray
 nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

Example 1:
Input: nums = [-2,4,-5,4,-5,9,4]
Output: 15
Explanation: Subarray [-2,4,9,4] has maximum sum 15.

Example 2:
Input: nums = [2,3,-4]
Output: 5

Constraints:

n == nums.length
1 <= n <= 3 * 10,000
-30,000 <= nums[i] <= 30,000
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Brute force
int maxSubarraySumCircular(vector<int> &nums)
{
    int n = nums.size();
    int res = nums[0];

    for(int i{}; i < n; i++)
    {
        int curr = 0;
        for(int j = i; j < i+n; j++)
        {
            curr += nums[j%n];
            res = max(curr, res);
        }
    }
    return res;
}

// Kadane's Algorithm
// int maxSubarraySumCircular(vector<int> & nums)
// {

// }

int main(int argc, char const *argv[])
{
    vector<int> inp = {-2,4,-5,4,-5,9,4};
    cout << maxSubarraySumCircular(inp);
    return 0;
}
