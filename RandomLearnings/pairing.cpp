#include <iostream>
#include <map>
#include <utility>

int main(int argc, char const *argv[])
{
    std::map <int, std::pair<double, double>> loc;

    loc[20] = {123.223, 213.313};

    std::cout << loc[20].first;
    
    return 0;
}
