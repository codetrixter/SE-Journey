/**
 * Given a binary tree, return true if it is height-balanced and false otherwise.

A height-balanced binary tree is defined as a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Example 1:
Input: root = [1,2,3,null,null,4]
Output: true

Example 2:
Input: root = [1,2,3,null,null,4,null,5]
Output: false

Example 3:
Input: root = []
Output: true

Constraints:
The number of nodes in the tree is in the range [0, 1000].
-1000 <= Node.val <= 1000

*/
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/// @brief Trivial O(n^2) complexity solution
/// @param root 
/// @return 
int height(TreeNode *root)
{
    if(!root)
        return 0;
    
        return 1+ max(height(root->left), height(root->right));
}

bool isBalanced(TreeNode *root)
{
    if(!root)
        return true;
    int left = height(root->left);
    int right = height(root->right);

    if(abs(left-right) > 1)
        return false;
    
        return isBalanced(root->left) && isBalanced(root->right);
}


///TODO: Write a recursive DFS with O(n) solution.

///TODO: Write an iterative DFS soultion.

int main(int argc, char const *argv[])
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(4);
    root1->right->left->left = new TreeNode(5);

    cout << boolalpha << isBalanced(root1);
    return 0;
}
