/**
 * You are given the head of a singly linked-list. The list can be represented as:

    L0 → L1 → … → Ln - 1 → Ln
    Reorder the list to be on the following form:

    L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
    You may not modify the values in the list's nodes. Only nodes themselves may be changed.

    Example 1:
    Input: head = [1,2,3,4]
    Output: [1,4,2,3]

    Example 2:
    Input: head = [1,2,3,4,5]
    Output: [1,5,2,4,3]
    
    Constraints:
    The number of nodes in the list is in the range [1, 5 * 104].
    1 <= Node.val <= 1000
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode *head)
{
    ListNode *slow = head, *fast = head->next;

    //finding the middle element of the list insg Floyd's cycle finding algo.
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //begining if the second half of the list
    ListNode *second = slow->next, *first = head;
    slow->next = nullptr;
    ListNode *temp = second, *prev = nullptr;

    //reversing the second half of the list
    while(temp != nullptr)
    {
        ListNode *dummy = temp->next;
        temp->next = prev;
        prev = temp;
        temp = dummy;
    }
    second = prev;

    //merging of the two lists.
    while(second)
    {
        ListNode *temp1 = first->next;
        ListNode *temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
}

int main(int argc, char const *argv[])
{
    ListNode *start = new ListNode(1);
    start->next = new ListNode(2);
    start->next->next = new ListNode(3);
    start->next->next->next = new ListNode(4);
    start->next->next->next->next = new ListNode(5);
    start->next->next->next->next->next = new ListNode(6);
    start->next->next->next->next->next->next = new ListNode(7);

    reorderList(start);

    while(start)
    {
        cout << start->val << " ";
        start = start->next;
    }
    return 0;
}
