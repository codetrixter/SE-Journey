/**
 * You are given the beginning of a linked list head, and an integer n.

    Remove the nth node from the end of the list and return the beginning of the list.

    Example 1:

    Input: head = [1,2,3,4], n = 2

    Output: [1,2,4]
    Example 2:

    Input: head = [5], n = 1

    Output: []
    Example 3:

    Input: head = [1,2], n = 2

    Output: [2]
    Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
 */

#include <iostream>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* iter = head;
        ListNode* prev = nullptr;
        int count = 0, position = 0;

        //calculate the size of the list
        while(iter != nullptr)
        {
            iter = iter->next;
            count++;
        }

        iter = head;
        position = count-n+1;

        while(iter != nullptr)
        {
            position--;
        
            if(position == 0)
            {
                if(iter == head)
                    head = iter->next;
                else    
                    prev->next = iter->next;
                break;
            }
            prev = iter;
            iter = iter->next;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    Solution s1{};
    ListNode *start = new ListNode(1);
    start->next = new ListNode(2);
    start->next->next = new ListNode(3);
    start->next->next->next = new ListNode(4);
    start->next->next->next->next = new ListNode(5);
    start->next->next->next->next->next = new ListNode(6);
    start->next->next->next->next->next->next = new ListNode(7);

    auto node = s1.removeNthFromEnd(start, 2);

    while(start)
    {
        cout << start->val << " ";
        start = start->next;
    }
    return 0;
}
