/**
 * @file LongestCommonPreficString.cpp
 * @author Abhishek
 * @brief 
 * Write a function to find the longest common prefix string amongst an array of strings.

    If there is no common prefix, return an empty string "".

    Example 1:
    Input: strs = ["flower","flow","flight"]
    Output: "fl"

    Example 2:
    Input: strs = ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
// Function to find the longest common prefix between two strings
string LCP(string X, string Y)
{
    int i = 0, j = 0;
    while (i < X.length() && j < Y.length())
    {
        if (X[i] != Y[j]) {
            break;
        }
 
        i++, j++;
    }
 
    return X.substr(0, i);
}
 
// Function to find the longest common prefix (LCP) between a given set of strings
string findLCP(vector<string> const &strs)
{
    string prefix = strs[0];
    for (string s: strs) {
        prefix = LCP(prefix, s);
    }
 
    return prefix;
}
 
int main()
{
    vector<string> words { "techie delight", "tech", "techie",
                        "technology", "technical" };
 
    cout << "The longest common prefix is " << findLCP(words);
 
    return 0;
}