/**
 * The depth of a binary tree is defined as the number of nodes along the longest path from the root node down to the farthest leaf node.
 *
 * Example 1:
 * Input: root = [1,2,3,null,null,4]
Output: 3

Example 2:
Input: root = []
Output: 0

Constraints:

0 <= The number of nodes in the tree <= 100.
-100 <= Node.val <= 100
*/
#include <iostream>
#include <stack>

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

class Solution
{
private:
    int count = 0;
    TreeNode * temp = nullptr;
public:
    int maxDepth(TreeNode *root)
    {
        // Do the inorder traversal and update the static count whenever a left or right child is found.
        traversalCount(root);
        return count;
    }

    void traversalCount(TreeNode *root)
    {
        if(root == nullptr)
            return;
        else
        {
            if(temp != root || temp == nullptr)
            {
                temp = root;
                count++;
            }
                
            traversalCount(root->left);
            traversalCount(root->right);
        }
    }
    /// @brief Iterative max depth
    /// @param root 
    /// @return 
    int maxDepthIterative(TreeNode* root) {
        
        stack<pair<TreeNode*, int>> st1;
        int maxd = 0;

        if(root == nullptr)
            return 0;

        st1.push(make_pair(root, 1));
        
        while(!st1.empty())
        {
            TreeNode* currentNode = st1.top().first;
            int currentDepth = st1.top().second;
            st1.pop();
            
            maxd = max(maxd, currentDepth);

            if(currentNode->left)
                st1.push(make_pair(currentNode->left, currentDepth + 1));
            if(currentNode->right)
                st1.push(make_pair(currentNode->right, currentDepth + 1));
        }
        return maxd;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2); node->right = new TreeNode(3);
    // node->left->right = new TreeNode(4);
    node->right->left = new TreeNode(5);

    Solution ss;
    cout << ss.maxDepth(node);

    /* for(auto& i :res)
    {   
        cout << i << " ";
    } */
    return 0;
}
