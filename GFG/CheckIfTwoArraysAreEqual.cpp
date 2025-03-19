/**
 * @file CheckIfTwoArraysAreEqual.cpp
 * @author Abhishek
 * @brief Given two arrays A and B of equal size N, the task is to find if given arrays are equal or not. 
 * Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation) of elements 
 * may be different though.
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>
using namespace std;
 
// Returns true if arr1[0..n-1] and arr2[0..m-1]
// contain same elements.
bool areEqual(vector<long long> A, vector<long long> B, int N)
{ 
    // Sort both arrays
    sort(A.begin(), A.begin()+N);
    sort(B.begin(), B.begin()+N);
 
    // Linearly compare elements
    for (int i = 0; i < N; i++)
        if (A[i] != B[i])
            return false;
 
    // If all elements were same.
    return true;
}
 
// Driver Code
int main()
{
    vector<long long> arr1 = { 3, 5, 2, 5, 2 };
    vector<long long> arr2 = { 2, 3, 5, 5, 2 };
     
    if (areEqual(arr1, arr2, arr1.size()))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}