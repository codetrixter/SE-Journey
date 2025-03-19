/**
 * @file lowerTriangle.cpp
 * @author Abhishek
 * @brief Imlementation of lower triangle.
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

class Triangle
{
    private:
        int n;
        int *Arr;

    public: 

    Triangle(int d)
    {
        this->n = d;
        Arr = new int[(d*(d+1))/2];
    }

    void set(int x, int r, int c);
    void setColumnMajor(int x, int r, int c);
    int get(int r, int c);
    int getColumnMajor(int r, int c);
    void display();
    void displayColumnMajor();
};

void Triangle::set(int x, int r, int c)
{
    if(r >= c )
        Arr[((r*(r-1))/2+(c-1))] = x;
}

int Triangle::get(int r, int c)
{
    if(r >= c)
        return Arr[((r*(r-1))/2+(c-1))];
    else
        return 0;
}

void Triangle::setColumnMajor(int x, int r, int c)
{
    if(r >= c )
    {
        int func = (n*(c-1)) - (((c-2)*(c-1))/2) + (r-c);
        Arr[func] = x;
    }
}

int Triangle::getColumnMajor(int r, int c)
{
    if(r >= c)
    {
        int func = (n*(c-1)) - (((c-2)*(c-1))/2) + (r-c);
        return Arr[func];
    }
    else
        return 0;
}

void Triangle::display()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i < j)
                std::cout << 0 << " ";
            else    
                std::cout << Arr[((i*(i-1))/2+(j-1))] << " ";
        }
        std::cout << std::endl;
    }
}

void Triangle::displayColumnMajor()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i < j)
                std::cout << 0 << " ";
            else    
                std::cout << Arr[(n*(j-1)) - (((j-2)*(j-1))/2) + (i-j)] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    Triangle tt(3);
    // tt.set(10, 1, 1);
    // tt.set(20, 2, 1);
    // tt.set(30, 2, 2);
    // tt.set(40, 3, 1);
    // tt.set(50, 3, 2);
    // tt.set(60, 3, 3);
    //------------------
    tt.setColumnMajor(10, 1, 1);
    tt.setColumnMajor(20, 2, 1);
    tt.setColumnMajor(30, 2, 2);
    tt.setColumnMajor(40, 3, 1);
    tt.setColumnMajor(50, 3, 2);
    tt.setColumnMajor(60, 3, 3);
    /**
     * 10  0 0
     * 20 30 0
     * 40 50 60
     */
    //tt.display();

    tt.displayColumnMajor();
    
    /**
     * 10   //row major
     * 50   //column major
     */
    std::cout << tt.getColumnMajor(3, 2);

    return 0;
}
