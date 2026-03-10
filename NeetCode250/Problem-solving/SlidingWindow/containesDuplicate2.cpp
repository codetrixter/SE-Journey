/**
 *You are given an integer array nums and an integer k, return true if there are two distinct indices i and
 j in the array such that nums[i] == nums[j] and abs(i - j) <= k, otherwise return false.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [2,1,2], k = 1
Output: false

Constraints:
1 <= nums.length <= 100,000
-1,000,000,000 <= nums[i] <= 1,000,000,000
0 <= k <= 100,000
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

/// @brief Trivial case, Brute force
/// @param nums 
/// @param k 
/// @return true/false
/* bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    for(int i{}; i < nums.size(); i++)
    {
        for(int j = i+1; j < nums.size(); j++)
        {
            if(nums[i] == nums[j] && abs(i-j) <= k)
                return true;
        }
    }
    return false;
} */

/// @brief using haskmap
/// @param nums 
/// @param k 
/// @return true/false
/* bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> lmap;

    for(int i{}; i < nums.size(); i++)
    {
        if((lmap.find(nums[i]) != lmap.end()) && i-lmap[nums[i]] <=k)
            return true;
        lmap[nums[i]] = i;
    }
    return false;
} */

/// @brief using hash set
/// @param nums 
/// @param k 
/// @return 
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_set<int> lset;
    int l = 0;

    for(int r{}; r < nums.size(); r++)
    {
        if(r-l > k)
        {
            lset.erase(nums[r]);
            l++;
        }

        if(lset.find(nums[r]) != lset.end())
            return true;
        
        lset.insert(nums[r]);
    }
    
    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> inp = {1, 2, 3, 1};

    cout << boolalpha << containsNearbyDuplicate(inp, 3);

    return 0;
}
