/**
 * @file problemsWithPassingParam.cpp
 * @author Abhishek
 * @brief Here we discuss about the problems that may arise while passing parameters to a worker thread:
 * 1- Here the thread 1 finishes execution while thread 2 is still using reference variable shared by thread1, which creates dangling 
 * reference problem.
 * @version 0.1
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <thread>
#include <chrono>

void func_2(int& x)
{
    while(true)
    {
        try
        {
            std::cout << x << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        catch(...)
        {
            throw std::runtime_error("this is runtime error");
        }
        
    }
}

void func_1()
{
    int x = 5;
    std::thread thread_2(func_2, std::ref(x));
    thread_2.detach();
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    printf("thread_1 finished execution... \n");
}

int main(int argc, char const *argv[])
{
    std::thread thread_1(func_1);
    thread_1.join();

    return 0;
}
