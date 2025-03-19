/**
 * @file joinAndDetach.cpp
 * @author Abhishek
 * @brief Here we discuss about the join and detach functions of thread class and when to use them:
 * JOIN, DETACH AND JOINABILITY::
    * JOIN:
    * 1- join() basically acts as a synchronization point between the new thread that calls join() and the parent thread within which the new thread is launched from.
    * 2- It will block the parent thread's execution untill newly launched thread's execution completes.
    *
    * DETACH:
    * 1- detach() basically makes the launched thread independent to the parent thread or the thread that launched the thread on which detach is called.
    * 2- WIth detach(), both parent and child threads execute independently.
 * @version 0.1
 * @date 2022-09-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <thread>
#include <chrono>

void foo()
{
	printf("Hello from foo.. \n");
}

void bar()
{
	printf("Hellow from bar.. \n");
}

void run()
{
	// properly constructed threads
	std::thread thread1(foo);
	std::thread thread2(bar);
	/*
	* Here we see that since thread2is detached, hence the main threads print function executes,
	and then thread2 executes, since they are independent
	*/
	thread2.detach();
	if (thread2.joinable())
		printf("After bar has been detahced from main \n");
	else
		printf("thread2 is not joinable... \n");

	/*
	* Here we see that thread1 executes first, finishes and the main thread prints, which means ain thread waited fro thread1 to finish,
	hence dependency is there.
	*/
	thread1.join();
	if (thread1.joinable())
		printf("After the foo thread is joined to main.. \n");
	else
		printf("Thread1 is not joinable \n");

	//Improperly constructed thread is non-joinable, even without calling join/detach on them.
	std::thread threads;
	if (threads.joinable())
		printf("threads is joinable... \n");
	else
		printf("threads is not joinable... \n");
}

int main()
{
	run();

	return 0;
}