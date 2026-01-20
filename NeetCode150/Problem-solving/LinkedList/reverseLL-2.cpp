/**
 * You are given the head of a singly linked list and two integers left and right where left <= right, reverse the
 * nodes of the list from position left to position right (1-indexed), and return the reversed list.
 * Example-1:
 * Input: head = [1,2,3,4,5], left = 1, right = 3
    Output: [3,2,1,4,5]
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {

        ListNode *iter = head;
        ListNode *temp = head;
        ListNode *tempnext = nullptr;
        ListNode *prev = nullptr;
        ListNode *last = nullptr;

        while (iter != nullptr)
        {
            if (iter->val == left)
            {
                while (iter->val != right)
                {
                    if (last == nullptr)
                    {
                        last = iter;
                        temp = iter;
                        iter = iter->next;  
                    }
                    else
                    {
                        tempnext = iter->next;
                        iter->next = temp;
                        temp = iter;
                        iter = tempnext;
                    }
                }
                last->next = iter->next;
                iter->next = temp;
            }
            prev = iter;
            if(tempnext == nullptr)
                iter = iter->next;
            iter = tempnext;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode *node1 = new ListNode(1);
    node1->next = new ListNode(2);
    node1->next->next = new ListNode(3);
    node1->next->next->next = new ListNode(4);
    node1->next->next->next->next = new ListNode(5);
    node1->next->next->next->next->next = new ListNode(6);

    auto head = s.reverseBetween(node1, 2, 5);

    while (head != nullptr)
    {
        cout << head->val << "->";
        head = head->next;
    }
    return 0;
}
