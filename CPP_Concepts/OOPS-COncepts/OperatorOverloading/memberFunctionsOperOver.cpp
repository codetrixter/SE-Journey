/**
 * @file memberFunctionsOperOver.cpp
 * @author Abhishek
 * @brief Here we discuss on how to do operator overloading using member functions, it is 
 * pretty similar to the friend functions way.
 * The following rules of thumb can help you determine which form is best for a given situation:

    a- If you’re overloading assignment (=), subscript ([]), function call (()), or member selection (->), do so 
    as a member function.
    b- If you’re overloading a unary operator, do so as a member function.
    c- If you’re overloading a binary operator that does not modify its left operand (e.g. operator+), do so as a 
    normal function (preferred) or friend function.
    d- If you’re overloading a binary operator that modifies its left operand, but you can’t add members to the 
    class definition of the left operand (e.g. operator<<, which has a left operand of type ostream), do so as 
    a normal function (preferred) or friend function.
    e- If you’re overloading a binary operator that modifies its left operand (e.g. operator+=), and you can 
    modify the definition of the left operand, do so as a member function.
 * @version 0.1
 * @date 2022-08-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

class Cents
{
private:
    int m_cents {};

public:
    Cents(int cents)
        : m_cents { cents } { }

    // Overload Cents + int
    Cents operator+(int value);

    int getCents() const { return m_cents; }
};

//here call to operator+(int value)-> operator(&Cents, int value), where Cents is the hidden this pointer.
Cents Cents::operator+(int value)
{
    return Cents(m_cents + value);
}

int main()
{
	Cents cents1 { 6 };
	Cents cents2 { cents1 + 2 };
	std::cout << "I have " << cents2.getCents() << " cents.\n";

	return 0;
}