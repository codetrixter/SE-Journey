/**
 * You are given a string s, return true if the s can be a palindrome after deleting at most one character from it.

A palindrome is a string that reads the same forward and backward.

Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).

Example 1:

Input: s = "aca"

Output: true
Explanation: "aca" is already a palindrome.

Example 2:

Input: s = "abbadc"

Output: false
Explanation: "abbadc" is not a palindrome and can't be made a palindrome after deleting at most one character.

Example 3:

Input: s = "abbda"

Output: true
Explanation: "We can delete the character 'd'.

Constraints:

1 <= s.length <= 100,000
s is made up of only lowercase English letters.
 */

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s1)
{
    int beg = 0, end = s1.size()-1;

    while(beg < end)
    {
        if (s1[beg] != s1[end])
        {
            return false;
        } 
        beg++;
        end--;
    }
    return true;
}

bool validPalindrome(string s) 
{
    int beg = 0, end = s.size()-1;

    while(beg < end)
    {
        if(s[beg] != s[end])
        {
            return isPalindrome(s.substr(0, beg) + s.substr(beg+1)) || 
                    isPalindrome(s.substr(0, end)+ s.substr(end+1));
        }
        beg++;
        end--;
    }

    return true;       
}

int main(int argc, char const *argv[])
{
    string s1 = "abbadc";
    string s2(s1[0], s1[2]);

    //.substr(0, 1);
    cout << s1.substr(0, 1) /* + s1.substr(2) */;
    //cout << isPalindrome("abbad");
    return 0;
}
