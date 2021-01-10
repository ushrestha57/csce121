#include "LinkedList.h"
#include <iostream>
using std:: cout, std:: endl;
LinkedList::LinkedList(): headNode(nullptr), tailNode(nullptr), previousNode(nullptr), markerNode(nullptr), _size(0){}
LinkedList::~LinkedList(){
    clear();
}
LinkedList::LinkedList(const LinkedList& other){
    Node* traverser = other.headNode;
    _size = 0;
    previousNode = nullptr;
    tailNode = nullptr;
    headNode = nullptr;
    markerNode = nullptr;
    while(traverser != nullptr)
    {
        push_back(traverser->data);
        traverser = traverser->next;
    }
    delete traverser;
}
LinkedList& LinkedList::operator=(const LinkedList& other)
{
    if(this != &other)
    {
        clear();
        Node* traverser = other.headNode;
        while(traverser != nullptr){
            push_back(traverser->data);
            traverser = traverser->next;
        }
        delete traverser;
    }
    return *this;
}
void LinkedList::clear(){
    markerNode = headNode;
    while(markerNode->next != nullptr)
    {
        previousNode = markerNode;
        markerNode = markerNode->next;
        delete previousNode;
    }
    delete markerNode;
    _size = 0;
    headNode = nullptr;
    tailNode = nullptr;
    markerNode = nullptr;
    previousNode = nullptr;
}
void LinkedList::push_back(int value)
{
    Node* node = new Node;
    node->next = nullptr;
    node->data = value;
    if(_size == 0)
    {
        headNode = node;
        tailNode = node;

    }
    else
    {
        tailNode->next = node;
        tailNode = node;
    }
    _size++;
}
void LinkedList::print()
{
    markerNode = headNode;
    while(markerNode != nullptr)
    {
        cout << markerNode->data << " ";
        markerNode = markerNode->next;
    }
    cout << "\n";
}
size_t LinkedList::size() const{
    return _size;
}
const Node* LinkedList::head() const{
    return headNode;
}
void LinkedList::remove_duplicates() { //todo

}
bool LinkedList::contains(int value) const{
    Node* traverser = headNode;
    while(traverser != nullptr)
    {
        if(value == traverser->data)
        {
            return true;
        }
        traverser = traverser->next;
    }
    return false;
}
size_t LinkedList::find_last_of(int value) const{
    size_t maxIndex = 0;
    bool found = false;
    Node* traverser = headNode;
    size_t counter = 0;
    while(traverser != nullptr)
    {
        if(traverser->data == value)
        {
            found = true;
            maxIndex = counter;
        }
        counter++;
        traverser = traverser->next;
    }
    if(found)
    {
        return maxIndex;
    }
    else
    {
        return static_cast<size_t>(-1);
    }
}