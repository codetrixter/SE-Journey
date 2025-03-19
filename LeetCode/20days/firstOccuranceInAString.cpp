/**
 * @file firstOccuranceInAString.cpp
 * @author Abhishek
 * @brief
 * Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

    Example 1:
    Input: haystack = "sadbutsad", needle = "sad"
    Output: 0
    Explanation: "sad" occurs at index 0 and 6.
    The first occurrence is at index 0, so we return 0.

    Example 2:
    Input: haystack = "leetcode", needle = "leeto"
    Output: -1
    Explanation: "leeto" did not occur in "leetcode", so we return -1.

    Constraints:
    1 <= haystack.length, needle.length <= 104
    haystack and needle consist of only lowercase English characters.

    //STL equivalent:
    haystack.find(needle);
 * @version 0.1
 * @date 2022-10-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>

int strStr(std::string haystack, std::string needle)
{
    int n = needle.size();

    if (n > haystack.size())
    {
        return -1;
    }

    for (int i = 0; i <= haystack.size() - n; i++)
    {
        std::string st = haystack.substr(i, n);

        if (st == needle)
        {
            return i;
        }
    }

    return -1;
}
int main(int argc, char const *argv[])
{
    std::cout << strStr("abhishek", "sh");
    return 0;
}
