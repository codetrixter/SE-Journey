/**
 * @file memcpyAbh.cpp
 * @author Abhishek
 * @brief Here we explore the purpose of memcpy and its uses:
 * 1- It is used to copy the data byte by byte from one type to another.
 * 2- It is different than lets say strcpy in the sense that strcpy stops copying once the null 
 * character is encountered, but memcpy does not stops at null characters.
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<string.h>

int main()
{
    char s[5]={'s','a','\0','c','h'};
    char p[5];
    char t[5];
    int i;
    strcpy(p,s);
    memcpy(t,s,5);
    for(i=0;i<5;i++)
        printf("%c",p[i]);
        printf("\n");
    for(i=0;i<5;i++)
        printf("%c",t[i]);

    return 0;
}

