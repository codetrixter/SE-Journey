/**
 * You are given an array of integers nums and an integer k, return the total number of subarrays whose
 * sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [2,-1,1,2], k = 2
Output: 4
Explanation: [2], [2,-1,1], [-1,1,2], [2] are the subarrays whose sum is equals to k.

Example 2:
Input: nums = [4,4,4,4,4,4], k = 4
Output: 6

Constraints:
1 <= nums.length <= 20,000
-1,000 <= nums[i] <= 1,000
-10,000,000 <= k <= 10,000,000
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/// @brief O(n^2) solution for finding subarry sum
/// @param nums
/// @param k
/// @return number of subarrays with sum k
/* int subarraySum(vector<int> &nums, int k)
{

    int n = nums.size(), count = 0, sum = 0;

    for (int i{}; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
                count++;
        }
    }

    return count;
} */

/// @brief calculates subarray count in O(1) after creating prefic array in O(n)
/// @param nums 
/// @param k 
/// @return count of subarrays equal to k
int subarraySum(vector<int> &nums, int k)
{
    int res = 0, curSum = 0;
    unordered_map<int, int> prefixSums;
    prefixSums[0] = 1;

    for (int num : nums)
    {
        curSum += num;
        int diff = curSum - k;
        res += prefixSums[diff];
        prefixSums[curSum]++;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> inp = {2, -1, 1, 2};
    cout << subarraySum(inp, 2);

    return 0;
}
