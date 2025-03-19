/**
 * @file listSTL.cpp
 * @author Abhishek
 * @brief 
 * Basics::
 * 1- These are sequential containers meaning that these can be used to access the elements in a define sequence,
 * which is either forward or backwards.
 * 2- These allow non-contiguous memory allocation.
 * 3- This API implements doubly linked list.
 * Here we discuss about the operations that we can perform on the doubly linked list:
 * 
    0- front()	Returns the value of the first element in the list.
    1- back() - 	Returns the value of the last element in the list.
    2- push_front(g) - 	Adds a new element ‘g’ at the beginning of the list.
    3- push_back(g) -  	Adds a new element ‘g’ at the end of the list.
    4- pop_front() - 	Removes the first element of the list, and reduces size of the list by 1.
    5- pop_back() - 	Removes the last element of the list, and reduces size of the list by 1.
    6- list::begin() - 	begin() function returns an iterator pointing to the first element of the list.
    7- list::end() - 	end() function returns an iterator pointing to the theoretical last element 
    which follows the last element.
    8- list rbegin() and rend() - 	rbegin() returns a reverse iterator which points to the last element of the list. 
    rend() returns a reverse iterator which points to the position before the beginning of the list.
    9- list cbegin() and cend()  - 	 cbegin() returns a constant random access iterator which points to the
    beginning of the list. cend() returns a constant random access iterator which points to the end of the list.
    10- list crbegin() and crend() -  	crbegin() returns a constant reverse iterator which points to the last 
    element of the list i.e reversed beginning of container. crend() returns a constant reverse iterator which 
    points to the theoretical element preceding the first element in the list i.e. the reverse end of the list.
    11- empty()  - 	Returns whether the list is empty(1) or not(0).
    12- insert() - 	Inserts new elements in the list before the element at a specified position.
    13- erase() - 	Removes a single element or a range of elements from the list.
    14- assign() - 	Assigns new elements to list by replacing current elements and resizes the list.
    15- remove() - 	Removes all the elements from the list, which are equal to given element.
    16- list::remove_if() - 	Used to remove all the values from the list that correspond true to the predicate or 
    condition given as parameter to the function.
    17- reverse() - 	Reverses the list.
    18- size() - 	Returns the number of elements in the list.
    19- list resize() - 	Used to resize a list container.
    20- sort() - 	Sorts the list in increasing order.
    21- list max_size() -  	Returns the maximum number of elements a list container can hold.
    22- list unique() - 	Removes all duplicate consecutive elements from the list.
    23- list::emplace_front() -  and list::emplace_back()	emplace_front() function is used to insert a new element 
    into the list container, the new element is added to the beginning of the list. emplace_back() function is 
    used to insert a new element into the list container, the new element is added to the end of the list.
    24- list::clear() - 	clear() function is used to remove all the elements of the list container, thus 
    making it size 0.
    25- list::operator= - 	This operator is used to assign new contents to the container by replacing the 
    existing contents.
    26- list::swap() - 	This function is used to swap the contents of one list with another list of same type and size.
    27- list splice() - 	Used to transfer elements from one list to another.
    28- list merge() - 	Merges two sorted lists into one.
    28- list emplace() - 	Extends list by inserting new element at a given position.
 * @version 0.1
 * @date 2022-06-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <list>

void printList(std::list<int> temp)
{
    std::list<int>::iterator it;
    for(auto it = temp.begin(); it != temp.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

int main(int argc, char const *argv[])
{
    std::list<int> list1, list2;

    //initializing the lists
    for(auto i = 0; i < 10; i++)
    {
        list1.push_back(i * 2);
        list2.push_back(i * 3);
    }

    printList(list1);
    printList(list2);

    return 0;
}