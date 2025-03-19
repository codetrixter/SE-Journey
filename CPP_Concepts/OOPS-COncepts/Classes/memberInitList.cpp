/**
 * @file memberInitList.cpp
 * @author Abhishek Mishra      
 * @brief C++11 provideas a way tp initialize the member variables of the class without assigning values to them
 * after they are created. It is called member initializer list.
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
    mem_A{valA}, Arr{1, 2, 3, 4, 5}, sum{valB}      //initilaizing the A's class member variables and array
    {
        std::cout << "inside B ctor" << sum;
    }

};

int main(int argc, char const *argv[])
{
    B nObj(5, 10);

    return 0;
}
