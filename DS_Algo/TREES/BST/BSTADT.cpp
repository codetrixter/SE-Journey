/**
 * @file BSTADT.cpp
 * @author Abhishek
 * @brief Here we discuss and implement the BST and its operations:
 * 
 * @version 0.1
 * @date 2022-07-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
}*root = NULL;      //global variable, for using it in functions.

void createBST(int *input, int size)
{
    struct Node *itr, *buff;
    //These flags keep track of itr = it it is pointing to the left or right child
    bool isLeft = false;
    bool isright = false;

    struct Node *temp = new Node();
    temp->data = input[0]; 

    root = temp;
    root->left = root->right = NULL;

    for(int i = 1; i < size; i++)
    {
        isLeft = isright = false;
        itr = root;
        while(itr != NULL)
        {
            //This buff keeps track of the prev value of node in a tree ie parent.
            buff = itr;
            if(input[i] < itr->data)
            {
                itr = itr->left;
                isLeft = true;
                isright = false;
            }
            else if(input[i] > itr->data)
            {
                itr = itr->right;
                isright = true;
                isLeft = false;
            }
        }
        struct Node *t = new Node();
        t->data = input[i];
        t->left = t->right = NULL;
        if(isLeft)
            buff->left = t;
        else if(isright)
            buff->right = t;
    }
}

bool searchInBST(struct Node *node, int element)
{
    while(node != NULL)
    {
        if(node->data == element)
        {
            std::cout << "Element found:" ;
            return true;
        }
        else if(element < node->data)
            node = node->left;
        else
            node = node->right;
    }
    return false;
}

bool searchBSTRecursive(struct Node *node, int element = 0)
{
    if(node == NULL)
        return false;
    else if(node->data == element)
        return true;
    else if(element < node->data)
        searchBSTRecursive(node->left, element);
    else
        searchBSTRecursive(node->right, element);
}

void preOrderTraversal(struct Node *node)
{
    if(node)
    {
        std::cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

int main(int argc, char const *argv[])
{
    int arr[9] = {9, 15, 5, 20, 16, 8, 12, 3, 6};
    createBST(arr, 9);

    //printing BST
    preOrderTraversal(root);

    //searching in a BST.
    //std::cout << std::boolalpha << searchInBST(root, 8);

    //recursive searching in BST
    std::cout << std::boolalpha << searchBSTRecursive(root, 22);
    return 0;
}
