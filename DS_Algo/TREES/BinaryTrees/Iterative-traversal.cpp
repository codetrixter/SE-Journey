/**
 * Here we are going to implement Pre-order traversal of the Binart tree Iteratively
 * Preorder Traversal technique : Root->Left->Right
 *
 * // !When you convert to iterative traversal, you're essentially simulating that call stack manually
 * // !using an explicit stack data structure. This is why:
   // !Preorder/Inorder/Postorder traversals use a stack - they mimic the depth-first nature of recursion
   // !Level-order traversal uses a queue - because it's breadth-first, not depth-first

   // ! IMPORTANT:
   The Pattern:
    DFS traversals (preorder, inorder, postorder) → Use Stack (go deep)
    BFS traversals (level-order) → Use Queue (go wide)
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

/// @brief ALTERNATE 1: Simpler iterative preorder (most intuitive)
/// @param root 
/// @details Process immediately on pop, push right then left
void preorderSimple(TreeNode *root)
{
    if (root == nullptr)
        return;
    
    stack<TreeNode*> nodes;
    nodes.push(root);
    
    while (!nodes.empty())
    {
        TreeNode* current = nodes.top();
        nodes.pop();
        
        cout << current->data << ", " << flush;
        
        // Push RIGHT first, then LEFT (so left gets popped first)
        if (current->right != nullptr)
            nodes.push(current->right);
        if (current->left != nullptr)
            nodes.push(current->left);
    }
    cout << endl;
}

/// @brief ALTERNATE 2: Recursive preorder (classic DFS)
/// @param root 
void preorderRecursive(TreeNode *root)
{
    if (root == nullptr)
        return;
    
    cout << root->data << ", " << flush;  // Root
    preorderRecursive(root->left);         // Left
    preorderRecursive(root->right);        // Right
}

/// @brief ALTERNATE 3: Morris Traversal - O(1) space, no stack/recursion!
/// @param root 
/// @details Uses threaded binary tree concept (temporary links)
void preorderMorris(TreeNode *root)
{
    TreeNode* current = root;
    
    while (current != nullptr)
    {
        if (current->left == nullptr)
        {
            // No left child, process current and go right
            cout << current->data << ", " << flush;
            current = current->right;
        }
        else
        {
            // Find inorder predecessor (rightmost node in left subtree)
            TreeNode* predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }
            
            if (predecessor->right == nullptr)
            {
                // First visit: create thread, process current, go left
                cout << current->data << ", " << flush;
                predecessor->right = current;  // Create thread
                current = current->left;
            }
            else
            {
                // Second visit: remove thread, go right
                predecessor->right = nullptr;  // Remove thread
                current = current->right;
            }
        }
    }
    cout << endl;
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
void postorder(TreeNode *root)
{
    stack<long int> nodes;
    long int temp;

    while (root != nullptr || !nodes.empty())
    {
        if (root)
        {
            nodes.emplace((long int)root);
            root = root->left;
        }
        else
        {
            temp = nodes.top();
            nodes.pop();

            if (temp > 0)
            {
                nodes.emplace(-temp);
                root = reinterpret_cast<TreeNode*>(temp)->right;
            }
            else
            {
                cout << reinterpret_cast<TreeNode*>(-1 * temp)->data << ", " << flush;
                root = nullptr;
            }
        }
    }
    cout << endl;
}

/// @brief ALTERNATE: Easier postorder using two stacks (Left->Right->Root)
/// @param root 
/// @details Uses modified preorder (Root->Right->Left) and reverses it
void postorderEasy(TreeNode *root)
{
    if (root == nullptr)
        return;
    
    stack<TreeNode*> s1, s2;
    s1.push(root);
    
    // Step 1: Do modified preorder (Root -> Right -> Left) and store in s2
    while (!s1.empty())
    {
        TreeNode* current = s1.top();
        s1.pop();
        s2.push(current);  // Store for later (this reverses the order)
        
        // Push LEFT first, then RIGHT (opposite of normal preorder)
        if (current->left != nullptr)
            s1.push(current->left);
        if (current->right != nullptr)
            s1.push(current->right);
    }
    
    // Step 2: Pop from s2 to get postorder (Left -> Right -> Root)
    while (!s2.empty())
    {
        cout << s2.top()->data << ", " << flush;
        s2.pop();
    }
    cout << endl;
}

/// @brief ALTERNATE 2: Single stack postorder using last visited tracking
/// @param root 
void postorderSingleStack(TreeNode *root)
{
    if (root == nullptr)
        return;
    
    stack<TreeNode*> nodes;
    TreeNode* lastVisited = nullptr;
    TreeNode* current = root;
    
    while (!nodes.empty() || current != nullptr)
    {
        // Go to the leftmost node
        if (current != nullptr)
        {
            nodes.push(current);
            current = current->left;
        }
        else
        {
            TreeNode* peekNode = nodes.top();
            
            // If right child exists and hasn't been processed yet
            if (peekNode->right != nullptr && lastVisited != peekNode->right)
            {
                current = peekNode->right;
            }
            else
            {
                // Process this node (both children are done)
                cout << peekNode->data << ", " << flush;
                lastVisited = nodes.top();
                nodes.pop();
            }
        }
    }
    cout << endl;
}

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

    /// Preorder traversal algos
    preorder(root);
    preorderSimple(root);
    preorderRecursive(root);
    preorderMorris(root);

    inorder(root);

    levelOrder(root);

    // Postorder traversal algos
    postorder(root);
    postorderEasy(root);
    postorderSingleStack(root);

    return 0;
}
