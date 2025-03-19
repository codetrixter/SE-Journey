/**
 * @file earlyBinding-lateBinding.cpp
 * @author Abhishek
 * @brief Here we discuss the concept of early and late binding and how they are different from each other:
 * Binding:-> This refers to the process of converting variables and functions names into addresses.
 * 1- Early Binding(Direct addressing): In this case the compiler converts and replaces the function name with the machine address, which tells the cpu at 
 * runtime where to go. In this case only one thing happens at run time:
 *      a. jump to the resolved address.
 * 2- Late Binding(Indirect addressing): In this case the resolution of the address space where the function is stored is delayed till run time, so at runtime two things happen 
 * instead of one:
 *      a. Address resolution.
 *      b. jump to the resolved address.
 * 
 * ***To read in depth about this follow: https://stackoverflow.com/questions/21350478/what-does-memory-allocated-at-compile-time-really-mean
 * 
 * Note::Any class that uses virtual functions has a *__vptr, and thus each object of that class will be bigger by one pointer. 
 * Virtual functions are powerful, but they do have a performance cost.
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
//*******************Point-1***
/* int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    int x{};
    std::cout << "Enter a number: ";
    std::cin >> x;

    int y{};
    std::cout << "Enter another number: ";
    std::cin >> y;

    int op{};
    do
    {
        std::cout << "Enter an operation (0=add, 1=subtract, 2=multiply): ";
        std::cin >> op;
    } while (op < 0 || op > 2);

    int result {};
    switch (op)
    {
        // call the target function directly using early binding
        case 0: result = add(x, y); break;
        case 1: result = subtract(x, y); break;
        case 2: result = multiply(x, y); break;
    }

    std::cout << "The answer is: " << result << '\n';

    return 0;
} */
//*******************Point-1***
//*******************Point-2***
int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    int x{};
    std::cout << "Enter a number: ";
    std::cin >> x;

    int y{};
    std::cout << "Enter another number: ";
    std::cin >> y;

    int op{};
    do
    {
        std::cout << "Enter an operation (0=add, 1=subtract, 2=multiply): ";
        std::cin >> op;
    } while (op < 0 || op > 2);

    // Create a function pointer named pFcn (yes, the syntax is ugly)
    int (*pFcn)(int, int) { nullptr };

    // Set pFcn to point to the function the user chose
    switch (op)
    {
        case 0: pFcn = &add; break;
        case 1: pFcn = &subtract; break;
        case 2: pFcn = &multiply; break;
    }

    // Call the function that pFcn is pointing to with x and y as parameters
    // This uses late binding
    // address resolution of the function pointer is done at run time.
    std::cout << "The answer is: " << pFcn(x, y) << '\n';

    return 0;
}
//*******************Point-2***
