/**
 * Here we look at the logic behing counting nodes of a Binary Tree.
*/

#include <iostream>
#include <vector>
#include <queue>

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

/// @brief counting nodes of a Binary Tree
/// @param root 
/// @return total number of nodes in a Binary Tree.
int countNodes(TreeNode *root)
{

    int x = 0, y = 0;

    if(root)
    {
        x = countNodes(root->left);
        y = countNodes(root->right);
        return x+y+1;
    }
    return 0;
}

/// @brief sum of all nodes of a Binary Tree
/// @param root 
/// @return sum of all nodes
int sumNodes(TreeNode *root)
{

    int x = 0, y = 0;

    if(root)
    {
        x = sumNodes(root->left);
        y = sumNodes(root->right);
        return x+y+root->val;
    }
    return 0;
}

/// @brief Calculate the height of a Binary Tree (simpler approach)
/// @param root 
/// @return height of the tree (number of edges in longest path from root to leaf)
int treeHeight(TreeNode *root)
{
    // Base case: empty tree has height 0
    if(!root) 
        return 0;
    
    // Recursively find height of left and right subtrees
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    
    // Height of current tree is 1 + max of left and right heights
    return 1 + max(leftHeight, rightHeight);
}

/// @brief Calculate height using iterative approach with level-order traversal (BFS)
/// @param root 
/// @return height of the tree
int treeHeightIterative(TreeNode *root)
{
    if(!root) return 0;
    
    queue<TreeNode*> q;
    q.push(root);
    int height = 0;
    
    // Level-order traversal
    while(!q.empty())
    {
        int levelSize = q.size(); // Number of nodes at current level
        height++;
        
        // Process all nodes at current level
        for(int i = 0; i < levelSize; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    
    return height;
}

/// @brief Calculate height by passing current level as parameter
/// @param root 
/// @param level current level in the tree
/// @return height of the tree
void treeHeightHelper(TreeNode *root, int level, int &maxLevel)
{
    if(!root) return;
    
    maxLevel = max(maxLevel, level);
    
    treeHeightHelper(root->left, level + 1, maxLevel);
    treeHeightHelper(root->right, level + 1, maxLevel);
}

int treeHeightWithLevel(TreeNode *root)
{
    if(!root) return 0;
    int maxLevel = 1;
    treeHeightHelper(root, 1, maxLevel);
    return maxLevel;
}

int main(int argc, char const *argv[])
{
    /// Creating a Tree ************
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(12);
    root->left->left->right = new TreeNode(4);
    root->left->left->right->left = new TreeNode(9);
    root->left->left->right->right = new TreeNode(7);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(2);

    /// Tree operations ************

    cout << "Count of nodes: " << countNodes(root) << endl;
    cout << "Sum of nodes: " << sumNodes(root) << endl;
    cout << "\n--- Different ways to calculate height ---" << endl;
    cout << "Height (recursive): " << treeHeight(root) << endl;
    cout << "Height (iterative BFS): " << treeHeightIterative(root) << endl;
    cout << "Height (level tracking): " << treeHeightWithLevel(root) << endl;

    return 0;
}
