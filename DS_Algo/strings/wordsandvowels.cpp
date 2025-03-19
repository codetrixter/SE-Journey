#include <iostream>

int main(int argc, char const *argv[])
{
    char str[] = "abhishek mishra";
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            std::cout << str[i];
        if(str[i] == ' ')
            count++;
    }
    std::cout << "Number of words are: " << count+1;
    return 0;
}
