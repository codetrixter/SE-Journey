/**
 * @file thisPointer.cpp
 * @author Abhishek
 * @brief Here we will see the puspose this pointer in c++
 * 1- this is a hidden pointer which is sent along with function param when a member func. is called on an instance
 * of a class.
 * 2- It can also be used to create member function chaining.
 * @version 0.1
 * @date 2022-06-03
 * @copyright Copyright (c) 2022
 */

#include <iostream>
/**
 * @brief Whenever a member function is called with the object then there is a hidden class pointer is sent 
 * to that function via parameters which helps the function in calling the correct instances members
 */
class Simple
{
private:
    int m_id;

public:
    Simple(int id)
        : m_id{ id }
    {
    }

    void setID(int id) { m_id = id; }
    //consecutively this line is also updated as 
    //void setID(Simple* const this, int id){this->m_id = id};
    int getID() { return m_id; }
};
int main()
{
    Simple simple{1};
    simple.setID(2);
    //above line is written as 
    //simple.setID(&simple, 2);
    std::cout << simple.getID() << '\n';

    return 0;
}