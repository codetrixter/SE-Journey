/**
 * Here we learn how to do sorting of array elements using heap sort technique.
 */

#include <iostream>
#include <vector>
#include "HeapCreation.cpp"
#include "HeapDeletion.cpp"

using namespace std;

/// @brief This uses Max heap creation and deletion logic.
/// @param inp 
/// @return sorted array in descending order.
vector<int> heapSortDesc(vector<int>& inp)
{
    vector<int> result;

    createMaxHeap(inp);

    while(!inp.empty())
    {
        heapDeleteMaxAndSort(inp, result);
    }

    return result;
}

/// @brief This uses Min heap creation and deletion logic.
/// @param inp 
/// @return sorted array in ascending order.
vector<int> heapSortAsc(vector<int>& inp)
{
    vector<int> result;

    createMinHeap(inp);

    while(!inp.empty())
    {
        heapDeleteMinAndSort(inp, result);
    }

    return result;
}

int main(int argc, char const *argv[])
{
    //vector<int> inp = {40, 35, 30, 15, 10, 25, 5};
    vector<int> inp1 = {5, 10, 15, 25, 30, 35, 40};
    vector<int> inp2 = {5, 10, 15, 25, 30, 35, 40};

    auto result = heapSortDesc(inp1);
    auto resultAsc = heapSortAsc(inp2);

    cout << "DESCENDING USING MAX HEAP" << endl;
    for(int item : result)
    {
        cout << item << " ";
    }

    cout << "ASCENDING USING MIN HEAP" << endl;

    for(int item : resultAsc)
    {
        cout << item << " ";
    }

    return 0;
}
