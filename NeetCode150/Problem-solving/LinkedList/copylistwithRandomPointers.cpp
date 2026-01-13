/**
 * You are given the head of a linked list of length n. Unlike a singly linked list, each node contains an additional pointer 
 * random, which may point to any node in the list, or null.

    Create a deep copy of the list.

    The deep copy should consist of exactly n new nodes, each including:

    The original value val of the copied node
    A next pointer to the new node corresponding to the next pointer of the original node
    A random pointer to the new node corresponding to the random pointer of the original node
    Note: None of the pointers in the new list should point to nodes in the original list.

    Return the head of the copied linked list.

    In the examples, the linked list is represented as a list of n nodes. Each node is represented as a pair of 
    [val, random_index] where random_index is the index of the node (0-indexed) that the random pointer points to, or null if 
    it does not point to any node.

    0 <= n <= 100
    -100 <= Node.val <= 100
    random is null or is pointing to some node in the linked list.

    //! the idea here is to do following:
    //! 1- create a new list by copying the existing nodes without copying next and random pointers.
    //! 2- create one to one mapping of the old list to the new list using hash map.
    //! Now you have everything for the new list to fill random and next pointers.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Node 
{
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*, Node*> listmapping{};

        Node* iter = head;

        while(iter != nullptr)
        {
            //mapping old list nodes to new list nodes
            Node* newNode = new Node(iter->val);
            listmapping[iter] = newNode;
            
            iter = iter->next;
        }

        //updating the next and random pointers
        iter = head;
        while(iter != nullptr)
        {
            listmapping[iter]->next = listmapping[iter->next];
            listmapping[iter]->random = listmapping[iter->random];
            iter = iter->next;
        }
        return listmapping[head];
    }
};

int main(int argc, char const *argv[])
{
    Solution s1{};
    Node* start = new Node(3);
    start->next = new Node(7);
    start->next->next = new Node(4);
    start->next->next->next = new Node(5);
    //assigning random pointers
    start->random = nullptr;
    start->next->random = start->next->next->next;
    start->next->next->random = start;
    start->next->next->next->random = start->next;

    auto node = s1.copyRandomList(start);

    while(node)
    {
        cout << "node val : " << node->val << " " << "random node val:" 
        << (node->random != nullptr? node->random->val: 0) << "\n";
        node = node->next;
    }
    
    return 0;
}
