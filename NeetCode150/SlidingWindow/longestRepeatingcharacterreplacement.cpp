/**
 * You are given a string s consisting of only uppercase english characters and an integer k. You can choose up to k 
 * characters of the string and replace them with any other uppercase English character.
   After performing at most k replacements, return the length of the longest substring which contains only one distinct 
   character.

    Example 1:
    Input: s = "XYYX", k = 2

    Output: 4
    Explanation: Either replace the 'X's with 'Y's, or replace the 'Y's with 'X's.

    Example 2:
    Input: s = "AAABABB", k = 1

    Output: 5
    Constraints:

    1 <= s.length <= 1000
    0 <= k <= s.length

    //! So the logic here is to look for a substring in the original string and store its characters in the hash map along 
    //! with its frequencies and constantly check below condition untill string length gets finished .
    
    //! --> sub string length - max frequent character <= k 
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <math.h>

 class Solution
 {
    public:
        int characterReplacement(std::string s1, int k)
        {
            std::unordered_map<char, int> substrFreq{};
            int res = 0;

            int l=0, maxf=0;

            for(int r = 0; r < s1.size(); r++)
            {
                substrFreq[s1[r]]++;
                maxf = std::max(maxf, substrFreq[s1[r]]);

                while(((r - l + 1) - maxf) > k)
                {
                    substrFreq[s1[l]]--;
                    l++;
                }

                res = std::max(res, r-l+1);
            }

            return res;
        }
 };

 int main(int argc, char const *argv[])
 {
    Solution sol;
    std::cout << sol.characterReplacement("AAABABB", 1);
    return 0;
 }
 