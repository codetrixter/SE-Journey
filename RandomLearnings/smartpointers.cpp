#include <iostream>
#include <memory>

int main(int argc, char const *argv[])
{
    int x = 13;
    std::unique_ptr<int> uptr(new int(13));
    if(uptr != nullptr)
    {
        std::cout << "valid pointer";
    } 
    return 0;
}
