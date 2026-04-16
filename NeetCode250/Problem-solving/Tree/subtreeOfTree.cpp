/**
 *Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1:
Input: root = [1,2,3,4,5], subRoot = [2,4,5]
Output: true

Example 2:
Input: root = [1,2,3,4,5,null,null,6], subRoot = [2,4,5]
Output: false

Constraints:
1 <= The number of nodes in both trees <= 100.
-100 <= root.val, subRoot.val <= 100
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

bool sameTree(TreeNode *root, TreeNode *subRoot)
{
    if (!root && !subRoot)
    {
        return true;
    }
    if (root && subRoot && root->val == subRoot->val)
    {
        return sameTree(root->left, subRoot->left) &&
               sameTree(root->right, subRoot->right);
    }
    return false;
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (!subRoot)
    {
        return true;
    }
    if (!root)
    {
        return false;
    }

    if (sameTree(root, subRoot))
    {
        return true;
    }
    return isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}

int main(int argc, char const *argv[])
{
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(5);

    cout << boolalpha << isSubtree(root1, root2);
    return 0;
}
