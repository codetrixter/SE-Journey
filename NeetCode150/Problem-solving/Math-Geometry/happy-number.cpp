/** A non-cyclical number is an integer defined by the following algorithm:
    Given a positive integer, replace it with the sum of the squares of its digits.
    Repeat the above step until the number equals 1, or it loops infinitely in a cycle which does not include 1.
    If it stops at 1, then the number is a non-cyclical number.
    Given a positive integer n, return true if it is a non-cyclical number, otherwise return false.

    Example 1:
    Input: n = 100
    Output: true

    Explanation: 1^2 + 0^2 + 0^2 = 1

    Example 2:
    Input: n = 101
    Output: false

    Explanation:
    1^2 + 0^2 + 1^2 = 2
    2^2 = 4
    4^2 = 16
    1^2 + 6^2 = 37
    3^2 + 7^2 = 58
    5^2 + 8^2 = 89
    8^2 + 9^2 = 145
    1^2 + 4^2 + 5^2 = 42
    4^2 + 2^2 = 20
    2^2 + 0^2 = 4 (This number has already been seen)

    Constraints:

    1 <= n <= 1000
*/

#include <iostream>
#include <unordered_set>
#include <iomanip>
#include <cmath>

using namespace std;

int sumOfSquares(int n)
{
    int sum = 0;
   while(n!=0)
    {
        int rem = n%10;
        sum += pow(rem, 2);
        n = n/10;
    }
    return sum;
}

bool isHappy(int n)
{
    unordered_set<int> nums;

    while(nums.find(n) == nums.end())
    {
        nums.insert(n);
        n = sumOfSquares(n);
        if(n == 1)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    cout << boolalpha << isHappy(19);
    return 0;
}



