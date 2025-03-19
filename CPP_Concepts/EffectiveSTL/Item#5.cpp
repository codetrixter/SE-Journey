/**
 * *Prefer range member function of the containers to their single-element counterparts.
*/
#include <bits/stdc++.h>
using namespace std;

//***Three versions of range insertions in vector.
int main(int argc, char const *argv[])
{
    vector<int> vec{99, 99};
    const int numval = 10;
    int data[numval] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> test = {10, 20, 30, 40, 50, 60};

    vec.insert(vec.begin(), test.begin(), test.end());

    //Approach1
    //vec.insert(vec.begin(), data, data+numval);

    //Approach2
    // vector<int>::iterator insertLoc(vec.begin());
    // for(int i = 0; i < numval; i++)
    //     insertLoc = vec.insert(insertLoc,data[i]);

    //Approach3 is used to avoid following:
    vec.resize(20);
    //More times of unnecessary function calls
    //More times of elements shift
    //More frequently memory rellocations

    // copy cannot assign values to the place where nothing's there before   
    //std::copy(data, data + numval, vec.begin()+2);

    //display
    for(auto item : vec)
    {
        cout << item << " ";
    } 
    return 0;
}
