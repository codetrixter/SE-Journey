/**
 *Given an array of meeting time interval objects consisting of start and end times
 [[start_1,end_1],[start_2,end_2],...] (start_i < end_i), find the minimum number of rooms required to
 schedule all meetings without any conflicts.

Note: (0,8),(8,10) is NOT considered a conflict at 8.

Example 1:
Input: intervals = [(0,40),(5,10),(15,20)]
Output: 2
Explanation:
room1: (0,40)
room2: (5,10),(15,20)

Example 2:
Input: intervals = [(4,9)]
Output: 1

Constraints:
0 <= intervals.length <= 500
0 <= intervals[i].start < intervals[i].end <= 1,000,000
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

/// @brief using 2 pointer method:
/// Create two arrays:
/// start → all meeting start times, sorted
/// end → all meeting end times, sorted
/// Initialize:
/// s = 0 → pointer for start times
/// e = 0 → pointer for end times
/// count = 0 → current number of ongoing meetings
/// res = 0 → maximum number of rooms needed
/// While there are still meetings to process (s < number of meetings):
/// If start[s] < end[e]:
/// a new meeting starts before the earliest one ends
/// increment count (need one more room)
/// move s forward
/// Else:
/// a meeting has ended
/// decrement count (a room is freed)
/// move e forward
/// Update res = max(res, count) after each step.
/// Return res.
/// @param intervals 
/// @return 
int minMeetingRooms(vector<Interval> &intervals)
{
    int count = 0, res = 0, s = 0, e = 0;
    vector<int> vstart, vend;

    for(auto i: intervals)
    {
        vstart.push_back(i.start);
        vend.push_back(i.end);
    }

    sort(vstart.begin(), vstart.end());
    sort(vend.begin(), vend.end());

    while(s < intervals.size())
    {
        if(vstart[s] < vend[e])
        {
            count++;
            s++;
        }
        else
        {
            count--;
            e++;
        }

        res = max(res, count);
    }

    return res;
}

int main(int argc, char const *argv[])
{
    vector<Interval> inp = {
        Interval(0, 40),
        Interval(5, 10),
        Interval(15, 20)};

    cout << minMeetingRooms(inp);
    return 0;
}
