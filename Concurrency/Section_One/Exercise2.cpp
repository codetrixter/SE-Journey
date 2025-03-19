/**
 * @file Exercise2.cpp
 * @author Abhishek
 * @brief 
    * TODO:
    * 1- Each role should be performed by different functions, and we have to launch a thread with
	*  particular function to execute the given order.
    * 2- Lets assume there are three actors:
    * a. Captian: main thread-> can issue 3 commands.
    *		1. order cleaning crew to clean, captain does not have to wait for this untill its done.
    *		2. Full speed ahead, captain has to wait 
    *		3. stop the engine, captiain has to wait
    * b. engine crew:
    * c. cleaners: 
    * 
    * WAP a menu driven program which takes the above three commands and stops when entered 100.
 * @version 0.1
 * @date 2022-09-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <chrono>
#include <thread>

void cleanTheShip()
{
	printf("Cleaning... \n");
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	printf("Cleaned... \n");
}

void fullSpeedAhead()
{
	printf("speeding ahead... \n");
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	printf("At full speed... \n");
}

void stopTheShip()
{
	printf("Halting... \n");
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	printf("Halted... \n");
}

int run()
{
	int commands = 0;
	do 
	{
		std::cout << "Enter the Commands Captain... \n";
		std::cout << "Enter 1 for cleaning the Ship... \n";
		std::cout << "Enter 2 for full speed ahead... \n";
		std::cout << "Enter the Stopping the ship... \n";
		std::cout << "Enter 100 for exit... \n";
		std::cin >> commands;
		// Why is this not working...
		/*switch (commands)
		{
		case 1:
			std::thread orderClean(cleanTheShip);
			orderClean.detach();
			break;
		case 2:
			std::thread orderSpeedAhead(fullSpeedAhead);
			orderSpeedAhead.join();
			break;
		case 3:
			std::thread orderHalt(stopTheShip);
			orderHalt.join();
			break;
		case 100:
			exit(0);
		default:
			std::cout << "Ivalid option selected... \n";
		}*/
		if (1 == commands)
		{
			std::thread orderClean(cleanTheShip);
			orderClean.detach();
		}
		else if (2 == commands)
		{
			std::thread orderSpeedAhead(fullSpeedAhead);
			orderSpeedAhead.join();
		}
		else if (3 == commands)
		{
			std::thread orderHalt(stopTheShip);
			orderHalt.join();
		}
		else if (100 == commands)
		{
			exit(0);
		}
	} while (commands != 100);
	
	return 0;
}
int main(int argc, char const *argv[])
{
    run();
    return 0;
}
