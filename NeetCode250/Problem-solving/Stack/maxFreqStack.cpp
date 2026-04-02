/**
 *Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

Example 1:
Input: ["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]

Output: [null, null, null, null, null, null, null, 5, 7, 5, 4]
Explanation:
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop(); // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop(); // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop(); // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop(); // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].

Constraints:
0 <= val <= 1,000,000,000
At most 20,000 calls will be made to push and pop.
It is guaranteed that there will be at least one element in the stack before calling pop.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/// @brief Trivial solution with O(n)
class FreqStack
{
    private:
    vector<pair<int, int>> m_stk;
    unordered_map<int, int> m_map;
    int maxFreq = 0;
public:
    FreqStack()
    {
    }

    /// @brief push back in vector and store the current max freq
    /// @param val 
    void push(int val)
    {
        m_map[val]++;
        int freq = m_map.find(val)->second;
        m_stk.push_back(make_pair(val, freq));

        maxFreq = max(maxFreq, freq);
    }

    int pop()
    {
        // Find the last (closest to top) element with maxFreq
        auto it = find_if(m_stk.rbegin(), m_stk.rend(), [&](const pair<int, int>& p)
        {
            return p.second == maxFreq;
        });

        int val = it->first;

        // Convert reverse iterator to forward iterator and erase
        m_stk.erase((it + 1).base());

        m_map[val]--;
        if (m_map[val] == 0)
            m_map.erase(val);

        // If no element with maxFreq remains, decrement maxFreq
        bool hasMaxFreq = any_of(m_stk.begin(), m_stk.end(), [&](const pair<int, int>& p)
        {
            return p.second == maxFreq;
        });
        if (!hasMaxFreq)
            maxFreq--;

        return val;
    }
};

/// @brief //TODO:Solution with constant time complexity
class FreqStackII
{
    private:
    
public:
    FreqStackII()
    {
    }

    /// @brief push back in vector and store the current max freq
    /// @param val 
    void push(int val)
    {
    }

    int pop()
    {
    }
};

int main(int argc, char const *argv[])
{
    FreqStack *freqStack = new FreqStack();
    freqStack->push(5); // The stack is [5]
    freqStack->push(7); // The stack is [5,7]
    freqStack->push(5); // The stack is [5,7,5]
    freqStack->push(7); // The stack is [5,7,5,7]
    freqStack->push(4); // The stack is [5,7,5,7,4]
    freqStack->push(5); // The stack is [5,7,5,7,4,5]
    cout << freqStack->pop() << endl;   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
    cout << freqStack->pop() << endl;   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
    cout << freqStack->pop() << endl;   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
    cout << freqStack->pop() << endl;   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
    return 0;
}
