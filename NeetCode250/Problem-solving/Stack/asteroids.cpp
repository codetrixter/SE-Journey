/**
 *  You are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid
moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids
moving in the same direction will never meet.

Example 1:

Input: asteroids = [2,4,-4,-1]

Output: [2]
Example 2:

Input: asteroids = [5,5]

Output: [5,5]
Example 3:

Input: asteroids = [7,-3,9]

Output: [7,9]
Constraints:

2 <= asteroids.length <= 10,000.
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
 */

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

//using namespace std;

std::vector<int> asteroidCollision(std::vector<int> &asteroids)
{
    std::stack<int> active;
    for (int &a : asteroids)
    {
        while (!active.empty() && a < 0 && active.top() > 0)
        {
            int diff = a + active.top();
            if (diff < 0)
            {
                active.pop();
            }
            else if (diff > 0)
            {
                a = 0;
            }
            else
            {
                a = 0;
                active.pop();
            }
        }
        if (a != 0)
        {
            active.push(a);
        }
    }

    std::vector<int> res;

    res.reserve(active.size());

    while(!active.empty())
    {
        res.push_back(active.top());
        active.pop();
    }

    reverse(res.begin(), res.end());
        
    return res;
}

int main(int argc, char const *argv[])
{
    std::vector<int> inp = {-2, -1, 1, 2};
    auto res = asteroidCollision(inp);

    for (auto &i : res)
        std::cout << i << " ";
    return 0;
}
