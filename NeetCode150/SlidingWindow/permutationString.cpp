/**
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
    In other words, return true if one of s1's permutations is the substring of s2.

    Example 1:
    Input: s1 = "ab", s2 = "eidbaooo"
    Output: true
    Explanation: s2 contains one permutation of s1 ("ba").

    Example 2:
    Input: s1 = "ab", s2 = "eidboaoo"
    Output: false
    
    Constraints:
    1 <= s1.length, s2.length <= 104
    s1 and s2 consist of lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;

bool isPermutation(vector<int> &count)
{
    for(int i = 0; i < count.size(); i++)
    {
        if(count[i] != 0)
            return false;
    }
    return true;
}
bool checkInclusive(string &s1, string &s2)
{
    int size1 = s1.size();
    int size2 = s2.size();
    vector<int> count(26);

    if(size1 > size2)
        return false;

    for(int i = 0; i < size1; i++)
    {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }
    if(isPermutation(count))
        return true;

    for(int i = size1; i < size2; i++)
    {
        count[s2[i] - 'a']--;
        count[s2[i-size1] - 'a']++;
        if(isPermutation(count))
            return true;
    }

    return false;
}

int main(int argc, char const *argv[])
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << boolalpha << checkInclusive(s1, s2);
    return 0;
}
