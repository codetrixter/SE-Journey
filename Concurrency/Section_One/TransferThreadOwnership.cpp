/**
 * @file TransferThreadOwnership.cpp
 * @author Abhishek
 * @brief Here we discuss how to transfer the ownership of a thread 
 * @version 0.1
 * @date 2022-09-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <chrono>
#include <thread>

void foo()
{
    std::cout << "Inside foo()... \n";
}
void bar()
{
    std::cout << "Inside bar()... \n";
}
void run()
{
    std::thread thread_1(foo);

    //This will not work since copy ctor is deleted.error: use of deleted function ‘std::thread::thread(const std::thread&)’
    //std::thread thread_2 = thread_1;    
    std::thread thread_2 = std::move(thread_1); 

    thread_1 = std::thread(bar);   //Here move constructor is invoked implicitly since thread object is created anonymously.

    // Trying to move thread object to an already owning thread variable, CANNOT do this gives exception!!
    std::thread thread_3(bar);
    thread_1 = std::move(thread_3);

    thread_1.join();
    thread_2.join();
    thread_3.join();
}
int main(int argc, char const *argv[])
{
    run();
    return 0;
}
