/**
 * @file addBinary.cpp
 * @author Abhishek
 * @brief Given two binary strings a and b, return their sum as a binary string.

    Example 1:
    Input: a = "11", b = "1"
    Output: "100"

    Example 2:
    Input: a = "1010", b = "1011"
    Output: "10101"

    Constraints:
    1 <= a.length, b.length <= 104
    a and b consist only of '0' or '1' characters.
    Each string does not contain leading zeros except for the zero itself.
 * @version 0.1
 * @date 2022-10-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;
string addBinary(string a, string b)
{
    int alen = a.length();
    int blen = b.length();
    int i = 0;
    int carry = 0;
    string ans = "";

    while (i < alen || i < blen || carry != 0)
    {
        int x = 0;
        if (i < alen && a[alen - i - 1] == '1')
        {
            x = 1;
        }
        int y = 0;
        if (i < blen and b[blen - i - 1] == '1')
        {
            y = 1;
        }
        ans = to_string((x + y + carry) % 2) + ans;
        carry = (x + y + carry) / 2;
        i += 1;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    std::cout << addBinary("110101", "111");
    return 0;
}
