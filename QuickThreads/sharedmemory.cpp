/**
 * @file sharedmemory.cpp
 * @author Abhishek
 * @brief Here we discuss the dynamic of using shared memory in multithreaded program:
 * Issues with shared memory:
 * 1- Dangling references and thread stacks.
 * 2- Races/Race conditions.
 * 3- using Unique references
 * @version 0.1
 * @date 2022-08-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>

//***************understanding race condition***
/* struct List
{
    struct Node
    {
        int _data;
        Node* _next;
        Node(int x): _data{x}, _next{nullptr}
        {}
    };
    Node* _head;
    List(): _head{nullptr}
    {}
    void insert(int x)
    {
        auto newNode = new Node(x);
        newNode->_next = _head;
        _head = newNode;
    }
    int count();

};

void thFun(List& list)
{
    for(int i = 0; i < 100; i++)
        list.insert(i);
}

int main(int argc, char const *argv[])
{
    List list;
    std::vector<std::thread> workers;
    for(int i = 0; i < 10; i++)
    {
        workers.push_back(std::thread(thFun, std::ref(list)));
    }
    std::for_each(workers.begin(), workers.end(), [](std::thread& th)
    {
        th.join();
    });

    int total = list.count();
    std::cout << total;
    return 0;
}

int List::count()
{
    Node* current = _head;
    int count = 0;
    while(current != nullptr)
    {
        count++;
        current = current->_next;
    }
    return count;
} */
//***************understanding race condition***
//***************Happens before and move***
#include <list>
#include <cmath>
void toSin(std::list<double>& list)
{
    std::for_each(list.begin(), list.end(), [](double& x)
    {
        x = sin(x);
    });
}

int main(int argc, char const *argv[])
{
    std::list<double> list;
    //access list from main thread
    const double PI = 3.141592;
    const double EPSILON = 0.0000001;
    for(double x = 0.0; x < 2*PI+EPSILON; x += PI/16)
        list.push_back(x);

    //start thread
    std::thread th(&toSin, std::ref(list));
    //join thread
    th.join();
    //access list from main thread
    std::for_each(list.begin(), list.end(), [](double& x)
    {
        int count  = static_cast<int>(10*x + 10.5);
        for(int i = 0; i < count; i++)
            std::cout.put('*');
        std::cout << std::endl;
    });
    return 0;
}

//***************Happens before and move***
