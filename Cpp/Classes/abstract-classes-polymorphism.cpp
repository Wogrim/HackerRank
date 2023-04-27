#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int value;
    int key;
    Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val){};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache
{

protected:
    map<int, Node *> mp;            // map the key to the node in the linked list
    int cp;                         // capacity
    Node *tail;                     // double linked list tail pointer
    Node *head;                     // double linked list head pointer
    virtual void set(int, int) = 0; // set function
    virtual int get(int) = 0;       // get function
};

//////////////////////////////////////////////////
// MY CODE START

class LRUCache : public Cache
{
private:
    //for debugging
    void printCache()
    {
        cout << "cache: ";
        Node *p = tail;
        while (p != nullptr)
        {
            cout << '(' << p->key << ',' << p->value << ')' << ' ';
            p = p->prev;
        }
        cout << endl;
        return;
    }
    //k
    void moveToHead(Node *p)
    {
        if (head == p)
            return;
        // else
        // fix other references to the node
        Node *prev = p->prev;
        Node *next = p->next;
        if (tail == p)
            tail = prev;
        else
            next->prev = prev;
        prev->next = next;
        // move to head
        p->next = head;
        head->prev = p;
        p->prev = nullptr;
        head = p;
    }

public:
    LRUCache(int capacity)
    {
        cp = capacity;
        tail = nullptr;
        head = nullptr;
    }
    virtual void set(int key, int value)
    {
        // printCache();//DEBUG
        // empty cache: set tail and head pointers to new node
        if (head == nullptr)
        {
            Node *p = new Node(nullptr, nullptr, key, value);
            head = tail = p;
            mp[key] = p;
            return;
        }

        // if node is in the cache, update value and move to head of linked list
        map<int, Node *>::iterator itr = mp.find(key);
        if (itr != mp.end())
        {
            Node *p = itr->second;
            p->value = value;
            moveToHead(p);
            return;
        }
        // else node was not in the cache, create at head
        Node *p = new Node(nullptr, head, key, value);
        head->prev = p;
        head = p;
        mp[key] = p;
        // if cache is full delete tail
        if (mp.size() > cp)
        {
            mp.erase(tail->key);
            Node *prev = tail->prev;
            prev->next = nullptr;
            delete tail;
            tail = prev;
        }
        return;
    }
    virtual int get(int key)
    {
        // printCache(); //DEBUG
        // if node is in the cache, move to head of linked list
        map<int, Node *>::iterator itr = mp.find(key);
        if (itr != mp.end())
        {
            Node *p = itr->second;
            moveToHead(p);
            return p->value;
        }
        // else not in cache
        return -1;
    }
};

// MY CODE STOP
//////////////////////////////////////////////////

int main()
{
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "get")
        {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set")
        {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
