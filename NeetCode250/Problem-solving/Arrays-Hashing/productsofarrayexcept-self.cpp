/**
 * Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

    Each product is guaranteed to fit in a 32-bit integer.

    Follow-up: Could you solve it in 
    O
    (
    n
    )
    O(n) time without using the division operation?

    Example 1:

    Input: nums = [1,2,4,6]

    Output: [48,24,12,8]
    Example 2:

    Input: nums = [-1,0,1,2,3]

    Output: [0,-6,0,0,0]
    Constraints:

    2 <= nums.length <= 1000
    -20 <= nums[i] <= 20

 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    //Brute force technique
   /*  vector<int> productExceptSelf(vector<int> nums) 
    {
        int i = 0, j = 0, size = nums.size();
        vector<int> prodvec(size, 1);

        while(i < size)
        {
            j = 0;
            for(; j < size; j++)
            {
                if(i == j)
                {
                    continue;
                }
                    
                prodvec[i] *= nums[j];
            }
            i++;
        }
        return prodvec;
    } */

    //O(n) solution requires following
    //! - create prefix arrays and postfix arrays from the array which will help in calculating the final value:
    //! - prefix array - contains product of the value of all the elements from left to right.
    //! - postfix array - contains product of the value of all the elements from right to left.
    //! - final array - will be the multiple of 2 array values index by index

    //! original    -[1, 2, 4, 6] 
    //!pre          -[1, 1, 2, 8] 
    //!post         -[48, 24, 6, 1]
    //!final        -[1*48, 1*24, 2*6, 8*1]   
    // In order to optimize space complexity we can opt out of using prefix and postfix arrays and directly 
    // write to the output array.
    vector<int> productExceptSelf(vector<int> nums) 
    {
        int i = 0, size = nums.size(), prod = 1;
        vector<int> out(size, 1);

        //first pass, updating with prefix products
        for(; i < size; i++)
        {
            if(i == 0)
                prod = 1;
            else
                prod *= nums[i-1];
            out[i] = prod;
        }

        //second pass just calculate the prod and multiply by the value at that location in out inmstead of copying
        for(i = size-1; i >= 0; i--)
        {
            if(i == size-1)
                prod = 1;
            else
                prod *= nums[i+1];
            out[i] *= prod;
        }
        
        return out;
    }

};

int main(int argc, char const *argv[])
{
    Solution s1;
    auto res = s1.productExceptSelf({1, 2, 4, 6});

    for(auto i : res)
        cout << i << "\n";
    return 0;
}
