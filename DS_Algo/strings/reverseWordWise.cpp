/**
 * *Write a program to reverse the string word wise.
 * 
 * !Using stack this problem became easy to solve.
*/

#include <iostream>
#include <string>
#include <stack>

void reverseString(std::string& input)
{
    std::stack<std::string> words;
    std::string temp;
    std::string reverse;
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] != ' ')
        {
            temp += input[i];
        }
        else
        {
            words.push(temp);
            temp = "";
        }
    }

    //pushing last word on the stack
    words.push(temp);
    int limit = 1;
    while(limit < words.size())
    {
        reverse += words.top();
        reverse +=" ";
        words.pop();
    }
    //concatenating last string without adding extra space.
    reverse += words.top();


    std::cout << reverse;
}

int main(int argc, char const *argv[])
{
    std::string s = "My name is Abhishek";
    reverseString(s);
    return 0;
}
