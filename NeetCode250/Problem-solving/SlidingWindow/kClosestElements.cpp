/**
 *You are given a sorted integer array arr, two integers k and x, return the k closest integers to x in the
 array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:
|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

Example 1:
Input: arr = [2,4,5,8], k = 2, x = 6
Output: [4,5]

Example 2:
Input: arr = [2,3,4], k = 3, x = 1
Output: [2,3,4]

Constraints:
1 <= k <= arr.length <= 10,000.
-10,000 <= arr[i], x <= 10,000
arr is sorted in ascending order.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/// @brief solution with O(nlogn) complexity, using sorting and 2 pointers
/// @param arr 
/// @param k 
/// @param x 
/// @return 
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> result;
    int n = arr.size(), l = 0, r = 0, pos = 0;

    // find the position of the last element <= x
    bool found = false;
    for(int i{}; i < n; i++)
    {
        if(arr[i] <= x)
        {
            pos = i;
            found = true;
        }
        else
            break;
    }

    // assigning left and right pointers
    if(!found)
    {
        l = -1;   // all elements are greater than x
        r = 0;
    }
    else
    {
        l = pos;
        r = pos + 1;
    }

    while(k != 0)
    {
        // take left if: left is valid AND (right is out of bounds OR 
        // left is closer OR equal distance with left being smaller)
        if((l >= 0) && (r >= n || abs(arr[l]-x) <= abs(arr[r]-x)))
        {
            result.push_back(arr[l]);
            k--;
            l--;
        }
        else if(r < n)
        {
            result.push_back(arr[r]);
            k--;
            r++;
        }
    }
    
    sort(result.begin(), result.end());
    return result;
}

/// @brief //TODO: solution using only 2 pointer method
/// @param arr 
/// @param k 
/// @param x 
/// @return 
vector<int> findClosestElementsII(vector<int> &arr, int k, int x)
{

}

/// @brief //TODO: Solution using Binary Search
/// @param arr 
/// @param k 
/// @param x 
/// @return 
vector<int> findClosestElementsIII(vector<int> &arr, int k, int x)
{

}



int main(int argc, char const *argv[])
{
    vector<int> inp = {2, 3, 4};

    auto res = findClosestElements(inp, 3, 1);

    for(auto i : res)
    {
        cout << i;
    }
    return 0;
}
