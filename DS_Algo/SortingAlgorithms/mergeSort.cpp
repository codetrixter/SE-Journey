/**
 * @file MergeSort.cpp
 * @author Abhishek
 * @brief Here we explore the merge sort algorithm two ways:
 * 1- Iterative
 * 2- Recursive.
 * @version 0.1
 * @date 2022-08-27
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <cmath>

void merge(std::vector<int>& A, int l, int mid, int h)
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

    //copying elements back to the original array
    for(int s = l; s <= h; s++)
        A[s] = C[s];
}

std::vector<int> MergeSortIterative(std::vector<int> A, int n)
{
    int p, i, l, h, mid;

    for(p = 2; p <= n; p *= 2)
    {
        for(i = 0; i + p - 1 < n; i = i+p)
        {
            l = i;
            h = i + p - 1;
            mid = (l+h)/2;
            merge(A, l, mid, h);
        }
    }
    if(p/2 < n)
        merge(A, 0, p/2, n-1);

    return A;
}

void recursiveMergeSort(std::vector<int>& A, int l, int h)
{
    int mid;
    if(l < h)
    {
        mid = (l+h)/2;
        recursiveMergeSort(A, l, mid);
        recursiveMergeSort(A, mid+1, h);
        merge(A, l, mid, h);
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> inp = {8, 3, 7, 4, 9, 2, 6, 5};
    //auto out = MergeSortIterative(inp, 8);

    recursiveMergeSort(inp, 0, 7);

    for(auto item: inp)
    {
        std::cout << item << " ";
    }
    return 0;
}
//-----------------------Alternative implementation---------------
/* #include <stdio.h>
#include <stdlib.h>
using namespace std;
void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];
    for (i = l; i <= h; i++)
        A[i] = B[i];
}
void IMergeSort(int A[], int n)
{
    int p, l, h, mid, i;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
        if (n - i > p / 2)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, n - 1);
        }
    }
    if (p / 2 < n)
    {
        merge(A, 0, p / 2 - 1, n - 1);
    }
}
int main()
{
    int A[] = {11, 5, 14, 2, 6, 3, 1}, n = 7, i;
    IMergeSort(A, n);
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
} */