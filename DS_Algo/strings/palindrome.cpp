#include <iostream>
#include <string>
#include <algorithm>

void palindrome(std::string str)
{

    /* if(equal(str.begin(), str.begin() + str.size()/2, str.rbegin()))
    {
        std::cout << "palindrome";
    }
    else{
        std::cout << "not palindrome";
    } */

    //----------------------Alternate----------

    int k = str.length()-1;
    for(int i = 0; i < str.length()/2; i++)
    {
        if(str[i] != str[k])
        {
            std::cout << "not palindrome";
            return;
        }
        k--;  
    }
    std::cout << "palindrome";
}

int main(int argc, char const *argv[])
{
    
    std::string inp = "abhishe";
    palindrome(inp);
    return 0;
}
