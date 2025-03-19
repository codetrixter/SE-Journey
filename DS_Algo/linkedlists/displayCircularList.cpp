/**
 * @file displayCircularList.cpp
 * @author Abhishek
 * @brief creation and manipulation of circular list.
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
} *first = NULL;

void create(int *A, int size)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = first;
    last = first;
    for (int i = 1; i < size; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void insertAtBeg(struct Node *head, int element)
{
    struct Node *newNode, *it;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = head;
    it = head;

    while (it->next != head)
    {
        it = it->next;
    }
    it->next = newNode;
    head = newNode;
    //need to do this as head is a local copy of the pointer first
    first = head;
}

void deleteFromMid(struct Node *head, int element)
{
    struct Node *it = head;
    while(it->next != head)
    {
        if(head->data == element && it == head)
        {
            head = head->next;
        }
        else if(it->next->data == element)
        {
            it->next = it->next->next;
        }
        else
            it = it->next;
    }
}

void DisplayInC(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != first);
}

void display(struct Node *start)
{
    struct Node *temp = start;
    while (temp->next != start)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    if (temp->next = start)
        std::cout << temp->data;

    std::cout << "\n";
}

struct Node *displayRecursive(struct Node *start)
{
    if (start->next == first)
    {
        std::cout << start->data;
        std::cout << "\n";
        return start;
    }
    else
    {
        std::cout << start->data << " ";
        return displayRecursive(start->next);
    }
}

int main(int argc, char const *argv[])
{
    int A[] = {10, 30, 2, 50, 1};
    create(A, 5);
    displayRecursive(first);

    // std::cout << "****insertion at beginning**** \n";
    // insertAtBeg(first, 256);
    // display(first);

    std::cout << "****deletion from mid**** \n";
    deleteFromMid(first, 1);
    display(first);
    return 0;
}
