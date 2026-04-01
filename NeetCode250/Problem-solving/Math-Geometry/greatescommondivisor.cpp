/**
 *For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

You are given two strings str1 and str2, return the largest string x such that x divides both str1 and str2. If there is no such string, return "".

Example 1:
Input: str1 = "ABAB", str2 = "AB"
Output: "AB"

Example 2:
Input: str1 = "NANANA", str2 = "NANA"
Output: "NA"

Constraints:
1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.
*/

#include <iostream>
#include <string>

using namespace std;

string gcdOfStrings(string str1, string str2)
{
    int len1 = str1.size(), len2 = str2.size();

    auto isDivisor = [&](int l)
    {
        if (len1 % l != 0 || len2 % l != 0)
        {
            return false;
        }
        string sub = str1.substr(0, l);
        int f1 = len1 / l, f2 = len2 / l;
        string repeated1 = "", repeated2 = "";
        for (int i = 0; i < f1; ++i)
            repeated1 += sub;
        for (int i = 0; i < f2; ++i)
            repeated2 += sub;
        return repeated1 == str1 && repeated2 == str2;
    };

    for (int l = min(len1, len2); l > 0; l--)
    {
        if (isDivisor(l))
        {
            return str1.substr(0, l);
        }
    }

    return "";
}

int main(int argc, char const *argv[])
{
    cout << gcdOfStrings("MAMAMAMAMAMA", "MAMA");
    return 0;
}
