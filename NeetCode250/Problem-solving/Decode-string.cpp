/**
 * You are given an encoded string s, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being
 repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are
 well-formed, etc. There will not be input like 3a, 2[4], a[a] or a[2].

The test cases are generated so that the length of the output will never exceed 100,000.

Example 1:

Input: s = "2[a3[b]]c"

Output: "abbbabbbc"
Example 2:

Input: s = "axb3[z]4[c]"

Output: "axbzzzcccc"
Example 3:

Input: s = "ab2[c]3[d]1[x]"

Output: "abccdddx"
Constraints:

1 <= s.length <= 30
s is made up of lowercase English letters, digits, and square brackets '[]'.
All the integers in s are in the range [1, 300].
s is guaranteed to be a valid input.
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decodeString(string s)
{
    stack<char> expr;
    string result{};
    for (auto &c : s)
    {
        if (c != ']')
        {
            expr.push(c);
        }
        else if (c == ']')
        {
            string temp = "";
            while (expr.top() != '[')
            {
                temp = expr.top() + temp;
                expr.pop();
            }
            // removing the opening braket
            expr.pop();

            // fetching the number for repetetion
            // ISSUE 2: Numbers can be multi-digit (1-300 per constraints)
            // This only handles single digit numbers (0-9)
            // Need to collect all consecutive digits before '['
            int reps = 0;
            int multiplier = 1;
            while (!expr.empty() && isdigit(expr.top()))
            {
                reps = (expr.top() - '0') * multiplier + reps;
                multiplier *= 10;
                expr.pop();
            }

            // ISSUE 3: String repetition logic is wrong
            // This doubles the string (reps-1) times instead of repeating it reps times
            // Example: if reps=3, temp="ab", this gives "abab" (2x) not "ababab" (3x)
            // Should store original temp and repeat it reps times
            string originalTemp = temp;
            for (int r = 1; r < reps; r++)
            {
                temp.append(originalTemp);
            }

            // decoded express added back to stach
            for (auto &c : temp)
            {
                expr.push(c);
            }
        }
    }
    
    //convert expression back to string;
    // ISSUE 4: Logic error - while(expr.empty()) will never execute
    // Should be while(!expr.empty()) to check if stack is NOT empty
    // This means result will always be empty string
    while(!expr.empty())
    {
        result = expr.top() + result;
        expr.pop();
    }
    return result;
}

int main(int argc, char const *argv[])
{
    cout << decodeString("2[a3[b]]c");
    return 0;
}
