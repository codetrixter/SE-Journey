/**
 * You are given an array of length n which was originally sorted in ascending order. It has now been rotated between 1
 * and n times. For example, the array nums = [1,2,3,4,5,6] might become:
 *
[3,4,5,6,1,2] if it was rotated 4 times.
[1,2,3,4,5,6] if it was rotated 6 times.
Notice that rotating the array 4 times moves the last four elements of the array to the beginning. Rotating the array 6
times produces the original array.
Assuming all elements in the rotated sorted array nums are unique, return the minimum element of this array.
A solution that runs in O(n) time is trivial, can you write an algorithm that runs in O(log n) time?

Example 1:
Input: nums = [3,4,5,6,1,2]
Output: 1

Example 2:
Input: nums = [4,5,0,1,2,3]\
Output: 0

Example 3:
Input: nums = [4,5,6,7]
Output: 4

Constraints:
1 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
 */

#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int> &nums)
{
    int s = 0, e = nums.size() - 1, mid = 0, min = 10000;
    // list is sorrted and not rotated
    if (nums[s] < nums[e])
        return nums[s];

    while (s <= e)
    {
        mid = s + (e - s / 2);
        if (min > nums[mid])
            min = nums[mid];

        if (nums[s] > nums[mid])
            e = mid - 1;
        else
            s = mid + 1;
    }
    return min;
}

int main(int argc, char const *argv[])
{
    vector<int> inp = {5, 6, 7, 1, 2, 3};
    cout << findMin(inp);
    return 0;
}
