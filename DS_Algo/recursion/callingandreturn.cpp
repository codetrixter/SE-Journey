/**
 * @file callingandreturnphose.cpp
 * @author Abhishek
 * @brief In this example we try to show the two phases of using recursion :
 * 1- Calling phase.
 * 2- Returm phase.
 * @version 0.1
 * @date 2022-05-03
 * 
 * @copyright Copyright (c) 2022
 */
#include <iostream>

void calling(int n)
{
    if(n > 0)
    {
        std::cout << n;
        calling(n-1);
    }
}

void returning(int n)
{
    if(n > 0)
    {
        returning(n-1);
        std::cout << n;
    }
}

int main(int argc, char const *argv[])
{
    int x = 4;
    //statements will be printed in chronological order
    std::cout << "*******printing in calling phase";
    calling(4);
    std::cout << std::endl;  
      
    //statements will be printed in reverse order
    std::cout << "*******printing in returning phase";
    returning(4);
    std::cout << std::endl;    
    return 0;
}
