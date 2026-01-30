/**
 * Given a 32-bit unsigned integer n, reverse the bits of the binary representation of n and return the
 * result.

Example 1:
Input: n = 00000000000000000000000000010101
Output:    2818572288 (10101000000000000000000000000000)

Explanation: Reversing 00000000000000000000000000010101, which represents the unsigned integer 21,
gives us 10101000000000000000000000000000 which represents the unsigned integer 2818572288.
 */

#include <iostream>
#include <cstdint>

using namespace std;

/* uint32_t reverseBits(uint32_t n)
{
    // vector<uint> inp
    return n;
} */

// Neet solution..
uint32_t reverseBits(uint32_t n)
{
    uint32_t res = 0;
    for (int i = 0; i < 32; i++)
    {
        uint32_t bit = (n >> i) & 1;    //This is for extracting the right most bit of the binary no.
        res += (bit << (31 - i));   //This is to put the extracted bit at the left most place for reversing the no.
    }
    return res;
}

int main(int argc, char const *argv[])
{
    uint32_t inp = 0b000000000000000000000000110010;

    // uint32_t bit = (inp >> 1) & 1;
    // cout << bit;

    cout << reverseBits(inp);
    return 0;
}
