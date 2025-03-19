/**
 * @file threadLocal.cpp
 * @author Abhishek
 * @brief Here we discuss about the thread_local specifier:
 * @version 0.1
 * @date 2022-10-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <thread>
#include <atomic>

// Here thread_local specifier gives each thread a local copy of the variable i.
thread_local std::atomic<int> i{ 0 };

void foo()
{
    ++i;
    std::cout << i;
}
int main(int argc, char const *argv[])
{
    std::thread t1(foo);
    std::thread t2(foo);
    std::thread t3(foo);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}

