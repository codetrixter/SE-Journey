/**
 * @file threadConstructors.cpp
 * @author Abhishek
 * @brief Here we discuss the types of thread constructors:
    * Thread Class contructors(four of them):
    * 1- deafault				- thread() noexcept
    * 2- initialization		    - template <class Fn, class... Args>
                                    explicit thread (Fn&& fn, Args**... args)				  
    * 3- copy[deleted]		    - thread (const thread&) = delete
    * 4- move					- thread (thread&& x) noexcept
 * @version 0.1
 * @date 2022-09-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <thread>
namespace
{
	void func_1(int x, int y)
	{
		printf("X + Y = %d \n", x + y);
	}

	void run()
	{
		int p = 10, q = 11;
		std::thread t1(func_1, p, q);
		t1.join();
	}

	int main()
	{
		run();
		return 0;
	}
}