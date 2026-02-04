/**
 * Given an m x n matrix of integers matrix, if an element is 0, set its entire row and column to 0's.
You must update the matrix in-place.
Follow up: Could you solve it using O(1) space?

Example 1:
Input: matrix = [
  [0,1],
  [1,0]
]
Output: [
  [0,0],
  [0,0]
]

Example 2:
Input: matrix = [
  [1,2,3],
  [4,0,5],
  [6,7,8]
]
Output: [
  [1,0,3],
  [0,0,0],
  [6,0,8]
]
Constraints:

1 <= matrix.length, matrix[0].length <= 100
-2^31 <= matrix[i][j] <= (2^31) - 1

 */

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    unordered_set<int> rows;
    unordered_set<int> cols;

    // finding the rows and columns that need to be 0.
    for(int i{}; i < matrix.size(); i++)
    {
        for(int j{}; j < matrix[0].size(); j++)
        {
            if(matrix[i][j] == 0)
            {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    // read the rows and set the values to 0.
    for(auto i = rows.begin(); i != rows.end(); i++)
    {
        int j = 0;
        while(j < matrix[0].size())
            matrix[*i][j++] = 0;
    }

    // read the columns and set the values to 0.
    for(auto i = cols.begin(); i != cols.end(); i++)
    {
        int j = 0;
        while(j < matrix.size())
            matrix[j++][*i] = 0;
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> inp = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    setZeroes(inp);

    for(int i{}; i < inp.size(); i++)
    {
        for(int j{}; j < inp[0].size(); j++)
        {
            cout << inp[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
