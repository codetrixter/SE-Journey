/**
 * @file overloadingParenthesis.cpp
 * @author Abhishek
 * @brief here we discuss the use of overloading parenthesis operator:
 * 1- Used for accessing 2D private member variable.
 * 2- Used as a functor. 
 * @version 0.1
 * @date 2022-08-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cassert> // for assert()
//***********************Matrix***
/* class Matrix
{
private:
    double m_data[4][4]{};

public:
    double& operator()(int row, int col);
    double operator()(int row, int col) const; // for const objects
    void operator()();
};

double& Matrix::operator()(int row, int col)
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return m_data[row][col];
}

double Matrix::operator()(int row, int col) const
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return m_data[row][col];
}

/// We don't usually use this for such purposes, since it is confusing.
void Matrix::operator()()
{
    /// reset all elements of the matrix to 0.0
    for (int row{ 0 }; row < 4; ++row)
    {
        for (int col{ 0 }; col < 4; ++col)
        {
            m_data[row][col] = 0.0;
        }
    }
}

int main(int argc, char const *argv[])
{
    Matrix matrix{};
    matrix(1, 2) = 4.5;
    std::cout << matrix(1,2);
    matrix(); // erase the matrix
    std::cout << matrix(1, 2);
    return 0;
} */
//***********************Matrix***
//***********************Functor***
/* 
/// This is just an example to show the functioning of the functor, esle these are usually used in complex 
/// scenarios for full benefits.
class Accumulator
{
private:
    int m_counter{ 0 };

public:
    int operator() (int i) { return (m_counter += i); }
};

int main()
{
    Accumulator acc{};
    std::cout << acc(10) << '\n'; // prints 10
    std::cout << acc(20) << '\n'; // prints 30

    Accumulator acc2{};
    std::cout << acc2(35) << "\n";  // 35
    std::cout << acc2(45) << "\n";  // 80

    return 0;
} */
//***********************Functor***
//***********************QUIZ***
/* #include <string>
#include <string_view>

class MyString
{
private:
	std::string m_string{};

public:
	MyString(std::string_view str = {})
		:m_string{ str }
	{
	}

	/// @brief  Here string_view is used as a return type since using MyString class object creates too many copies.
	/// @param start 
	/// @param length 
	/// @return string_view object
	std::string_view operator()(int start, int length)
	{
		assert(start >= 0);
		assert(start + length <= static_cast<int>(m_string.length()) && "MyString::operator(int, int): Substring is out of range");

		return std::string_view{m_string}.substr(start, length);
	}

    friend std::ostream& operator<< (std::ostream& out, const MyString& str)
    {
        return out << str.m_string;
    }
};

int main()
{
	MyString str{ "Hello, world!" };
	std::cout << str(7, 5) << '\n'; // start at index 7 and return 5 characters

	return 0;
} */
//***********************QUIZ***

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **operator() for matrix access** | `matrix(row, col)` — multi-dimensional subscript |
| 2 | **Functors (function objects)** | `Accumulator` class with stateful `operator()` |
| 3 | **Const overload of operator()** | Read-only version for const objects |
| 4 | **operator() as reset** | `matrix()` resets all elements (unusual but valid) |

### 🔄 Alternatives & Modern C++ Idioms:
- C++23: `operator[]` can accept multiple arguments (multidimensional subscript)
- `std::function` wraps functors, lambdas, function pointers uniformly
- Lambdas often replace simple functors in modern C++

### ⚡ Quick Revision:
- `operator()` can take any number of args (unlike `operator[]`)
- Functors = objects callable like functions, can hold state
- Lambdas are compiler-generated functors
- Use for: matrix access, function objects, custom comparators
*/