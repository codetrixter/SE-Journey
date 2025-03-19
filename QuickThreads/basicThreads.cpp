/**
 * @file basicThreads.cpp
 * @author Abhishek
 * @brief 
 * 1- created two threads which show the parallel work done is faster than sequential.
 * NOTE***
 * Try compiling using
    g++ -O3 filename
    or
    g++ -Ofast filename
    or else it might beslower using threads
 * @version 0.1
 * @date 2022-08-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

using ull = unsigned long long;

ull oddSum{ 0 };
ull evenSum{ 0 };

void findEven(ull start, ull end)
{
    for(ull i = start; i <= end; ++i)
    {
        if((i & 1) == 0)
            evenSum += i;
    }
}

void findOdd(ull start, ull end)
{
    for(ull i = start; i <= end; ++i)
    {
        if((i & 1) == 1)
            oddSum += i;
    }
}

int main(int argc, char const *argv[])
{
    ull start{ 0 };
    ull end{ 1900000000 };

    auto startTime{ high_resolution_clock::now() };

    //here we have created threads using function pointers, which represent the task to be done by the threads.
    std::thread t1(findEven, start, end);
    std::thread t2(findOdd, start, end);

    //join() lets the new threads t1 and t2 finish before exiting from main thread.
    t1.join();
    t2.join();
    // findEven(start, end);
    // findOdd(start, end);

    auto endTime{ high_resolution_clock::now() };

    auto duration{ duration_cast<milliseconds>(endTime - startTime) };

    std::cout << "OddSum : " << oddSum << std::endl;
    std::cout << "EvenSum : " << evenSum << std::endl;

    std::cout << duration.count() << std::endl; 
    return 0;
}
