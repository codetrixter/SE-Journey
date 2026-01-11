/**
 * 
 */

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

//This solution only works for limited digit size
/* bool isDigit(string num)
{
    for(int i{}; i < num.length(); i++)
    {
        if(num.at(i) >= 48 && num.at(i) <= 57)
            return true;
    }
    return false;
}

string multiply(string num1, string num2)
{
    if(num1 == "0")
        return "0";
    u_int64_t n1 = 0, n2 = 0;
    int count = 0;
    while(count < num1.length() || count < num2.length())
    {
        if(count < num1.length())
            n1 += (num1.at(count)-'0') * (pow(10, (num1.length()-1-count)));
        if(count < num2.length())
            n2 += (num2.at(count)-'0') * (pow(10, (num2.length()-1-count)));
        count++;
    }

    u_int64_t mul = n1*n2;
    u_int64_t temp = mul;
    int size = 0; 
    count = 0;
    //find the size fo the number
    while(mul > 0)
    {
        int rem = mul%10;
        mul = mul/10;
        ++size;
    }

    count = 0;
    char result[size+1];
    
    while(temp > 0)
    {
        int rem = temp%10;
        temp = temp/10;
        result[count++] = rem + '0';
    }

    result[count] = '\0';

    string res_str(result);
    reverse(res_str.begin(), res_str.end());
    return res_str;
} */

//----------------------------

string multiply(string num1, string num2) 
{
    if (num1 == "0" || num2 == "0") {
        return "0";
    }

    vector<int> res(num1.length() + num2.length(), 0);
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    for (int i1 = 0; i1 < num1.length(); i1++) {
        for (int i2 = 0; i2 < num2.length(); i2++) {
            int digit = (num1[i1] - '0') * (num2[i2] - '0');
            res[i1 + i2] += digit;
            res[i1 + i2 + 1] += res[i1 + i2] / 10;
            res[i1 + i2] %= 10;
        }
    }

    stringstream result;
    int i = res.size() - 1;
    while (i >= 0 && res[i] == 0) {
        i--;
    }
    while (i >= 0) {
        result << res[i--];
    }
    return result.str();
}

int main(int argc, char const *argv[])
{
    //multiply("12", "1234");
    cout << "Product of two string nums is : " << multiply("498828660196", "840477629533") << endl;
    return 0;
}
