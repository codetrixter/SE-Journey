/**
 * @file dailyTemperatures.cpp
 * @author Abhishek
 * @brief Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

    Example 1:
    Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]

    Example 2:
    Input: temperatures = [30,40,50,60]
    Output: [1,1,1,0]

    Example 3:
    Input: temperatures = [30,60,90]
    Output: [1,1,0]

    Constraints:
    1 <= temperatures.length <= 105
    30 <= temperatures[i] <= 100
 * @version 0.1
 * @date 2022-10-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;
vector<int> dailyTemperatures(vector<int> &temp)
{
    for (int i = 0; i < temp.size(); i++)
    {
        int j;
        for (j = i + 1; j < temp.size() && temp[i] >= temp[j]; j++)
            ;
        temp[i] = j == temp.size() ? 0 : j - i;
    }
    return temp;
}
// Alternate solution
vector<int> dailyTemperaturesAlt(vector<int> &temp)
{
    stack<pair<int, int>> st;
    for (int i = 0; i < temp.size(); i++)
    {
        while (!st.empty() && st.top().first < temp[i])
        {
            temp[st.top().second] = i - st.top().second;
            st.pop();
        }
        st.push({temp[i], i});
    }
    while (!st.empty())
    {
        temp[st.top().second] = 0;
        st.pop();
    }
    return temp;
}

int main(int argc, char const *argv[])
{
    vector<int> inp{73, 74, 75, 71, 69, 72, 76, 73};
    //auto result = dailyTemperatures(inp);
    auto result = dailyTemperaturesAlt(inp);
    for (auto i : result)
    {
        std::cout << i << " ";
    }
    return 0;
}
