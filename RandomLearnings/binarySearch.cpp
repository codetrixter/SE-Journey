#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size()-1;
        int mid = 0;

        while(low < high)
        {
            mid = (low+high)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(target < nums[mid])
            {
                high = mid-1;
            }
            else if(target > nums[mid])
            {
                low = mid+1;
            }
        }
        return -1;
    }
int main(int argc, char const *argv[])
{
    vector<int> inp = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << search(inp, target);
    return 0;
}
