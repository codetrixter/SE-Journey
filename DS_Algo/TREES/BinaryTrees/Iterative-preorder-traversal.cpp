/**
 * Here we are going to implement Pre-order traversal of the Binart tree Iteratively
 * Preorder Traversal technique : Root->Left->Right 
 * 
 * // !When you convert to iterative traversal, you're essentially simulating that call stack manually 
 * // !using an explicit stack data structure. This is why:
   // !Preorder/Inorder/Postorder traversals use a stack - they mimic the depth-first nature of recursion
   // !Level-order traversal uses a queue - because it's breadth-first, not depth-first
*/

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val, TreeNode* lptr = nullptr, TreeNode* rptr = nullptr):
    data{val},
    left{lptr},
    right{rptr}
    {
    }
};

void preorder(TreeNode* root)
{
    stack<TreeNode*> nodes;

    while(root != nullptr || !nodes.empty())
    {
        if(root)
        {
            cout << root->data;
            nodes.push(root);
            root = root->left;
        }
        else
        {
            root = nodes.top()->right;
            nodes.pop();
        }
    }
}

int main(int argc, char const *argv[])
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3); 
    root->left->left = new TreeNode(4); root->left->right = new TreeNode(9);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(7); root->right->right = new TreeNode(2);

    preorder(root);

    return 0;
}
