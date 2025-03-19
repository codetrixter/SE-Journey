/**
 * @file addTwoNumbers.cpp
 * @author Abhishek
 * @brief Here we add two numbers using list.
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <list>
#include <iterator>

std::list<int> addNumbers(std::list<int>& list1, std::list<int>& list2)
{
    int carry = 0;
    // Reversing the lists
    list1.reverse();
    list2.reverse();

    //Third list to return the result
    std::list<int> list3{};

    std::list<int>::iterator it1 = list1.begin();
    std::list<int>::iterator it2 = list2.begin();

    while(it1 != list1.end() || it2 != list2.end())
    {
        list3.push_front((*it1 + *it2 + carry)%10); 
        carry = (*it1 + *it2 + carry)/10;
        it1++; it2++;
    }

    if(it1 == list1.end())
    {
        while(it2 != list2.end())
        {
            list3.push_front((*it2 + carry) % 10);
            carry = *it2 + carry / 10;
            it2++;
        }   
    }
    else if(it2 == list2.end())
    {
        while(it1 != list1.end())
        {
            list3.push_front((*it1 + carry) % 10);
            carry = *it1 + carry / 10;
            it1++;
        }   
    }

    return list3;
}
int main(int argc, char const *argv[])
{
    std::list<int> l1 = {2, 9, 9};
    std::list<int> l2 = {3, 9, 9};

    auto sumlist = addNumbers(l1, l2);
    //sumlist.reverse();

    for(auto item : sumlist)
    {
        std::cout << item;
    }
    return 0;
}
