/**
 * You are given the root of a binary tree root. Invert the binary tree and return its root.
Example 1:
Input: root = [1,2,3,4,5,6,7]
Output: [1,3,2,7,6,5,4]

Example 2:
Input: root = [3,2,1]
Output: [3,1,2]

Example 3:
Input: root = []
Output: []

Constraints:
0 <= The number of nodes in the tree <= 100.
-100 <= Node.val <= 100
*/

#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/// @brief Recursive tree inversion
/// @param root 
/// @return root of the inverted tree.
TreeNode *invertTree(TreeNode *root)
{
    if (root)
    {
        TreeNode *temp = root->left;

        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);
    }

    return root;
}

/// @brief //TODO: Iterative inversion of a tree
/// @param root 
/// @return root of the inverted tree
TreeNode* invertTreeIterative(TreeNode *root)
{

}

int main(int argc, char const *argv[])
{
    /// Tree creation *************
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    /// Tree operations ************
    invertTree(root);


    return 0;
}
