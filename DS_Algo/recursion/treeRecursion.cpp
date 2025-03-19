/**
 * @file treeRecursion.cpp
 * @author Abhishek
 * @brief implementation of tree recursion, it includes multiple recursive calls
 * @version 0.1
 * @date 2022-05-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

# include <iostream>

void treeCall(int n)
{
    if(n > 0)
    {
        std::cout << n;
        treeCall(n-1);
        treeCall(n-1);
    }
}
int main(int argc, char const *argv[])
{
    int x = 3;
    treeCall(x);
    
    return 0;
}
