/**
 * 
 */

#include <iostream>
#include <vector>  
#include <cmath> 

using namespace std;

// vector<int> plusOne(vector<int> digits) 
// {
//    int n = digits.size();
//         for (int i = n - 1; i >= 0; i--) {
//             if (digits[i] < 9) {
//                 digits[i]++;
//                 return digits;
//             }
//             digits[i] = 0;
//         }
//         vector<int> result(n + 1);
//         result[0] = 1;
//         return result;
// }

//using recursion
vector<int> plusOne(vector<int> digits) 
{
    if (digits.empty())
        return {1};

    if (digits.back() < 9) {
        digits.back() += 1;
        return digits;
    } else {
        digits.pop_back();
        vector<int> result = plusOne(digits);
        result.push_back(0);
        return result;
    }
}

    
int main(int argc, char const *argv[])
{
    auto arr = plusOne({9, 9, 9, 9, 9});
    for(auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}


   