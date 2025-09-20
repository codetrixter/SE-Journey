/**
 * @file commandLineArguments.cpp
 * @author Abhishek
 * @brief Here we look at how command line arguments work:
 * 1- the command line arguments are the arguments that are part of the main function and they
 * process the arguments which are passed while executing program.
 * 2- there are two parameters:
 *  a- argc -> this keeps count of the number of arguments passed after the executable file name.
 *  b- argv -> this is the pointer to c-style chars which contains the strings divided by spaces.
 * 3- Usually stings passed as arguments while executing the code is parsed by the shell, hence for different 
 * type of results we can do:
 *  a- for passing a single string with multiple words use "abhishek is good" argv1 = abhishek is good
 *  b- for taking double quote as a string use \"abhihsek is good\" -> argv1 = \"abhishek, argv2 = is, argv3 = good\" 
 * @version 0.1
 * @date 2022-06-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <sstream>
//****************basic command line example***
 int main(int argc, char const *argv[])
{
    for(int i = 0; i < argc; i++)
    {
        std::cout << i << ' ' << argv[i] << "\n";
    }
    return 0;
} 
//****************basic command line example***
//****************Dealing with numerc arguments***
/*
int main(int argc, char* const argv[])
{
    if (argc <= 1)
	{
		// On some operating systems, argv[0] can end up as an empty string instead of the program's name.
		// We'll conditionalize our response on whether argv[0] is empty or not.
		if (argv[0])
			std::cout << "Usage: " << argv[0] << " <number>" << '\n';
		else
			std::cout << "Usage: <program name> <number>" << '\n';

		return 1;
	}

	std::stringstream convert{ argv[1] }; // set up a stringstream variable named convert, initialized with the input from argv[1]

	int myint{};
	if (!(convert >> myint)) // do the conversion
		myint = 0; // if conversion fails, set myint to a default value

	std::cout << "Got integer: " << myint << '\n';

	return 0;
}*/
//****************Dealing with numerc arguments***
