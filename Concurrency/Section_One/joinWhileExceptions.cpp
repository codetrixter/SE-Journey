/**
 * @file joinWhileExceptions.cpp
 * @author Abhishek
 * @brief Here we discuss about the handling thread lifecycle during exceptions:
 * 
 * @version 0.1
 * @date 2022-09-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <thread>
#include <vector>

void foo1()
{
   printf("Hello from foo... \n");
}

void otherOperation()
{
   std::cout << "This is other operation... \n";
   throw std::runtime_error("this is a runtime error");
}

class thread_guard
{
private:
   std::thread& t;

public:
   explicit thread_guard(std::thread& _t) :
      t(_t)
   {}

   ~thread_guard()
   {
      if (t.joinable())
         t.join();
   }
     
   thread_guard(const thread_guard& tg) = delete;
   thread_guard& operator= (const thread_guard& tg) = delete;
};

//****************Approach with RAII***
int run()
{
   //run();

   // runTryCatch();

   //New approach
   std::thread t1(foo1);
   thread_guard newThread(t1);   //when this object goes out of scope due to exception, its detructor calls join on the thread, hence it is safe

   try
   {
      otherOperation();
   }
   catch (const std::exception&)
   {

   }
   return 0;
}
int main(int argc, char const *argv[])
{
    run();
    return 0;
}

