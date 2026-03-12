/**
 * You are given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:
Input: root = [1,2,3,4,5,6,7]
Output: [1,2,4,5,3,6,7]

Constraints:
0 <= number of nodes in the tree <= 100
-100 <= Node.val <= 175
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include <iostream>
#include <vector>

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

/// @brief //TODO: Morris Traversal
/// @param root
/// @return preorder traversal of a tree
vector<int> preorderTraversal(TreeNode *root)
{
}

int main(int argc, char const *argv[])
{
    return 0;
}
