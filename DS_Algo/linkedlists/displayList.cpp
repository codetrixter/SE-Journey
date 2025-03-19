#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *MS = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int countNodes(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int countNodeRecursive(struct Node *p)
{
    static int count = 0;
    if (p == NULL)
        return count;
    else
        count++;
    return countNodeRecursive(p->next);
}

int sumNodes(struct Node *p)
{
    static int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int sumNodeRecursive(struct Node *p)
{
    static int sum = 0;
    if (p == NULL)
        return sum;
    sum += p->data;
    return sumNodeRecursive(p->next);
}

bool search(struct Node *p, int element)
{
    bool found = false;
    while (p != NULL)
    {
        if (p->data == element)
            found = true;
        p = p->next;
    }
    return found;
}

bool searchRecursive(struct Node *p, int element)
{
    if (p == NULL)
        return false;
    else if (p->data == element)
        return true;
    return searchRecursive(p->next, element);
}

/**
 * @brief remove duplicates from a sorted list.
 *
 * @param p
 */

void removeDuplicatesSorted(struct Node *p)
{
    while (p != NULL)
    {
        if (p->next != NULL && p->data == p->next->data)
        {
            struct Node *temp = p->next;
            p->next = p->next->next;
            free(temp);
        }
        else
            p = p->next;
    }
}

void reverse(struct Node *p)
{
    struct Node *temp = NULL, *prevNode = NULL;
    while (p != NULL)
    {
        prevNode = p;
        p = p->next;
        prevNode->next = temp;
        temp = prevNode;
    }
    first = temp;
}

void reverseTwo(struct Node *head)
{
    struct Node *prev = NULL, *next = NULL, *curr = head;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        
    }
    first = prev;
}

void reverseRecursive(struct Node *prev, struct Node *curr)
{
    static struct Node *temp = NULL, *prevNode = NULL;
    if (curr != NULL)
    {
        reverseRecursive(curr, curr->next);
        curr->next = prev;
    }
    else
        first = prev;
}

struct Node* concatenate(struct Node *first, struct Node *second)
{
    struct Node *temp = first;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = second;

    return first;
}

bool loopCheck(struct Node *head)
{
    struct Node *slow = head, *fast = head;

    while(slow && fast && fast->next)
    {
        if(slow == fast)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }   
    return false;
}

void merge(struct Node *first, struct Node *second)
{
    struct Node *ML = NULL;
    if (first->data < second->data)
    {
        MS = first;
        ML = first;
        first = first->next;
        ML->next = NULL;
    }
    else
    {
        MS = second;
        ML = second;
        second = second->next;
        ML->next = NULL;
    }

    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            ML->next = first;
            ML = first;
            first = first->next;
            ML->next = NULL;
        }
        else
        {
            ML->next = second;
            ML = second;
            second = second->next;
            ML->next = NULL;
        }
    }

    if (first != NULL)
        ML->next = first;
    else
        ML->next = second;
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void RecursiveDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d", p->data);
        RecursiveDisplay(p->next);
    }
}

void ReverseDisplay(struct Node *p)
{
    if (p != NULL)
    {
        ReverseDisplay(p->next);
        printf("%d ", p->data);
    }
}

int main()
{
    struct Node *temp;
    int A[] = {2, 8, 10, 15};
    int B[] = {4, 7, 12, 14, 17, 20};
    std::cout << "****create and display linked list**** \n";
    create(A, 4);
    create2(B, 6);
    Display(first);
    std::cout << "\n";

    // count iterative and recursive
    //  std::cout << countNodes(first);
    //  std::cout << countNodeRecursive(first);

    // sum pf all nodes
    //  std::cout << sumNodes(first);
    //  std::cout << sumNodeRecursive(first);

    // searching in a linked list
    //  std::cout << std::boolalpha << search(first, 2);
    //  std::cout << std::boolalpha << searchRecursive(first, 32);

    // removiing duplicates from the sorted list.
    //  removeDuplicatesSorted(first);
    //  Display(first);

    // std::cout <<"****reversing a linked list using sliding pointer method**** \n";
    // reverseRecursive(NULL, first);
    // reverseTwo(first);
    // reverse(first);
    // Display(first);
    // std::cout << "\n";

    // std::cout << "****merging a singly linked list**** \n";
    // merge(first, second);
    // Display(MS);

    //std::cout << "****concatenating two singly linked list**** \n";
    //Display(concatenate(first, second));

    std::cout << "****loop check in list****\n";
    std::cout << std::boolalpha << loopCheck(first);
    return 0;
}