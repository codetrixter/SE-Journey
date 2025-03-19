/**
 * @file GroupAnagrams.cpp
 * @author Abhishek
 * @brief :
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.

    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

    Example 1:
    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

    Example 2:
    Input: strs = [""]
    Output: [[""]]

    Example 3:
    Input: strs = ["a"]
    Output: [["a"]]

 * @version 0.1
 * @date 2022-08-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
/* class Solution
{
public:
    std::vector < std::vector < std::string >> groupAnagrams(std::vector < std::string > &strs)
    {
        std::unordered_map<std::string, std::vector < std::string >> link;
        std::vector < std::vector < std::string >> result;

        for (int i = 0; i < strs.size(); i++)
        {
            std::string key = getKey(strs[i]);
            link[key].push_back(strs[i]);
        }

       for (auto it = link.begin(); it != link.end(); it++) {
            result.push_back(it->second);
        }

        return result;
    }

    std::string getKey(std::string str)
    {
        std::vector < int > encode(26);
        std::string encodeStr = "";

        for (int j = 0; j < encode.size(); j++)
            encode[str[j] - 'a']++;

        for (int j = 0; j < 26; j++)
        {
            encodeStr.append(std::to_string(encode[j] + 'a'));
        }

        return encodeStr;
    }
}; */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string key = getKey(strs[i]);
            m[key].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
private:
    string getKey(string str) {
        vector<int> count(26);
        for (int j = 0; j < str.size(); j++) {
            count[str[j] - 'a']++;
        }
        
        string key = "";
        for (int i = 0; i < 26; i++) {
            key.append(to_string(count[i] + 'a'));
        }
        return key;
    }
};

int main(int argc, char const *argv[])
{
    Solution s1{};
    std::vector < std::string > inp = {"cat", "tea", "tan", "ate", "nat"};
    auto groups = s1.groupAnagrams(inp);
    
    return 0;
}
