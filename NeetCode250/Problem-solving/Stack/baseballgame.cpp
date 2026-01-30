/**
 *
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int calPoints(vector<string> &operations)
{
    stack<int> eval;
    int sum = 0;

    for (int i{}; i < operations.size(); i++)
    {
        if (isdigit(operations[i][0]) || operations[i][0] == '-')
            eval.push(stoi(operations[i]));
        else if (operations[i] == "C")
            eval.pop();
        else if (operations[i] == "+")
        {
            int temp = eval.top();
            eval.pop();
            int new_val = temp + eval.top();
            eval.push(temp);
            eval.push(new_val);
        }
        else if (operations[i] == "D")
            eval.push(eval.top() * 2);
    }

    while (!eval.empty())
    {
        sum += eval.top();
        eval.pop();
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    vector<string> exp = {"5","-2","4","C","D","9","+","+"};
    cout << calPoints(exp);
    return 0;
}
