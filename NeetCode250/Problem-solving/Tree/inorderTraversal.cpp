/**
 * In order traversal of a binary tree.
 */

#include <iostream>
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

class Solution
{
private:
    vector<int> result;

public:

    //This uses trivial recursive procedure
    vector<int> inorderTraversl(TreeNode *root)
    {
        if (root != nullptr)
        {
            inorderTraversl(root->left);
            result.push_back(root->val);
            inorderTraversl(root->right);
        }
        return result;
    }

    //TODO, Iterative procedure.
};

int main(int argc, char const *argv[])
{
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2); node->right = new TreeNode(3);
    node->left->right = new TreeNode(4);
    node->right->left = new TreeNode(5);

    Solution ss;
    auto res = ss.inorderTraversl(node);

    for(auto& i :res)
    {   
        cout << i << " ";
    }
    
    return 0;
}
