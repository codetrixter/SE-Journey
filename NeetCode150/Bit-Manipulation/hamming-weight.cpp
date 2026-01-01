/**
 * 
 * You are given an unsigned integer n. Return the number of 1 bits in its binary representation.
    You may assume n is a non-negative integer which fits within 32-bits.

    Example 1:
    Input: n = 00000000000000000000000000010111
    Output: 4

    Example 2:
    Input: n = 01111111111111111111111111111101
    Output: 30
 */

#include <iostream>
#include <cstdint>

using namespace std;

int hammingWeight(uint32_t n)
{
    int res = 0;
    while(n !=0)
    {
        res += (n&1)?1:0;
        n >>= 1;
    }
    
    return res;
}

int main(int argc, char const *argv[])
{
    cout << "\n" << hammingWeight(000000101);
    return 0;
}
