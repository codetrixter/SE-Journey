/**
 * @file diagonalMatrix.cpp
 * @author Abhishek
 * @brief Hee we implement diagonal matrix but use single dimension array to store it to save space.
 * @version 0.1
 * @date 2022-04-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

class Diagonal
{
    private:
    int n;
    int *A;

    public:
    //Storing 2D diagonal matrix as a single dimnesion array.
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }

    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~Diagonal()
    {
        delete []A;
    }
};

void Diagonal::set(int i, int j, int x)
{
    if(i == j)
    {
        A[i-1] = x;
    }
}

int Diagonal::get(int i, int j)
{
    if(i != j)
        return 0;
    else
        return A[i-1]; 
}

void Diagonal::display()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j)
                std::cout << 0 << " ";
            else    
                std::cout << A[i] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    Diagonal dMatrix(4);
    dMatrix.set(1, 1, 10);
    dMatrix.set(2, 2, 20);
    dMatrix.set(3, 3, 30);
    dMatrix.set(4, 4, 40);
    dMatrix.display();
    dMatrix.get(3,2);

    return 0;
}
