/**
 * Given an array of integers nums, find the subarray with the largest sum and return the sum.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [2,-3,4,-2,2,1,-1,4]

Output: 8
Explanation: The subarray [4,-2,2,1,-1,4] has the largest sum 8.

Example 2:

Input: nums = [-1]

Output: -1
Constraints:

1 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Kadane's algo to be used for optimum output.

int maxSubArray(vector<int> &nums)
{
    int currMax = 0, globalMax = nums[0], n = nums.size();

    for (int i{}; i < n; i++)
    {
        /// The idea behind making subarray sum to 0 if sum is -ve is that anyting +ve added to a negative sum 
        /// will only reduce the overall sum
        if (currMax < 0)
            currMax = 0;
        currMax += nums[i];

        globalMax = max(currMax, globalMax);
    }
    return globalMax;
}

int main(int argc, char const *argv[])
{
    vector<int> inp = {-5, -6, -3};
    cout << maxSubArray(inp);
    return 0;
}
