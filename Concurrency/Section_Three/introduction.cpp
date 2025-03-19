/**
 * @file introduction.cpp
 * @author Abhishek
 * @brief Here we try to understand and implement following scenario:
 * 1- Imagine we are on a bus ride to some place, if we wnat to reach the destination, we can do so in following ways:
 *      a. Awake all night chatting with the driver.
 *      b. Set alarm clock and then wake up to it.
 *      c. Ask someone to wake you up upon the arrival of the destination.
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
#include <thread>
#include <chrono>

bool have_i_arrived = false;
int distance_my_destination = 10;
int distance_coverd = 0;

bool keep_driving()
{
	while (!have_i_arrived)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		distance_coverd++;
	}

	return false;
}

void keep_awake_all_night()
{
    //This check uses more CPU time hence satisfying the condition of driver being busy chatting.
	while (distance_coverd < distance_my_destination)
	{
		std::cout << "keep check, whether i am there \n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
    have_i_arrived = true;
	std::cout << "finally i am there, distance_coverd = " << distance_coverd << std::endl;;
}

//running this multiple times migt give us different results, modeling traffic conditions.
void set_the_alarm_and_take_a_nap()
{
	if (distance_coverd < distance_my_destination)
	{
		std::cout << "let me take a nap \n";
		std::this_thread::sleep_for(std::chrono::milliseconds(10000));
	}
    have_i_arrived = true;
	std::cout << "finally i am there, distance_coverd = " << distance_coverd << std::endl;;
}

int main()
{
	std::thread driver_thread(keep_driving);
	std::thread keep_awake_all_night_thread(keep_awake_all_night);
	std::thread set_the_alarm_and_take_a_nap_thread(set_the_alarm_and_take_a_nap);

	keep_awake_all_night_thread.join();
	set_the_alarm_and_take_a_nap_thread.join();
	driver_thread.join();

    return 0;
}
