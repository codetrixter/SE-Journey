/**
 * @file helloThreads.cpp
 * @author Abhishek
 * @brief creating and using threads
 * @version 0.1
 * @date 2022-06-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <thread>

void function1()
{
   printf("Inside function1()... %d \n", std::this_thread::get_id());
}

class callableClass
{
public:
   void operator()()
   {
      printf("Inside callable class ()... %d \n", std::this_thread::get_id());
   }
};

void run()
{
   callableClass obj1;
   std::thread t1(function1);
   std::thread t2(obj1);

   std::thread t3([]
      {
         printf("Inside lambda()... %d \n", std::this_thread::get_id());
      });

   t1.join();
   t2.join();
   t3.join();

   printf("Inside main()... %d \n", std::this_thread::get_id());
}

int main(int argc, char const *argv[])
{
    run();
    return 0;
}

