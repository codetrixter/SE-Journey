/**
 * You are given an integer array nums of size n, return an array of all the unique quadruplets
 * [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Note: [1,0,3,2] and [3,0,1,2] are considered as same quadruplets.

Example 1:
Input: nums = [3,2,3,-3,1,0], target = 3
Output: [[-3,0,3,3],[-3,1,2,3]]

Example 2:
Input: nums = [1,-1,1,-1,1,-1], target = 2
Output: [[-1,1,1,1]]

Constraints:
1 <= nums.length <= 200
-1,000,000,000 <= nums[i] <= 1,000,000,000
-1,000,000,000 <= target <= 1,000,000,000
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
    vector<vector<int>> res;
    vector<int> quad;

public:
    /// @brief Brute force solution.
    /// @param nums
    /// @param target
    /// @return vector of quadruplets with sum = target.
    /* vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> result;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int a = 0; a < n; a++)
        {
            for(int b = a + 1; b < n; b++)
            {
                for(int c = b + 1; c < n; c++)
                {
                    for(int d = c + 1; d < n; d++)
                    {
                        if(nums[a]+nums[b]+nums[c]+nums[d] == target)
                        {
                            result.insert({nums[a], nums[b], nums[c], nums[d]});
                        }
                    }
                }
            }
        }

        return vector<vector<int>>(result.begin(), result.end());
    } */

    // best possible saving here is from O(n^4)->O(n^3), where the inner 2 loops are replaced with 2 sum 
    // solution.
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return {};
        sort(nums.begin(), nums.end());
        kSum(nums, 4, 0, (long long)target);
        return res;
    }

private:
    void kSum(vector<int> &nums, int k, int start, long long target)
    {
        if (k == 2)
        {
            int l = start, r = nums.size() - 1;
            while (l < r)
            {
                long long sum = (long long)nums[l] + nums[r];
                if (sum < target)
                {
                    l++;
                }
                else if (sum > target)
                {
                    r--;
                }
                else
                {
                    quad.push_back(nums[l]);
                    quad.push_back(nums[r]);
                    res.push_back(quad);
                    quad.pop_back();
                    quad.pop_back();
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }
            return;
        }

        for (int i = start; i < nums.size() - k + 1; i++)
        {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            quad.push_back(nums[i]);
            kSum(nums, k - 1, i + 1, target - nums[i]);
            quad.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> inp = {3, 2, 3, -3, 1, 0};

    auto res = s.fourSum(inp, 3);

    for (auto &i : res)
    {
        cout << i[0] << ", " << i[1] << ",  " << i[2] << ", " << i[3];
    }
    return 0;
}
