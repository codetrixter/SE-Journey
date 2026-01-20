/**
 *
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++)
    {
        int j = 0;
        while (j < min(prefix.length(), strs[i].length()))
        {
            if (prefix[j] != strs[i][j])
            {
                break;
            }
            j++;
        }
        prefix = prefix.substr(0, j);
    }
    return prefix;
}

int main(int argc, char const *argv[])
{
    vector<string> strs = {
        {"bad"},
        {"bad"},
        {"bank"},
        {"band"}};
    cout << longestCommonPrefix(strs);

    return 0;
}
