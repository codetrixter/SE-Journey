/**
 * You are given an array of integers temperatures where temperatures[i] represents the daily temperatures on the ith day.

Return an array result where result[i] is the number of days after the ith day before a warmer temperature appears on a 
future day. If there is no day in the future where a warmer temperature will appear for the ith day, set result[i] to 0 
instead.

Example 1:

Input: temperatures = [30,38,30,36,35,40,28]

Output: [1,4,1,2,1,0,0]
Example 2:

Input: temperatures = [22,21,20]

Output: [0,0,0]
Constraints:

1 <= temperatures.length <= 1000.
1 <= temperatures[i] <= 100
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    //Brute force technique
    /* vector<int> dailyTemperatures(vector<int> temperatures) 
    {
        int i = 0, j = 0, flag = 0;
        int size = temperatures.size();
        vector<int> res(size);

        while(i < size)
        {
            j = i+1;
            if(i == size-1)
                break;
            for(; j < size; j++)
            {
                if(temperatures[j] > temperatures[i])
                {
                    res[i] = j-i;
                    i++;
                    flag = 1;
                    break;
                }
            }
            if(flag ==0)
            {
                
                i++;
            }
            flag = 0;
        }

        return res;
        
    } */

    // The idea here is to stpre temp and index both on stack and pop the stack only whena temp is found to be greater
    // than top of stack, this way we dont have to repeat the push and pops for the already traversed elements.
    vector<int> dailyTemperatures(vector<int> temperatures)
    {
        int size = temperatures.size();
        vector<int> res(size);
        stack<pair<int, int>> temps{};

        for(int i{0}; i < size; i++)
        {
            while(!temps.empty() && (temps.top().first < temperatures[i]))
            {
                auto pair = temps.top();
                temps.pop();
                res[pair.second] =  i - pair.second;
            }
            temps.push({temperatures[i], i});
        } 
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s1{};

    auto arr = s1.dailyTemperatures({30, 38, 30, 36, 35, 40, 28});

    for(auto i : arr)
    {
        cout << i << "\n";
    }
    return 0;
}
