/**
 * You are given two non-empty linked lists, l1 and l2, where each represents a non-negative integer.

    The digits are stored in reverse order, e.g. the number 321 is represented as 1 -> 2 -> 3 -> in the linked list.

    Each of the nodes contains a single digit. You may assume the two numbers do not contain any leading zero, 
    except the number 0 itself.

    Return the sum of the two numbers as a linked list.

    EX-1:
    Input: l1 = [1,2,3], l2 = [4,5,6]
    Output: [5,7,9]
    Explanation: 321 + 654 = 975.

    EX-2:
    Input: l1 = [9], l2 = [9]
    Output: [8,1]
 */

#include <iostream>
#include <math.h>
#include <cstdint>

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
    //My lengthy way of adding 2 numbers
    /* ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        uint64_t num1 = 0, num2 = 0, count = 0;
        ListNode* iter1 = l1;
        ListNode* iter2 = l2;
        ListNode* head = new ListNode(99);
        ListNode* iterNew = head;
        ListNode* prev = iterNew;

        ///iterating through the first list and fetch the number
        while(iter1 != nullptr)
        {
            num1 += (iter1->val) * (pow(10, count++));
            iter1 = iter1->next; 
        }

        ///iterating through the second list and fetch the number
        count = 0;
        while(iter2 != nullptr)
        {
            num2 += (iter2->val) * (pow(10, count++));
            iter2 = iter2->next; 
        }

        int res = num1+num2;
        ///handling the special case where the sum is 0
        if(res == 0)
        {
            head->val = 0;
            return head;
        }

        while(res > 0)
        {
            int rem = static_cast<int>(res) % 10;
            if(iterNew->val == 99)
            {
                head->val = rem;
                iterNew = head;
                prev = iterNew;
            }
            else
            {
                iterNew = new ListNode(rem);
                prev->next = iterNew;
                prev = iterNew;
            }   
            res = res/10;
        }
        return head;
    } */

    //shorter way
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int v1 = (l1 != nullptr) ? l1->val : 0;
            int v2 = (l2 != nullptr) ? l2->val : 0;

            int val = v1 + v2 + carry;
            carry = val / 10;
            val = val % 10;
            cur->next = new ListNode(val);

            cur = cur->next;
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    ListNode* node1 = new ListNode(1);
    node1->next = new ListNode(2);
    node1->next->next = new ListNode(3);
    
    ListNode* node2 = new ListNode(4);
    node2->next = new ListNode(5);
    node2->next->next = new ListNode(6);

    auto node = s.addTwoNumbers(node1, node2);

    while(node != nullptr)
    {
        cout << node->val << " ";
        node = node->next;
    }
    
    return 0;
}
