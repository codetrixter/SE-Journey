/**
 * You are given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

Example 1:

Input: nums = [10,9,1,1,1,2,3,1]

Output: [1,1,1,1,2,3,9,10]
Example 2:

Input: nums = [5,10,2,1,3]

Output: [1,2,3,5,10]
Constraints:

1 <= nums.length <= 50,000.
-50,000 <= nums[i] <= 50,000
 */

#include <iostream>
#include <vector>

using namespace std;

// we are goig to use quick sort for sorting the array since it has O(n*logn) complexity.

void swap(int &a, int &b)
{
    int temp = 0;
    temp = b;
    b = a;
    a = temp;
}

int partition(vector<int> &A, int l, int h)
{
    int i = l, j = h, pivot = A[l];

    while (i < j)
    {
        while (A[i] <= pivot)
            i++;

        while (A[j] > pivot)
            j--;

        if (i < j)
            swap(A[i], A[j]);
    }

    // Moving pivot element to the sorted location.
    swap(A[l], A[j]);

    return j;
}

void quicksort(vector<int> &A, int l, int h)
{
    int partition_position = 0;
    if (l < h)
    {
        partition_position = partition(A, l, h);
        // will sort the element of all left most elements of partition position
        quicksort(A, l, partition_position - 1);
        // will sort the elemenst of right most elements of partition position
        quicksort(A, (partition_position + 1), h);
    }
}

vector<int> sortArray(vector<int> &input)
{
    input.push_back(__INT32_MAX__);

    quicksort(input, 0, input.size() - 1);

    input.pop_back();
    return input;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {10, 9, 1, 1, 1, 2, 3, 1};
    auto res = sortArray(v);

    for (auto &i : v)
    {
        cout << i << " ";
    }

    return 0;
}
