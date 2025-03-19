/**
 * @file mutexThingsToRemember.cpp
 * @author Abhishek
 * @brief here we see the things we need to take care of while using mutex:
 * 1- When returning pointer/reference to the protected data.
 * 2- passing code to the protected data structure which you don't have control on.
 * @version 0.1
 * @date 2022-10-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <mutex>
#include <list>
#include <thread>

/*********************** example 1 *********************/
class list_wrapper
{
    std::list<int> my_list;
    std::mutex m;

public:
    void add_to_list(int const &x)
    {
        std::lock_guard<std::mutex> lg(m);
        my_list.push_front(x);
    }

    void size()
    {
        std::lock_guard<std::mutex> lg(m);
        int size = my_list.size();
        std::cout << "size of the list is : " << size << std::endl;
    }

    std::list<int> *get_data()
    {
        // Here once the pointer to the list is handed over,
        // we can no longer ensure the thread safety of this member since it can be used in any way.
        return &my_list;
    }
};

/*********************** example 2 *********************/
class data_object
{

public:
    void some_operation()
    {
        std::cout << "this is some operation \n";
    }
};

class data_wrapper
{

    data_object protected_data;
    std::mutex m;

public:
    template <typename function>
    void do_some_work(function f)
    {
        std::lock_guard<std::mutex> lg(m);
        f(protected_data);  //the function pointer passed here may not be thread safe hence should be avoided, as in this case it exposes protected data.
    }
};

data_object *unprotected_data;

void malisious_function(data_object &data)
{
    unprotected_data = &data;
}

void run_code()
{
    data_wrapper wrapper;
    wrapper.do_some_work(malisious_function);
}

int main()
{
    run_code();
}