/**
 * * Non-Const global variables are evil :
 * ! - Non const. varibales are discouraged because due to their nature i.e external linkage, meaning any function of any translation unit can change the 
 * !value of that varibales in a way that make it difficult to debug -> This can be rectified by using local variables
 * ! - Initialization order problem of global variables
 * *
 */

 #include <iostream>

int g_mode; // declare global variable (will be zero-initialized by default)

void doSomething()
{
    g_mode = 2; // set the global g_mode variable to 2
}

int main()
{
    g_mode = 1; // note: this sets the global g_mode variable to 1.  It does not declare a local g_mode variable!

    doSomething();

    // Programmer still expects g_mode to be 1
    // But doSomething changed it to 2!

    if (g_mode == 1)
    {
        std::cout << "No threat detected.\n";
    }
    else
    {
        std::cout << "Launching nuclear missiles...\n";
    }

    return 0;
}