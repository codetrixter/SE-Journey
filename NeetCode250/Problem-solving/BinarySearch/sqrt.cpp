/**
 * You are given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
Example 1:
Input: x = 9
Output: 3

Example 2:
Input: x = 13
Output: 3

Constraints:
0 <= x <= ((2^31)-1)
*/

#include <iostream>

using namespace std;

/// @brief Typical approach where binary search is used to arrive at sqrt(n)
/// @param n 
/// @return 
int mySqrt(int n)
{
    int l = 0, r = n;
    int res = 0;

    while(l <= r)
    {
        int m = l + (r-l)/2;
        // First upcast m and then do the multiplication or else loss of precision happens.
        long long sq = static_cast<long long>(m) * m;

        if(sq < n )
        {
            l = m+1;
            res = m;
        }
        else if(sq > n)
            r = m-1;
        else    
            return m; 
    }

    return res; 
}

/// @brief //TODO: Newton's method for calculting sqrt(x)
/// @param x 
/// @return 
int mySqrtII(int x)
{

}

int main(int argc, char const *argv[])
{
    cout << mySqrt(2147395600);
    return 0;
}
