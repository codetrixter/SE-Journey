/**
 * Given a binary tree root, return the level order traversal of it as a nested list, where each sublist
 * contains the values of nodes at a particular level in the tree, from left to right.

Example 1:
Input: root = [1,2,3,4,5,6,7]
Output: [[1],[2,3],[4,5,6,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []

Constraints:
0 <= The number of nodes in the tree <= 1000.
-1000 <= Node.val <= 1000
 */

#include <iostream>
#include <queue>
#include <vector>

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

/// @brief level order traversal BFS approach
/// @param root
/// @return
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == nullptr)
        return result;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        vector<int> level;

        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *temp = q.front();
            q.pop();

            level.push_back(temp->val);

            if (temp->left != nullptr)
                q.push(temp->left);
            if (temp->right != nullptr)
                q.push(temp->right);
        }

        result.push_back(level);
    }

    return result;
}

/// @brief //TODO: DFS approach to level order traversal
/// @param root 
/// @return 
vector<vector<int>> levelOrderDFS(TreeNode *root)
{
}

int main(int argc, char const *argv[])
{
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->left->left = new TreeNode(4);
    node->left->right = new TreeNode(5);
    node->right->left = new TreeNode(6);
    node->right->right = new TreeNode(7);

    auto result = levelOrder(node);

    for (const auto &level : result)
    {
        cout << "[ ";
        for (int i = 0; i < level.size(); i++)
            cout << level[i] << (i + 1 < level.size() ? ", " : "");
        cout << " ]\n";
    }

    return 0;
}
