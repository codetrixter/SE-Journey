/**
 * @file revePolishNotation.cpp
 * @author Abhishek
 * @brief Evaluate the value of an arithmetic expression in Reverse Polish Notation.

    Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
    Note that division between two integers should truncate toward zero.
    It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not
    be any division by zero operation.

    Example 1:
    Input: tokens = ["2","1","+","3","*"]
    Output: 9
    Explanation: ((2 + 1) * 3) = 9

    Example 2:
    Input: tokens = ["4","13","5","/","+"]
    Output: 6
    Explanation: (4 + (13 / 5)) = 6

    Example 3:
    Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    Output: 22
    Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
    = ((10 * (6 / (12 * -11))) + 17) + 5
    = ((10 * (6 / -132)) + 17) + 5
    = ((10 * 0) + 17) + 5
    = (0 + 17) + 5
    = 17 + 5
    = 22

    Constraints:
    1 <= tokens.length <= 104
    tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;
long long doOperation(long long lhs, long long rhs, char operation)
{
    switch (operation)
    {
    case '+':
        return lhs + rhs;
    case '-':
        return lhs - rhs;
    case '*':
        return lhs * rhs;
    case '/':
        return lhs / rhs;
    default:
        return 0;
    }
}

bool isNumber(string s)
{
    try
    {
        int n = stoi(s);
        return true;
    }
    catch (exception e)
    {
        return false;
    }
}

int evalRPN(vector<string> &tokens)
{
    stack<string> s;
    for (auto i : tokens)
    {
        string cur = i;
        if (isNumber(cur))
        {
            s.push(cur);
        }
        else
        {
            char operation = cur[0];
            long long rhs = stoll(s.top());
            s.pop();
            long long lhs = stoll(s.top());
            s.pop();
            int result = doOperation(lhs, rhs, operation);
            s.push(to_string(result));
        }
    }
    return stoi(s.top());
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> ss{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    std::cout << evalRPN(ss);
    return 0;
}
