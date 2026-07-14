/**
 * Program to insert into max heap and Min heap.
 */

#include <iostream>
#include <vector>

using namespace std;

void insertMaxHeap(vector<int>& A, int elem)
{
    A.push_back(elem);
    int pos = A.size()-1;

    while(pos > 0)
    {
        int parent = (pos-1)/2;
        if(A[pos] <= A[parent])
            break;
        swap(A[pos], A[parent]);
        pos = parent;
    }
}

void insertMinHeap(vector<int>& B, int elem)
{
    B.push_back(elem);
    int pos = B.size()-1;

    while(pos > 0)
    {
        int parent = (pos-1)/2;
        if(B[pos] >= B[parent])
            break;
        swap(B[pos], B[parent]);
        pos = parent;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> inp = {30, 20, 15, 5};
    vector<int> inpMin = {10, 20, 30, 40, 50, 60};

    // insertMaxHeap(inp, 40);
    insertMinHeap(inpMin, 5);

    for(int item : inpMin)
    {
        cout << item << " ";
    }

    return 0;
}
