/**
 * Design and implement circular queue. The circular queue is a linear data structure in which the
 *  operations are performed based on FIFO (First In First Out) principle, and the last position is
 *  connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue.
 In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space
  in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language.
Example 1:

Input: ["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]

Output: [null, true, true, true, false, 3, true, true, true, 4]
Explanation:
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear(); // return 3
myCircularQueue.isFull(); // return True
myCircularQueue.deQueue(); // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear(); // return 4

Constraints:

1 <= k <= 1000.
0 <= value <= 1000
At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull.

*/

#include <iostream>
#include <memory>

using namespace std;

class MyCircularQueue
{
private:
    struct Node
    {
        int data;
        Node *next = nullptr;
        Node *prev = nullptr;

        Node(int val, Node *ptr, Node *p_ptr = nullptr) : data{val},
                                                          next{ptr},
                                                          prev{p_ptr}
        {
        }
    };

    int capacity;
    int size;

    Node *front = nullptr;
    Node *rear = nullptr;

public:
    MyCircularQueue(int k) : capacity{k},
                             size{0}
    {
    }

    ~MyCircularQueue()
    {
        while (size > 0)
        {
            deQueue();
        }
    }

    /// @brief insert in FIFO order, insert at rear
    /// @param value
    /// @return true(success) / false
    bool enQueue(int value)
    {
        // queue is full
        if (size == capacity)
            return false;

        if (size == 0)
        {
            front = new Node(value, front);
            rear = front;
            front->prev = rear;
            size++;
        }
        else
        {
            Node *node = new Node(value, front);
            node->prev = rear;
            rear->next = node;
            rear = node;
            front->prev = rear; // Update front's prev to point to new rear

            size++;
        }

        return true;
    }

    /// @brief FIFO means delete from front, update rear->next
    /// @return true(success) / false
    bool deQueue()
    {
        /// Q is empty
        if (size == 0)
            return false;

        // since rear is saved hence this takes constant time.
        Node *temp = front;

        // Only one element, set both pointers to nullptr
        if (size == 1)
        {
            front = nullptr;
            rear = nullptr;
        }
        else
        {
            front = temp->next;
            front->prev = rear;
            rear->next = front;
        }

        delete temp; // Use delete instead of free for C++ objects

        size--;

        return true;
    }

    /// @brief gets the front of the list
    /// @return front or -1
    int Front()
    {
        if (front)
            return front->data;
        else
            return -1;
    }

    /// @brief get the rear element of the list
    /// @return rear or -1
    int Rear()
    {
        if (rear)
            return rear->data;
        else
            return -1;
    }

    bool isEmpty()
    {
        if (size == 0)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (size == capacity)
            return true;
        else
            return false;
    }
};

int main(int argc, char const *argv[])
{
    unique_ptr<MyCircularQueue> myCircularQueue = make_unique<MyCircularQueue>(1);
    cout << boolalpha << myCircularQueue->enQueue(1) << ", "; // return True
    cout << boolalpha << myCircularQueue->deQueue() << ", ";
    cout << boolalpha << myCircularQueue->deQueue() << ", ";
    cout << myCircularQueue->Front() << ", ";
    cout << myCircularQueue->Rear() << ", ";
    cout << myCircularQueue->isEmpty();
    return 0;
}
