/**
 * Given an m x n matrix of integers matrix, return a list of all elements within the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:
1 <= matrix.length, matrix[i].length <= 10
-100 <= matrix[i][j] <= 100
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    int left = 0, right = matrix[0].size();
    int top = 0, bottom = matrix.size();

    while (left < right && top < bottom)
    {
        for (int i = left; i < right; i++)
        {
            res.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i < bottom; i++)
        {
            res.push_back(matrix[i][right - 1]);
        }
        right--;
        if (!(left < right && top < bottom))
        {
            break;
        }
        for (int i = right - 1; i >= left; i--)
        {
            res.push_back(matrix[bottom - 1][i]);
        }
        bottom--;
        for (int i = bottom - 1; i >= top; i--)
        {
            res.push_back(matrix[i][left]);
        }
        left++;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> inp = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}};

    auto result = spiralOrder(inp);

    for(auto i : result)
    {
        cout << i << " ";
    }

    return 0;
}
