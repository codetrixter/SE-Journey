/**
 * ! Prefer nullptr to 0 and NULL
 * *Following are the benefits of using nullptr over 0 and NULL
 * *1- This could save you from overload resolution surprises.
 * *2- It improves code clarity hen auto type is used for type identification
 * *3- benefits of using nullptr over its counterparts shines brightly when templates enter the picture.
 */

 #include <iostream>

 //----------point 1--------------

 /* void fun(int)
 {
    std::cout << "int...\n";
 }

 void fun(bool)
 {
    std::cout << "bool...\n";
 }

 void fun(void*)
 {
    std::cout << "void...\n";
 }

 int main(int argc, char const *argv[])
 {
    fun(0);
    fun(NULL);  //give ambigous error since NULL internall acts as an INT which could resolve to int or void pointer.   
    return 0;
 } */
 
 //----------point 1--------------

 //----------point 2--------------

int* findRecord()
{
    std::cout << "find record...\n";
    return static_cast<int*>(0);
}                

int main(int argc, char const *argv[])
{
    auto result = findRecord();
    if(result == 0) //if there is difficult to find out the return type of the function then it is ver hard to find out that the return type is int or pointer.
        std::cout <<"match";
    return 0;
}

 //----------point 2--------------
