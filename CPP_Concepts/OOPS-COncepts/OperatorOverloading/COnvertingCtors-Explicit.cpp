/**
 * @file COnvertingCtors-Explicit.cpp
 * @author Abhishek
 * @brief Here we discuss the implicit conversions while using cinstructors and how to avoid them:
 * 1- "explicit" keyword can be used before the constructor to stop using that ctor from implicit casting.
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <iostream>
//*******************************Point-1***
/* class MyString
{
private:
	std::string m_string;
public:
	explicit MyString(int x) // allocate string of size x
	{
		m_string.resize(x);
	}

	MyString(const char* string) // allocate string to hold string value
	{
		m_string = string;
	}

	friend std::ostream& operator<<(std::ostream& out, const MyString& s);

};

std::ostream& operator<<(std::ostream& out, const MyString& s)
{
	out << s.m_string;
	return out;
}

void printString(const MyString& s)
{
	std::cout << s;
}

int main()
{
    // WIth explicit used this will give error: invalid conversion from ‘char’ to ‘const char*’
	//MyString mine = 'x'; // Will compile and use MyString(int), will do implicit casting char to int.

    // These work eveb with explicit.
    MyString mine{ 'x' }; //This doesn't do narrowing conversions but happily does other conversions.
    std::cout << static_cast<MyString>(5);

	std::cout << mine << '\n';

    // WIth explicit used this will give error: invalid conversion from ‘char’ to ‘const char*’
    // But explicit casting works even with explicit keyword.
	printString(static_cast<MyString>('x')); // Will compile and use MyString(int)
	return 0;
} */
//*******************************Point-1***
//*******************************Point-2***
class MyString
{
private:
	std::string m_string;

    // objects of type MyString(char) can't be constructed from outside the class
    //MyString(char) { }
public:

    MyString(char) = delete;    //any use of this will result in an error

	explicit MyString(int x) // allocate string of size x
	{
		m_string.resize(x);
	}

	MyString(const char* string) // allocate string to hold string value
	{
		m_string = string;
	}

	friend std::ostream& operator<<(std::ostream& out, const MyString& s);

};

std::ostream& operator<<(std::ostream& out, const MyString& s)
{
	out << s.m_string;
	return out;
}

/**
 * @brief way to prevent implecit/explicit casting:
 * make the constructor private/delete
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    MyString mine{ 'x' };
    std::cout << mine << '\n';
    return 0;
}
//*******************************Point-2***