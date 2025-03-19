/**
 * @file tempateClasses.cpp
 * @author Abhishek
 * @brief Here we discuss about the template classes:
 * 1- We can start learning about template class by writing an Array class which supports multiple datat types.
 * 
 * ***NOTE: Template classes are instanced in the same way template functions are -- the compiler stencils out 
 * a copy upon demand, with the template parameter replaced by the actual data type the user needs, and then 
 * compiles the copy. If you don’t ever use a template class, the compiler won’t even compile it.
 * @version 0.1
 * @date 2022-08-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cassert>

template <typename T>
class Array
{
    private:
    int length{};
    T* m_data{};

    public:
    Array(int len)
    {
        assert(len > 0);
        m_data = new T[len]{};
        length = len;
    }

    //wont allow copies of this to be created
    //we can se ethe return types to be of non-templated type class, since these are within the class
    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    ~Array()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        //we need to set m_data to 0 here, else it will be left pointing to deallocated memory 
        m_data = nullptr;
        length = 0;
    }

    T& operator[](int index)
    {
        assert(index >= 0 && index < length);
        return m_data[index];
    }

    // templated getLength() function defined below
    int getLength() const;
};

// member functions defined outside the class need their own template declaration
template <typename T>
int Array<T>::getLength() const
{
    return length;
}
#endif

int main(int argc, char const *argv[])
{
    Array<int> intArray { 12 };
	Array<double> doubleArray { 12 };

	for (int count{ 0 }; count < intArray.getLength(); ++count)
	{
		intArray[count] = count;
		doubleArray[count] = count + 0.5;
	}

	for (int count{ intArray.getLength() - 1 }; count >= 0; --count)
		std::cout << intArray[count] << '\t' << doubleArray[count] << '\n';
    return 0;
}


