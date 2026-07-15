/**
 * Here we will create a heap out of a noraml given tree in array representation.
 */

#include <iostream>
#include <vector>
#include "MaxMinHeap.cpp"
using namespace std;

void createHeap(vector<int>& inp)
{
    int i = 1, len = inp.size()-1;
    if(inp.size() == 1)
        return;
    
    // create subarray with incremental values
    while (i <= len)
    {
        vector<int> subV(inp.begin(), inp.begin()+i);
        int val = inp[i];
        insertMaxHeap(subV, val);
        
        // update the max heap values back in orginal input
        for(int j = 0; j < subV.size(); j++)
            inp[j] = subV[j];

        i++;
    }
}

/**
 * Optimized heap creation using the "heapify" approach.
 * 
 * Idea: Treat the array as a complete binary tree. Every leaf node is already
 * a valid max-heap by itself. Start from the last internal (non-leaf) node
 * (index n/2 - 1) and sift-down each node up to the root.
 *
 * Why it works: sift-down restores the heap property for a subtree in O(h)
 * time. Summing over all nodes gives O(n) total — better than the O(n log n)
 * insertion-based approach.
 */
void siftDown(vector<int>& inp, int i, int n)
{
    while (true)
    {
        int largest = i;
        int left    = 2 * i + 1;
        int right   = 2 * i + 2;

        if (left  < n && inp[left]  > inp[largest]) largest = left;
        if (right < n && inp[right] > inp[largest]) largest = right;

        if (largest == i) break;   // heap property satisfied

        swap(inp[i], inp[largest]);
        i = largest;               // continue sifting down
    }
}

void createHeapOptimized(vector<int>& inp)
{
    int n = inp.size();
    // Start from the last non-leaf node and heapify each subtree bottom-up
    for (int i = n / 2 - 1; i >= 0; i--)
        siftDown(inp, i, n);
}

int main(int argc, char const *argv[])
{
    vector<int> inp = {10, 20, 30, 25, 5, 40, 35};

    createHeap(inp);

    for(int item : inp)
    {
        cout << item << " ";
    }

    return 0;
}
