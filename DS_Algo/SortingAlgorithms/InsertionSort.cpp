/**
 * @file InsertionSort.cpp
 * @author Abhishek
 * @brief Here we discuss about Insertion sorting technique with following points:
 * 1- Comparisons - O(n^2)
 * 2- Swap - O(n)
 * 3- Adaptive: yes this algo is adaptive.
 * 4- Stable: This algo is stab;e.
 * 5- This algo did not take extra memory.
 * ***NOTE: Intermediate results are of no use here, they show no pattern.
 * @version 0.1
 * @date 2022-08-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <array>
#include <algorithm>

void InsertionSortNonAdaptive(std::array<int, 5>& A, int n)
{
    for(int i = 1; i < n; i++)
    {
        int el = A[i];
        bool flag = false;
        for(int j = i; j > 0; j--)
        {
            if(A[j-1] > el)
            {
                A[j] = A[j-1];
            }
            else
            {
                A[j] = el;
                flag = true;  
            }
        }
        if(!flag)
            A[0] = el;
    }
}

/**
 * @brief Performs Insertion Sort(Adaptively)
 * 
 * @param A: array of items on which the sorting needs to be performed 
 * @param n: size of the array. 
 */
void InsertionSort(std::array<int, 5>& A, int n)
{
    for(int i = 1; i < n; i++)
    {
        int x = A[i];
        int j = i-1;
        while(j > -1 && A[j] > x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main(int argc, char const *argv[])
{
    std::array<int, 5> list = {8, 5, 7, 3, 2};
    //InsertionSort(list, 5);
    InsertionSortNonAdaptive(list, 5);

    for(auto i : list)
        std::cout << i << " ";
    return 0;
}
