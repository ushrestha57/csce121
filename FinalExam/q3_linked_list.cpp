// q3_linked_list.cpp

#include <iostream>
#include "exam_helpers.h"

using std::cout, std::endl;

struct Node {
    char data;
    Node* next;
    Node(char c) : data(c), next(nullptr) {}
};

class PalindromeLinkedList {
  size_t size;
  Node* head;
  Node* tail;
  
  public: 
    PalindromeLinkedList() : size(0), head(nullptr), tail(nullptr) {}
    bool empty() const { return size == 0; } 
    void push_both_ends(char);
    void remove_center();
    
    friend std::ostream& operator<<(std::ostream&, const PalindromeLinkedList&);
};

std::ostream& operator<<(std::ostream& os, const PalindromeLinkedList& list) {
    if (list.empty()) { return (os << "<empty>"); }
    const Node* curr = list.head;
    while (curr) {
        os << curr->data;
        curr = curr->next;
    }
    return os;
}

void PalindromeLinkedList::push_both_ends(char value) { //complete
    // TODO(student): implement push_both_ends()
    Node* frontNode = new Node(value);
    if(size == 0)
    {
        head = frontNode;
        tail = frontNode;
        size++;
    }
    else
    {
        Node* backNode = new Node(value);
        frontNode->next = head;
        head = frontNode;
        Node* traverser = head;
        while(traverser->next != nullptr)
        {
            traverser = traverser->next;
        }
        tail->next = backNode;
        backNode->next = nullptr;
        tail = backNode;
        size+=2;
    }
}

void PalindromeLinkedList::remove_center() {
    // TODO(student): implement remove_center()
    if(size == 0)
    {
        throw std::out_of_range("Out of range");
    }
    else if(size % 2 == 0) //if even
    {
        if(size == 2) //special case
        {
            delete head;
            delete tail;
            size = 0;
        }
        else
        {
            size_t startIndex = size / 2 - 2; //index we want to stop iterating at
            Node* traverser = head->next;
            Node* previous = head;
            for(size_t i = 0; i < startIndex; ++i)
            {
                previous = traverser;
                traverser = traverser->next;
            }
            traverser = traverser->next; //basically two remove() functions paired together
            delete previous->next;
            previous->next = traverser;
            traverser = traverser->next;
            delete previous->next;
            previous->next = traverser;
            size-=2;

        }

    }
    else
    {
        if(size == 1) //special case
        {
            delete head;
            size = 0;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            size_t startIndex = size / 2 - 1; //stop index, different than even because we're only deleting one
            Node* traverser = head->next;
            Node* previous = head;
            for(size_t i = 0; i < startIndex; ++i)
            {
                previous = traverser;
                traverser = traverser->next;
            }
            traverser = traverser->next; //simple remove function
            delete previous->next;
            previous->next = traverser;
            size--;
        }
    }
}

int main() {
    PalindromeLinkedList list;
    INFO(list);
    list.push_both_ends('o');
    INFO(list);
    list.push_both_ends('c');
    INFO(list);
    list.push_both_ends('a');
    INFO(list);
    list.push_both_ends('t');
    INFO(list);
    cout << "-----" << endl;
    INFO(list);
    list.remove_center();
    INFO(list);
    list.remove_center();
    INFO(list);
    list.remove_center();
    INFO(list);
    list.remove_center();
    INFO(list);
    
    return 0;
}
