/**
 * @file shallowDeepCopy.cpp
 * @author Abhishek
 * @brief Here we discuss the intricacies of shallow and deep copying:
 * 1- Whenever the class provides the default versions of the copy constructor and copy assignment operator
 * we do member wise initialization/copy which is also known as shallow copy.
 * 2- Deep copy is used so that any dynamic memory allocation within an instance can be copied/assigned
 * properly.
 * NOTE: A better solution
 * Classes in the standard library that deal with dynamic memory, such as std::string and std::vector,
 * handle all of their memory management, and have overloaded copy constructors and assignment operators that
 * do proper deep copying. So instead of doing your own memory management, you can just initialize or assign
 * them like normal fundamental variables! That makes these classes simpler to use, less error-prone, and you
 * don’t have to spend time writing your own overloaded functions!
 * @version 0.1
 * @date 2022-08-23
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <cassert>
#include <iostream>
#include <cstring> // for strlen()
#include <cassert> // for assert()

//***************************Shallow copying***
/* class Fraction
{
private:
    int m_numerator { 0 };
    int m_denominator { 1 };

public:
    /// Default constructor
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{ numerator }
        , m_denominator{ denominator }
    {
        assert(denominator != 0);
    }

    /// Possible implementation of implicit copy constructor
    Fraction(const Fraction& f)
        : m_numerator{ f.m_numerator }
        , m_denominator{ f.m_denominator }
    {
    }

    /// Possible implementation of implicit assignment operator
    Fraction& operator= (const Fraction& fraction)
    {
        /// self-assignment guard
        if (this == &fraction)
            return *this;

        /// do the copy
        m_numerator = fraction.m_numerator;
        m_denominator = fraction.m_denominator;

        /// return the existing object so we can chain this operator
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
    {
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
    }
}; */
//***************************Shallow copying***
//***************************Deep copying***
/* class MyString
{
private:
    char *m_data{};
    int m_length{};

public:
    MyString(const char *source = "")
    {
        assert(source); // make sure source isn't a null string

        /// Find the length of the string
        /// Plus one character for a terminator
        m_length = std::strlen(source) + 1;

        /// Allocate a buffer equal to this length
        m_data = new char[m_length];

        /// Copy the parameter string into our internal buffer
        for (int i{0}; i < m_length; ++i)
            m_data[i] = source[i];
    }

    MyString(const MyString &source)
    {
        deepCopy(source);
    }

    MyString& operator= (const MyString &source)
    {
        if (this != &source)
            deepCopy(source);

        return *this;
    }

    ~MyString() // destructor
    {
        /// We need to deallocate our string
        delete[] m_data;
    }

    void deepCopy(const MyString &source)
    {
        /// first we need to deallocate any value that this string is holding!
        delete[] m_data;

        /// because m_length is not a pointer, we can shallow copy it
        m_length = source.m_length;

        /// m_data is a pointer, so we need to deep copy it if it is non-null
        if (source.m_data)
        {
            /// allocate memory for our copy
            m_data = new char[m_length];

            /// do the copy
            for (int i{0}; i < m_length; ++i)
                m_data[i] = source.m_data[i];
        }
        else
            m_data = nullptr;
    }

    char *getString() { return m_data; }
    int getLength() { return m_length; }
};

int main()
{
    /// error:free(): double free detected in tcache 2, Aborted (core dumped)
    MyString hello{"Hello, world!"};
    {
        MyString copy{hello}; // use default copy constructor
    }                         // copy is a local variable, so it gets destroyed here. The destructor deletes copy's string, 
    ///which leaves hello with a dangling pointer

    std::cout << hello.getString() << '\n'; // this will have undefined behavior

    return 0;
} */
//***************************Deep copying***

//--------Alternate example----------
#include <iostream>
using namespace std;

class DummyClass
{
private:
    int num1, num2;
    int *ptr;

public:
    DummyClass()
    {
        ptr = new int;
    }

    void setData(int x, int y, int z)
    {
        num1 = x;
        num2 = y;
        *ptr = z;
    }

    void showData()
    {
        cout << "A = " << num1 << " B = " << num2 << endl;
    }

    /// copy constructor -> it is responsible for deep copy.
    DummyClass(DummyClass &D)
    {
        ptr = new int;  //This needs to be allocated here else seg fault will occur.
        num1 = D.num1;
        num2 = D.num2;
        *ptr = *(D.ptr);    //data pointed to by the pointer is copied and not the just the pointer address itself
    }

    /// destructor -> to deallocate memory consumed by new pointer ptr.
    ~DummyClass()
    {
        delete ptr;
    }
};

int main()
{
    DummyClass D1;
    D1.setData(3, 5, 11);
    D1.showData();

    /// Copy constructor declared above will came in action and do deep copy.
    DummyClass D2 = D1;
    D2.showData();
}