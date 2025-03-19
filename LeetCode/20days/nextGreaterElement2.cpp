/**
 * @file nextGreaterElement2.cpp
 * @author Abhishek
 * @brief Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

    The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find
    its next greater number. If it doesn't exist, return -1 for this number.

    Example 1:
    Input: nums = [1,2,1]
    Output: [2,-1,2]
    Explanation: The first 1's next greater number is 2;
    The number 2 can't find next greater number.
    The second 1's next greater number needs to search circularly, which is also 2.

    Example 2:
    Input: nums = [1,2,3,4,3]
    Output: [2,3,4,-1,4]

    Constraints:
    1 <= nums.length <= 104
    -109 <= nums[i] <= 109
 * @version 0.1
 * @date 2022-10-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < 2 * n - 1; i++)
    {
        while (!st.empty() and nums[st.top()] < nums[i % n])
        {
            ans[st.top()] = nums[i % n];
            st.pop();
        }
        st.push(i % n);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> temp{1, 2, 1};
    auto result = nextGreaterElements(temp);
    for(int i : result)
    {
        cout << i << " ";
    }
    return 0;
}
