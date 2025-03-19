/**
 * @file initializerList.cpp
 * @author Abhishek
 * @brief Here we discuss the way of initializing our containers the way we can initialize STL:
 * 1- using initializer list for brace initializing our containers.
 * 2- One caveat: Initializer lists will always favor a matching initializer_list constructor over other potentially matching constructors. 
 * Thus, this variable definition:
 * a- std::vector<int> array(5); // Calls std::vector::vector(std::vector::size_type), 5 value-initialized elements: 0 0 0 0 0
 * b- std::vector<int> array{ 5 }; // Calls std::vector::vector(std::initializer_list<int>), 1 element: 5
 * 3- we can overload assignment operator to take initializer_list as an argument which will work for class level assignments.
 * @version 0.1
 * @date 2022-08-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <cassert> // for assert()
#include <iostream>
#include <initializer_list>

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;

    IntArray(int length)
        : m_length{ length }
        , m_data{ new int[length]{} }
    {
    }

    IntArray(std::initializer_list<int> list) // allow IntArray to be initialized via list initialization
		: IntArray(static_cast<int>(list.size())) // use delegating constructor to set up initial array
	{
		// Now initialize our array from the list
		int count{ 0 };
        //initializer list does not allows subscripts hence we have to initialize out class like this.
		for (auto element : list)
		{
			m_data[count] = element;
			++count;
		}
	}

    ~IntArray()
    {
        delete[] m_data;
        // we don't need to set m_data to null or m_length to 0 here, since the object will be destroyed immediately after this function anyway
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    IntArray& operator= (const IntArray& arr) = delete;

    IntArray& operator= (std::initializer_list<int> list)
    {
        // If the new list is a different size, reallocate it
		int length{ static_cast<int>(list.size()) };
        if (length != m_length)
		{
			delete[] m_data;
			m_length = length;
			m_data = new int[length]{};
		}

        int count = 0;
        for (auto element : list)
		{
			m_data[count] = element;
			++count;
		}

        return *this;
    }

    int getLength() const { return m_length; }
};

int main()
{
	// What happens if we try to use an initializer list with this container class?
	IntArray array { 5, 4, 3, 2, 1 }; // this line doesn't compile
	for (int count{ 0 }; count < 5; ++count)
		std::cout << array[count] << ' ';

    std::cout << std::endl;

    array = {1, 3, 5, 7, 9, 11};

    for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	return 0;
}