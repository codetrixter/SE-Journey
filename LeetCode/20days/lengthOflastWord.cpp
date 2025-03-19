/**
 * @file lengthOflastWord.cpp
 * @author Abhishek
 * @brief Given a string s consisting of words and spaces, return the length of the last word in the string.

    A word is a maximal substring consisting of non-space characters only.

    Example 1:
    Input: s = "Hello World"
    Output: 5
    Explanation: The last word is "World" with length 5.

    Example 2:
    Input: s = "   fly me   to   the moon  "
    Output: 4
    Explanation: The last word is "moon" with length 4.

    Example 3:
    Input: s = "luffy is still joyboy"
    Output: 6
    Explanation: The last word is "joyboy" with length 6.

    Constraints:
    1 <= s.length <= 104
    s consists of only English letters and spaces ' '.
    There will be at least one word in s.
 * @version 0.1
 * @date 2022-10-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{
    int count = 0, flag;
    for (int i = 0; s[i]; i++)
    {

        if (s[i] != ' ')
        {
            count++;
            flag = count;
        }
        else if (s[i] == ' ')
        {
            count = 0;
        }
    }
    return flag;
}

int main(int argc, char const *argv[])
{
    cout << lengthOfLastWord("My name is    abhishek   of world  ");
    return 0;
}
