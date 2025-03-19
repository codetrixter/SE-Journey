/**
 * @file AddToArrayForm.cpp
 * @author Abhishek
 * @brief
 * @version 0.1
 * @date 2022-10-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> addToArrayForm(vector<int> A, int K)
{
    for (int i = A.size() - 1; i >= 0 && K > 0; i--)
    {
        A[i] += K;
        K = A[i] / 10;
        A[i] %= 10;
    }
    while (K > 0)
    {
        A.insert(A.begin(), K % 10);
        K /= 10;
    }
    return A;
}
int main(int argc, char const *argv[])
{
    vector<int> vec{1, 0, 8, 3};
    auto result = addToArrayForm(vec, 23);
    for(auto i : result)
        std::cout << i << " ";

    return 0;
}
