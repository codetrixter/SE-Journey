/**
 * @file mutex.cpp
 * @author Abhishek
 * @brief Here we discuss about the mutex and how to use it for thread synchronization:
 * 1- mutex(stands for mutual excusion), provides mutual exclusive access to the shared object to more than one threads.
 *  a. lock: locks the mutex, blocks if the mutex is not available.
 *  b. try_lock: tries to lock the mutex, returns is mutex is not available.
 *  c. unlock: unlocks the mutex.
 * 2- Lock_guard: 
 *      - It is a mutex wrapper that provides a convenient RAII style mechanism for owning a mutex for the duration of a scoped block.
 *      - When a lock_guard object is created, it takes ownership opf the mutex and it is deleted and mutex is released when the scope of lock_guard 
 *          ends.
 * EXAMPLE: List or most of the STL data structures are not thread safe, hence if more than one thread tries to access or insert data into 
 * the list, then there is a chnace that the data can be currupted or removed without notice.
 *  In the below example, when two threads try insert an elemnt to the front of the list then in some cases the element inserted by one thread 
 * be overwritten by another thread.
 * @version 0.1
 * @date 2022-10-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <list>

std::list<int> myList{10, 20, 30 ,40};
std::mutex m;

void addToList(const int& x)
{
    std::lock_guard<std::mutex> lg(m);
    //m.lock();
    myList.push_front(x);
    //m.unlock();
}

void size()
{
    m.lock();
    int size = myList.size();
    m.unlock();
    std::cout << size;
}

int main(int argc, char const *argv[])
{
    std::thread t1(addToList, 4);
    std::thread t2(addToList, 11);

    t1.join();
    t2.join();

    for(auto item : myList)
    {
        std::cout << item << " ";
    }
    return 0;
}
