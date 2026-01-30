/**
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

/* vector<int> getConcatenation(vector<int>& nums) 
{
    vector<int> ans(nums.size()*2);
    int i = 0, j = 0;
    for(; i < nums.size(); i++)
    {
        ans[i] = nums[i];
    }
    for(; i < ans.size(); i++)
    {
        ans[i] = nums[j];
        j++;
    }
    return ans;
} */

vector<int> getConcatenation(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> ans(n*2);
    
    for(int i{}; i < n; i++)
    {
        ans[i] = nums[i];
        ans[i+n] = nums[i];
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> inp = {1, 2, 3, 4};
    auto result = getConcatenation(inp);

    for(auto i: result)
    {
        cout << i << " ";
    }
    return 0;
}
