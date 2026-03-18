/**
 *
 */

#include <iostream>
#include <stack>

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

/// @brief Iterative DFS approach
/// @param p 
/// @param q 
/// @return true if trees are same, false otherwise
bool isSameTreeDFS(TreeNode *p, TreeNode *q)
{
    stack<pair<TreeNode *, TreeNode *>> stk;
    stk.push({p, q});

    while (!stk.empty())
    {
        auto [node1, node2] = stk.top();
        stk.pop();

        if (!node1 && !node2)
            continue;
        if (!node1 || !node2 || node1->val != node2->val)
            return false;

        stk.push({node1->right, node2->right});
        stk.push({node1->left, node2->left});
    }

    return true;
}

/// @brief //TODO: Recusive approach
/// @param p 
/// @param q 
/// @return 
bool isSameTreeRecusive(TreeNode *p, TreeNode *q)
{
}

/// @brief //TODO: Iterative BFS
/// @param p 
/// @param q 
/// @return 
bool isSameTreeBFS(TreeNode *p, TreeNode *q)
{
}

int main(int argc, char const *argv[])
{
    TreeNode *root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(3);
    root1->right->right = new TreeNode(4);
    root1->right->left->left = new TreeNode(5);

    TreeNode *root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(4);
    root2->right->left->left = new TreeNode(5);

    cout << boolalpha << isSameTreeDFS(root1, root2);
    return 0;
}
