/**
 *
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int majorityElement(vector<int> &nums)
{
    int majority = nums.size() / 2;
    unordered_map<int, int> mapp;

    for (auto &i : nums)
    {
        mapp[i] += 1;
    }

    for (auto &i : mapp)
    {
        if (i.second > majority)
            return i.first;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {5, 5, 5, 2};
    cout << majorityElement(vec);
    return 0;
}
