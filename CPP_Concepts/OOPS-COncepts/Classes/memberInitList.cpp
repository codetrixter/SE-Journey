/**
 * @file memberInitList.cpp
 * @author Abhishek Mishra      
 * @brief C++11 provideas a way to initialize the member variables of the class, It is called member initializer list.
 * 1- In the the member initializer list, the member variables are initialized before the body of the constructor is executed.
 * 2- The member initializer list is more efficient than assignment in the constructor body.
 * 3- The member initializer list is the only way to initialize the const and reference member variables.
 * @version 0.1
 * @date 2022-05-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

class A
{
    private:
    int val_a;

    public:
    A(int val): val_a{val}
    {
        std::cout << "inside A ctor" << val_a << "\n";
    }
};

class B
{
    private:
    A mem_A;
    const int Arr[5];
    int sum;

    public:
    B(int valA, int valB):
    mem_A{valA}, Arr{1, 2, 3, 4, 5}, sum{valB}      /// initilaizing the A's class member variables and array
    {
        std::cout << "inside B ctor" << sum;
    }

};

int main(int argc, char const *argv[])
{
    B nObj(5, 10);

    return 0;
}
