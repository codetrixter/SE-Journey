/**
 * @file functionPointers.cpp
 * @author Abhishek
 * @brief here we look at the syntax and uses of function pointers:
 * 1- The function call makes the program execution jump to a function definition, whenever a 
 * function is called using ().
 * 2- syntax of a function pointer:
 *  --> int (*funptr)() : here, funptr is a function pointer to a function who has a return type of integer and takes
 *      no parameters.
 * 
 * 3- Assigning a function to a function pointer.
 * 4- Calling functions using function pointer.
 * 5- passing functions as argumenst to other functions AKA callback functions.
 *  a--> we can use type aliases by "using" for making function pointers definitions less ugly.
 * 6- std::function<> can also be used to define function pointers.
 * 7- Quiz.
 * @version 0.1
 * @date 2022-06-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <utility>


//*********point 1***
/* int foo()   //code for foo starts at memory address 0x002717f0
{
    return 5;
}

int main(int argc, char const *argv[])
{
    ///the execution pointer jumps to address of foo function i.e 0x002717f0
    std::cout << foo();

    ///prints the address of the function foo()
    std::cout << reinterpret_cast<void*>(foo);  
    return 0;
} */
//*********point 1***

//*********point 3 and 4***
// int foo()
// {
//     return 5;
// }

// int goo(int a, int b)
// {
//     return a+b;
// }
// int main(int argc, char const *argv[])
// {
//     int (*funptr1)() {&foo};
//     std::cout << (*funptr1)() << std::endl; //output = 5

//     int (*funptr2)(int, int) = &goo;
//     std::cout << funptr2(10, 20); //output = 30
//     return 0;
// } 
//*********point 3 and 4***

//*********point 5***
/*
/// Here is a comparison function that sorts in ascending order
/// (Note: it's exactly the same as the previous ascending() function)
bool ascending(int x, int y)
{
    return x > y; // swap if the first element is greater than the second
}

/// Here is a comparison function that sorts in descending order
bool descending(int x, int y)
{
    return x < y; // swap if the second element is greater than the first
}

///we can use using for making function pointers pretier.
using validateFunction = bool (*)(int, int);

/// Note our user-defined comparison is the third parameter, which can also be given as default parameter.

///void selectionSort(int* array, int size, bool (*comaparatorFun)(int, int) = ascending)
void selectionSort(int* array, int size, validateFunction validate = ascending)
{
    /// Step through each element of the array
    for (int startIndex{ 0 }; startIndex < (size - 1); ++startIndex)
    {
        /// bestIndex is the index of the smallest/largest element we've encountered so far.
        int bestIndex{ startIndex };

        /// Look for smallest/largest element remaining in the array (starting at startIndex+1)
        for (int currentIndex{ startIndex + 1 }; currentIndex < size; ++currentIndex)
        {
            /// If the current element is smaller/larger than our previously found smallest
            if (validate(array[bestIndex], array[currentIndex])) // COMPARISON DONE HERE
            {
                /// This is the new smallest/largest number for this iteration
                bestIndex = currentIndex;
            }
        }

        /// Swap our start element with our smallest/largest element
        std::swap(array[startIndex], array[bestIndex]);
    }
}

/// This function prints out the values in the array
void printArray(int* array, int size)
{
    for (int index{ 0 }; index < size; ++index)
    {
        std::cout << array[index] << ' ';
    }

    std::cout << '\n';
}

int main()
{
    int array[9]{ 5, 7, 1, 9, 2, 4, 3 };

    /// Sort the array in descending order using the descending() function
    selectionSort(array, 9, descending);
    std::cout << "Sorted in descending order: ";
    printArray(array, 9);

    /// Sort the array in ascending order using the ascending() function
    selectionSort(array, 9, ascending);
    std::cout << "Sorted in ascending order: ";
    printArray(array, 9);

    return 0;
} */
//*********point 5***

//*********point 6***
/* #include <functional>

int foo()
{
    return 5;
}

int goo(int a, int b)
{
    return a+b;
}
int main(int argc, char const *argv[])
{
    std::function<int()> funptr1{&foo};
    std::cout << funptr1();

    std::function<int(int, int)> funptr2 = &goo;
    std::cout << funptr2(10, 20);
    return 0;
} */
//*********point 6***
//*********QUIZ***
// #include <functional>

// using ArithmaticFunction = std::function<int(int, int)>;

// int add(int x, int y)
// {
//     return x+y;
// }

// int sub(int x, int y)
// {
//    return x-y; 
// }

// int mul(int x, int y)
// {
//     return x*y;
// }

// int division(int x, int y)
// {
//     return x/y;
// }

// ArithmaticFunction getArithmaticFunction(char operation)
// {
//     if(operation == '+')
//         return &add;
//     else if(operation == '-')
//         return &sub;
//     else if(operation == '*')
//         return &mul;
//     else if(operation == '/')
//         return &division;
//     else
//         return nullptr;
// }
// int main(int argc, char const *argv[])
// {
//     int val1, val2;
//     char op;
//     std::cout << "Enter two numbers: ";
//     std::cin >> val1 >> val2;
    
//     do 
//     {
//         std::cout << "enter the operation you want to perform on the given numbers: ";
//         std::cin >> op; 
//     }while(op != '+' && op != '-' && op != '*' && op != '/');   //checking for any other input other than 4 operations

//     ArithmaticFunction funTemp = getArithmaticFunction(op);
//     std::cout << funTemp(val1, val2);
//     return 0;
// }

//*********QUIZ***