#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
struct Node {
    int data;
    Node* next;
// TODON'T(student): change the visibility, types, or names of the members

// TOMAYBE(student): the optional-rest of the Node
};

class LinkedList {
    Node* headNode;
    Node* tailNode;
    Node* previousNode;
    Node* markerNode;
    size_t _size;
// the type to use for sizes and indices is size_t.
// TODO(student): the rest of the LinkedList
    public:
        LinkedList(); //constructor
        ~LinkedList(); //desctructor
        LinkedList(const LinkedList& other);
        LinkedList& operator=(const LinkedList& other);
        void push_back(int value);
        size_t size() const;
        void remove(size_t index);
        void clear();
        const Node* head() const;
        void remove_duplicates();
        void print();
        bool contains(int value) const;
        size_t find_last_of(int value) const;


        


};

#endif  // LINKEDLIST_H