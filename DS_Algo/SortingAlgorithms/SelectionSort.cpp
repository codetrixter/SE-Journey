/**
 * @file SelectionSort.cpp
 * @author Abhishek
 * @brief here we explore Selection Sorting technique:
 * 1- Number of comparisons - O(n^2)
 * 2- Number of swaps - O(n)
 * 3- Adaptive: No
 * 4- Stable: No
 * 5- Extra memory usage: No
 * 
 * ***NOTE: Intermediate results are usefull and show the kth smallest elemnt in the data set.
 * @version 0.1
 * @date 2022-08-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <array>
#include <algorithm>

void selectionSort(std::array<int, 6>& A, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int j = i, k = i;
        while(j < n)
        {
            if(A[j] < A[k])
                k = j;
            j++;
        }
        std::swap(A[i], A[k]);
    }
}
int main(int argc, char const *argv[])
{
    std::array<int, 6> list = {8, 6, 3, 2, 5, 4};
    selectionSort(list, 6);

    for(auto item : list)
        std::cout << item << " ";
    return 0;
}
