/**
 *You are given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "101", b = "10"
Output: "111"

Example 2:
Input: a = "10010", b = "111"
Output: "11001"

Constraints:
1 <= a.length, b.length <= 10,000
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addBinary(string a, string b)
{
    string result = "";
    int carry = 0;
    int n1 = a.length() - 1, n2 = b.length() - 1;

    while (n1 >= 0 || n2 >= 0 || carry)
    {
        int sum = carry;
        if (n1 >= 0)
        {
            sum += a[n1] - '0';
            n1--;
        }
        if (n2 >= 0)
        {
            sum += b[n2] - '0';
            n2--;
        }
        result += ('0' + sum % 2);
        carry = sum / 2;
    }

    // Result was built LSB-first, so reverse it
    reverse(result.begin(), result.end());
    return result;
}

int main(int argc, char const *argv[])
{
    cout << addBinary("111", "111");
    return 0;
}
