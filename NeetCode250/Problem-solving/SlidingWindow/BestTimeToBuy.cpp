/**
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one stock and choosing a different
    day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit,
    return 0.

    Example 1:
    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

    Example 2:
    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transactions are done and the max profit = 0.

    Constraints:
    1 <= prices.length <= 105
    0 <= prices[i] <= 104
 */

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int left = 0, n = prices.size() - 1;
    int right = left + 1;
    int profit = 0;

    if (prices.size() < 2)
        return 0;
    while ((left <= n) && (right <= n))
    {
        if (prices[left] < prices[right])
        {
            profit = max(profit, (prices[right] - prices[left]));
            right++;
        }
        else if (prices[right] < prices[left])
        {
            // profit = 0;
            left = right;
            right = left + 1;
        }
        else if (prices[left] > prices[right])
        {
            left++;
            right = left + 1;
        }
        else
        {
            left++;
            right = left + 1;
        }
    }
    return profit;
}

//------------Better Alternate approach----
// TODO
int maxProfitNew(vector<int> &prices)
{
    int min_price = prices[0];
    int max_profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        max_profit = max(max_profit, prices[i] - min_price);
        min_price = min(min_price, prices[i]);
    }
    return max_profit;
}
//------------Better Alternate approach----
int main(int argc, char const *argv[])
{
    vector<int> input = {7, 7, 6, 4, 4, 1, 8};
    cout << maxProfitNew(input);
    return 0;
}
