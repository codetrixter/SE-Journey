/**
 * 
 * Given a square n x n matrix of integers matrix, rotate it by 90 degrees clockwise.

    You must rotate the matrix in-place. Do not allocate another 2D matrix and do the rotation.

    Example 1:
    Input: matrix = [
    [1,2],
    [3,4]
    ]

    Output: [
    [3,1],
    [4,2]
    ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
    void rotate(vector<vector<int>>& matrix)
    {
        int l = 0, r = matrix.size()-1;
        
        while(l < r)
        {
            
            for(int i{}; i < (r-l); i++)
            {
                int t = l, b = r;
                //update top-left matrix element by keeping it in temp and updating it with bottom-left
                int topleft = matrix[t][l+i];
                matrix[t][l+i] = matrix[b-i][l];

                //update bottom-left with bottom-right
                matrix[b-i][l] = matrix[b][r-i];

                //update bottom-right with top-right
                matrix[b][r-i] = matrix[t+i][r];

                //update top-right with top-left
                matrix[t+i][r] = topleft;
            }
            l += 1;
            r -= 1;
        }
    }

    //Another way to do this is to do an inverse and transpose of the matrix which gives the same result.
    //TODO
};

int main(int argc, char const *argv[])
{
    Solution s1;
    vector<vector<int>> matrix = {
        {1,  2,  3,  4,  5},
        {16, 17, 18, 19, 6},
        {15, 24, 25, 20, 7},
        {14, 23, 22, 21, 8},
        {13, 12, 11 ,10, 9}
    };

    s1.rotate(matrix);

    for(auto i : matrix)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
