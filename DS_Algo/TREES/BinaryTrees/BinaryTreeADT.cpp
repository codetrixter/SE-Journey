/**
 * @file BinaryTreeADT.cpp
 * @author Abhishek
 * @brief Here we will try to create a Binry Tree implementation and perform various operations on it.
 * @version 0.1
 * @date 2022-06-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <queue>
#include <stack>

struct Node
{
    struct Node* lchild;
    int data;
    struct Node* rchild; 
    bool fromleft = true;
}*root = NULL;

void createBT()
{
    struct Node* temp;
    std::queue<struct Node*> add;
    int value;

    //take the root of the binary tree from the command line.
    std::cout << "Enter the root Node : " ;
    std::cin >> value;
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = value;
    root->lchild = root->rchild = NULL;
    add.push(root);

    while(!add.empty())
    {
        struct Node* ptr = add.front();
        add.pop();
        if(ptr->lchild == NULL)
        {
            //take the left or right child of the tree from the command line.
            std::cout << "Enter left child of : " << ptr->data;
            std::cin >> value;
            if(value != -1)
            {
                temp = (struct Node*)malloc(sizeof(struct Node));
                temp->data = value;
                temp->lchild = temp->rchild = NULL;
                ptr->lchild = temp;
                add.push(temp);
            }
        }
        if(ptr->rchild == NULL)
        {
            //take the left or right child of the tree from the command line.
            std::cout << "Enter right child of : " << ptr->data;
            std::cin >> value;
            if(value != -1)
            {
                temp = (struct Node*)malloc(sizeof(struct Node));
                temp->data = value;
                temp->lchild = temp->rchild = NULL;
                ptr->rchild = temp;
                add.push(temp);
            }
        }
    }
}

void preOrderTraversal(struct Node* node)
{
    if(node)
    {
        std::cout << node->data << " ";
        preOrderTraversal(node->lchild);
        preOrderTraversal(node->rchild);
    }
}

void iterativePreorderTraversal(struct Node* node)
{
    std::stack<struct Node*> buff;

    while((node != NULL) || (!buff.empty()))
    {
        if(node)
        {
            std::cout << node->data << " ";
            buff.push(node);
            node = node->lchild;
        }
        else
        {
            node = buff.top();
            buff.pop();
            node = node->rchild;
        }
    }
}

void iterativeInorderTraversal(struct Node* node)
{
    std::stack<struct Node*> buff;

    while((node != NULL) || (!buff.empty()))
    {
        if(node)
        {
            buff.push(node);
            node = node->lchild;
        }
        else
        {
            node = buff.top();
            buff.pop();
            std::cout << node->data << " ";
            node = node->rchild;
        }
    }
}

//using 2 stack method of GeeksForGeeks
void iterativePostorderTraversal(struct Node* node)
{
    std::stack<struct Node*> buff1, buff2;
    buff1.push(node);

    while(!buff1.empty())
    {
        //pushing stack 1 elements to stack 2
        buff2.push(buff1.top());
        buff1.pop();

        //pushing stack 2's left and right child's in stack 1
        if(buff2.top()->lchild)
            buff1.push(buff2.top()->lchild);
        if(buff2.top()->rchild)
            buff1.push(buff2.top()->rchild);
    }

    while(!buff2.empty())
    {
        std::cout << buff2.top()->data << " ";
        buff2.pop();
    }
}

//it is the same way we did the BT creation
void levelOrderTraversal(struct Node* node)
{
    std::queue<struct Node*> buffer;
    if(node)
        buffer.push(node);
    else
        return;

    while(!buffer.empty())
    {
        //pop root from the queue and print it
        auto temp = buffer.front();
        buffer.pop();
        std::cout << temp->data << " ";

        //push left and right childs back into queue.
        if(temp->lchild)
            buffer.push(temp->lchild);
        if(temp->rchild)
        buffer.push(temp->rchild);
    }
}

int countNodes(struct Node* node)
{
    int x, y;
    if(node == NULL)
        return 0;
    else
    {
        x = countNodes(node->lchild);
        y = countNodes(node->rchild);
        return x + y + 1;
    } 
}

int mystrey(struct Node* node)
{
    int x = 0, y = 0;
    if(node == NULL)
        return 0;
    else
    {
        x = mystrey(node->lchild);
        y = mystrey(node->rchild);
        if(x > y)
            return x+1;
        else
            return y+1;
    } 
}

int main(int argc, char const *argv[])
{
    //creates a Binary Tree by taking node informations as command line arguments.
    createBT();
    //prints the data of Binary Tree using preOrder traversal technique.
    //preOrderTraversal(root);

    //Iterative preorder traversal of Binary tree
    //iterativePreorderTraversal(root);

    //Iterative In order traversal of Binary tree.
    //iterativeInorderTraversal(root);

    //Iterative post order binary tree traversal, using 2 stack method
    //iterativePostorderTraversal(root);

    //Iterative level order traversal of Binary tree.
    //levelOrderTraversal(root);

    //count the number of nodes in a binary tree.
    //std::cout << countNodes(root);

    //finding what this does.
    std::cout << mystrey(root);

    return 0;
}
