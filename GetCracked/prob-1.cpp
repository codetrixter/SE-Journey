#include <iostream>

int x{42};
int main(int argc, char const *argv[])
{
    int x{x}; //here x will havejunk value since thi statement resolves to 

    // int x{}; //x here gets junk since local scope
    // x = x; // junk is assigned here.
    std::cout << x;
    return 0;
}
