/**
 *You are given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner
(row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside
the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.
Example 1:

Input: ["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]

Output: [null, 8, 11, 12]
Explanation:
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
-10,000 <= matrix[i][j] <= 10,000
0 <= row1 <= row2 < m
0 <= col1 <= col2 < n
At most 10,000 calls will be made to sumRegion.
*/

#include <iostream>
#include <vector>

using namespace std;

/// @brief O(n^2) solution
/* class NumMatrix
{
private:
    vector<vector<int>> m_matrix;
public:
    NumMatrix(vector<vector<int>> &matrix):
    m_matrix{matrix}
    {
    }

    // Trivial n^2 solution
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = 0;
        for(int row = row1; row <= row2; row++)
        {
            for(int col = col1; col <= col2; col++)
            {
                sum += m_matrix[row][col];
            }
        }

        return sum;
    }
}; */

/// @brief 1D Prefix sum solution O(n)
/// Time Complexity: Constructor O(m*n), sumRegion O(m) where m = rows, n = cols
/// Space Complexity: O(m*n) for storing prefix sums
class NumMatrix {
private:
    // Store cumulative sum for each row from left to right
    // prefixSum[i][j] = sum of elements from matrix[i][0] to matrix[i][j]
    vector<vector<int>> prefixSum;

public:
    // Constructor: Precompute prefix sums for each row
    // This allows us to calculate any row sum in O(1) time
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        prefixSum = vector<vector<int>>(rows, vector<int>(cols, 0));

        // Build prefix sum array for each row independently
        for (int row = 0; row < rows; row++) {
            // First element is just the matrix value itself
            prefixSum[row][0] = matrix[row][0];
            
            // For each subsequent column, add current element to previous prefix sum
            // prefixSum[row][col] = sum of all elements from column 0 to col in this row
            for (int col = 1; col < cols; col++) {
                prefixSum[row][col] = prefixSum[row][col - 1] + matrix[row][col];
            }
        }
    }

    // Calculate sum of rectangle region in O(m) time where m = number of rows
    // Key insight: Using prefix sums, we can get sum of any contiguous segment in a row in O(1)
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        
        // Iterate through each row in the region
        for (int row = row1; row <= row2; row++) {
            // For this row, we need sum from col1 to col2
            // Using prefix sum: sum(col1 to col2) = prefixSum[col2] - prefixSum[col1-1]
            if (col1 > 0) {
                // Subtract the prefix sum before col1 to get sum of range [col1, col2]
                res += prefixSum[row][col2] - prefixSum[row][col1 - 1];
            } else {
                // If col1 is 0, the prefix sum at col2 is already our answer
                res += prefixSum[row][col2];
            }
        }
        return res;
    }
};

/// @brief 2D Prefix sum O(1) solution, with preping the matrix taking O(n^2) time.
/* class NumMatrix {
private:
    vector<vector<int>> sumMat;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        sumMat = vector<vector<int>>(ROWS + 1, vector<int>(COLS + 1, 0));

        for (int r = 0; r < ROWS; r++) {
            int prefix = 0;
            for (int c = 0; c < COLS; c++) {
                prefix += matrix[r][c];
                int above = sumMat[r][c + 1];
                sumMat[r + 1][c + 1] = prefix + above;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        int bottomRight = sumMat[row2][col2];
        int above = sumMat[row1 - 1][col2];
        int left = sumMat[row2][col1 - 1];
        int topLeft = sumMat[row1 - 1][col1 - 1];
        return bottomRight - above - left + topLeft;
    }
}; */

int main(int argc, char const *argv[])
{
    vector<vector<int>> inp = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    NumMatrix *numMatrix = new NumMatrix(inp);
    cout << numMatrix->sumRegion(2, 1, 4, 3) << endl; // return 8 (i.e sum of the red rectangle)
    cout << numMatrix->sumRegion(1, 1, 2, 2) << endl; // return 11 (i.e sum of the green rectangle)
    cout << numMatrix->sumRegion(1, 2, 2, 4) << endl; // return 12 (i.e sum of the blue rectangle)

    return 0;
}
