/**
 * @file displayCircularList.cpp
 * @author Abhishek
 * @brief creation and manipulation of doubly list.
 * @version 0.1
 * @date 2022-05-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *first = NULL;

void create(int *A, int size)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    first->prev = NULL;
    last = first;
    for (int i = 1; i < size; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(struct Node *start)
{
    struct Node *temp = start;
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << "\n";
}

void insert(struct Node *start, int pos)
{
    struct Node *it = start;
    int count = 1;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = 1000;

    while(it != NULL)
    {
        if(count == pos)
        {
            newNode->prev = it->prev;
            newNode->next = it;
            it->prev->next = newNode; 
            it->prev = newNode;
            break;
        }
        else
        {
            count++;
            it = it->next;
        }
    }
}

void deleteNode(struct Node *start, int pos)
{
    int count = 1;
    
    while(start != NULL)
    {
        if(pos == 1)
        {
            start = start->next;
            start->prev = NULL;
            first = start;
            break;
        }
        else if(count == pos)
        {
            if(start->next == NULL)
                start->prev->next = NULL;
            else
            {
                start->prev->next = start->next;
                start->next->prev = start->prev;
            }
            break;
        }
        count++;
        start = start->next;
    }
}

void displayReverse(struct Node *start)
{
    struct Node *temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while(temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->prev;
    }
}

int main(int argc, char const *argv[])
{
    int A[] = {10, 30, 2, 50, 1};
    create(A, 5);
    display(first);
    //displayReverse(first);

    //insert at middle
    // insert(first, 2);
    // display(first);

    //delete from a doubly linked list
    deleteNode(first, 5);
    display(first);
    return 0;
}
