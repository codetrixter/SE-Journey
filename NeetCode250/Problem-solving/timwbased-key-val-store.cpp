/**
 * Implement a time-based key-value data structure that supports:

Storing multiple values for the same key at specified time stamps
Retrieving the key's value at a specified timestamp
Implement the TimeMap class:

TimeMap() Initializes the object.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time
 timestamp.
String get(String key, int timestamp) Returns the most recent value of key if set was previously called on
 it and the most recent timestamp for that key prev_timestamp is less than or equal to the given timestamp
 (prev_timestamp <= timestamp). If there are no values, it returns "".
Note: For all calls to set, the timestamps are in strictly increasing order.

Example 1:
Input:
["TimeMap", "set", ["alice", "happy", 1], "get", ["alice", 1], "get", ["alice", 2], "set", ["alice", "sad", 3], "get", ["alice", 3]]

Output:
[null, null, "happy", "happy", null, "sad"]

Explanation:
TimeMap timeMap = new TimeMap();
timeMap.set("alice", "happy", 1);  // store the key "alice" and value "happy" along with timestamp = 1.
timeMap.get("alice", 1);           // return "happy"
timeMap.get("alice", 2);           // return "happy", there is no value stored for timestamp 2, thus we return the value at timestamp 1.
timeMap.set("alice", "sad", 3);    // store the key "alice" and value "sad" along with timestamp = 3.
timeMap.get("alice", 3);           // return "sad"
Constraints:

1 <= key.length, value.length <= 100
key and value only include lowercase English letters and digits.
1 <= timestamp <= 1000
 */

#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>
#include <memory>

using namespace std;

//-----------neets's ways------------
/* class TimeMap {
public:
    unordered_map<string, map<int, string>> m;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" : prev(it)->second;
    }
}; */

class TimeMap
{
private:
    string mKey{};
    string mValue{};
    int mTimestamp{};
    vector<map<pair<string, string>, int>> mTimeMaps;

public:
    TimeMap() = default;

    void set(string key, string value, int timestamp)
    {
        map<pair<string, string>, int> temp;
        temp[make_pair(key, value)] = timestamp;

        mTimeMaps.push_back(temp);
    }

    string get(string key, int timestamp)
    {
        // Reverse iterate through mTimeMaps to find the most recent entry
        for (auto i = mTimeMaps.rbegin(); i != mTimeMaps.rend(); ++i)
        {
            // Iterate through each map entry
            for (const auto &entry : *i)
            {
                const auto &keyValuePair = entry.first;
                int storedTimestamp = entry.second;

                // Check if the key matches and timestamp is valid
                if (keyValuePair.first == key && storedTimestamp <= timestamp)
                {
                    return keyValuePair.second; // Return the value
                }
            }
        }
        return ""; // Return empty string if no matching key found
    }
};

int main(int argc, char const *argv[])
{
    unique_ptr<TimeMap> timeMap = make_unique<TimeMap>();
    timeMap->set("alice", "happy", 1); // store the key "alice" and value "happy" along with timestamp = 1.
    cout << timeMap->get("alice", 1);  // return "happy"
    cout << timeMap->get("alice", 2);  // return "happy", there is no value stored for timestamp 2, thus we return the value at timestamp 1.
    timeMap->set("alice", "sad", 3);   // store the key "alice" and value "sad" along with timestamp = 3.
    cout << timeMap->get("alice", 3);  // return "sad"
    return 0;
}
