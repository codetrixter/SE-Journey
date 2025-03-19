/**
 * @file Merging.cpp
 * @author Abhishek
 * @brief Here we discuss about the merging procedure which is the precursor top Merge sort:
 * 1-> A - 2 10 18 20 23: B - 4 9 19 25 --> C - 2 4 9 10 18 19 20 23 25
 * @version 0.1
 * @date 2022-08-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> A, std::vector<int> B, int sizeA, int sizeB)
{
    int i, j, k;
    i = j = k = 0;
    std::vector<int> C(sizeA+sizeB);

    while(i < sizeA && j < sizeB)
    {
        if(A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
    while(i < sizeA)
        C[k++] = A[i++];
    while(j < sizeB)
        C[k++] = B[j++];

    return C;
}

std::vector<int> mergeSameArray(std::vector<int> A, int l, int mid, int h)
{
    int i = l, j = mid+1, k = l;
    std::vector<int> C(A.size());
    while(i <= mid && j <= h)
    {
        if(A[i] < A[j])
            C[k++] = A[i++];
        else
            C[k++] = A[j++];
    }
    while(i <= mid)
        C[k++] = A[i++];
    while(j <= h)
        C[k++] = A[j++];

    return C;

}

int main(int argc, char const *argv[])
{
    /* //for merging using different arrays
    std::vector<int> A = {2, 10, 18, 20, 23};
    std::vector<int> B = {4, 9, 19, 25};
    std::vector<int> result = merge(A, B, 5, 4);

    for(auto i : result)
        std::cout << i << " "; */

    /////////////////////////////////////////////////////

    //for merging using same array/ used in merge sort.
    std::vector<int> same = {2, 5, 8, 12, 3, 6, 7, 10};
    
    std::vector<int> result = mergeSameArray(same, 0, 3, 7);
    for(auto i : result)
        std::cout << i << " "; 
    
    return 0;
}
