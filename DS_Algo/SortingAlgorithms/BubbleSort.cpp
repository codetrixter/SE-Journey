/**
 * @file BubbleSort.cpp
 * @author Abhishek
 * @brief Here we access following things about the bubble sorting technique:
 * 1- Number of comparisons: O(n^2)
 * 2- Number of swaps: O(n^2)
 * 3- Whether algo is adaptive or not: originally no, but made into one.
 * 4- Whether algo is stable or not: yes because the order of duplicate elements after sorting is maintained.
 * 5- If the algo took extra memory or not: NO
 * 
 * ***NOTE: Intermediate results give the highest or largest elemnt in the data list, can be use to find out 
 * kth larget element as well.
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <array>
#include <algorithm>

void bubbleSort(std::array<int, 5>& A, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        //This flag makes this algorithm adaptive, meaning for already sorted data list, 
        //the algo will skip processing.
        bool flag = false;
        for(int j = 0; j < n-1-i; j++)
        {
            if(A[j] > A[j+1])
            {
                std::swap(A[j], A[j+1]);
                flag = true;
            }
        }
        if(!flag)
            break;
    }
}

int main(int argc, char const *argv[])
{
    std::array<int, 5> elements = {8, 5, 7, 3, 2};
    bubbleSort(elements, 5);

    for(auto i : elements)
        std::cout << i << " ";
    
    return 0;
}
