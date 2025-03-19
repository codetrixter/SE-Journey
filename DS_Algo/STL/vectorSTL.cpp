/**
 * @file vectorstl.cpp
 * @author Abhishek
 * @brief Exploring vector STL and its functions and properties:
 * 1- Vectors are dnamic arrays that have the ability to resize itself accordingly.
 * 2- Removal from last takes constant time.
 * 3- insertions and deletion from beginning and middle takes linear time.
 * @version 0.1
 * @date 2022-06-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>

//***************traversing the vector
/* int main(int argc, char const *argv[])
{
    std::vector<int> lVect;

    for(int i = 0; i < 5; i++)
        lVect.push_back(i);
    
    //begin()->returns an iterator pointing to the first element in the vector.
    //end()->returns an iterator pointing to the theoritical element that follows the last element of the vector.
    std::cout << "\n traversing using begin() and end(): ";
    for(auto i = lVect.begin(); i != lVect.end(); ++i)
        std::cout << *i << " ";
    
    //begin()->returns a reverse iterator pointing to the last element in the vector.
    //end()->returns a reverse iterator pointing to the theoritical element that follows the first element of the vector.
    std::cout << "\n traversing using cbegin() and cend(): ";
    for(auto i = lVect.cbegin(); i != lVect.cend(); ++i)
        std::cout << *i << " ";

    //begin()->returns a constant iterator pointing to the first element in the vector.
    //end()->returns a constant iterator pointing to the theoritical element that follows the last element of the vector.
    std::cout << "\n traversing using rbegin() and rend(): ";
    for(auto i = lVect.rbegin(); i != lVect.rend(); ++i)
        std::cout << *i << " ";

    //begin()->returns a constant iterator pointing to the last element in the vector.
    //end()->returns a constant iterator pointing to the theoritical element that follows the first element of the vector.
    std::cout << "\n traversing using crbegin() and crend(): ";
    for(auto i = lVect.crbegin(); i != lVect.crend(); ++i)
        std::cout << *i << " ";

    return 0;
} */
//***************traversing the vector

//***************exploring capcity functions of vector
/* int main(int argc, char const *argv[])
{
    std::vector<int> lVect;

    for(int i = 1; i <= 5; i++)
        lVect.push_back(i);

    //returns the number of elements in the vector.
    std::cout << "\n size of the vector is: " << lVect.size();
    //returns the max amount of elements that the vector can hold.
    std::cout << "\n max size of the vector is: " << lVect.max_size();
    //returns the size of the storage space allocated to the vector, expressed as number of elements.
    std::cout << "\n capacity of the vector is: " << lVect.capacity();

    //resizes the vector to size 4.
    lVect.resize(4);
    std::cout << "\n resized vector size is: " << lVect.size();

    //checks if the vector is empty or not.
    if(!lVect.empty())
        std::cout << "\n vector is not empty";
    else
        std::cout << "vector is empty";
    
    //resizes the capacity of the vector to its size and destry all the elements beyond the capacity.
    lVect.shrink_to_fit();
    std::cout << "\n vector elements are: ";
    for(auto it = lVect.begin(); it != lVect.end(); ++it)
        std::cout << *it;
    
    //resize(n)-> it requests the vector capacity to be at least enough to accomodate n elements.
    return 0;
} */

//***************exploring capcity functions of vector

//***************exploring element access functions of vector
/* int main(int argc, char const *argv[])
{
    std::vector<int> lVect;

    for(int i = 1; i < 10; ++i)
        lVect.push_back(i*10);
    
    //reference operator[]
    std::cout << "\n Reference operator [x]: lVect[2]" << lVect[2];

    //at(x)->returns rference to the element at x position in the vector
    std::cout << "\n at(x): lVect.at(3) " << lVect.at(3);

    //front()-> returns the reference of the first element
    std::cout << "\n front(): " << lVect.front();

    //back()->returns the reference to the last element.
    std::cout << "\n back(): " << lVect.back();

    //data()->returns the direct pointer to the memory array used to store its own elements.
    int *ptr = lVect.data();
    std::cout << "\n data(): " << *ptr;

    return 0;
} */

//***************exploring element access functions of vector

//***************modifier functions of the vector
int main(int argc, char const *argv[])
{
    std::vector<int> lVect;

    //assign allocats 5, 10 times.
    //it assignes new values by repacing old ones.
    lVect.assign(5, 10);
    std::cout << "\n The vector elements are: ";
    for(auto it = lVect.begin(); it != lVect.end(); ++it)
        std::cout << *it;

    //inserts 15 at the back of the vector.
    lVect.push_back(15);
    int size = lVect.size();
    std::cout << "\n The last element is: " << lVect[size-1];

    //removes last element in the vector
    lVect.pop_back();

    std::cout << "\n The vector elements after pop are: ";
    for(auto it = lVect.begin(); it != lVect.end(); ++it)
        std::cout << *it;
    
    //inserts element before the specified position.
    lVect.insert(lVect.begin(), 5);
    std::cout << "\n The first element is : " << lVect[0];

    //removes element from the specified position
    lVect.erase(lVect.begin());
    std::cout << "\n The first element is : " << lVect[0];

    //extends the vector by inserting at the specified position
    lVect.emplace(lVect.begin(), 5);
    std::cout << "\n The first element is : " << lVect[0];

    //inserts at the end
    lVect.emplace_back(20);
    int sizeNew = lVect.size();
    std::cout << "\n The first element is : " << lVect[sizeNew-1];

    //erase the vector.
    lVect.clear();
    std::cout << "\n vector size after the erase: " << lVect.size();

    // two vector to perform swap
    std::vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
  
    std::cout << "\n\n Vector 1: ";
    for (int i = 0; i < v1.size(); i++)
        std::cout << v1[i] << " ";
  
    std::cout << "\n Vector 2: ";
    for (int i = 0; i < v2.size(); i++)
        std::cout << v2[i] << " ";

    //swaps v1 with v2.
    v1.swap(v2);

    std::cout << "\n After Swap \nVector 1: ";
    for (int i = 0; i < v1.size(); i++)
        std::cout << v1[i] << " ";
  
    std::cout << "\n Vector 2: ";
    for (int i = 0; i < v2.size(); i++)
        std::cout << v2[i] << " ";

    return 0;
}
//***************modifier functions of the vector
