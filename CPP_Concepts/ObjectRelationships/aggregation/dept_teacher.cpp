/**
 * @file dept_teacher.cpp
 * @author Abhishek
 * @brief Here we discuss about Aggregation concept of OOPs:
 * 1- To qualify as an aggregation, a whole object and its parts must have the following relationship:
    1- The part (member) is part of the object (class)
    2- The part (member) can belong to more than one object (class) at a time
    3- The part (member) does not have its existence managed by the object (class)
    4- The part (member) does not know about the existence of the object (class)
 * 2- This is a "has-a" relationship
 * 3- If there are more than one teachers in our department class then we can store them in a vector, but since vector can't store references as they
 * cannot be reassigned, so we use std::reference_wrapper which make the onjects behave as reassignable references. 
 * 
 * Composition VS Aggregation::
 *  Compositions:
    - Typically use normal member variables
    - Can use pointer members if the class handles object allocation/deallocation itself
    - Responsible for creation/destruction of parts

    Aggregations:
    - Typically use pointer or reference members that point to or reference objects that live outside the scope of the aggregate class
    - Not responsible for creating/destroying parts

 * QUIZ:
 * Would you be more likely to implement the following as a composition or an aggregation?
    a) A ball that has a color - Composition: Color is an intrinsic property of a ball.
    b) An employer that is employing multiple people - Aggregation: An employer doesn’t start with any employees and hopefully doesn’t destroy all its 
    employees when it goes bankrupt. 
    c) The departments in a university - Composition: Departments can’t exist in absence of a university.
    d) Your age - Composition: Your age is an intrinsic property of you.
    e) A bag of marbles - Aggregation: The bag and the marbles inside have independent existences.

 * BEST:PRACTICE::
 * Implement the simplest relationship type that meets the needs of your program, not what seems right in real-life.
 * ]   
 * @version 0.1
 * @date 2022-08-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>

/* class Teacher
{
    private:
    std::string m_name{};

    public:
    Teacher(const std::string& name):
        m_name{name}
        {}
    
    const std::string& getName() const { return m_name; }
};

class Department
{
    private:
    // This dept holds only one teacher for simplicity, but it could hold many teachers
    const Teacher& m_teacher;

    public:
    Department(const Teacher& teach):
        m_teacher{teach}
        {}
};

int main()
{
  // Create a teacher outside the scope of the Department
  Teacher bob{ "Bob" }; // create a teacher

  {
    // Create a department and use the constructor parameter to pass
    // the teacher to it.
    Department department{ bob };

  } // department goes out of scope here and is destroyed

  // bob still exists here, but the department doesn't

  std::cout << bob.getName() << " still exists!\n";

  return 0;
} */
//*************************QUIZ***
#include <functional>
#include <vector>

class Teacher
{
private:
  std::string m_name{};

public:
  Teacher(const std::string& name)
      : m_name{ name }
  {
  }

  const std::string& getName() const { return m_name; }
};

class Department
{
private:
  std::vector<std::reference_wrapper<const Teacher>> m_teachers{};

public:
  // Pass by regular reference. The user of the Department class shouldn't care
  // about how it's implemented.
  void add(const Teacher& teacher)
  {
    m_teachers.push_back(teacher);
  }

  friend std::ostream& operator<<(std::ostream& out, const Department& department)
  {
    out << "Department: ";

    for (const auto& teacher : department.m_teachers)
    {
        /**
         * @brief When we use auto, teacher is deduced to be a std::reference_wrapper<const Teacher>. We have to use get() to get the object being 
         * referenced. When you explicitly use Teacher& as the type, the compiler will implicitly convert the std::reference_wrapper<const Teacher> 
         * to a Teacher object, which we can access directly, so no get() is needed. 
         * Either is fine.
         * 
         */

      out << teacher.get().getName() << ' ';
    }

    out << '\n';

    return out;
  }
};

int main()
{
  // Create a teacher outside the scope of the Department
  Teacher t1{ "Bob" };
  Teacher t2{ "Frank" };
  Teacher t3{ "Beth" };

  {
    // Create a department and add some Teachers to it
    Department department{}; // create an empty Department

    department.add(t1);
    department.add(t2);
    department.add(t3);

    std::cout << department;

  } // department goes out of scope here and is destroyed

  std::cout << t1.getName() << " still exists!\n";
  std::cout << t2.getName() << " still exists!\n";
  std::cout << t3.getName() << " still exists!\n";

  return 0;
} 
//*************************QUIZ***
