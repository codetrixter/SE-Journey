/**
 * @file referenceInThreads.cpp
 * @author Abhishek
 * @brief here we discuss the dangers of using references in multithreaded programing:
 * @version 0.1
 * @date 2022-08-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <thread>
#include <cassert>
#include <algorithm>
#include <vector>

void thFun(int& i)
{
    std::cout << "Hi from Worker " << i << "!\n";
}

void createWorkers(std::vector<std::thread>& workers)
{
    for(int i = 0; i < 8; i++)
    {
        //using std::ref(i) creates a lot of issues here, duplicate references and garbage values.
        auto worker = std::thread(&thFun, std::ref(i));
        workers.push_back(std::move(worker));
        assert(!worker.joinable());
    }
}   //once this function gets over, the i value gets deallocated from the stack

int main(int argc, char const *argv[])
{
    std::vector<std::thread> workers;
    createWorkers(workers);

    //Here when the stack gets updated, the updated garbage values are seen in output.
    std::cout << "Hi from main !\n";
    std::for_each(workers.begin(), workers.end(), [](std::thread & th)
    {
        assert(th.joinable());
        th.join();
    });
    return 0;
}
//One of the outputs
/* Hi from Worker 2!
Hi from Worker 2!   //This happened since two threads used same reference to i.
Hi from Worker 3!
Hi from Worker 4!
Hi from Worker 5!
Hi from Worker 6!
Hi from Worker 7!
Hi from main !
Hi from Worker 32557! */