/**
 * You are given a 2D integer array matrix, return the transpose of matrix.
The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
Example 1:
Input: matrix = [
    [2,1],
    [-1,3]
]
Output: [
    [2,-1],
    [1,3]
]

Example 2:
Input: [
    [1,0,5],
    [2,4,3]
]
Output: [
    [1,2],
    [0,4],
    [5,3]
]

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
1 <= m * n <= 100,000
-1,000,000,000 <= matrix[i][j] <= 1,000,000,000
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> transpose(vector<vector<int>> &matrix)
{
    int ROWS = matrix.size(), COLS = matrix[0].size();
    vector<vector<int>> res(COLS, vector<int>(ROWS));

    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            res[c][r] = matrix[r][c];
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> inp = {
        {1, 2, 3},
        {4, 5, 6}
    };

    auto res = transpose(inp);

    for (int r = 0; r < res.size(); ++r)
    {
        for (int c = 0; c < res[0].size(); ++c)
        {
            cout << res[r][c];
        }
        cout << "\n";
    }
    return 0;
}
