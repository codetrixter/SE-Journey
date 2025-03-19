/**
 * * Lvalues abd Rvalues are in c++ even before c++11, with the advent of c++11, Lvalue and 
 * * Rvalue references were introduced.
*/

// Takes an l-value and returns an l-value.
int lValueFunc(int a)
{
    return a;
}

//This function takes the r-value as input and returns the rvalue as well.
int rValueFunc(int&& a)
{
    return a;
}

//This function while return an l-value but can take both l and r values as parameters.
int lRvalueFunc(const int& value)
{
    return value;
} 

int main(int argc, char const *argv[])
{
    int x = 10; //x here is an L-value.
    lValueFunc(x);  //l-value is passed hence no error
    lValueFunc(222); //here the rvalus is converted to an lvalue while being passed to the function
    rValueFunc(20); //r-value is passed 
    //rValueFunc(22) = 100; //lvalue required on lHS of = operator.

    //-------------------

    lRvalueFunc(x);
    lRvalueFunc(20);

    return 0;
}
