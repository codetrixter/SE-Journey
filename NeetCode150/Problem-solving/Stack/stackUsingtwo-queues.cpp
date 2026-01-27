/**
 *
 */

#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack()
    {
    }

    // This method uses two queues to achieve stack like behaviour
    /* void push(int x)
    {
        // only executes when first element is inserted
        if (q1.empty())
        {
            q1.push(x);
            return;
        }

        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // updating q1 and making q2 empty for next push
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    } */

    // This method uses single queue for stack like behaviour
    void push(int x) 
    {
        // only executes when first element is inserted
        if(q1.empty())
        {
            q1.push(x);
            return;
        }   

        q1.push(x);
        int update_size = q1.size()-1;
        while(update_size != 0)
        {
            q1.push(q1.front());
            q1.pop();
            update_size--;
        } 
    }

    //@TODO use queue of queues for constant time push() and pop().

    int pop()
    {
        int top_val = q1.front();
        q1.pop();
        return top_val;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main(int argc, char const *argv[])
{
    MyStack ms;
    ms.push(5);
    ms.push(10);
    cout <<  ms.top();
    return 0;
}
