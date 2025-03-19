/**
 * @file partitionList.cpp
 * @author Abhishek
 * @brief
 * Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

    You should preserve the original relative order of the nodes in each of the two partitions.

    Example 1:
    Input: head = [1,4,3,2,5,2], x = 3
    Output: [1,2,2,4,3,5]

    Example 2:
    Input: head = [2,1], x = 2
    Output: [1,2]

    Constraints:
    The number of nodes in the list is in the range [0, 200].
    -100 <= Node.val <= 100
    -200 <= x <= 200

 * @version 0.1
 * @date 2022-10-06
 *
 * @copyright Copyright (c) 2022
 *
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

ListNode *partition(ListNode *head, int x)
{
    ListNode *dummy1 = new ListNode(-1);
    ListNode *dummy2 = new ListNode(-1);
    ListNode *dummyPtr1 = dummy1;
    ListNode *dummyPtr2 = dummy2;
    while (head)
    {
        if (head->val < x)
        {
            dummyPtr1->next = new ListNode(head->val);
            dummyPtr1 = dummyPtr1->next;
        }
        else
        {
            dummyPtr2->next = new ListNode(head->val);
            dummyPtr2 = dummyPtr2->next;
        }
        head = head->next;
    }
    dummyPtr1->next = dummy2->next;
    return dummy1->next;
}
int main(int argc, char const *argv[])
{
    vector<int> v = {1, 4, 6, 3, 2, 5, 2, 8};
    ListNode *head = make_list(v);
    print_list(ob.partition(head, 3));
    return 0;
}
