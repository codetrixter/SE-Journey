/**
 * @file final-covariantreturnTypes.cpp
 * @author Abhishek
 * @brief here we discuss about the following:
 * 1- override specifier: this just ensures that the functions that are meant to be overriden are overriden with correct function signatures and are not 
 * taken as separate functions of the derived class.
 * 2- final specifier: This prevents from further overriding and inheritance, can be used with funtions and classes.
 * 3- covariant return type: This allows the derived versions of the functions to have return types that are of inherited class type.
 * @version 0.1
 * @date 2022-07-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string_view>

//**********point-1***
/* class A
{
public:
	virtual std::string_view getName1(int x) { return "A"; }
	virtual std::string_view getName2(int x) { return "A"; }
	virtual std::string_view getName3(int x) { return "A"; }
};

class B : public A
{
public:
    //without override specifier there would not have been any errors.
	std::string_view getName1(short int x) override { return "B"; } // compile error, function is not an override, marked as override but did otherwise.
	std::string_view getName2(int x) const override { return "B"; } // compile error, function is not an override
	std::string_view getName3(int x) override { return "B"; } // okay, function is an override of A::getName3(int)

};

int main()
{
	return 0;
} */
//**********point-1***
//**********point-2***
/* class A
{
public:
	virtual std::string_view getName() { return "A"; }
};

class B : public A
{
public:
	// note use of final specifier on following line -- that makes this function no longer overridable
	std::string_view getName() override final { return "B"; } // okay, overrides A::getName()
};

class C : public B
{
public:
	std::string_view getName() override { return "C"; } // compile error: overrides B::getName(), which is final
}; */
//--------------------------
/* class A
{
public:
	virtual std::string_view getName() { return "A"; }
};

class B final : public A // note use of final specifier here
{
public:
	std::string_view getName() override { return "B"; }
};

class C : public B // compile error: cannot inherit from final class
{
public:
	std::string_view getName() override { return "C"; }
}; */
//**********point-2***
//**********point-3***
class Base
{
public:
	// This version of getThis() returns a pointer to a Base class
	virtual Base* getThis() { std::cout << "called Base::getThis()\n"; return this; }
	void printType() { std::cout << "returned a Base\n"; }
};

class Derived : public Base
{
public:
	// Normally override functions have to return objects of the same type as the base function
	// However, because Derived is derived from Base, it's okay to return Derived* instead of Base*
	Derived* getThis() override { std::cout << "called Derived::getThis()\n";  return this; }
	void printType() { std::cout << "returned a Derived\n"; }
};
int main(int argc, char const *argv[])
{
    Derived d{};
    Base* base{&d};
    
    d.getThis()->printType();
    //here the return pointer of Derived class gets upcasted to base type.
    base->getThis()->printType();
    return 0;
}
//**********point-3***
