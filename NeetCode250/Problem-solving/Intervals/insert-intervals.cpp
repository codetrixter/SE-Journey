/**
 * You are given an array of non-overlapping intervals intervals where intervals[i] = [start_i, end_i] represents the start and the end time of the ith interval.
 * intervals is initially sorted in ascending order by start_i.
You are given another interval newInterval = [start, end].

Insert newInterval into intervals such that intervals is still sorted in ascending order by start_i and also intervals still does not have any overlapping intervals.
 You may merge the overlapping intervals if needed.

Return intervals after adding newInterval.

Note: Intervals are non-overlapping if they have no common point. For example, [1,2] and [3,4] are non-overlapping, but [1,2] and [2,3] are overlapping.

Example 1:
Input: intervals = [[1,3],[4,6]], newInterval = [2,5]
Output: [[1,6]]

Example 2:
Input: intervals = [[1,2],[3,5],[9,10]], newInterval = [6,7]
Output: [[1,2],[3,5],[6,7],[9,10]]

Constraints:
0 <= intervals.length <= 1000
newInterval.length == intervals[i].length == 2
0 <= start <= end <= 1000
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> res;
    int i = 0, n = intervals.size();

    while ((i < n) && newInterval[0] > intervals[i][1])
    {
        res.push_back(intervals[i]);
        i++;
    }

    while ((i < n) && newInterval[1] >= intervals[i][0])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);

    while ((i < n))
    {
        res.push_back(intervals[i]);
        i++;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> l_intervals = {
        {1, 2},
        {3, 5},
        {9, 10}};
    vector<int> l_interval = {6, 7};

    auto result = insert(l_intervals, l_interval);

    for (auto &item : result)
    {
        cout << item[0] << item[1] << " ";
    }

    return 0;
}
