/**
 * @file generateParenthesis.cpp
 * @author Abhishek
 * @brief 
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

    Example 1:
    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]

    Example 2:
    Input: n = 1
    Output: ["()"]
    
    Constraints:
    1 <= n <= 8

 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> ans;
    void recurse(string s,int open,int close,int n){
        if(open==n and close==n){
            ans.push_back(s);
            return;
        }
        if(open<n)
            recurse(s+"(",open+1,close,n);
        if(close<open)
            recurse(s+")",open,close+1,n);
    }
    vector<string> generateParenthesis(int n) {
        recurse("",0,0,n);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s1;
    auto braces = s1.generateParenthesis(3);

    for(auto item: braces)
    {
        std::cout << item << " ";
    }
    return 0;
}
