/**
 * @file RAIIDestructor.cpp
 * @author Abhishek
 * @brief Destructor use and purpose:
 * 1- Whenever a dynamically allocated object goes out of scope the destructor is called for 
 * graceful deallocation of the memory. hence it called just before the memory is deallocated.
 * 2- Destructor does not have any return value or parameters and can only be defined once per class. 
 * 
 * The below example also demostrates RAII(Resource Acquisation Is Initialization)
 * which basicall means that when the resource is acquired then only it is initialized and 
 * it is deallocated when no more in use. We achieve this via contructors and Destructors.
 * @version 0.1
 * @date 2022-06-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

class Simple
{
private:
    int m_nID{};

public:
    Simple(int nID)
        : m_nID{ nID }
    {
        std::cout << "Constructing Simple " << nID << '\n';
    }

    ~Simple()
    {
        std::cout << "Destructing Simple" << m_nID << '\n';
    }

    int getID() { return m_nID; }
};

int main()
{
    // Allocate a Simple on the stack
    Simple simple{ 1 };
    std::cout << simple.getID() << '\n';

    // Allocate a Simple dynamically
    Simple* pSimple{ new Simple{ 2 } };

    std::cout << pSimple->getID() << '\n';

    // We allocated pSimple dynamically, so we have to delete it.
    delete pSimple;

    return 0;
} // simple goes out of scope here