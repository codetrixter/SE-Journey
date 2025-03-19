#include <iostream>

int main(int argc, char const *argv[])
{
    char str[] = "abhishek";
    int i = 0;

    for(; str[i] != '\0'; i++)
    {
        str[i] = str[i]-32;
    }

    for(int j = 0; str[j] != '\0'; j++)
    {
        std::cout << str[j];
    }
    return 0;
}
