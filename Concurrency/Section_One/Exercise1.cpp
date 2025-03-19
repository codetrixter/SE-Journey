/**
 * @file Exercise1.cpp
 * @author Abhishek
 * @brief Launching of threads
 * @version 0.1
 * @date 2022-09-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <thread>

void functionC()
{
	printf("Hello from functionC... \n");
}

void functionA()
{
	printf("Hello from functionA... \n");
	std::thread tC(functionC);
	tC.join();
}
void functionB()
{
	printf("Hello from functionB... \n");
}
/*
* Need to define threads and then call join on them to maintain the sequence of the threads.
*/
int run()
{
	std::thread tA(functionA);
	tA.join();
	std::thread tB(functionB);
	tB.join();

	printf("Hello from main... \n");

	return 0;
}
int main(int argc, char const *argv[])
{
    run();
    return 0;
}
