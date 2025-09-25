/**
 * @file staticMembers.cpp
 * @author Abhishek 
 * @brief Here we discuss the properties of the static members 
 * 1- They are global variables that are associated with the class and not the object, hence they are shared among objects.
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
/* class Something
{
public:
    static int s_value; // declares the static member variable
};

int Something::s_value{ 1 }; // defines the static member variable (we'll discuss this section below)

int main()
{
    /// note: we're not instantiating any objects of type Something

    Something::s_value = 2;
    std::cout << Something::s_value << '\n';
    return 0;
} */
//************************

//************************another way of initializing static variables inside the class
/* #include <array>

class Whatever
{
public:
    static constexpr double s_value{ 2.2 }; // ok
    static constexpr std::array<int, 3> s_array{ 1, 2, 3 }; // this even works for classes that support constexpr initialization
}; */

//***********************

//**********************initializing static variabls inside the class
/* class Whatever
{
public:
    static const int s_value1{ 3 }; // a static const int can be declared and initialized directly
    static inline int s_value{ 4 }; // a static inline int can be declared and initialized directly (C++17)
};
int main(int argc, char const *argv[])
{
    return 0;
} */
//*************************

//*************************Only static memebres can have auto or CTAD, which is not possible for non-static members

/* #include <utility> // for std::pair<T, U>

class Foo
{
private:
    /// auto m_x { 5 };           // auto not allowed for non-static members
    /// std::pair m_v { 1, 2.3 }; // CTAD not allowed for non-static members

    static inline auto s_x { 5 };           // auto allowed for static members
    static inline std::pair s_v { 1, 2.3 }; // CTAD allowed for static members

public:
    Foo() {};
};

int main()
{
    Foo foo{};

    return 0;
} */
//*************************
