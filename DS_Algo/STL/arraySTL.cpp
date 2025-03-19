/**
 * @file arraySTL.cpp
 * @author Abhishek
 * @brief Array class in c++ has following benefits compared to c-style arrays:
 * 1- These know their own size, hence while passing to functions we need to pass size as a parameter
 * 2- Array classes don't decay into pointers.(need to look more into this)
 * 3- These are generally more efficient, light-weight and reliable.
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <array>
#include <tuple>    //get()
//************at(), get() and operator[]***

/* int main(int argc, char const *argv[])
{
    std::array<int, 6> ar = {1, 2, 3, 4, 5, 6};

    std::cout << "\n array elements using at() : ";
    for(int i = 0; i < 6; i++)
        std::cout << ar.at(i) << " ";
    std::cout << std::endl;

    //This is not a member of the array class, instead overloaded function from tuple.
    std::cout << "\n array elements using get() : ";
    std::cout << std::get<0>(ar) << " " << std::get<1>(ar) << " ";
    std::cout << std::get<2>(ar) << " " << std::get<3>(ar) << " ";
    std::cout << std::get<4>(ar) << " " << std::get<5>(ar) << " ";
    std::cout << std::endl;

    std::cout << "\n The array elements are (using operator[]) : ";
    for ( int i=0; i<6; i++)
    std::cout << ar[i] << " ";
    std::cout << std::endl;

    return 0;
} */
//************at(), get() and operator[]***

//************front(), back()***
/* int main(int argc, char const *argv[])
{
    std::array<int, 6> arr = {1, 2, 3, 4, 5, 6};

    std::cout << "First element fo the array is: ";
    std::cout << arr.front() << std::endl;

    std::cout << "Last element of the array is: ";
    std::cout << arr.back() << std::endl;

    return 0;
} */

//************front(), last()***

//************size() and max_size()***
/* int main()
{
    // Initializing the array elements, the rest of the places are filled with ) hence the size will 
    // still sow up as 10
    std::array<int,10> ar = {1, 2, 3, 4, 5, 6};
 
    // Printing number of array elements
    std::cout << "The number of array elements is : ";
    std::cout << ar.size() << std::endl;
 
    // Printing maximum elements array can hold
    std::cout << "Maximum elements array can hold is : ";
    std::cout << ar.max_size() << std::endl;
 
    return 0;
 
} */
//************size() and max_size()***
//************swap()***
/* int main()
{
 
    // Initializing 1st array
    std::array<int,6> ar = {1, 2, 3, 4, 5, 6};
 
    // Initializing 2nd array
    std::array<int,6> ar1 = {7, 8, 9, 10, 11, 12};
 
    // Printing 1st and 2nd array before swapping
    std::cout << "The first array elements before swapping are : ";
    for (int i=0; i<6; i++)
    std::cout << ar[i] << " ";
    std::cout << std::endl;
    std::cout << "The second array elements before swapping are : ";
    for (int i=0; i<6; i++)
    std::cout << ar1[i] << " ";
    std::cout << std::endl;
 
    // Swapping ar1 values with ar
    ar.swap(ar1);
 
    // Printing 1st and 2nd array after swapping
    std::cout << "The first array elements after swapping are : ";
    for (int i=0; i<6; i++)
    std::cout << ar[i] << " ";
    std::cout << std::endl;
    std::cout << "The second array elements after swapping are : ";
    for (int i=0; i<6; i++)
    std::cout << ar1[i] << " ";
    std::cout << std::endl;
 
    return 0;
 
} */
//************swap()***

//************empty() and fill()***
int main()
{
 
    // Declaring 1st array
    std::array<int,6> ar;
 
    // Declaring 2nd array as empty
    std::array<int,0> ar1;
 
    // Checking size of array if it is empty
    ar1.empty()? std::cout << "Array empty":
        std::cout << "Array not empty";
    std::cout << std::endl;
 
    // Filling array with 0
    ar.fill(0);
 
    // Displaying array after filling
    std::cout << "Array after filling operation is : ";
    for ( int i=0; i<6; i++)
        std::cout << ar[i] << " ";
 
    return 0;
 
}
//************empty() and fill()***