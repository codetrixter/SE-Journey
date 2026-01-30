/**
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
    int size_intervals = intervals.size();
    vector<vector<int>> res_intervals;

    for(int i{}; i < size_intervals; ++i)
    {
         
    }
    return res_intervals;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> l_intervals = {
        {1, 2},
        {3, 5},
        {9, 10}
    };
    vector<int> l_interval = {6, 7};

    auto result = insert(l_intervals, l_interval);

    for(auto& item : result)
    {
        cout << item[0] << "  " << item[1];
    }

    
    return 0;
}
