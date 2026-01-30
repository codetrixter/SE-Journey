/**
 * You are given an array of characters which represents a string s. Write a function which reverses a string.

You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["n","e","e","t"]

Output: ["t","e","e","n"]
Example 2:

Input: s = ["r","a","c","e","c","a","r"]

Output: ["r","a","c","e","c","a","r"]
Constraints:

1 <= s.length < 100,000
s[i] is a printable ascii character.

 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) 
{
    int beg = 0, end = s.size()-1;
    
    while(beg < end)
    {
        char temp = s[end];
        s[end] = s[beg];
        s[beg] = temp;
        beg++;
        end--;
    }
}


int main(int argc, char const *argv[])
{
    vector<char> str = {'a','b', 'h' ,'i', 's', 'h' ,'e', 'k'};

    reverseString(str);

    for(auto i : str)
    {
        cout << i << " ";
    }

    return 0;
}
