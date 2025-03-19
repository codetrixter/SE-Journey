/**
 * @file threadSafeQ.cpp
 * @author Abhishek
 * @brief Here we implement a thread safe version of queue which prevents following race conditions:
 * 1- empty() vs front()
 * 2- empty() vs back()
 * 3- pop() vs back()
 * 4- pop() vs front() 
 * @version 0.1
 * @date 2022-10-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <thread>

#include "threadSafeQ.hpp"

thread_safe_queue<int> queue;

void func_1()
{
	int value;
	queue.wait_pop(value);
	std::cout << value << std::endl;

}

void func_2()
{
	int x = 10;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	queue.push(x);
}

int main()
{
	std::thread thread_1(func_1);
	std::thread thread_4(func_1);
	std::thread thread_2(func_2);
	std::thread thread_3(func_2);

	thread_1.join();
	thread_2.join();
    thread_3.join();
    thread_4.join();
}