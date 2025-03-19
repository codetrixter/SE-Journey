/**
 * @file non-deterministicThreads.cpp
 * @author Abhishek
 * @brief Here we discuss following along with non deterministic behaviour of threads:
 * 1- Forking threads: this can be done by creating multiple worker threads.
 * 2- Barrier: can be implemented by joining all the forked threads.
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <thread>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<std::thread> workers;

    //Forking 10 threads
    for(int i = 0; i < 10; i++)
    {
        workers.push_back(std::thread([i]()
        {
            //Hi from worker thread!0Hi from worker thread!1, this gets printed which means that each statement 
            //print is a separate instruction execution
            std::cout << "Hi from worker thread!" << i << std::endl;    
        }));
    }

    //this message can be printed in between execution of any of the 10 threads created here, which proves that 
    //threads are non deterministic in nature.
    std::cout << "Hi from main thread" << std::endl;

    //Barrier implementation
    for(auto& task : workers)
    {
        task.join();
    }
    return 0;
}
