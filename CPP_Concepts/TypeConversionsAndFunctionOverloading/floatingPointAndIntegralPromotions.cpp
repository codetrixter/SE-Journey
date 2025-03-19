/**
 * @file floatingPointAndIntegralPromotions.cpp
 * @author Abhishek
 * @brief Here we discuss the Numeric promotions:
 * 1- This type of promotion a narrower numeric type is converted to a wider numeric type.
 * 2- All numeric promotions are value preserving meaning there is no loss od data or precision.
 * Numeric promotions are of two type:
 * 1- Integral 
 * 2- Floating point
 * Integral Promotion:
 *  - signed char or signed short can be converted to int.
    - unsigned char, char8_t, and unsigned short can be converted to int, if int can hold the entire range of the type, or unsigned int otherwise.
    - If char is signed by default, it follows the signed char conversion rules above. If it is unsigned by default, it follows the unsigned char conversion rules above.
    - bool can be converted to int, with false becoming 0 and true becoming 1.
 * Floating Point promotion:
    - value of type float can be converted to double.   
 * @version 0.1
 * @date 2022-06-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

void printInt(int val)
{
    std::cout << val << std::endl;
}

void printDouble(double dd)
{
    std::cout << dd;
}

int main(int argc, char const *argv[])
{
    printInt(2);

    //short is promoted to int
    short s{3};
    printInt(s);
    //char is promoted to int
    printInt('a');
    //boolean is promoted to int
    printInt(false);    

    //float value is promoted to double
    printDouble(3.5f);
    
    return 0;
}
