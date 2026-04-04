/**
 *We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
You call a pre-defined API int guess(int num), which returns three possible results:

0: your guess is equal to the number I picked (i.e. num == pick).
-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
Return the number that I picked.

Example 1:
Input: n = 5, pick = 3
Output: 3

Example 2:
Input: n = 15, pick = 10
Output: 10

Example 3:
Input: n = 1, pick = 1
Output: 1

Constraints:
1 <= pick <= n <= ((2^31)-1)
*/

#include <iostream>

using namespace std;

int NUM = 0;

/// @brief
/// @param  num   your guess
/// @return 	        -1 if num is higher than the picked number
///			            1 if num is lower than the picked number
///                     otherwise return 0
int guess(int num)
{
    if (num < NUM)
        return 1;
    else if (num > NUM)
        return -1;
    else
        return 0;
}

/// @brief using binary search to reach to the number in log n time.
/// @param n 
/// @return 
int guessNumber(int n)
{
    int l = 1, r = n;

    while(true)
    {
        int m = l + (r-l)/2;
        int res = guess(m);
        if(res > 0)
            l = m + 1;
        else if(res < 0)
            r = m - 1;
        else
            return m;
    }
}

int main(int argc, char const *argv[])
{
    NUM = 200;
    cout << guessNumber(100); // n must be >= NUM (the picked number)
    return 0;
}
