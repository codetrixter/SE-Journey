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

// Brute force
//  int maxSubarraySumCircular(vector<int> &nums)
//  {
//      int n = nums.size();
//      int res = nums[0];

//     for(int i{}; i < n; i++)
//     {
//         int curr = 0;
//         for(int j = i; j < i+n; j++)
//         {
//             curr += nums[j%n];
//             res = max(curr, res);
//         }
//     }
//     return res;
// }

// Modified Kadane's Algorithm for Circular Array
// Key Insight: Maximum subarray sum in a circular array can be in two cases:
// Case 1: Maximum subarray is in the middle (doesn't wrap around) - use standard Kadane's
// Case 2: Maximum subarray wraps around (uses end and beginning) - compute total - minimum subarray
int maxSubarraySumCircular(vector<int> &nums)
{
        // globMax: Maximum subarray sum found so far (Case 1: no wrap-around)
        // globMin: Minimum subarray sum found so far (used for Case 2: wrap-around)
        int globMax = nums[0], globMin = nums[0];
        
        // curMax: Current maximum subarray sum ending at current position
        // curMin: Current minimum subarray sum ending at current position
        // total: Sum of all elements in the array
        int curMax = 0, curMin = 0, total = 0;

        // Single pass through array - simultaneously find max subarray, min subarray, and total
        for (int& num : nums) {
            // Standard Kadane's for maximum subarray
            // Either extend current subarray or start new one from current element
            curMax = max(curMax + num, num);
            
            // Kadane's variation for minimum subarray
            // Either extend current subarray or start new one from current element
            curMin = min(curMin + num, num);
            
            // Accumulate total sum of all elements
            total += num;
            
            // Update global maximum (best max subarray seen so far)
            globMax = max(globMax, curMax);
            
            // Update global minimum (best min subarray seen so far)
            globMin = min(globMin, curMin);
        }

        // Return the maximum of two cases:
        // Case 1: globMax (normal subarray, no wrap-around)
        // Case 2: total - globMin (wrapped subarray = total - minimum middle part)
        // 
        // Edge case: If globMax <= 0, all numbers are negative
        // In this case, total - globMin would give 0 (empty array), so return globMax (least negative)
        // 
        // Example: nums = [5, -3, 5]
        // Case 1: globMax = 5 (just first or last element)
        // Case 2: total = 7, globMin = -3, so 7 - (-3) = 10 (wraps: [5] + [5])
        // Answer: max(5, 10) = 10 ✓
        return globMax > 0 ? max(globMax, total - globMin) : globMax;
    }

int main(int argc, char const *argv[])
{
    vector<int> inp = {2, -4, -1, 3, -2, 5};
    cout << maxSubarraySumCircular(inp);
    return 0;
}
