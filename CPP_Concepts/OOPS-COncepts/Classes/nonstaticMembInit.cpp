/**
 * @file nonstaticMembInit.cpp
 * @author Abhishek 
 * @brief non static member initializer list
 * @version 0.1
 * @date 2022-05-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

class square
{
    private:
    //non static member initializer list.
    int val_a{ 10 };
    int val_b{ 20 };    //brace init
    int val_d = 40;     //copy initi
    //int val_c( 30 );        //parenthesis cannot be used for non static member init.

    public:
    square(int valA, int valB):
    val_a{valA}, val_b{valB}
    {
        std::cout << "ctor" << val_a << val_b;
    }
};

int main(int argc, char const *argv[])
{
    square sq{10, 20};
    square sqNew(30, 40);     
    return 0;
}
