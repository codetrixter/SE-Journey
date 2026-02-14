/**
 * You are given an array of length n which was originally sorted in ascending order. It has now been rotated between 1 and n times. For example, the
 * array
 * nums = [1,2,3,4,5,6] might become:

[3,4,5,6,1,2] if it was rotated 4 times.
[1,2,3,4,5,6] if it was rotated 6 times.
Given the rotated sorted array nums and an integer target, return the index of target within nums, or -1 if it is not present.
You may assume all elements in the sorted rotated array nums are unique,
A solution that runs in O(n) time is trivial, can you write an algorithm that runs in O(log n) time?

Example 1:
Input: nums = [3,4,5,6,1,2], target = 1
Output: 4

Example 2:
Input: nums = [3,5,6,0,1,2], target = 4\
Output: -1

Constraints:
1 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-1000 <= target <= 1000
All values of nums are unique.
nums is an ascending array that is possibly rotated.
 */

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &nums, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (nums[mid] == target)
            return mid;

        if (target > nums[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    int s = 0, e = nums.size() - 1, m = 0;

    // find the pivot element around which the roatation is done.
    while (s < e)
    {
        m = (s + e) / 2;

        if (nums[m] > nums[e])
            s = m + 1;
        else
            e = m;
    }

    int pivot = s;

    // doing binary search on both sides of the pivot element.
    int result = binarySearch(nums, target, 0, pivot - 1);
    if (result != -1)
        return result;

    return binarySearch(nums, target, pivot, nums.size() - 1);
}

int main(int argc, char const *argv[])
{
    vector<int> inp = {3, 5, 6, 0, 1, 2};
    cout << search(inp, 1);

    return 0;
}
