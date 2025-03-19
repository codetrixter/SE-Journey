/**
 * @file forwardListSTL.cpp
 * @author Abhishek
 * @brief Here we explore forward list and all its members:
 * 1- assign() function is overloaded to achieve multiple functionalities.
 * 2- push_front(), emplace_front() and pop_front().
 * 3- insert_after(), emplace_after() and erase_after().
 * 4- remove() and remove_if().
 * @version 0.1
 * @date 2022-06-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <forward_list>

//*****************assign()***
/* int main(int argc, char const *argv[])
{
    std::forward_list<int> fList1;
    std::forward_list<int> fList2;
    std::forward_list<int> fList3;

    //storing random elements
    fList1.assign({1, 2, 3});

    //storing repeatable elements
    fList2.assign(5, 10);

    //assignment via another list
    fList3.assign(fList1.begin(), fList1.end());

    for(auto i: fList1)
        std::cout << i << " ";
    std::cout << std::endl;

    for(auto i: fList2)
        std::cout << i << " ";
    std::cout << std::endl;

    for(auto i: fList3)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
} */
//*****************assign()***

//*****************push_front(), emplace_front() and pop_front()***
/* int main(int argc, char const *argv[])
{
    std::forward_list<int> fList {1, 2, 3, 4, 5, 6};

    std::cout << "The list initialized: ";
    for(auto i: fList)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //pushing the element to the start of the list
    fList.push_front(60);
    std::cout << "The list after push_front: ";
    for(auto i: fList)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //pushes element to the front of the list without copy.
    fList.emplace_front(70);
    std::cout << "The list afteremplace_front: ";
    for(auto i: fList)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //deletes first element of the list.
    fList.pop_front();
    std::cout << "The list after pop_front: ";
    for(auto i: fList)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
} */
//*****************push_front(), emplace_front(), splice_after() and pop_frot()***

//*****************insert_after(), emplace_after() and erase_after()***
int main(int argc, char const *argv[])
{
    std::forward_list<int> flist{10, 20, 30};
    std::forward_list<int> flist2{60, 70, 80};

    std::forward_list<int>::iterator itr;

    //inserting 1, 2,and 3 in the list after the first element.
    itr = flist.insert_after(flist.begin(), {1, 2, 3});

    std::cout << "list after the insert_after() operation: ";
    for(int& c: flist)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    //it does the same job as insert_after but without copying.This inserts 2 after itr(1, 2, 3)
    itr = flist.emplace_after(itr, 2);

    std::cout << "list after the emplace_after() operation: ";
    for(int& c: flist)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    //it does the same job as insert_after but copies the list of elements.
    flist.splice_after(flist.begin(), flist2);

    std::cout << "list after the splice_after() operation: ";
    for(int& c: flist)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    //erase after, erases the element after the mentioned element.
    itr = flist.erase_after(itr);

    std::cout << "list after the erase_after() operation: ";
    for(int& c: flist)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    //another version of the erase_after which deletes all the elements between the start and end
    //iterator exclusively.
    itr = flist.erase_after(flist.begin(), flist.end());

    std::cout << "list after the emplace_after() range operation: ";
    for(int& c: flist)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    return 0;
}
//*****************insert_after(), emplace_after() and erase_after()***

//*****************remove() and remove_if()***
/* int main(int argc, char const *argv[])
{
    std::forward_list<int> flist{20, 40, 60};

    std::forward_list<int>::iterator itr;

    //remove the specified element from the list.
    flist.remove(20);
    std::cout << "list after the remove() operation: ";
    for(int& c: flist)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    //remove the specified element from the list on a given condition, the condition is given via lambda.
    flist.remove_if([](int n) 
    { 
        return n < 50;
    });

    std::cout << "list after the remove_if() operation: ";
    for(int& c: flist)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    
    return 0;
} */

//*****************remove() and remove_if()***