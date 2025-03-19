/**
 * @file is-a-relation.cpp
 * @author Abhishek
 * @brief This example shows the is - a relation of the inheritance 
 * 1- Inheritance is useful in the sense that we dont have to redefine the base class info into the derived classes,
 * in short it allows us to reuse the classes.
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>

class Person
{
public:
    std::string m_name{};
    int m_age{};

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }

    Person(const std::string& name = "", int age = 0)
        : m_name{name}, m_age{age}
    {
    }
};

// Employee publicly inherits from Person
class Employee: public Person
{
public:
    double m_hourlySalary{};
    long m_employeeID{};

    Employee(double hourlySalary = 0.0, long employeeID = 0)
        : m_hourlySalary{hourlySalary}, m_employeeID{employeeID}
    {
    }

    void printNameAndSalary() const
    {
        std::cout << m_name << ": " << m_hourlySalary << '\n';
    }
};

int main()
{
    Employee frank{20.25, 12345};
    frank.m_name = "Frank"; // we can do this because m_name is public

    frank.printNameAndSalary();

    return 0;
}
