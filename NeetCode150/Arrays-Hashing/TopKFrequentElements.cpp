/**
 * @file TopKFrequentElements.cpp
 * @author Abhishek
 * @brief 
 * Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
    Example 1:
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]

    Example 2:
    Input: nums = [1], k = 1
    Output: [1]
    
    Constraints:
    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    k is in the range [1, the number of unique elements in the array].
    It is guaranteed that the answer is unique.
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
// Time: O(n log k)
// Space: O(n + k)

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> m;
//         for (int i = 0; i < nums.size(); i++) {
//             m[nums[i]]++;
//         }
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         for (auto it = m.begin(); it != m.end(); it++) {
//             pq.push({it->second, it->first});
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//         }
//         vector<int> result;
//         while (!pq.empty()) {
//             result.push_back(pq.top().second);
//             pq.pop();
//         }
//         return result;
//     }
// };

// Time: O(n)
// Space: O(n)

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        
        vector<vector<int>> buckets(n + 1);
        // We are storing key as count/frequency and value as the number.
        for (auto it = m.begin(); it != m.end(); it++) 
        {
            buckets[it->second].push_back(it->first);
        }
        
        vector<int> result;
        
        for (int i = n; i >= 0; i--) {
            if (result.size() >= k) {
                break;
            }
            // Here we are checking that last element of the bucket because that contains element with highest freqency.
            if (!buckets[i].empty()) {
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        
        return result;
    }

int main(int argc, char const *argv[])
{
    std::vector<int> inp = {4, 1, -1, 2, -1, 2, 3,};
    auto result = topKFrequent(inp, 2);
    std::cout << std::endl;
    for(auto item : result)
    {
        std::cout << item << " ";
    }
    return 0;
}
