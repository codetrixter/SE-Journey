/**
 * Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's
 * price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day
and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock
today is 2, then the span of today is 4 because starting from today, the price of the stock was less than
or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8,
then the span of today is 3 because starting from today, the price of the stock was less than or equal 8
for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.

Example 1:
Input: ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]

Output: [null, 1, 1, 1, 2, 1, 4, 6]
Explanation:
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80); // return 1
stockSpanner.next(60); // return 1
stockSpanner.next(70); // return 2
stockSpanner.next(60); // return 1
stockSpanner.next(75); // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85); // return 6

Constraints:
1 <= price <= 100,000
At most 10,000 calls will be made to next.
*/

#include <iostream>
#include <vector>

using namespace std;

class StockSpanner
{
private:
    vector<pair<int, int>> m_stock;
    vector<int> m_st;
    int span = 0;

public:
    StockSpanner()
    {
    }

    /// @brief Brute force O(n^2)
    /// @param price 
    /// @return span
    int next(int price)
    {
        m_st.push_back(price);
        
        // setting this so that loop can reverse iterate from end -1 element as the last element is the one 
        // that is inserted recently
        int i = m_st.size()-2;
        while (i >=0 && m_st[i] <= price)
        {
            i--;
        }


        return (m_st.size()-1) - i;
    }

    /// @brief Complexity O(n), since we remove the elements that have price <= current price, span is stored
    /// which keeps track of all the prices less than curr price
    /// @param price
    /// @return span
    /*  int next(int price)
     {
         span = 1;

         while(!m_stock.empty() && m_stock.back().first <= price)
         {
             span += m_stock.back().second;
             m_stock.pop_back();
         }

         m_stock.push_back(make_pair(price, span));
         return span;
     } */
};

int main(int argc, char const *argv[])
{
    StockSpanner *stockSpanner = new StockSpanner();
    cout << stockSpanner->next(100) << ", "; // return 1
    cout << stockSpanner->next(80) << ", ";  // return 1
    cout << stockSpanner->next(60) << ", ";  // return 1
    cout << stockSpanner->next(70) << ", ";  // return 2
    cout << stockSpanner->next(60) << ", ";  // return 1
    cout << stockSpanner->next(75) << ", ";  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
    cout << stockSpanner->next(85) << ", ";  // return 6
    return 0;
}
