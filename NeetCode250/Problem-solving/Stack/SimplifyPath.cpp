/**
 *You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your
 task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file
name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent
directories.
Return the simplified canonical path.

Example 1:
Input: path = "/neetcode/practice//...///../courses"
Output: "/neetcode/practice/courses"

Example 2:
Input: path = "/..//"
Output: "/"

Example 3:
Input: path = "/..//_home/a/b/..///"
Output: "/_home/a"

Constraints:
1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.
*/

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

string simplifyPath(string path)
{
    vector<string> stk;
    stringstream ss(path);
    string token;

    // getline(ss, token, '/') reads from the stringstream 'ss' into 'token'
    // using '/' as the delimiter (instead of the default '\n').
    // It splits the path by '/' and returns each segment one at a time.
    // e.g. "/..//_home/a" -> "", "..", "", "_home", "a"
    // Empty strings result from consecutive slashes like "//".
    // The while loop continues until the entire stream is consumed.
    while(getline(ss, token, '/'))
    {
        //cout << token << " ** ";

        if(token == "" || token == ".")
            continue;                   // skip empty (multiple slashes) and current dir
        else if(token == "..")
        {
            if(!stk.empty())
                stk.pop_back();         // go to parent directory
        }
        else
            stk.push_back(token);       // valid directory/file name (handles letters, digits, '_', '...' etc.)
    }

    string out = "";
    for(const string& dir : stk)
        out += "/" + dir;

    return out.empty() ? "/" : out;
}

int main(int argc, char const *argv[])
{
    string inp = "/..//_home/a/b/../.....//";

    cout << simplifyPath(inp);
    return 0;
}
