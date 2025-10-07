/**
 * @file OverIncrDecrOperators.cpp
 * @author Abhishek
 * @brief Here we explore the following:
 * 1- Prefix increment and decrement operator overloading.
 * 2- Postfix increment and decrememnt operator overloading.
 * ***NOTE: In postfix operator implementation, we have created a temporary object of the Class and returned that,
 * the increment is done to the actial object. So in this way we receive the state of the objct before it is 
 * incremented/decremented and also when used later only, we get the incremented/decremented instance of the class.
 * 
 * This also shows that postfix expressions are more difficult to process in comparison to prefix expressions.
 * @version 0.1
 * @date 2022-08-12
 * 
 * @copyright Copyright (c) 2022
 */
#include <iostream>
//******************Pont-1 & 2***
class Digit
{
private:
    int m_digit;
public:
    Digit(int digit=0)
        : m_digit{digit}
    {
    }

    Digit& operator++(); // prefix has no parameter
    Digit& operator--(); // prefix has no parameter

    Digit operator++(int); // postfix has an int parameter
    Digit operator--(int); // postfix has an int parameter

    friend std::ostream& operator<< (std::ostream& out, const Digit& d);
};

// No parameter means this is prefix operator++
Digit& Digit::operator++()
{
    // If our number is already at 9, wrap around to 0
    if (m_digit == 9)
        m_digit = 0;
    // otherwise just increment to next number
    else
        ++m_digit;

    return *this;
}

// No parameter means this is prefix operator--
Digit& Digit::operator--()
{
    // If our number is already at 0, wrap around to 9
    if (m_digit == 0)
        m_digit = 9;
    // otherwise just decrement to next number
    else
        --m_digit;

    return *this;
}

// int parameter means this is postfix operator++
//By declaring parameter as a placeholder we have told compiler that we will not use this variable,
//hence it will not throw warning.
// We are returning here by value since we are returning local value which will get deleted once this function's
// scope dies. 
Digit Digit::operator++(int)    
{                                   
    // Create a temporary variable with our current digit, shallow copy is done here
    Digit temp{*this};

    // Use prefix operator to increment this digit
    ++(*this); // apply operator

    // return temporary result
    return temp; // return saved state
}

// int parameter means this is postfix operator--
// We are returning here by value since we are returning local value which will get deleted once this function's
// scope dies. 
Digit Digit::operator--(int)
{
    // Create a temporary variable with our current digit, shallow copy is done here
    Digit temp{*this};

    // Use prefix operator to decrement this digit
    --(*this); // apply operator

    // return temporary result
    return temp; // return saved state
}

std::ostream& operator<< (std::ostream& out, const Digit& d)
{
	out << d.m_digit;
	return out;
}

int main()
{
    Digit digit(5);

    std::cout << digit;
    std::cout << ++digit; // calls Digit::operator++();
    std::cout << digit++; // calls Digit::operator++(int);
    std::cout << digit;
    std::cout << --digit; // calls Digit::operator--();
    std::cout << digit--; // calls Digit::operator--(int);
    std::cout << digit;

    return 0;
}
//******************Pont-1 & 2***
