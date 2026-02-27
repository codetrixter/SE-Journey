/**
 *Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the
 map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no
 mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
Example 1:

Input: ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]

Output: [null, null, null, 1, -1, null, 1, null, -1]
Explanation:
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1); // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3); // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2); // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2); // return -1 (i.e., not found), The map is now [[1,1]]

Constraints:

0 <= key, value <= 1,000,000
At most 10,000 calls will be made to put, get, and remove.
 */

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

/* class MyHashMap
{
private:
    vector<pair<int, int>> v_map;

public:
    MyHashMap()
    {
    }

    void put(int key, int value)
    {
        // Check if key already exists in v_map using std::find_if
        auto it = find_if(v_map.begin(), v_map.end(),
                               [key](const pair<int, int>& p) {
                                   return p.first == key;
                               });

        if (it != v_map.end())
        {
            // Key found, update the value
            it->second = value;
        }
        else
        {
            // Key not found, add new pair
            v_map.push_back(make_pair(key, value));
        }
    }

    int get(int key)
    {
        auto it = find_if(v_map.begin(), v_map.end(),
                                [key](const pair<int, int>& p)
                            {
                                return p.first == key;
                            });

        if(it != v_map.end())
            return it->second;
        else
            return -1;

    }

    void remove(int key)
    {
        // moves all elements matching the condition to the end and returns an
        // iterator to the first "removed" element, hence it is begin() of erase.
        v_map.erase(remove_if(v_map.begin(), v_map.end(),
                            [key](pair<int, int> &p)
                        {
                            return p.first == key;
                        }), v_map.end());
    }

    void show()
    {
        for(auto& pair : v_map)
        {
            cout << pair.first << ", " << pair.second << "\n";
        }
    }
}; */

// using array, with O(1) time complexity
/* class MyHashMap
{
private:
    vector<int> map;

public:
    MyHashMap() : map(1000001, -1) {}

    void put(int key, int value)
    {
        map[key] = value;
    }

    int get(int key)
    {
        return map[key];
    }

    void remove(int key)
    {
        map[key] = -1;
    }
}; */

// using Linked List with Chaining (Separate Chaining for Collision Resolution)
// This is a proper HashMap implementation with O(1) average time complexity
class MyHashMap
{
private:
    // Node structure for the linked list in each bucket
    struct ListNode
    {
        int key, val;      // Store key-value pair
        ListNode *next;    // Pointer to next node in the chain

        // Constructor with default parameters
        // Default key=-1 and val=-1 used for dummy head nodes
        ListNode(int key = -1, int val = -1, ListNode *next = nullptr)
            : key(key), val(val), next(next) {}
    };

    // Array of buckets, each bucket is a linked list (represented by head pointer)
    // This is the core data structure: vector of pointers to ListNodes
    vector<ListNode *> map;
    
    // Hash function: maps any key to a bucket index [0, map.size()-1]
    // Uses modulo operation for uniform distribution
    // Example: key=1001, map.size()=1000 -> hash(1001) = 1
    int hash(int key)
    {
        return key % map.size();
    }

public:
    // Constructor: Initialize HashMap with 1000 buckets
    // Each bucket starts with a dummy head node for easier insertion/deletion
    MyHashMap()
    {
        map.resize(1000);  // Create 1000 buckets
        for (auto &bucket : map)
        {
            // Each bucket gets a dummy head node (key=-1, val=-1)
            // This simplifies insertion at the beginning of the list
            bucket = new ListNode(0);
        }
    }

    // Insert or update a key-value pair
    // Time Complexity: O(n/k) where n=number of elements, k=number of buckets
    // Average case: O(1) with good hash distribution
    void put(int key, int value)
    {
        // Start from the dummy head of the appropriate bucket
        ListNode *cur = map[hash(key)];
        
        // Traverse the linked list to find if key already exists
        while (cur->next)
        {
            if (cur->next->key == key)
            {
                // Key found! Update the value and return
                cur->next->val = value;
                return;
            }
            cur = cur->next;
        }
        
        // Key not found, append new node at the end of the chain
        cur->next = new ListNode(key, value);
    }

    // Retrieve value for a given key
    // Returns -1 if key doesn't exist
    // Time Complexity: O(n/k) average, O(1) with good distribution
    int get(int key)
    {
        // Start from first actual node (skip dummy head with ->next)
        ListNode *cur = map[hash(key)]->next;
        
        // Traverse the chain to find the key
        while (cur)
        {
            if (cur->key == key)
            {
                return cur->val;  // Key found, return value
            }
            cur = cur->next;
        }
        
        return -1;  // Key not found
    }

    // Remove a key-value pair from the map
    // Time Complexity: O(n/k) average
    void remove(int key)
    {
        // Start from dummy head (need previous node for deletion)
        ListNode *cur = map[hash(key)];
        
        // Traverse to find the node to delete
        while (cur->next)
        {
            if (cur->next->key == key)
            {
                // Found the key! Delete the next node
                ListNode *tmp = cur->next;           // Store node to delete
                cur->next = cur->next->next;         // Bypass the node
                delete tmp;                          // Free memory
                return;
            }
            cur = cur->next;
        }
        // If key not found, do nothing (no error)
    }

    void show()
    {
        // Can implement to display all key-value pairs for debugging
    }
};

int main(int argc, char const *argv[])
{
    unique_ptr<MyHashMap> myHashMap = make_unique<MyHashMap>();
    myHashMap->put(1, 1); // The map is now [[1,1]]
    myHashMap->put(2, 2); // The map is now [[1,1], [2,2]]
    myHashMap->get(1);    // return 1, The map is now [[1,1], [2,2]]
    myHashMap->get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
    myHashMap->put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
    myHashMap->get(2);    // return 1, The map is now [[1,1], [2,1]]
    myHashMap->remove(2); // remove the mapping for 2, The map is now [[1,1]]
    myHashMap->get(2);    // return -1 (i.e., not found), The map is now [[1,1]]

    myHashMap->show();
    return 0;
}
