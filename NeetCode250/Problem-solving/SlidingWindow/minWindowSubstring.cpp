/**
 *Given two strings s and t, return the shortest substring of s such that every character in t, 
 including duplicates, is present in the substring. If such a substring does not exist, return an empty 
 string "".

You may assume that the correct output is always unique.

Example 1:
Input: s = "OUZODYXAZV", t = "XYZ"
Output: "YXAZ"
Explanation: "YXAZ" is the shortest substring that includes "X", "Y", and "Z" from string t.

Example 2:
Input: s = "xyz", t = "xyz"
Output: "xyz"

Example 3:
Input: s = "x", t = "xy"
Output: ""

Constraints:
1 <= s.length <= 1000
1 <= t.length <= 1000
s and t consist of uppercase and lowercase English letters.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

/// @brief Sliding window approach to find minimum window substring - O(n) time complexity
/// @param s The source string to search in
/// @param t The target string containing characters that must be in the window
/// @return The minimum window substring, or empty string if none exists
string minWindow(string s, string t)
{
    // Edge case: if s is shorter than t, no valid window exists
    if(s.length() < t.length() || t.empty())
        return "";

    // countT: frequency map of characters in target string t
    // window: frequency map of characters in current window of s
    unordered_map<char, int> countT, window;
    
    // Build frequency map for target string t
    for(char c : t) {
        countT[c]++;
    }

    // minLen: tracks the minimum window length found so far
    // l: left pointer of sliding window
    // have: count of unique characters in window that match required frequency in t
    // need: count of unique characters required from t
    int minLen = INT_MAX;
    int l = 0, have = 0, need = countT.size();  // need should be unique chars, not length
    pair<int, int> substr = {-1, -1};  // stores the start and end indices of minimum window

    // Expand window by moving right pointer
    for(int r{}; r < s.length(); r++)
    {
        // Add current character to window
        char c = s[r];
        window[c]++;

        // If current character is in t and we now have the required frequency,
        // increment the count of satisfied unique characters
        if(countT.count(c) && window[c] == countT[c])
            have++;
    
        // Contract window from left while all required characters are present
        while(have == need)
        {
            // Update minimum window if current window is smaller
            if((r - l + 1) < minLen)
            {
                minLen = r - l + 1;
                substr = {l, r};
            } 

            // Remove leftmost character from window
            window[s[l]]--;
            
            // If removing this character breaks the requirement, decrement have
            if(countT.count(s[l]) && window[s[l]] < countT[s[l]])
                have--;
            
            // Move left pointer to contract the window
            l++;
        }
    }

    // If no valid window was found, return empty string, otherwise return the substring
    return minLen == INT_MAX ? "" : s.substr(substr.first, minLen);
}

int main(int argc, char const *argv[])
{
    string inp = "aa";
    cout << "Input: s = \"" << inp << "\", t = \"aa\"" << endl;
    cout << "Output: \"" << minWindow(inp, "aa") << "\"" << endl;

    return 0;
}
