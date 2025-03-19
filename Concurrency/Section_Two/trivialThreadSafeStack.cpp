/**
 * @file trivialThreadSafeStack.cpp
 * @author Abhishek
 * @brief Here we implement a simple thread safe stack, few facts about below implementation:
 * 1- We have wrapped all stack functionalities with synchronization mechanisms.
 * 2- We achieved thread safety but limited our parallelism, as only one thread has access to a function at a time.
 * 3- Few race conditions can still occur, which are called race conditions inherit from interface:
 *      a. Race condition between empty() and top().
 *      b. Race condition between top() and pop().
 * @version 0.1
 * @date 2022-10-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <iostream>
#include <mutex>
#include <stack>
#include <thread>

template<typename T>
class trivial_thread_safe_stack {
	std::stack<T> stk;
	std::mutex m;

public:
	void push(T element)
	{
		std::lock_guard<std::mutex> lg(m);
		stk.push(element);
	}

	void pop()
	{
		std::lock_guard<std::mutex> lg(m);
		stk.pop();
	}

	T& top()
	{
		std::lock_guard<std::mutex> lg(m);
		return stk.top();
	}

	bool empty()
	{
		std::lock_guard<std::mutex> lg(m);
		return stk.empty();
	}

	size_t size()
	{
		std::lock_guard<std::mutex> lg(m);
		return stk.size();
	}
};