/**
 * @file futures.cpp
 * @author Abhsihek
 * @brief Here we discuss about the std::future:
 * 1- It provides a mechanism to access the result of asynchronous operation.
 * @version 0.1
 * @date 2022-10-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <future>

int do_background_task()
{
    std::cout <<"doing heavy task \n";
    return 5000;
}

void do_other_tasks()
{
    std::cout << "doing other stuff \n";
}

int main(int argc, char const *argv[])
{
    std::future<int> result = std::async(do_background_task);
    do_other_tasks();
    std::cout << "The result of async task is : " << result.get() << std::endl;
    return 0;
}
