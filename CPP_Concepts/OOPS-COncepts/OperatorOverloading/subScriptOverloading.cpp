/**
 * @file subScriptOverloading.cpp
 * @author Abhishek
 * @brief Here we discuss about the "[]" operator overloading.
 * 1- If a class has an array as a private member variable, in order to access the elements of array we either need
 * getter/setters or some memebr function exposing that variable, but we can write an overloaded memeber function
 *  for that class that makes it intuitive to access the variables of the array.
 * 2- Overloading subscript operator for const class instance.
 * 3- subscript operOver. can be used for making element access more secure, since [] on arrays does not gives
 * heads up during out of bounds access at compile time.
 * 
 * 4- pointers to objects with overloaded operator([]).
 * 5- function parameter for overloaded'[]' doesn't need to be integer.
 * 
 * ***NOTE: This operator overlaoding is used in string class for accessing each character.
 * @version 0.1
 * @date 2022-08-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cassert>
#include <iterator> //std::size() c++17

//***********Point-1, 2 and 3***
// class IntList
// {
//     private:
//     int m_list[10]{};

//     public:
//     int& operator[] (int index); 
//     int operator[] (int index) const; // could also return const int& if returning a non-fundamental type
// };
// /**
//  * @brief The reason wht the retun type is reference, because the object while using subscript operator is on the
//  * LHS of the assignment, hence it needs to resolve to an lvalue.
//  * 
//  * @param i 
//  * @return int& 
//  */
// int& IntList::operator[] (int i) // for non-const objects: can be used for assignment
// {
//     //This will prevent form out of bounds access by giving compiler error.
//     assert(i > 0 && i < std::size(m_list));
//     return m_list[i];
// }

// int IntList::operator[] (int i) const // for const objects: can only be used for access
// {
//     return m_list[i];
// }

// int main(int argc, char const *argv[])
// {
//     IntList intList{};
//     intList[11] = 26;
//     std::cout << intList[5] << " ";

//     const IntList clist{};
//     //clist[2] = 3;   //error: lvalue required as left operand of assignment, since it is called on const version.
//     std::cout << clist[3];

//     return 0;
// }
//*************************Point-1, 2 and 3***
//**********************************Point-4***
/* class IntList
{
private:
    int m_list[10]{};

public:
    int& operator[] (int index);
};

int& IntList::operator[] (int index)
{
    assert(index >= 0 && index < std::size(m_list));

    return m_list[index];
}

int main()
{
    IntList* list{ new IntList{} };
    //list [2] = 3; // error: this will assume we're accessing index 2 of an array of IntLists
    //even though this works but it is error prone.
    (*list)[2] = 3; // get our IntList object, then call overloaded operator[]
    delete list;

    return 0;
} */
//**********************************Point-4***
//**********************************Point-5***
#include <string_view> // C++17

/* class Stupid
{
private:

public:
	void operator[] (std::string_view index);
};

// It doesn't make sense to overload operator[] to print something
// but it is the easiest way to show that the function parameter can be a non-integer
void Stupid::operator[] (std::string_view index)
{
	std::cout << index;
}

int main()
{
	Stupid stupid{};
	stupid["Hello, world!"];

	return 0;
} */
//**********************************Point-5***
//**********************************QUIZ-1***
#include <string>
#include <algorithm>
#include <vector>

struct StudentGrade
{
    std::string name{};
    char grade{};
};

class GradeMap
{
    private:
    //this keeps things unsorted, hence finding names everytime is time consuming, we can optimize it by 
    //sorting it and using Binary seearch for searching through the elements.
    std::vector<StudentGrade> m_map{};

    public:
    char& operator[] (std::string_view name);

};

char& GradeMap::operator[] (std::string_view name)
{
    auto found{ std::find_if(m_map.begin(), m_map.end(), [&](const auto& student)
    {
        return (student.name == name);
    }) };

    if(found != m_map.end())
        return found->grade;

    // otherwise create a new StudentGrade for this student and add
	// it to the end of our vector.
	m_map.push_back({ std::string{name} });

	// and return the element
	return m_map.back().grade;
}

/* int main()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
} */

//Another part of Quiz
/**
 * @brief When Frank is added, the std::vector may need to grow to hold it. This requires dynamically allocating 
 * a new block of memory, copying the elements in the array to that new block, and deleting the old block. 
 * When this happens, any references to existing elements in the std::vector are invalidated (meaning they are 
 * left as dangling references to deleted memory).
 * 
 * In other words, after we push_back("Frank"), if the std::vector had to grow to make room for Frank, 
 * the gradeJoe reference would be invalidated. Accessing gradeJoe to print Joe’s grade would then lead to 
 * undefined results.
 * 
 * How a std::vector grows is a compiler-specific detail, so we can expect the above program to work fine when 
 * compiled with some compilers and not others.
 * 
 * @return int 
 */
int main()
{
	GradeMap grades{};

	char& gradeJoe{ grades["Joe"] }; // does a push_back
	gradeJoe = 'A';

	char& gradeFrank{ grades["Frank"] }; // does a push_back
	gradeFrank = 'B';

	std::cout << "Joe has a grade of " << gradeJoe << '\n';
	std::cout << "Frank has a grade of " << gradeFrank << '\n';

	return 0;
}
//**********************************QUIZ-1***

