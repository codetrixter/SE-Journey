/**
 * You are given an integer array heights where heights[i] represents the height of the ith bar.

You may choose any two bars to form a container. Return the maximum amount of water a container can store.
Exanmple:
Input: height = [1,7,2,5,4,7,3,6]

Output: 36 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> heights) 
    {
        int areamax = 0, i = 0, j = heights.size()-1;

        while(i != j)
        {
            if(heights[i] <= heights[j])
            {
                int area = heights[i] * (j-i);
                areamax = (area > areamax)?area:areamax;
                i++;
            }
            else
            {
                int area = heights[j] * (j-i);
                areamax = (area > areamax)?area:areamax;
                j--;
            }
        }
        return areamax;
    }
};

int main(int argc, char const *argv[])
{
    Solution s1;
    cout << s1.maxArea({1,7,2,5,4,7,3,6}) << "\n";
    return 0;
}
