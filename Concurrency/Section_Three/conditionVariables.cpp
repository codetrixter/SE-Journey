/**
 * @file conditionVariables.cpp
 * @author Abhishek
 * @brief Here we discuss about the condition varibales and how to use them:
 * 1- Condition variables(Synchronization primitive) are used for event based thread programming, where a thread waits for an event to be triggered by another
 *  thread before proceeding with some task.
 * 2- An event can notify one/or more threads once the condition satisfies.
 * PROCEDURE:
 * The thread that intends to modify the shared variable has to 
 *  1- acquire a std::mutex (typically via std::lock_guard)
    2- perform the modification while the lock is held
    3- execute notify_one or notify_all on the std::condition_variable (the lock does not need to be held for notification)
    Even if the shared variable is atomic, it must be modified under the mutex in order to correctly publish the modification to the waiting thread.

    - Any thread that intends to wait on std::condition_variable has to

    1- acquire a std::unique_lock<std::mutex>, on the same mutex as used to protect the shared variable
        either
        a. check the condition, in case it was already updated and notified
        b. execute wait, wait_for, or wait_until. The wait operations atomically release the mutex and suspend the execution of the thread.
        c. When the condition variable is notified, a timeout expires, or a {SPURIOUS WAKEUP} occurs, the thread is awakened, and the mutex is atomically reacquired. The 
        thread should then check the condition and resume waiting if the wake up was spurious.
 * @version 0.1
 * @date 2022-10-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <chrono>
#include <condition_variable>

bool have_i_arrived = false;
int total_distance = 5;
int distance_coverd = 0;
std::condition_variable cv;
std::mutex m;

void keep_moving()
{
	while (!have_i_arrived)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		distance_coverd++;
        std::cout << "moving towards destination... \n";

		//notify the waiting threads if the event occurs
		if (distance_coverd == total_distance)
			cv.notify_one();
	}

}

void ask_driver_to_wake_u_up_at_right_time()
{
	std::unique_lock<std::mutex> ul(m);
	cv.wait(ul, [] {return distance_coverd == total_distance; });
    have_i_arrived = true;
	std::cout << "finally i am there, distance_coverd = " << distance_coverd << std::endl;;
}

int main()
{
	std::thread driver_thread(keep_moving);
	std::thread passener_thread(ask_driver_to_wake_u_up_at_right_time);
	passener_thread.join();
	driver_thread.join();
}