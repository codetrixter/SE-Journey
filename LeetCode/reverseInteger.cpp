/**
 * Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go
 * outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

    Example 1:
    Input: x = 123
    Output: 321

    Example 2:
    Input: x = -123
    Output: -321

    Example 3:
    Input: x = 120
    Output: 21

    Constraints:
    -231 <= x <= 231 - 1
*/
#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    int res = 0;
    while (x != 0)
    {
        int digit = x % 10;
        x = x / 10;
        //We need to make sure that after reversing the value does not gets bigger than range of int.
        if (res > INT_MAX / 10 || res == INT_MAX / 10 && digit >= INT_MAX % 10)
            return 0;
        else if (res < INT_MIN / 10 || res == INT_MIN / 10 && digit <= INT_MIN % 10)
            return 0;
        res = res * 10 + digit;
    }
    return res;
}

//---------Alternate working within range------
/* int reverse(int x)
{
    int reverseNumber = 0;
    while (x != 0)
    {
        int remainder = x % 10;
        if ((reverseNumber > INT_MAX / 10) || ((reverseNumber == INT_MAX / 10) && (remainder > 7)))
            return 0;
        if ((reverseNumber < INT_MIN / 10) || ((reverseNumber == INT_MIN / 10) && (remainder < -8)))
            return 0;
        reverseNumber = reverseNumber * 10 + remainder;
        x = x / 10;
    }
    return reverseNumber;
} */

//-----------------------------------------------

int main(int argc, char const *argv[])
{
    cout << reverse(123);
    return 0;
}
