/**
 * You are given an array nums consisting of n elements where each element is an integer representing
 * a color:
0 represents red
1 represents white
2 represents blue
Your task is to sort the array in-place such that elements of the same color are grouped together and arranged in the order: red (0), white (1), and then blue (2).

You must not use any built-in sorting functions to solve this problem.

Example 1:
Input: nums = [1,0,1,2]
Output: [0,1,1,2]

Example 2:
Input: nums = [2,1,0]
Output: [0,1,2]

Constraints:
1 <= nums.length <= 300.
0 <= nums[i] <= 2.
Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
private:
    vector<int> nums;

public:
    void setValue(vector<int> &inp)
    {
        nums = inp;
    }

    vector<int> &getNums()
    {
        return nums;
    }
    // Trivial solution using ibuilt osrting with complexity (O)-nlogn
    /* void sortColors(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
    } */

    // algo for doing it in linear time and space using counting sort.
    void sortColors(vector<int> &nums)
    {
        // init a vector of size numms with zeros
        vector<int> count(3);

        for (int &num : nums)
        {
            count[num]++;
        }

        int index = 0;
        for (int i = 0; i < 3; i++)
        {
            while (count[i]-- > 0)
            {
                nums[index++] = i;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> inp = {0, 1, 2, 1};
    s.setValue(inp);
    s.sortColors(s.getNums());

    for (auto &i : s.getNums())
    {
        cout << i << " ";
    }
    return 0;
}
