/**
 * @file reverseArrayInGroups.cpp
 * @author Abhishek
 * @brief 
 * Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.
Example 1:
Input:
N = 5, K = 3
arr[] = {1,2,3,4,5}
Output: 3 2 1 5 4
Explanation: First group consists of elements
1, 2, 3. Second group consists of 4,5.
 * @version 0.1
 * @date 2022-07-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n, int k)
{
    for (int i = 0; i < n; i += k)
    {
        int left = i;
 
        // to handle case when k is not multiple of n
        int right = min(i + k - 1, n - 1);
 
        // reverse the sub-array [left, right]
        while (left < right)
            swap(arr[left++], arr[right--]);
    }
}
 
// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 3;
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    reverse(arr, n, k);
 
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}
