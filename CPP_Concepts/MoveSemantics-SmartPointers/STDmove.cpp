/**
 * @file STDmove.cpp
 * @author Abhishek
 * @brief Here we discuss about the std::move and how to use it:
 * 1- We can invoke move copy contructor and move assignement on l-values by using std::move, which casts l-value to r-value reference.
 * 2- We should not use std::move on any persistent object we don't want to modify.
 * 
 * CONCLUSION:
 * //!std::move can be used whenever we want to treat an l-value like an r-value for the purpose of invoking move semantics instead of copy semantics.
 * //!std::move can alsobe used in a lot of sorting algorithms since thise involve a lot of swapping.
 * @version 0.1
 * @date 2022-09-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <utility>

// copy version of the swap, this leads to excessive string creation and destruction which is slow.
// template<class T>
// void myswap(T& a, T& b)
// {
// 	T tmp { a }; // invokes copy constructor
// 	a = b; // invokes copy assignment
// 	b = tmp; // invokes copy assignment
// } 

//Move version of swap
/* template<class T>
void myswap(T& a, T& b)
{
	T tmp { std::move(a) }; // invokes move constructor
	a = std::move(b); // invokes move assignment
	b = std::move(tmp); // invokes move assignment
}

int main()
{
	std::string x{ "abc" };
	std::string y{ "de" };

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	myswap(x, y);

	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	return 0;
} */
//*******************Alternate ex***
#include <vector>

int main()
{
	std::vector<std::string> v;
	std::string str = "Knock";

	std::cout << "Copying str\n";
	v.push_back(str); // calls l-value version of push_back, which copies str into the array element

	std::cout << "str: " << str << '\n';
	std::cout << "vector: " << v[0] << '\n';

	std::cout << "\nMoving str\n";

	v.push_back(std::move(str)); // calls r-value version of push_back, which moves str into the array element

	// Here str is  a moved from object, these objects are in a valid but indeterminate state hence should be avoided for any use after move operation.
	std::cout << "str: " << str << '\n';
	std::cout << "vector:" << v[0] << ' ' << v[1] << '\n';
}

	