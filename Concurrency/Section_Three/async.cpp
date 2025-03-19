/**
 * @file async.cpp
 * @author Abhishek
 * @brief Here we discuss about async tasks:
 * 1- std::async(std::launch policy, Function&& f, Args&&... args);
 *      a. std::launch::async: tasks gets executed in a separate thread.
 *      b. std::launch::deferred: task gets executed in the creators thread when future.get is invoked.
 *      c. both can be given as well, which leaves the decision on the compiler.
 * @version 0.1
 * @date 2022-10-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <future>
#include <string>

void printing()
{
	std::cout << "printing runs on-" << std::this_thread::get_id() << std::endl;
}

int addition(int x, int y)
{
	std::cout << "addition runs on-" << std::this_thread::get_id() << std::endl;
	return x + y;
}

int substract(int x, int y)
{
	std::cout << "substract runs on-" << std::this_thread::get_id() << std::endl;
	return x - y;
}

int main()
{
	std::cout << "main thread id -" << std::this_thread::get_id() << std::endl;

	int x = 100;
	int y = 50;

	std::future<void> f1 = std::async(std::launch::async, printing);
	std::future<int> f2 = std::async(std::launch::deferred, addition, x, y);
	std::future<int> f3 = std::async(std::launch::deferred | std::launch::async, substract, x, y);
	f1.get();
    
    //Deferred tasks are executed after the below call is made.
	std::cout << "value recieved using f2 future -" << f2.get() << std::endl;   //This will not run if the future.get() is not called/
    //This will execute depending on whether future.get() is there or not, if not: then it will be invoked immediatly else after this call.
	std::cout << "value recieved using f2 future -" << f3.get() << std::endl;   

}