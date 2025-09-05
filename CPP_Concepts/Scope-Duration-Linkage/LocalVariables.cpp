/**
 * *SCOPE:
 * - Scope (of an identifier) referes to the availablity of that identifier during the course of the program execution.
 * - If the identifer can be accessed, then it is (in scope), else (out of scope).
 * 
 * *Duration:
 * - This refers to the rules that govern when and how a variable is created(instantiated) or when it is destroyed.
 * - usually it referes to the varibales lifetime.
 * 
 * *LINKAGE:
 * - An identifier’s linkage determines whether a declaration of that same identifier in a different scope refers to the 
 * same object (or function).
 * 
 * !importanat points to rem.:
 * - Local vairable have block scope.
 * - All varibale names within a scope must be unique.
 * - Local variables have automatic storage duration.
 * - Local variabels have no linkage.
 * 
 * *NOTE: Local variables must be defined in the most limited scope.
 */

 #include <iostream>

 int main(int argc, char const *argv[])
 {
    int small = 0, large = 0;   //uninitialized by default
    std::cout << "Enter an Integer:" << std::endl;
    std::cin >> small;

    std::cout << "Enter a larger no: " << std::endl;
    std::cin >> large;

    //if the user did it incorrectly.
    if(large < small)
    {
        std::cout << "Swapping the values..." << std::endl;
        int temp = 0;
        temp = large;
        large = small;
        small = temp;
    }   //scope of temp ends here
       
    std::cout << "The smaller value is : " << small << std::endl;
    std::cout << "The larger value is : " << large << std::endl;
    return 0;
 }
 