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

//We don't usually use this for such purposes, since it is confusing.
void Matrix::operator()()
{
    // reset all elements of the matrix to 0.0
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
    matrix();
    std::cout << matrix(1, 2);
    return 0;
} */
//***********************Matrix***
//***********************Functor***
/* class Accumulator
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

    return 0;
} */
//***********************Functor***
//***********************QUIZ***
#include <string>
class MyString
{
private:
	std::string m_string{};

public:
	MyString(const std::string& string = {})
		:m_string{ string }
	{
	}

	std::string operator()(int start, int length)
	{
		assert(start >= 0);
		assert(start + length <= static_cast<int>(m_string.length()) && "MyString::operator(int, int): Substring is out of range");

		return m_string.substr(start, length);
	}
};

int main()
{
	MyString string{ "Hello, world!" };
	std::cout << string(7, 5) << '\n'; // start at index 7 and return 5 characters

	return 0;
}
//***********************QUIZ***