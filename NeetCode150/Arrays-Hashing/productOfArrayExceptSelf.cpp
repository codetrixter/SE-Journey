/**
 * @file productOfArrayExceptSelf.cpp
 * @author Abhishek
 * @brief
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
    You must write an algorithm that runs in O(n) time and without using the division operation.

    Example 1:
    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]

    Example 2:
    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]

    Constraints:
    2 <= nums.length <= 105
    -30 <= nums[i] <= 30
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    **NOTE: We cannot use division operator.
 * @version 0.1
 * @date 2022-10-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, 1);

    int prefix = 1;
    for (int i = 0; i < n; i++)
    {
        result[i] = prefix;
        prefix = prefix * nums[i];
    }

    for (auto item : result)
    {
        std::cout << item << " ";
    }
    int postfix = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        result[i] = result[i] * postfix;
        postfix = postfix * nums[i];
    }

    return result;
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec = {1, 2, 3, 4};
    auto result = productExceptSelf(vec);

    for (auto item : result)
    {
        std::cout << item << " ";
    }
    return 0;
}
