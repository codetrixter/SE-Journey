/**
 * You are given two strings, word1 and word2. Construct a new string by merging them in alternating order,
 * starting with word1 — take one character from word1, then one from word2, and repeat this process.

If one string is longer than the other, append the remaining characters from the longer string to the end of the merged result.

Return the final merged string.

Example 1:

Input: word1 = "abc", word2 = "xyz"

Output: "axbycz"
Example 2:

Input: word1 = "ab", word2 = "abbxxc"

Output: "aabbbxxc"
Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
 */

#include <iostream>
#include <string>

using namespace std;

string mergeAlternately(string word1, string word2)
{
    string merged = "";
    int len1 = word1.length() - 1, len2 = word2.length() - 1;

    int c = 0;

    while (c <= len1 || c <= len2)
    {
        if(c <= len1)
            merged += word1.at(c);
        if(c <= len2)
            merged += word2.at(c);
        c++;
    }
    return merged;
}

int main(int argc, char const *argv[])
{
    string s = "abbxxc";
    cout << mergeAlternately("short", "longer");
    // string s2 = s.substr(2, s.length()-1-2+1);
    // cout << s2;
    return 0;
}
