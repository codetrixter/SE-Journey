/**
 * You are given an integer columnNumber, return its corresponding column title as it appears in an
 * Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
Example 1:

Input: columnNumber = 32

Output: "AF"
Example 2:

Input: columnNumber = 53

Output: "BA"
Constraints:

1 <= columnNumber <= ((2^31)-1)
 */

#include <iostream>
#include <string>

using namespace std;

class Solution
{
private:
    string col{};

public:
    string convertToTitle(int columnNumber)
    {
        if (columnNumber <= 26)
        {
            col = char('A' + columnNumber - 1) + col;
            return col;
        }
        else
        {
            int a = columnNumber / 26;
            int b = columnNumber % 26;
            col = char('A' + b - 1) + col;
            convertToTitle(a);
        }
        return col;
    }

    // More optimized solution
    string convertToTitle(int columnNumber)
    {
        if (columnNumber == 0)
        {
            return "";
        }
        int n = columnNumber - 1;
        return convertToTitle(n / 26) + char('A' + n % 26);
    }
};

int main(int argc, char const *argv[])
{
    Solution s1;
    cout << s1.convertToTitle(6666);
    return 0;
}
