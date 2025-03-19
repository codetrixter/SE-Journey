/**
 * @file PassingParamToTherads.cpp
 * @author Abhishek
 * @brief Here we discuss about the thread constructors and how to use them:
 * Thread Class contructors(four of them):
    1- deafault				- thread() noexcept
    2- initialization		- template <class Fn, class... Args>
                                explicit thread (Fn&& fn, Args**... args)
    3- copy[deleted]		- thread (const thread&) = delete
    4- move					- thread (thread&& x) noexcept
 *
 * @version 0.1
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <thread>
#include <chrono>

void func_1(int x, int y)
{
    printf("X + Y = %d \n", x+y);
}

void func_2(int& x)
{
    while(true)
    {
        printf("Thread 1 calue of X = %d \n", x);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void run()
{
    int p = 10, q = 11;
    std::thread t1(func_1, p, q);
    t1.join();
}

void run_2()
{
    int x = 10;

    printf("Main thread value of X - %d \n", x);

    std::thread refThread(func_2, std::ref(x));
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    x = 15;
    printf("Main thread value of X has been changed to - %d \n", x);
    refThread.join();
}

int main(int argc, char const *argv[])
{
    //run();
    run_2();
    return 0;
}
