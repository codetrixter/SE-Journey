/**
 * @file COnvertingCtors-Explicit.cpp
 * @author Abhishek
 * @brief Here we discuss the implicit conversions while using constructors and how to avoid them:
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
	 MyString(int x) // allocate string of size x
	{
		std::cout << "int version called...\n";
		m_string.resize(x);
	}

	/// @brief  This will not be called by the 'x', since this takes a const char* which is not equal to const char
	/// @param string 
	MyString(const char* string) // allocate string to hold string value
	{
		std::cout << "char version called...\n";
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
    /// WIth explicit used this will give error: invalid conversion from ‘char’ to ‘const char*’
	MyString mine1 = 'x'; // Will compile and use MyString(int), will do implicit casting char to int.

    /// These work eveb with explicit.
    MyString mine2{ 'x' }; //This doesn't do narrowing conversions but happily does other conversions.
    std::cout << static_cast<MyString>(5);

	std::cout << mine1 << mine2 << '\n';

	printString(static_cast<MyString>('x')); // Will compile and use MyString(int)
	return 0;
} */
//*******************************Point-1***
//*******************************Point-2***
class MyString
{
private:
	std::string m_string;

    /// objects of type MyString(char) can't be constructed from outside the class
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

///@brief way to prevent implecit/explicit casting:
///make the constructor private/delete
///
///@param argc 
///@param argv 
///@return int 

int main(int argc, char const *argv[])
{
    MyString mine{ 'x' };	// This will throw error since const char ctor is delete, it will not prmote x to int and use int ctor in this case
    std::cout << mine << '\n';
    return 0;
}
//*******************************Point-2***

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Converting constructors** | Single-arg ctor allows implicit conversion |
| 2 | **explicit keyword** | Prevents implicit conversions via constructor |
| 3 | **= delete on specific ctor** | `MyString(char) = delete` — blocks char usage entirely |
| 4 | **Brace init vs copy init** | `MyString mine = 'x'` (copy init) vs `MyString mine{'x'}` (direct) |

### 🔄 Alternatives & Modern C++ Idioms:
- Mark ALL single-arg constructors `explicit` by default (Google style guide)
- C++20: `explicit(bool)` — conditional explicit
- Use named factory functions for clarity

### 🏭 Real-World Usage:
- `std::vector(int)` is explicit — prevents `vector v = 5`
- `std::string(const char*)` is NOT explicit — allows `string s = "hello"`
- Rule: explicit unless implicit conversion is genuinely useful

### ⚡ Quick Revision:
- Without `explicit`: `MyString s = 5` compiles (implicit conversion)
- With `explicit`: only `MyString s{5}` or `static_cast<MyString>(5)` works
- `= delete` completely removes overload from consideration
- `explicit` + `= delete` together give maximum control
*/