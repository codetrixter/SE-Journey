/**
 *Given an integer n, count the number of 1's in the binary representation of every number in the range [0, n].

Return an array output where output[i] is the number of 1's in the binary representation of i.

Example 1:
Input: n = 4
Output: [0,1,1,2,1]

Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100

Constraints:
0 <= n <= 1000
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int n)
{
    vector<int> res(n + 1);
    for (int num = 1; num <= n; num++)
    {
        for (int32_t i = 0; i < 32; i++)
        {
            if (num & (1 << i))
            {
                res[num]++;
            }
        }
    }
    return res;
}

/// @brief //TODO: cover the alterbate ways to do this problem
/// @param n 
/// @return 
vector<int> countBits(int n)
{

}

int main(int argc, char const *argv[])
{
    auto result = countBits(10);

    cout << "[";
    for(auto i : result)
    {
        cout << i << ", " ;
    }
    cout << "]" << endl;
    return 0;
}
