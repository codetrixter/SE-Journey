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
#include <queue>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val, TreeNode *lptr = nullptr, TreeNode *rptr = nullptr) : data{val},
                                                                            left{lptr},
                                                                            right{rptr}
    {
    }
};

/// @brief Iterative preorder Traversal Root->Left->Right
/// @param root
void preorder(TreeNode *root)
{
    stack<TreeNode *> nodes;

    while (root != nullptr || !nodes.empty())
    {
        if (root)
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

/// @brief inorder Traversal Left->Root->Right
/// @param root
void inorder(TreeNode *root)
{
    stack<TreeNode *> nodes;

    while (root != nullptr || !nodes.empty())
    {
        if (root)
        {
            nodes.push(root);
            root = root->left;
        }
        else
        {
            cout << nodes.top()->data;
            root = nodes.top()->right;
            nodes.pop();
        }
    }
}

/// @brief traversal in post order left->Right->Root
/// @param root
/* void postorder(TreeNode *root)
{
    stack<TreeNode*> nodes;

    while(root != nullptr || !nodes.empty())
    {
        if(root)
        {
            nodes.push(root);
            root = root->left;
        }
        else
        {

        }
    }
} */

/// @brief level order traversal, implemented via a queue
/// @param root
void levelOrder(TreeNode *root)
{
    if (root == nullptr)
        return;

    queue<TreeNode *> nodes;

    nodes.push(root);

    while (!nodes.empty())
    {
        TreeNode *current = nodes.front();
        nodes.pop();

        cout << current->data << " ";

        if (current->left != nullptr)
            nodes.push(current->left);
        if (current->right != nullptr)
            nodes.push(current->right);
    }
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(2);

    // preorder(root);

    // inorder(root);

    levelOrder(root);

    return 0;
}
