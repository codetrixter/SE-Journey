/**
 *Given an array of meeting time interval objects consisting of start and end times
 [[start_1,end_1],[start_2,end_2],...] (start_i < end_i), determine if a person could add all meetings to
 their schedule without any conflicts.

Note: (0,8),(8,10) is not considered a conflict at 8

Example 1:
Input: intervals = [(0,30),(5,10),(15,20)]
Output: false

Explanation:
(0,30) and (5,10) will conflict
(0,30) and (15,20) will conflict

Example 2:
Input: intervals = [(5,8),(9,15)]
Output: true

Constraints:
0 <= intervals.length <= 500
0 <= intervals[i].start < intervals[i].end <= 1,000,000
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition of Interval:
class Interval
{
public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

bool canAttendMeetings(vector<Interval> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
        return a.start < b.start;
    });

    for(int i = 1; i < intervals.size(); i++)
    {
        if(intervals[i].start < intervals[i-1].end)
            return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    vector<Interval> inp = {
        Interval(0, 30),
        Interval(5, 10),
        Interval(15, 20)
    };

    cout << boolalpha << canAttendMeetings(inp);

    return 0;
}
