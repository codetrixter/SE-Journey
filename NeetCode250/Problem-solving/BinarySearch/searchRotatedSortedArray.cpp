/**
 * You are given an array of length n which was originally sorted in non-decreasing order (not necessarily with
 * distinct values). It has now been rotated between 1 and n times. For example, the array nums = [1,2,3,4,5,6]
 * might become:

[3,4,5,6,1,2] if it was rotated 4 times.
[1,2,3,4,5,6] if it was rotated 6 times.
Given the rotated sorted array nums and an integer target, return true if target is in nums, or false if it is not
present.

You must decrease the overall operation steps as much as possible.

Example 1:

Input: nums = [3,4,4,5,6,1,2,2], target = 1

Output: true
Example 2:

Input: nums = [3,5,6,0,0,1,2], target = 4

Output: false
Constraints:

1 <= nums.length <= 5000
-10,000 <= target, nums[i] <= 10,000
nums is guaranteed to be rotated at some pivot.
 */

#include <iostream>
#include <vector>

using namespace std;

//TODO, write a solution where pivot point is found and then binary search (with duplicates) is applied
bool binarySearch(vector<int> &vec, int start, int end, int target)
{
    int mid = 0;

    while (start < end)
    {
        mid = (end - start) / 2;
        if (target == vec[mid])
            return true;
        else if (target < vec[mid])
        {
            end -= mid;
        }
        else if (target > vec[mid])
        {
            start += mid + 1;
        }
    }

    return false;
}
/*
bool search(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    int size = nums.size();
    while (nums[start] >= nums[end] && start < end)
    {
        start++;
        end--;
    }
    int largest_element = start - 1;
    cout << largest_element;
    if (target >= nums[start] && target <= largest_element)
        return binarySearch(nums, 0, largest_element, target);
    else
        return binarySearch(nums, largest_element, size, target);
} */

// Neet's approach...
//TODO understand this solution.
bool neetSearch(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (nums[m] == target)
        {
            return true;
        }

        if (nums[l] < nums[m])
        { // Left portion
            if (nums[l] <= target && target < nums[m])
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        else if (nums[l] > nums[m])
        { // Right portion
            if (nums[m] < target && target <= nums[r])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        else
        {
            l++;
        }
    }

    return false;
}


int main(int argc, char const *argv[])
{
    // vector<int> inp = {2, 4, 4, 5, 6, 1, 2, 2};
    // vector<int> inp = {6, 6, 1, 3, 3, 5, 5};
    vector<int> inp = {1, 1, 2, 2, 2, 2, 3};
    int target = 3;
    // cout << neetSearch(inp, target);
    cout << std::boolalpha ;
    cout << binarySearch(inp, 0, inp.size()-1, target);
    return 0;
}
