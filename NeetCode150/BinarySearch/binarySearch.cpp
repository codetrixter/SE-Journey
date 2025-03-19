/**
 * Given an array of integers nums which is sorted in ascending order, and an integer target, write a 
 * function to search target in nums. If target exists, then return its index. Otherwise, return -1.

    You must write an algorithm with O(log n) runtime complexity.

    Example 1:
    Input: nums = [-1,0,3,5,9,12], target = 9
    Output: 4
    Explanation: 9 exists in nums and its index is 4

    Example 2:
    Input: nums = [-1,0,3,5,9,12], target = 2
    Output: -1
    Explanation: 2 does not exist in nums so return -1
    
    Constraints:
    1 <= nums.length <= 104
    -104 < nums[i], target < 104
    All the integers in nums are unique.
    nums is sorted in ascending order.
*/
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size()-1;
    int mid = 0;

    while(low <= high)
    {
        mid = (low+high)/2;

        if(target == nums[mid])
            return mid;
        else if(target < nums[mid])
            high = mid-1;
        else if(target > nums[mid]) 
            low = mid+1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> input = {10, 3, -5, 3, 6, 22, 123};
    int target = 1;
    cout << search(input, target);
    return 0;
}
