/**
 *You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 
 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.

Return the minimum possible value of nums[n - 1].

Example 1:
Input: n = 3, x = 2
Output: 6
Explanation: nums can be [2,3,6].

Example 2:
Input: n = 5, x = 3
Output: 19
Explanation: nums can be [3,7,11,15,19].

Constraints:
1 <= n, x <= 100,000,000
 */

#include <iostream>

using namespace std;
/// @brief O(n) complexity solution
/// @param n 
/// @param x 
/// @return 
long long minEnd(int n, int x)
{
    long long res = x;

    for (int i = 0; i < n - 1; i++)
    {
        res = res + 1 | x;
    }
    return res;
}

/// @brief //TODO: O(log n) complexity solution
/// @param n 
/// @param x 
/// @return 
long long minEndII(int n, int x)
{
    long long res = x;

    return res;
}

int main(int argc, char const *argv[])
{
    cout << minEnd(3, 2);
    return 0;
}
