/**
 * @file MergeTwoLists.cpp
 * @author Abhishek
 * @brief
 * @version 0.1
 * @date 2022-09-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL && list2 == NULL)
    {
        return NULL;
    }
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    ListNode *head = NULL;
    if (list1->val <= list2->val)
    {
        head = list1;
        list1 = list1->next;
    }
    else
    {
        head = list2;
        list2 = list2->next;
    }
    ListNode *curr = head;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
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

    if (list1 == NULL)
    {
        curr->next = list2;
    }
    else
    {
        curr->next = list1;
    }

    return head;
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

    ListNode* six = new ListNode();
    ListNode* seven = new ListNode();
    ListNode* eight = new ListNode();
    ListNode* nine = new ListNode();
    ListNode* ten = new ListNode();
    ten->val = 100;ten->next = NULL;
    nine->val = 90;nine->next = ten;
    eight->val = 80;eight->next = nine;
    seven->val = 70;seven->next = eight;
    six->val = 60;six->next = seven;

    auto list = mergeTwoLists(one, six);

    while(list!=NULL)
    {
        std::cout << list->val << " ";
        list = list->next;
    }

    return 0;
}
