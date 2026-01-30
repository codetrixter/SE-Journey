/**
 * There are n cars traveling to the same destination on a one-lane highway.

    You are given two arrays of integers position and speed, both of length n.

    position[i] is the position of the ith car (in miles)
    speed[i] is the speed of the ith car (in miles per hour)
    The destination is at position target miles.

    A car can not pass another car ahead of it. It can only catch up to another car and then drive at the same speed as the 
    car ahead of it.
    A car fleet is a non-empty set of cars driving at the same position and same speed. A single car is also considered 
    a car fleet.
    If a car catches up to a car fleet the moment the fleet reaches the destination, then the car is considered to be 
    part of the fleet.
    Return the number of different car fleets that will arrive at the destination.

    Example 1:
    Input: target = 10, position = [1,4], speed = [3,2]
    Output: 1
    Explanation: The cars starting at 1 (speed 3) and 4 (speed 2) become a fleet, meeting each other at 10, the destination.

    Example 2:
    Input: target = 10, position = [4,1,0,7], speed = [2,2,1,1]
    Output: 3
    Explanation: The cars starting at 4 and 7 become a fleet at position 10. The cars starting at 1 and 0 never catch up to the car ahead of them. Thus, there are 3 car fleets that will arrive at the destination.

    Constraints:
    n == position.length == speed.length.
    1 <= n <= 1000
    0 < target <= 1000
    0 < speed[i] <= 100
    0 <= position[i] < target
    All the values of position are unique.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) 
{
    stack<double> fleet;

    //create a vector of pair of pos and speed of the cars
    vector<pair<int, int>> cars;
    
    for(int i{}; i < position.size(); i++)
    {
        cars.push_back({position[i], speed[i]});
    }
    sort(cars.rbegin(), cars.rend());

    for(auto& i : cars)
    {
        double intersection = static_cast<double>(target-i.first)/(i.second);
        if(fleet.empty())
        {
            fleet.push(intersection);
        }
        else if( intersection > fleet.top())
        {
            fleet.push(intersection);
        }
    }
    return fleet.size();
}

int main(int argc, char const *argv[])
{
    int target = 10;
    vector<int> pos = {6, 8};
    vector<int> speed = {3, 2};
    cout << carFleet(target, pos, speed);
    return 0;
}
