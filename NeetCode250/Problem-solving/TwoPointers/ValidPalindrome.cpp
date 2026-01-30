/**
 * @file ValidPalindrome.cpp
 * @author Abhishek
 * @brief 
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

    Given a string s, return true if it is a palindrome, or false otherwise.

    Example 1:
    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.

    Example 2:
    Input: s = "race a car"
    Output: false
    Explanation: "raceacar" is not a palindrome.

    Example 3:
    Input: s = " "
    Output: true
    Explanation: s is an empty string "" after removing non-alphanumeric characters.
    Since an empty string reads the same forward and backward, it is a palindrome.
    
    Constraints:
    1 <= s.length <= 2 * 105
    s consists only of printable ASCII characters.
 * @version 0.1
 * @date 2022-09-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>

bool isPalindrome(std::string s) 
{
    int i = 0, j = s.size()-1;

    while(i < j)
    {
        while(!isalnum(s[i]) && i < j)
            i++;
        
        while(!isalnum(s[j]) && i < j)
            j--;

        if(tolower(s[i]) != tolower(s[j]))
            return false;
        i++;j--;
    }

    return true;
}
int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha << isPalindrome("0p");
    return 0;
}
