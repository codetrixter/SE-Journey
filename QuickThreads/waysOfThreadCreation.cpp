/**
 * @file waysOfThreadCreation.cpp
 * @author Abhishek
 * @brief TOPIC: Different Types Of Thread Creation And Calling.
    There are 5 different types of creating threads and calling callable in threads.

    NOTES: Different types for creating threads.
    1. Function Pointer -- this is the very basic form of creating threads.
    2. Lambda Function
    3. Functor (Function Object)
    4. Non-static member function:
        a.For a non-static member function of a class, you have to provide a pointer to the object, because 
        non-static member functions of a class take the first pointer to the object as a hidden parameter, which 
        is called 'this' pointer. When you use C++ to call a non-static member function you don't need to provide the 
        `this' pointer because C++ takes care of it and it knows that, but it's how the program works under the hood. 
        For std::thread you have to explicitly pass `this' pointer as the first parameter.
    5. Static member function:
        Static member functions of classes, don't have an object associated with them. Therefore, they don't 
        need to pass `this' pointer as the first parameter. In fact, using `this' pointer inside a static member 
        function of a class is illegal in C++. It would be a compiler error. Try it if you don't believe me.
 * @version 0.1
 * @date 2022-08-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <thread>
//**********Creating threads using function pointer***
/* void fun(int x)
{
    //printing the value of x in reverse order
    while(x-- > 0)
        std::cout << x << std::endl;
}

int main(int argc, char const *argv[])
{
    std::thread t1(fun, 20);
    t1.join();
    return 0;
} */
//**********Creating threads using function pointer***
//**********Creating threads using Lambda***
/* int main(int argc, char const *argv[])
{
    std::thread t1([](int x)
    {
        while(x-- > 0)
            std::cout << x << std::endl;
    }, 10);

    //sigabrt is called if we miss this line.
    t1.join();
    return 0;
} */
//**********Creating threads using Lambda***
//**********Creating threads using Funtors***
/* class Base
{
    public:
    void operator()(int x)
    {
        while(x-- > 0)
            std::cout << x << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    std::thread t1((Base()), 30);
    t1.join();
    return 0;
} */
//**********Creating threads using Funtors***
//**********Creating threads using Non-Static member function***
/* class Base
{
public:
    void fun(int x)
    {
        // printing the value of x in reverse order
        while (x-- > 0)
            std::cout << x << std::endl;
    }
};
int main(int argc, char const *argv[])
{
    Base base{};
    std::thread t1((&Base::fun), &base, 5);
    t1.join();
    return 0;
} */
//**********Creating threads using Non-Static member function***
//**********Creating threads using Static member function***
class Base
{
public:
    static void fun(int x)
    {
        // printing the value of x in reverse order
        while (x-- > 0)
            std::cout << x << std::endl;
    }
};
int main(int argc, char const *argv[])
{
    Base base{};
    std::thread t1((&Base::fun), 15);
    t1.join();
    return 0;
}
//**********Creating threads using Static member function***
