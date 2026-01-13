/**
 * Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards 
 * have gone and will come back in h hours.

    Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and 
    eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and 
    will not eat any more bananas during this hour.
    Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
    Return the minimum integer k such that she can eat all the bananas within h hours.

    Example 1:
    Input: piles = [3,6,7,11], h = 8
    Output: 4

    Example 2:
    Input: piles = [30,11,23,4,20], h = 5
    Output: 30

    Example 3:
    Input: piles = [30,11,23,4,20], h = 6
    Output: 23
    
    Constraints:
    1 <= piles.length <= 104
    piles.length <= h <= 109
    1 <= piles[i] <= 109
*/
#include <bits/stdc++.h>
using namespace std;

int minEatingBananas(vector<int>& piles, int h)
{
    /* int n = piles.size();

    int low = 1, high = 0;
    for(int i = 0; i < n; i++)
        high = max(high, piles[i]);

    int result = high;

    while(low <= high)
    {
        //k is the mid element which willl decide the rate of eating bananas.
        int k = low + (high-low)/2;
        long int hours = 0;

        //scanning through whole input piles to see if the selected k(rate) is min enough
        for(auto &i : piles)
            hours += ceil(double(piles[i]/k));

        if(hours <= h)
        {
            result = min(result, k);
            high = k-1;
        }
        else    
            low = k+1;
    }
    return result; */

    //---------------------
    int n = piles.size();
        
        int low = 1;
        int high = 0;
        for (int i = 0; i < n; i++) {
            high = max(high, piles[i]);
        }
        
        int result = high;
        
        while (low <= high) {
            int k = low + (high - low) / 2;
            long int hours = 0;
            for (int i = 0; i < n; i++) {
                hours += ceil((double) piles[i] / k);
            }
            if (hours <= h) {
                result = min(result, k);
                high = k - 1;
            } else {
                low = k + 1;
            }
        }
        
        return result;
    //----------------------------
}
int main(int argc, char const *argv[])
{
    vector<int> input = {3, 6, 7, 11};
    int h = 8;
    cout << minEatingBananas(input, h);
    return 0;
}
