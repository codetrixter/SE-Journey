/**
 *You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. However, you can buy it then immediately sell it
on the same day. Also, you are allowed to perform any number of transactions but can hold at most one share
of the stock at any time.

Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4. Then buy on day 4
(price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3. Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4. Total profit is 4.

Constraints:
1 <= prices.length <= 30,000
0 <= prices[i] <= 10,000
*/

#include <iostream>
#include <vector>

using namespace std;

/// @brief buying at low and selling high each day is better than buying low and holding for 
/// minor low after a high.
/// @param prices 
/// @return maximum profits
int maxProfit(vector<int> &prices)
{
    int profit= 0;

    for(int i = 1; i < prices.size(); i++)
    {
        if(prices[i] > prices[i-1])
        {
            profit += prices[i] - prices[i-1]; 
        }
    }

    return profit;
}

int main(int argc, char const *argv[])
{
    vector<int> inp = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(inp);

    return 0;
}
