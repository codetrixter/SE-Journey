/**
 *
 */

#include <iostream>
#include <math.h>

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

/// @brief O(n^2) solution,
/// @param root
/// @return
/* int maxHeight(TreeNode *root)
{
    if(!root)
        return 0;
    else
    {
        return 1 + max(maxHeight(root->left), maxHeight(root->right));
    }
}

int diameterOfBinaryTree(TreeNode *root)
{
    if(root)
    {
        int Lheight = maxHeight(root->left);
        int Rheight = maxHeight(root->right);
        int dia = Lheight + Rheight;
        int sub = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return max(dia, sub);
    }
    else
        return 0;
} */

/// @brief //TODO: DFS
/// @param root
/// @return
class SolutionDFS
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int res = 0;
        dfs(root, res);
        return res;
    }

private:
    int dfs(TreeNode *root, int &res)
    {
        if (!root)
        {
            return 0;
        }
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        res = max(res, left + right);
        
        return 1 + max(left, right);
    }
};

/// @brief //TODO: Iterative DFS
/// @param root
/// @return
int diameterOfBinaryTreeIterative(TreeNode *root)
{
}

int main(int argc, char const *argv[])
{
    TreeNode *node = new TreeNode(1);
    node->right = new TreeNode(2);
    node->right->left = new TreeNode(3);
    node->right->right = new TreeNode(4);
    node->right->left->left = new TreeNode(5);

    SolutionDFS s1;
    cout << s1.diameterOfBinaryTree(node);

    return 0;
}
