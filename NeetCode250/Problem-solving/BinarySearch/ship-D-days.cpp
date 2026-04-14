/**
 *A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages
on the conveyor belt (in the order given by weights). It is not allowed to load weight more than the
maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt
being shipped within days days.

Example 1:
Input: weights = [2,4,6,1,3,10], days = 4
Output: 10
Explanation:
1st day: [2]
2nd day: [4,6]
3rd day: [1,3]
4th day: [10]

Example 2:
Input: weights = [1,2,3,4,5], days = 5
Output: 5
Explanation:
1st day: [1]
2nd day: [2]
3rd day: [3]
4th day: [4]
5th day: [5]

Example 3:
Input: weights = [1,5,4,4,2,3], days = 3
Output: 8

Explanation:
1st day = [1,5]
2nd day = [4,4]
3rd day = [2,3]

Constraints:
1 <= days, weights.length <= 50,000
1 <= weights[i] <= 500

//! INTUITION:
Here the brute force way to solve is:
1- min weight of a ship that we need to transport the goods is the max weight of a good i.e so that at least that 
particular good can be transported.
2- secondly using this min weight as the starting point we will now iterate over the array and find if this weight
is enough to carry all goods in x days, if not then we increment weight of the ship by and repeat till we find the 
min weight that we need.

Now since we are doing a linera search in the range from [min weight, sum of weights of all goods], we can arrive
at the correct value quicker by doing binary search.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>    // std::reduce, std::ranges::max
#include <ranges>     // std::views
#include <span>       // std::span

using namespace std;

int shipWithinDays(vector<int> &weights, int days)
{
    int SUM = 0, MAX = 0, m = 0;
    // find the sum of all weights (upper bound for binary search)
    for(auto i : weights)
    {
        MAX += i;
    }

    // find the max weight (lower bound for binary search)
    for(auto i : weights)
    {
        if(i > SUM)
            SUM = i;
    }


    while(SUM <= MAX)
    {
        m = (SUM + MAX)/2;
        int s = 0, c = 0;
        // find for the given weight i.e m, whether the condition holds true 
        for(int i = 0; i < weights.size(); i++)
        {
            s += weights[i];

            if(s > m)
            {
                c++;
                s = weights[i];
            }
        }
        if(c+1 > days)
            SUM = m+1;
        else   // c+1 <= days: m is a valid capacity, search left for a smaller one
            MAX = m-1;
    }
    return SUM;
}

// ─────────────────────────────────────────────
//  C++20 optimized version
// ─────────────────────────────────────────────

// Concept: ensure the container holds an integral element type
template<typename R>
concept IntegralRange = std::ranges::forward_range<R> &&
                        std::integral<std::ranges::range_value_t<R>>;

// Returns the minimum ship capacity needed to ship all weights within `days`.
int shipWithinDays_v2(std::span<const int> weights, int days)
{
    // C++20 ranges: bounds computed in one pass each, no raw loops
    const int lo = std::ranges::max(weights);               // lower bound: heaviest package
    const int hi = std::reduce(weights.begin(), weights.end()); // upper bound: total weight

    // Feasibility check as a named lambda (captures nothing, easily testable)
    // Returns true if capacity `cap` is enough to ship everything within `days`.
    auto canShip = [&weights, days](int cap) -> bool {
        int daysNeeded = 1, load = 0;
        for (int w : weights) {
            if (load + w > cap) { ++daysNeeded; load = 0; }
            load += w;
        }
        return daysNeeded <= days;
    };

    // Standard binary search on the answer space [lo, hi]
    // std::partition_point finds the first position where canShip becomes true.
    auto searchRange = std::views::iota(lo, hi + 1);
    auto it = std::ranges::partition_point(searchRange, [&](int cap) {
        return !canShip(cap);   // false once canShip(cap) is true
    });

    return *it;
}

int main(int argc, char const *argv[])
{
    vector<int> inp = {1, 2, 3, 4, 5};
    int days = 2;

    cout << "Original : " << shipWithinDays(inp, days)    << "\n";
    cout << "C++20 v2 : " << shipWithinDays_v2(inp, days) << "\n";

    // Additional test cases
    vector<int> t1 = {2,4,6,1,3,10}; cout << shipWithinDays_v2(t1, 4) << "\n"; // 10
    vector<int> t2 = {1,5,4,4,2,3};  cout << shipWithinDays_v2(t2, 3) << "\n"; // 8

    return 0;
}
