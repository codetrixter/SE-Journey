/**
 * Here we will see how deletion works in Heap.
 */

#include <iostream>
#include <vector>

using namespace std;

void heapDelete(vector<int>& inp)
{
    // This is for storing all the deleted elements of heap
    vector<int> sortedheap;

    if (inp.empty()) return;

    // Replace root with last element and shrink
    inp[0] = inp.back();
    inp.pop_back();

    // Sift down to restore max-heap property
    int beg = 0;
    int size = (int)inp.size();

    while (true)
    {
        int left    = 2 * beg + 1;  // correct 0-based left child
        int right   = 2 * beg + 2;  // correct 0-based right child
        int largest = beg;

        if (left < size && inp[left] > inp[largest])
            largest = left;
        if (right < size && inp[right] > inp[largest])
            largest = right;

        if (largest == beg)         // heap property restored
            break;

        swap(inp[beg], inp[largest]);
        beg = largest;
    }
}


/// @brief This deletes the element from max heap
/// @param inp 
/// @param sortedHeap 
void heapDeleteMaxAndSort(vector<int>& inp, vector<int>& sortedHeap)
{
    if (inp.empty()) return;

    sortedHeap.push_back(inp.front());
    
    // Replace root with last element and shrink
    inp[0] = inp.back();
    inp.pop_back();

    // Sift down to restore max-heap property
    int beg = 0;
    int size = (int)inp.size();

    while (true)
    {
        int left    = 2 * beg + 1;  // correct 0-based left child
        int right   = 2 * beg + 2;  // correct 0-based right child
        int largest = beg;

        if (left < size && inp[left] > inp[largest])
            largest = left;
        if (right < size && inp[right] > inp[largest])
            largest = right;

        if (largest == beg)         // heap property restored
            break;

        swap(inp[beg], inp[largest]);
        beg = largest;
    }
}

/// @brief This deletes elements from min heap
/// @param inp 
/// @param sortedHeap 
void heapDeleteMinAndSort(vector<int>& inp, vector<int>& sortedHeap)
{
    if (inp.empty()) return;

    sortedHeap.push_back(inp.front());
    
    // Replace root with last element and shrink
    inp[0] = inp.back();
    inp.pop_back();

    // Sift down to restore max-heap property
    int beg = 0;
    int size = (int)inp.size();

    while (true)
    {
        int left    = 2 * beg + 1;  // correct 0-based left child
        int right   = 2 * beg + 2;  // correct 0-based right child
        int smallest = beg;

        if (left < size && inp[left] < inp[smallest])
            smallest = left;
        if (right < size && inp[right] < inp[smallest])
            smallest = right;

        if (smallest == beg)         // heap property restored
            break;

        swap(inp[beg], inp[smallest]);
        beg = smallest;
    }
}

int main02(int argc, char const *argv[])
{
    vector<int> inp = {40, 35, 30, 15, 10, 25, 5};

    heapDelete(inp);

    for(int item : inp)
    {
        cout << item << " ";
    }

    return 0;
}
