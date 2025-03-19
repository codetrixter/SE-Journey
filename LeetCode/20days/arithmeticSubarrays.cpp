/**
 * @file arithmeticSubarrays.cpp
 * @author Abhishek
 * @brief 
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>
using namespace std;

vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> res;
    for (auto i = 0, j = 0; i < l.size(); ++i) {
        vector<int> n(begin(nums) + l[i], begin(nums) + r[i] + 1);
        sort(begin(n), end(n));
        for (j = 2; j < n.size(); ++j)
            if (n[j] - n[j - 1] != n[1] - n[0])
                break;
        res.push_back(j == n.size());
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> a{4, 6, 5, 9, 3, 7}, b{0, 0, 2}, c{2, 3, 5};
    auto result = checkArithmeticSubarrays(a, b, c);
    for(auto i: result)
    {
        cout << boolalpha << i << " ";
    }
    return 0;
}
