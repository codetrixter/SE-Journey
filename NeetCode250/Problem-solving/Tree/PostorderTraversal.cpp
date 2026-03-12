/**
 * You are given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,2,3,4,5,6,7]
Output: [4,5,2,6,7,3,1]

Example 2:
Input: root = [1,2,3,null,4,5,null]
Output: [4,2,5,3,1]

Example 3:
Input: root = []
Output: []

Constraints:
0 <= number of nodes in the tree <= 100
-100 <= Node.val <= 175
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include <iostream>
#include <vector>
#include <stack>
#include <memory>
#include <functional>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/// @brief using single stack, DFS
/// @param root
/// @return
vector<int> postorderTraversalSimple(reference_wrapper<shared_ptr<TreeNode>> root)
{
    vector<int> result;
    stack<shared_ptr<TreeNode>> s1;

    if (root.get())
    {
        s1.push(root);

        while (!s1.empty())
        {
            shared_ptr<TreeNode> temp = s1.top();
            s1.pop();
            result.push_back(temp->val);

            if (temp->left != nullptr)
                s1.push(temp->left);
            if (temp->right != nullptr)
                s1.push(temp->right);
        }

        reverse(result.begin(), result.end());
    }

    return result;
}

/// @brief //TODO: using DFS-II with marking the already visited node
/// @param root
/// @return
vector<int> postorderTraversalMorris(reference_wrapper<shared_ptr<TreeNode>> root)
{
}

/// @brief //TODO: using Morris traversal
/// @param root
/// @return
vector<int> postorderTraversalMorris(reference_wrapper<shared_ptr<TreeNode>> root)
{
}

int main(int argc, char const *argv[])
{
    shared_ptr<TreeNode> root = make_unique<TreeNode>(1);
    root->left = make_unique<TreeNode>(2);
    root->right = make_unique<TreeNode>(3);
    root->left->left = make_unique<TreeNode>(4);
    root->left->right = make_unique<TreeNode>(5);
    root->right->left = make_unique<TreeNode>(6);
    root->right->right = make_unique<TreeNode>(7);

    auto result = postorderTraversalSimple(ref(root));

    // Print result
    cout << "Postorder traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
