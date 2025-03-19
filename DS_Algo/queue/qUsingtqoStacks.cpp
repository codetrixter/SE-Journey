#include <iostream>
#include <stack>

class QueueWithStacks
{
public:
    std::stack<int> s1, s2;

    void enq(int x)
    {
        s1.push(x);
    }

    int deq()
    {
        // if both stacks are empty
        if (s1.empty() && s2.empty()) {
            std::cout << "Q is empty";
            exit(0);
        }
  
        // if s2 is empty, move
        // elements from s1
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
  
        // return the top item from s2
        int x = s2.top();
        s2.pop();
        return x;
    }
};
int main(int argc, char const *argv[])
{
    QueueWithStacks q;
    q.enq(10);
    q.enq(20);
    q.enq(30);
    std::cout << q.deq();
    std::cout << q.deq();
    return 0;
}
