/**
 * @file Exercise3.cpp
 * @author Abhsihek
 * @brief Here we WAP with folloing rules:
 * TODO:
 * 1- There will be two queues:
 *      a. Engine work queue.
 *      b. Clean work queue.
 * 2- If queue has work then sleep for 1 second else sleep for 2 seconds.
 * @version 0.1
 * @date 2022-09-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <thread>
#include <queue>
#include <chrono>
#include <cstdio>

void shipCleaners(std::queue<bool> &cleaningQ)
{
    while (true)
    {
        if (!cleaningQ.empty())
        {
            cleaningQ.pop();
            std::cout << "Cleaning...\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        else
        {
            std::cout << "Sitting IDLE...\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
}

void shipEngineWorkers(std::queue<bool> &engineQ)
{
    while (true)
    {
        if (!engineQ.empty())
        {
            engineQ.pop();
            std::cout << "working on engine...\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        else
        {
            std::cout << "Sitting IDLE...\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
}

void run()
{
    std::queue<bool> CQ;
    std::queue<bool> EQ;

    std::thread cleaners_thread(shipCleaners, std::ref(CQ));
    std::thread workers_thread(shipEngineWorkers, std::ref(EQ));

    cleaners_thread.detach();
    workers_thread.detach();

    int command_no;
    while (true)
    {
        std::cout << "\nEnter a command {1=clean,2=work,100=exit} : ";
        std::cin >> command_no;
        if (command_no == 1)
        {
            printf("<clean>\n");
            CQ.push(true);
        }
        else if (command_no == 2)
        {
            printf("<work>\n");
            EQ.push(true);
        }
        else if (command_no == 100)
        {
            printf("<exit>.\n");
            break;
        }
        else
        {
            printf("<unknown command>\n");
        }
    }
}
int main(int argc, char const *argv[])
{
    run();
    return 0;
}
