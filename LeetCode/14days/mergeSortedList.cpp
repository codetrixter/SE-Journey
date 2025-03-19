/**
 * You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the
    first two lists.
    Return the head of the merged linked list.

    Example 1:
    Input: list1 = [1,2,4], list2 = [1,3,4]
    Output: [1,1,2,3,4,4]

    Example 2:
    Input: list1 = [], list2 = []
    Output: []

    Example 3:
    Input: list1 = [], list2 = [0]
    Output: [0]

    Constraints:
    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.
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

/* ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{

    ListNode *itr1 = list1, *itr2 = list2, *temp = nullptr;

    if (!list1)
        return list2;
    else if (!list2)
        return list1;

    while (itr1->next != NULL && itr2->next != NULL)
    {
        if (itr1->val <= itr2->val)
        {
            temp = itr1->next;
            itr1->next = itr2;
            itr1 = temp;
        }
        else if (itr1->val >= itr2->val)
        {
            temp = itr2->next;
            itr2->next = itr1;
            itr2 = temp;
        }
    }

    if (itr1->next == NULL)
        itr1->next = itr2;
    else
        itr2->next = itr1;

    return list1;
} */

//------------ALternate----------
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    // if list1 happen to be NULL
    // we will simply return list2.
    if (list1 == NULL)
        return list2;

    // if list2 happen to be NULL
    // we will simply return list1.
    if (list2 == NULL)
        return list1;

    ListNode *ptr = list1;
    if (list1->val > list2->val)
    {
        ptr = list2;
        list2 = list2->next;
    }
    else
    {
        list1 = list1->next;
    }
    ListNode *curr = ptr;

    // till one of the list doesn't reaches NULL
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            curr->next = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    // adding remaining elements of bigger list.
    if (!list1)
        curr->next = list2;
    else
        curr->next = list1;

    return ptr;
}
//-------------------------------
int main(int argc, char const *argv[])
{
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    auto result = mergeTwoLists(head1, head2);

    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
