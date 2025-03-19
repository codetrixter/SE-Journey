/**
 * @file lowerTriangle.cpp
 * @author Abhishek
 * @brief Imlementation of upper triangle using row major and column major technique.
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

    void setRowMajor(int x, int r, int c);
    void setColumnMajor(int x, int r, int c);
    int getRowMajor(int r, int c);
    int getColumnMajor(int r, int c);
    void displayRowMajor();
    void displayColumnMajor();
};

void Triangle::setRowMajor(int x, int r, int c)
{
    if(r <= c )
        Arr[(n*(r-1)) - (((r-2)*(r-1))/2) + (c-r)] = x;
}

int Triangle::getRowMajor(int r, int c)
{
    if(r <= c)
        return Arr[(n*(r-1)) - (((r-2)*(r-1))/2) + (c-r)];
    else
        return 0;
}

void Triangle::setColumnMajor(int x, int r, int c)
{
    if(r <= c )
    {
        int func = ((c*(c-1))/2) + (r-1);
        Arr[func] = x;
    }
}

int Triangle::getColumnMajor(int r, int c)
{
    if(r <= c)
    {
        int func = ((c*(c-1))/2) + (r-1);
        return Arr[func];
    }
    else
        return 0;
}

void Triangle::displayRowMajor()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i > j)
                std::cout << 0 << " ";
            else    
                std::cout << Arr[(n*(i-1)) - (((i-2)*(i-1))/2) + (j-i)] << " ";
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
            if(i > j)
                std::cout << 0 << " ";
            else    
                std::cout << Arr[((j*(j-1))/2) + (i-1)] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    Triangle tt(3);
    tt.setRowMajor(10, 1, 1);
    tt.setRowMajor(20, 1, 2);
    tt.setRowMajor(30, 1, 3);
    tt.setRowMajor(40, 2, 2);
    tt.setRowMajor(50, 2, 3);
    tt.setRowMajor(60, 3, 3);
    //------------------
    // tt.setColumnMajor(10, 1, 1);
    // tt.setColumnMajor(20, 2, 1);
    // tt.setColumnMajor(30, 2, 2);
    // tt.setColumnMajor(40, 3, 1);
    // tt.setColumnMajor(50, 3, 2);
    // tt.setColumnMajor(60, 3, 3);
    /**
     * 10  0 0
     * 20 30 0
     * 40 50 60
     */
    tt.displayRowMajor();

    //tt.displayColumnMajor();
    
    /**
     * 10   //row major
     * 50   //column major
     */
    std::cout << tt.getRowMajor(3, 3);

    return 0;
}
