/**
 * @file ReverseLinkedist.cpp
 * @author Abhishek
 * @brief
 * @version 0.1
 * @date 2022-09-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <list>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = curr->next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main(int argc, char const *argv[])
{
    ListNode* one = new ListNode();
    ListNode* two = new ListNode();
    ListNode* three = new ListNode();
    ListNode* four = new ListNode();
    ListNode* five = new ListNode();
    five->val = 50;five->next = NULL;
    four->val = 40;four->next = five;
    three->val = 30;three->next = four;
    two->val = 20;two->next = three;
    one->val = 10;one->next = two;
    auto list = reverseList(one);
    std::cout << list->next->val;
    return 0;
}
