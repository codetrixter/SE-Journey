/**
 * You are given an integer array nums sorted in non-decreasing order. Your task is to remove duplicates from nums in-place so that each element appears only once.

After removing the duplicates, return the number of unique elements, denoted as k, such that the first k elements of nums contain the unique elements.

Note:

The order of the unique elements should remain the same as in the original array.
It is not necessary to consider elements beyond the first k positions of the array.
To be accepted, the first k elements of nums must contain all the unique elements.
Return k as the final result.

Example 1:

Input: nums = [1,1,2,3,4]

Output: [1,2,3,4]
Explanation: You should return k = 4 as we have four unique elements.

Example 2:

Input: nums = [2,10,10,30,30,30]

Output: [2,10,30]
Explanation: You should return k = 3 as we have three unique elements.

Constraints:

1 <= nums.length <= 30,000
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// using extra space
/* int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res;
    res.push_back(nums[0]);

    for(int i = 1; i < n; i++)
    {
        if(nums[i] != nums[i-1])
            res.push_back(nums[i]);
    }

    return res.size();
} */

// without using extra space with O(n^2)
/* void leftShift(vector<int> &arr, int pos, int &size)
{
    for(int i = pos; i < arr.size()-1; i++)
    {
        arr[i] = arr[i+1];
    }

    arr.resize(size-1);
}

// without using extra space
int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();

    for(int i = 1; i < n; i++)
    {
        if(nums[i] == nums[i-1])
        {
            leftShift(nums, i, n);
            n--;
            i--;
        }
    }

    return nums.size();
} */

// using 2 pointers method without extra space O(n)
int removeDuplicates(vector<int> &nums)
{
    int u_pos = 0, n = nums.size();
    int size = n;

    for(int i = 1; i < n; i++)
    {
        if(nums[i] != nums[i-1])
        {
            nums[++u_pos] = nums[i];
        }
        else
            size--;
    }
    nums.resize(size);

    return size;
}

int main(int argc, char const *argv[])
{
    vector<int> inp = {1, 2, 3, 3, 3};
    cout << removeDuplicates(inp);

    for (auto &i : inp)
        cout << i << " ";

    return 0;
}
