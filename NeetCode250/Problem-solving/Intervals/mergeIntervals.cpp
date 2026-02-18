/**
 * Given an array of intervals where intervals[i] = [start_i, end_i], merge all overlapping intervals, and
 * return an array of the non-overlapping intervals that cover all the intervals in the input.

You may return the answer in any order.
Note: Intervals are non-overlapping if they have no common point. For example, [1, 2] and [3, 4] are
non-overlapping, but [1, 2] and [2, 3] are overlapping.

Example 1:
Input: intervals = [[1,3],[1,5],[6,7]]
Output: [[1,5],[6,7]]

Example 2:
Input: intervals = [[1,2],[2,3]]
Output: [[1,3]]

Constraints:
1 <= intervals.length <= 1000
intervals[i].length == 2
0 <= start <= end <= 1000
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> output;
    output.push_back(intervals[0]);

    for (auto &interval : intervals)
    {
        int start = interval[0];
        int end = interval[1];
        int lastEnd = output.back()[1];

        if (start <= lastEnd)
        {
            output.back()[1] = max(lastEnd, end);
        }
        else
        {
            output.push_back({start, end});
        }
    }
    return output;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> inp = {
        {1, 2},
        {2, 3},
    };

    auto result = merge(inp);

    for (auto &i : result)
    {
        cout << i[0] << ", " << i[1] << "\n";
    }
    return 0;
}
