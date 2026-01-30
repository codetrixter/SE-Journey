/**
 * You are given an m x n integer matrix matrix with the following two properties:
    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.
    Given an integer target, return true if target is in matrix or false otherwise.

    You must write a solution in O(log(m * n)) time complexity.

    Example 1:
    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true

    Example 2:
    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    Output: false

    Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -104 <= matrix[i][j], target <= 104

    Time COmplexity - O(log m + log n) - O(log(m*n))
    Space Complexity - O(1)
*/
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int lowRow = 0;
    int highRow = matrix.size() - 1;
    //searching for the row which contains the element.
    while (lowRow < highRow)
    {
        int mid = lowRow + (highRow - lowRow) / 2;
        if (matrix[mid][0] == target)
        {
            return true;
        }
        if (matrix[mid][0] < target && target < matrix[mid + 1][0])
        {
            lowRow = mid;
            break;
        }
        if (matrix[mid][0] < target)
        {
            lowRow = mid + 1;
        }
        else
        {
            highRow = mid - 1;
        }
    }

    int lowCol = 0;
    int highCol = matrix[0].size() - 1;

    //search for the element in the columns.
    while (lowCol <= highCol)
    {
        int mid = lowCol + (highCol - lowCol) / 2;
        if (matrix[lowRow][mid] == target)
        {
            return true;
        }
        if (matrix[lowRow][mid] < target)
        {
            lowCol = mid + 1;
        }
        else
        {
            highCol = mid - 1;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> input = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};
    int target = 11;

    cout << boolalpha << searchMatrix(input, target);
    return 0;
}
