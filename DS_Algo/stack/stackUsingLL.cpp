/**
 * @file stackUsingLL.cpp
 * @author Abhishek 
 * @brief implementing stack using linked list.
 * @version 0.1
 * @date 2022-05-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

class stacking 
{
    struct Node
    {
        int data;
        struct Node *next;
    }*head = NULL;

    public:

    void push(int element);
    void display();
};

void stacking::push(int element)
{
    Node *newNode = new Node();
    if(!newNode)
    {
        std::cout << "stack overflow";
    }
    
    newNode->data = element;
    newNode->next = head;
    head = newNode;
}

void stacking::display()
{
    Node *temp = head;
    while(temp != NULL)
    {
        std::cout << temp->data;
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{   
    stacking *st = new stacking();
    st->push(3);
    st->push(4);
    st->push(6);
    st->display();
    return 0;
}
