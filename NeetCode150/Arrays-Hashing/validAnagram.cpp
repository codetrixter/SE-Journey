/**
 * @file validAnagram.cpp
 * @author Abhishek
 * @brief 
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the 
    original letters exactly once.
    Example 1:
    Input: s = "anagram", t = "nagaram"
    Output: true
 * @version 0.1
 * @date 2022-07-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) 
    {
        if (s.size() != t.size()) {
            return false;
        }
        
        std::vector<int> count(26);
        
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }
        
        for (int j = 0; j < t.size(); j++) {
            count[t[j] - 'a']--;
            if (count[t[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    std::string s = "god";
    std::string t = "dog";
    std::cout << std::boolalpha << sol.isAnagram(s, t);

    return 0;
}
