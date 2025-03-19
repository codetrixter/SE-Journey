/**
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order
 * of the non-zero elements.

    Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1

Follow up: Could you minimize the total number of operations done?
*/
#include <iostream>
#include <vector>

void moveZeroes(std::vector<int> &nums)
{
    int i = 0, k = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[k++] = nums[i];
        }
    }
    for (; k < nums.size(); k++)
    {
        nums[k] = 0;
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> input = {0, 1, 0, 3, 0, 0, 12, 0, 0};
    moveZeroes(input);
    for(auto& item : input)
    {
        std::cout << item << " ";
    }
    return 0;
}
