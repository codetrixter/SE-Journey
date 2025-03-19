/**
 *
 */
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x)
{
    int rev = 0, digit = 0, temp = x;
    if (x < 0)
        return false;
    while (temp != 0)
    {
        digit = temp % 10;
        //to make sure that the reversed number stays in the range of 32bit integer variable.
        if (rev > INT_MAX / 10 || rev == INT_MAX / 10 && digit % 10 > 7)
            return false;
        rev = rev * 10 + digit;
        temp /= 10;
    }
    if (rev == x)
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    cout << boolalpha << isPalindrome(121);
    return 0;
}
