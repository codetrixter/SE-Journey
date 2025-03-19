/**
 * @file staticMemberFunctions.cpp
 * @author Abhishek
 * @brief static member functions important points:
 * 1- If we want to access private static data members of the class we can use static member functions.
 * 2- static member funtions dont have hidden this pointer.
 * 3- static member functions can access staic members(data and functions) but cannot access non-static members, this
 * is because non-static members must belong to class.
 * 4- pure static classes acts as class decalred with global scope.
 * 5- C++ does not suppor static constructors unlike other programming languages where static ctors are allowed.
 * @version 0.1
 * @date 2022-06-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

//*************using static member functions
// class Something
// {
// private:
//     static int s_value;
// public:
//     static int getValue() { return s_value; } // static member function
// };

// int Something::s_value{ 1 }; // initializer

// int main()
// {
//     std::cout << Something::getValue() << '\n';
// }
//*********************
//***************defining static members outside the class
#include <iostream>

class IDGenerator
{
private:
    static int s_nextID; // Here's the declaration for a static member

public:
     static int getNextID(); // Here's the declaration for a static function
};

// Here's the definition of the static member outside the class.  Note we don't use the static keyword here.
// We'll start generating IDs at 1
int IDGenerator::s_nextID{ 1 };

// Here's the definition of the static function outside of the class.  Note we don't use the static keyword here.
int IDGenerator::getNextID() { return s_nextID++; }

int main()
{
    for (int count{ 0 }; count < 5; ++count)
        std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';

    return 0;
}
//***************

//***************Different unique ways of initializing static members.
class MyClass
{
public:
    static std::vector<char> s_mychars;
};

std::vector<char> MyClass::s_mychars{
  []{ // The parameter list of lambdas without parameters can be omitted.
      // Inside the lambda we can declare another vector and use a loop.
      std::vector<char> v{};

      for (char ch{ 'a' }; ch <= 'z'; ++ch)
      {
          v.push_back(ch);
      }

      return v;
  }() // Call the lambda right away
};

//****
class MyClass
{
public:
	static std::vector<char> s_mychars;

public:

	class init_static // we're defining a nested class named init_static
	{
	public:
		init_static() // the init constructor will initialize our static variable
		{
			for (char ch{ 'a' }; ch <= 'z'; ++ch)
			{
				s_mychars.push_back(ch);
			}
		}
	} ;

private:
// we'll use this static object to ensure the init_static constructor is called.
	static init_static s_initializer; 
};
// define our static member variable
std::vector<char> MyClass::s_mychars{}; 
// define our static initializer, which will call the init_static constructor, which will initialize s_mychars
MyClass::init_static MyClass::s_initializer{}; 
//***************