#include <iostream>
#include <algorithm>

void rotate(std::vector<int>& vec, int k)
{
    int a = k%vec.size();

    std::reverse(vec.begin(), vec.end());
    std::reverse(vec.begin(), vec.begin()+a);
    std::reverse(vec.begin()+a, vec.end()); 
}

int main(int argc, char const *argv[])
{
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7};
    rotate(input, 3);

    for(auto &item : input)
    {
        std::cout << item << " ";
    }    
    return 0;
}
