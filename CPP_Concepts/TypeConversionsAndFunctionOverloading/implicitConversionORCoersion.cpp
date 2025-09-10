/**
 * @file implicitConversionORCoersion.cpp
 * @author Abhishek 
 * @brief Here we see the imlicit conversion dynamics:
 * 1- Implicit type conversion cases.
 * 2- C++ defines how different fundamental types are converted called as "standard conversions".
 * These standard conversions are divided into 4 categories:
 * a- Numeric promotions.
 * b- Numeric conversions.
 * c- Arithmetic conversions.
 * d- Other conversions.
 * 
 * When a type conversion is needed, the compiler will see if there are standard conversion that it can 
 * use to convert the value to the desired type. The compiler might use 0 or more standard conversion in 
 * the conversion process.
 * !For full list of supported conversion in C++23 here is the list which can be referred from the image typeconversions.png
 * @version 0.1
 * @date 2022-06-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
//****************IMplicit type conversions***
 
void doSomething(long ld)
{}

//Here integert type 7 is converted into float
float foo()
{
    return 7;
}

int main(int argc, char const *argv[])
{
    //here integer type 3 is converted to type double.
    double d{3};
    d = 9;

    //Here integer type 4 is converted to double
    double division{3.0/4};

    //Here integer type 5 is converted to boolean
    if(5)

    //Here passed integer value is converted to long
    doSomething(5);

    //narrowing conversion are not allowed during brace initialization
    //int x{2.9}; //error

    return 0;
}
//****************IMplicit type conversions***