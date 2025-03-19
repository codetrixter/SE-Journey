#include <iostream>


struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

void createPoly(struct Node *start)
{
    struct Node *newNode = NULL, last = NULL;
    int size = 0, coeff = 0, exp = 0;
    std::cout << "Enter the number of terms";
    std::cin >> size;
    std::cout >> "enter each term with coeff and exp";
    for(int i = 0; i < size; i++)
    {
        newNode = (struct Node *)malloc(sizeOf(struct Node));
        std::cin >> newNode->coeff >> newNode->exp;
        newNode->next = NULL;
        if(start == NULL)
            start = last = newNode;
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}
