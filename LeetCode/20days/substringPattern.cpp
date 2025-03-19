/**
 * @file substringPattern.cpp
 * @author Abhishek
 * @brief Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

    Example 1:
    Input: s = "abab"
    Output: true
    Explanation: It is the substring "ab" twice.

    Example 2:
    Input: s = "aba"
    Output: false

    Example 3:
    Input: s = "abcabcabcabc"
    Output: true
    Explanation: It is the substring "abc" four times or the substring "abcabc" twice.

    Constraints:
    1 <= s.length <= 104
    s consists of lowercase English letters.
 * @version 0.1
 * @date 2022-10-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>

bool repeatedSubstringPattern(std::string s)
{
    int size = s.size();
    
    // trying to find the largest repeatable substring.
    for(int i = size/2; i >= 1; i--)
    {
        if(size%i == 0)
        {
            if(s.substr(0, size-i) == s.substr(i))
                return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha << repeatedSubstringPattern("cbcacbcacbca");
    return 0;
}
