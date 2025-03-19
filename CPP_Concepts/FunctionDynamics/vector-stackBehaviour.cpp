/**
 * @file vector-stackBehaviour.cpp
 * @author Abhishek
 * @brief  Here we discuss the vector capacity and its stack behaviour.
 * We usually avoid the vector from resizing itself since it is a very expensive operation
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>

/* void printStack(const std::vector<int>& stack)
{
	for (auto element : stack)
		std::cout << element << ' ';
	std::cout << "(cap " << stack.capacity() << " length " << stack.size() << ")\n";
}

int main()
{
	std::vector<int> stack{};
	stack.reserve(5);

	printStack(stack);

	stack.push_back(5); // push_back() pushes an element on the stack
	printStack(stack);

	stack.push_back(3);
	printStack(stack);

	stack.push_back(2);
	printStack(stack);

	std::cout << "top: " << stack.back() << '\n'; // back() returns the last element

	stack.pop_back(); // pop_back() pops an element off the stack
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	return 0;
} */

/* 
(cap 0 length 0)
5 (cap 1 length 1)
5 3 (cap 2 length 2)
5 3 2 (cap 4 length 3)
top: 2
5 3 (cap 4 length 2)
5 (cap 4 length 1)
(cap 4 length 0)
--------------------------
With reserved size of vector we dont resize at all:

(cap 5 length 0)
5 (cap 5 length 1)
5 3 (cap 5 length 2)
5 3 2 (cap 5 length 3)
top: 2
5 3 (cap 5 length 2)
5 (cap 5 length 1)
(cap 5 length 0)
*/

//**********************vetor resizing value is taken with incremental values to avoid constant resizing.
int main()
{
	std::vector<int> v{ 0, 1, 2, 3, 4 };
	std::cout << "size: " << v.size() << "  cap: " << v.capacity() << '\n';

	v.push_back(5); // add another element
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	//once the size limit is reached for the vector, its capacity is doubled everytime.
	std::cout << "size: " << v.size() << "  cap: " << v.capacity() << '\n';

	return 0;
}
//**********************vetor resizing value is taken with incremental values to avoid constant resizing.