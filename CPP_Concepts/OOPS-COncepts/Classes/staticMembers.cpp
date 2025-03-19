/**
 * @file staticMembers.cpp
 * @author Abhishek 
 * @brief Here we discuss the properties of the static members 
 * 1- They are associated with the class and not the object, hence they are shared among objects.
 * 2- When static members are of const integral type(char and bool) or const enum, then there is no 
 * need for initialization outside the class.
 * @version 0.1
 * @date 2022-06-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
//*******************
// class Something
// {
// public:
//     static int s_value; // declares the static member variable
// };

// int Something::s_value{ 1 }; // defines the static member variable (we'll discuss this section below)

// int main()
// {
//     // note: we're not instantiating any objects of type Something

//     Something::s_value = 2;
//     std::cout << Something::s_value << '\n';
//     return 0;
// }
//************************

//************************const statc members 
// #include <array>

// class Whatever
// {
// public:
//     static constexpr double s_value{ 2.2 }; // ok
//     static constexpr std::array<int, 3> s_array{ 1, 2, 3 }; // this even works for classes that support constexpr initialization
// };

//***********************

//**********************non const static members init in c++17
class Whatever
{
public:
    static inline int s_value{ 4 }; // a static inline int can be declared and initialized directly (C++17)
};
int main(int argc, char const *argv[])
{
    return 0;
}

//*************************
