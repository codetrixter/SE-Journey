/**
 * Implement the Least Recently Used (LRU) cache class LRUCache. The class should support the following operations

LRUCache(int capacity) Initialize the LRU cache of size capacity.
int get(int key) Return the value corresponding to the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
If the introduction of the new pair causes the cache to exceed its capacity, remove the least recently used key.
A key is considered used if a get or a put operation is called on it.

Ensure that get and put each run in 
O(1) average time complexity.

Example 1:

Input:
["LRUCache", [2], "put", [1, 10],  "get", [1], "put", [2, 20], "put", [3, 30], "get", [2], "get", [1]]

Output:
[null, null, 10, null, null, 20, -1]

Explanation:
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 10);  // cache: {1=10}
lRUCache.get(1);      // return 10
lRUCache.put(2, 20);  // cache: {1=10, 2=20}
lRUCache.put(3, 30);  // cache: {2=20, 3=30}, key=1 was evicted
lRUCache.get(2);      // returns 20 
lRUCache.get(1);      // return -1 (not found)
Constraints:

1 <= capacity <= 100
0 <= key <= 1000
0 <= value <= 1000
 */

#include <iostream>

using namespace std;

//------------@TODO 
class LRUCache 
{
    private:
        pair<int, int> data;
        LRUCache* next;
        LRUCache* head;
        int cap, size;
    public:
    LRUCache(int key, int value);
    LRUCache(int capacity);

    //freeing the list memory...
    // ~LRUCache()
    // {
    //     if(head == nullptr)
    //         free(head);
    //     else
    //     {
    //         while(head != nullptr)
    //         {
    //             LRUCache* temp = head;
    //             head = head->next;
    //             free(temp);
    //         }
    //     }
    // }
    
    // here we will fetch the item and move the node to the begining, so that least recently used node is at the end of the list.
    int get(int key);
    
    // since implementing using list, hence this will do insert at begining
    // if the capacity is reached, delete from the end.
    void put(int key, int value);
};

LRUCache::LRUCache(int key, int value) :
data {key, value},
next {nullptr},
head {nullptr},
size {++size}
{

}

LRUCache::LRUCache(int capacity) :
    data {NULL, NULL},
    next {nullptr},
    head {nullptr},
    cap {capacity},
    size {0}
{
    
}

void LRUCache::put(int key, int value) 
{
    if(head == nullptr)
    {
        head->data.first = key;
        head->data.second = value;
    }
    else
    {
        LRUCache* newNode = new LRUCache(key, value);
        newNode->next = head;
        head = newNode;
    }
    //delete from the end
    if(size > cap)
    {
        LRUCache* temp = head;
        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        size--;
    }
}

int LRUCache::get(int key)
{
    LRUCache* temp = head;
    LRUCache* prev = head;

    while(temp->data.first != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp->next == nullptr && temp->data.first != key)
        return -1;
    else
    {
        prev->next = temp->next;
    }
    
    //insert key in the beg
    temp->next = head;
    head = temp;

    return head->data.second;
}

int main(int argc, char const *argv[])
{
    LRUCache cache(2);

    cache.put(1, 10);  // cache: {1=10}
    cout << cache.get(1);      // return 10
    cache.put(2, 20);  // cache: {1=10, 2=20}
    cache.put(3, 30);  // cache: {2=20, 3=30}, key=1 was evicted
    cout << cache.get(2);      // returns 20 
    cout << cache.get(1);      // return -1 (not found)

    return 0;
}
