/**
 * Given an array of intervals intervals where intervals[i] = [start_i, end_i], return the minimum number of
 * intervals you need to remove to make the rest of the intervals non-overlapping.

Note: Intervals are non-overlapping even if they have a common point. For example, [1, 3] and [2, 4] are overlapping,
but [1, 2] and [2, 3] are non-overlapping.

Example 1:
Input: intervals = [[1,2],[2,4],[1,4]]
Output: 1
Explanation: After [1,4] is removed, the rest of the intervals are non-overlapping.

Example 2:
Input: intervals = [[1,2],[2,4]]
Output: 0

Constraints:
1 <= intervals.length <= 1000
intervals[i].length == 2
-50000 <= starti < endi <= 50000
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start >= prevEnd) {
                prevEnd = end;
            } else {
                res++;
                prevEnd = min(end, prevEnd);
            }
        }
        return res;
    }

int main(int argc, char const *argv[])
{
    vector<vector<int>> inp = {
        {1, 2},
        {2, 4},
        {1, 4}
    };

    cout << eraseOverlapIntervals(inp);
    return 0;
}
