/**
 * Given two integers a and b, return the sum of the two integers without using the + and - operators.

Example 1:
Input: a = 1, b = 1
Output: 2

Example 2:
Input: a = 4, b = 7
Output: 11

Constraints:
-1000 <= a, b <= 1000
 */

#include <iostream>

using namespace std;

int getSum(int a, int b)
{
    // Keep looping until there's no carry left
    while (b != 0)
    {
        // Calculate carry: AND gives us bits where both are 1, shift left to add to next position
        // Example: 5 (101) & 3 (011) = 1 (001), then << 1 = 2 (010)
        int carry = (a & b) << 1;
        
        // XOR gives us sum without carry (addition without considering carry bits)
        // Example: 5 (101) ^ 3 (011) = 6 (110)
        a ^= b;
        
        // Move carry to b for next iteration
        // We'll keep adding the carry until there's nothing left to carry
        b = carry;
    }
    // When b becomes 0, a contains the final sum
    return a;
}

int main(int argc, char const *argv[])
{
    // Test case: 100 + (-300) = -200
    // This algorithm works with negative numbers using two's complement representation
    cout << getSum(100, -300);
    return 0;
}
