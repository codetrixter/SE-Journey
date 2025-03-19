#include <iostream>

int main(int argc, char const *argv[])
{
    char str[] = "Abhishek";
    int i = 0, count = 0;
    for(; str[i] != '\0'; i++)
    {
        count++;
    }
    std::cout << count;
    return 0;
}
