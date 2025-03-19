/**
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the 
 * input string is valid.

    An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
    
    Example 1:
    Input: s = "()"
    Output: true

    Example 2:
    Input: s = "()[]{}"
    Output: true

    Example 3:
    Input: s = "(]"
    Output: false
    
    Constraints:
    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.
*/

#include <bits/stdc++.h>
using namespace std;

bool isOpen(char &ch)
{
    if(ch == '(' || ch == '[' || ch == '{')
        return true;
    else    
        return false;
}

bool isClosed(char &ch)
{
    if(ch == ')' || ch == ']' || ch == '}')
        return true;
    else    
        return false;
}

bool isValid(string s)
{
    stack<char> charList;
    if(s.size() < 2)
        return false;

    for(auto &i : s)
    {
        if(charList.empty() && isClosed(i))
            return false;
        else if(isOpen(i))
            charList.push(i);
        else if(!charList.empty() && isClosed(i))
        {
            if((charList.top() == '(' && i == ')') || (charList.top() == '[' && i == ']') ||
            (charList.top() == '{' && i == '}'))
                charList.pop();
            else
                return false;
        }
    }
    if(charList.empty())
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    string input = "()[]{";
    cout << boolalpha << isValid(input);
    return 0;
}
