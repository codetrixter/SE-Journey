/**
 * Given a string s, find the length of the longest substring without repeating characters.

    Example 1:
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.

    Example 2:
    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.

    Example 3:
    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

    Constraints:
    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.
*/

#include <bits/stdc++.h>
using namespace std;
/*
int lengthOfLongestSubstring(string s) {
        unordered_set<char> letters;

        int i = 0;
        int j = 0;

        int result = 0;

        while (j < s.size()) {
            if (letters.find(s[j]) == letters.end()) {
                letters.insert(s[j]);
                result = max(result, j - i + 1);
                j++;
            } else {
                letters.erase(s[i]);
                i++;
            }
        }

        return result;
    }
*/
// Same solution as above with the same amount of total iterations.
// Above solution: no inner loop, but the "j" variable is not increased at each iteration
// Below: inner loop increasing "i", outer loop increasing "j".

int lengthOfLongestSubstringTwo(string &s)
{
    unordered_set<char> chars;
    int maxSize = 0;
    int i = 0, j = 0;
    while (j < s.size())
    {
        while (chars.find(s[j]) != chars.end())
        {
            chars.erase(s[i]);
            ++i;
        }
        maxSize = max(maxSize, j - i + 1);
        chars.insert(s[j]);
        ++j;
    }
    return maxSize;
}
int main(int argc, char const *argv[])
{
    string inp = "abcabcabb";
    cout << lengthOfLongestSubstringTwo(inp);
    return 0;
}
