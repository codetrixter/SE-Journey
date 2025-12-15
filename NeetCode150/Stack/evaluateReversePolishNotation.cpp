/**
 * You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.

    Return the integer that represents the evaluation of the expression.

    The operands may be integers or the results of other operations.
    The operators include '+', '-', '*', and '/'.
    Assume that division between integers always truncates toward zero.
    Example 1:

    Input: tokens = ["1","2","+","3","*","4","-"]

    Output: 5

    Explanation: ((1 + 2) * 3) - 4 = 5
    Constraints:

    1 <= tokens.length <= 1000.
    tokens[i] is "+", "-", "*", or "/", or a string representing an integer in the range [-100, 100].
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

int evalRPN(vector<string> tokens) {
        int result=0, count = 0;
    std::stack<int> exp{};

    while(count < tokens.size())
    {
        
        if(tokens[count] == "+")
        {
            int a = exp.top();
            exp.pop();
            int b = exp.top();
            exp.pop();
            exp.push(b+a);
        }
        else if(tokens[count] == "-")
        {
            int a = exp.top();
            exp.pop();
            int b = exp.top();
            exp.pop();
            exp.push(b-a);
        }
        else if(tokens[count] == "*")
        {
            int a = exp.top();
            exp.pop();
            int b = exp.top();
            exp.pop();
            exp.push(b*a);
        }
        else if(tokens[count] == "/")
        {
            int a = exp.top();
            exp.pop();
            int b = exp.top();
            exp.pop();
            exp.push(b/a);
        }
        else
        {
            exp.push(stoi(tokens[count]));
        }
        count++;
    }
    return exp.top();
    }

int main(int argc, char const *argv[])
{
    //std::cout << evalRPN({"1","2","+","3","*","4","-"});
    std::cout << evalRPN({"4", "13", "5", "/", "+"});
    // std::vector<std::string> ex{"1","2","+","3","*","4","-"};
    // std::cout << ex.size() << "\n";
    // std::cout << ex[1].at(0) << "\n";
    // std::cout << isdigit('+');
    return 0;
}
