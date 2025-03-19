/**
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that 
 * i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.

    Example 1:
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation: 
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    The distinct triplets are [-1,0,1] and [-1,-1,2].
    Notice that the order of the output and the order of the triplets does not matter.

    Example 2:
    Input: nums = [0,1,1]
    Output: []
    Explanation: The only possible triplet does not sum up to 0.

    Example 3:
    Input: nums = [0,0,0]
    Output: [[0,0,0]]
    Explanation: The only possible triplet sums up to 0.

    Constraints:
    3 <= nums.length <= 3000
    -105 <= nums[i] <= 105

    Complexity Analysis:
    Time = O(n^2)
    Space = O(n)/(1) -> depends on the sorting algorithm.
*/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> res;
    int n = nums.size();
    //return the empty vector if the size of the vector is not more than 3
    if(n < 3)
        return res;

    //sorting the vector so that duplicates can be identified easily
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < n-2; i++)
    {
        if(nums[i] > 0)
            break;

        //if duplicate found for the first position if the triplet then move ahead.
        if( i > 0 && nums[i-1] == nums[i])
            continue;
        
        int j = i+1;
        int k = n-1;

        //loop for finding the rest of the triplets
        while(j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if(sum > 0)
                k--;
            else if(sum < 0)
                j++;
            else
            {
                res.push_back({nums[i], nums[j], nums[k]});

                //handling duplicates in the second and third position of the triplets
                while(j < k && nums[j] == nums[j+1])
                    j++;
                j++;

                while(j < k && nums[k] == nums[k-1])
                    k--;
                k--;
            }
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> input = {-1, 0, 1, 2, -1, 4};
    auto result = threeSum(input);  

    for(auto i: result)
    {
        for(auto j: i)
        {
            cout << j << " "; 
        }
        cout << endl;
    }  
    return 0;
}
