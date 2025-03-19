/**
 * @file balancedBinaryTree.cpp
 * @author Abhishek
 * @brief WAp to find if the binary tree is balanced or not.
 * @version 0.1
 * @date 2022-10-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getHeightOfSubTree(TreeNode *currentNode)
{
    // end of the current is null
    if (currentNode == nullptr)
    {
        return 0;
    }

    // get the height of each subtree
    int l = getHeightOfSubTree(currentNode->left);
    int r = getHeightOfSubTree(currentNode->right);

    // use -1 to note if there is already an imbalance found
    // check for imbalance using abs(l-r) >= 2
    if (l == -1 || r == -1 || std::abs(l - r) >= 2)
    {
        return -1;
    }

    return std::max(l, r) + 1;
}

bool isBalanced(TreeNode *root)
{
    return getHeightOfSubTree(root) != -1;
}

int main(int argc, char const *argv[])
{
    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(2);
    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(3);
    // root->left->left->left = new TreeNode(4);
    // root->left->left->right = new TreeNode(4);

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    // root->left->left = new TreeNode(null);
    // root->left->right = new TreeNode(null);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::cout << isBalanced(root);
    return 0;
}
