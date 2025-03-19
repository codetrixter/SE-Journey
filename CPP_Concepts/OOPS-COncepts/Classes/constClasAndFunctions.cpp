/**
 * @file constClasAndFunctions.cpp
 * @author Abhishek
 * @brief Const class and member functions:
 * Here we cover that:
 * 1- const data memebers and object needs to be initialized at the time of decalration.
 * 2- const object cannot call non-cont member functions as that would violate the rule of const.
 * 3- any const member function cannot change or call the non-const members of the class.
 * 4- never make function parameters as const if they are call by value, since they are temporary.
 * 5- const members cannot return non-const references to members.
 * 6- If a const member function is invoked on non-const objects then the function returns const object.
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>

//******************************const members
// class Something
// {
// public:
//     int m_value {};

//     Something(): m_value{0} { }

//     void resetValue() { m_value = 0; }
//     void setValue(int value) { m_value = value; }

//     int getValue() const; // note addition of const keyword here
// };

// int Something::getValue() const // and here
// {
//     return m_value;
// }

// int main()
// {
//     const Something something{}; // calls default constructor

//     something.m_value = 5; // compiler error: violates const
//     something.setValue(5); // compiler error: violates const

//     return 0;
// }
//********************************

//********************************const member overloading
class Something
{
private:
    std::string m_value {};

public:
    Something(const std::string& value=""): m_value{ value } {}

    const std::string& getValue() const { return m_value; } // getValue() for const objects (returns const reference)
    std::string& getValue() { return m_value; } // getValue() for non-const objects (returns non-const reference)
};
int main()
{
	Something something;
	something.getValue() = "Hi"; // calls non-const getValue();

	const Something something2;
	something2.getValue(); // calls const getValue();

	return 0;
}
//*********************************