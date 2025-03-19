/**
 * @file linkedListInbTree.cpp
 * @author Abhishek
 * @brief Given a binary tree root and a linked list with head as the first node.

    Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree
    otherwise return False.

    In this context downward path means a path that starts at some node and goes downwards.

    Example 1:
    Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
    Output: true
    Explanation: Nodes in blue form a subpath in the binary Tree.

    Example 2:
    Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
    Output: true

    Example 3:
    Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
    Output: false
    Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.

    Constraints:
    The number of nodes in the tree will be in the range [1, 2500].
    The number of nodes in the list will be in the range [1, 100].
    1 <= Node.val <= 100 for each node in the linked list and binary tree.
 * @version 0.1
 * @date 2022-10-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool inpath(ListNode *head, TreeNode *root)
{
    if (root == NULL && head != NULL)
        return false;

    if (head == NULL)
        return true;

    if (head->val != root->val)
        return false;

    // if(root->left && head->next && root->left->val == head->next->val)
    bool b1 = inpath(head->next, root->left);

    // if(root->right && head->next && root->right->val == head->next->val)
    bool b2 = inpath(head->next, root->right);

    return b1 || b2;
}

bool isSubPath(ListNode *head, TreeNode *root)
{
    if (root == NULL)
        return false;

    if (root->val == head->val)
    {
        if (inpath(head, root))
            return true;
    }

    bool b1 = isSubPath(head, root->left);
    bool b2 = isSubPath(head, root->right);

    return b1 || b2;
}

int main(int argc, char const *argv[])
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(2);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    root->left->right->left = new TreeNode(1);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(8);

    std::cout << std::boolalpha << isSubPath(head, root);
    return 0;
}
