/**
 * 
 */
#include <iostream>

using namespace std;


double myPow(double x, int n) 
{
    double eval{1};
    int count = 0;
    bool isNegative = false;
    count = n;

    if(count == 0)
        return 1;
    
    if(count < 0)
    {
        isNegative = true;
        count *= -1;
    }

    while(count > 0)
    {
        if(isNegative)
            eval *= 1.0d/x;
        else
            eval *= x;
        count--;
    }
    
    return eval;
}

int main(int argc, char const *argv[])
{
    cout << myPow(5, -3);
    return 0;
}
    