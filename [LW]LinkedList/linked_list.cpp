#include "linked_list.h"
#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

void MyList::add(string name, int score) {
    MyNode* newNode = new MyNode(name,score);
    if(_size == 0)
    {
        _headPtr = newNode;
        _tailPtr = newNode;
        _size++;
    }
    else
    {
        _tailPtr->setNext(newNode);
        _tailPtr = newNode;
        _size++;

    }
    
    // TODO
}

void MyList::clear() {
    MyNode* currentNode = _headPtr;
    MyNode* deleter; 
    while(currentNode != nullptr)
    {
        deleter = currentNode->next();
        delete currentNode;
        currentNode = deleter;
    }
    _headPtr = nullptr;
    _tailPtr = nullptr;
    _prevPtr = nullptr;
    _size = 0;
    // TODO
}

bool MyList::remove(string name) {
    if(_size == 0)
    {
        return false;
    }
    MyNode* currentNode = _headPtr;
    MyNode* nextNode = currentNode->next();
    if(currentNode->name() == name)
    {
        _size--;
        delete currentNode;
        _headPtr = nextNode;
        return true;
    }
    while(nextNode != nullptr)
    {
        if(nextNode->name() == name)
        {
            currentNode->setNext(nextNode->next());
            delete nextNode;
            _size--;
            return true;
        }
        currentNode = nextNode;
        nextNode = nextNode->next();
    }
    return false;
}

bool MyList::insert(string name, int score, size_t index) {

    return false;
}

MyList::MyList() {
    _size = 0;
    _headPtr = nullptr;
    _tailPtr = nullptr;
    _prevPtr = nullptr;
    _marker = nullptr;
}

MyList::~MyList() {
    clear();
}

size_t MyList::size() {
    return _size;
}

bool MyList::empty() {
    return _headPtr == nullptr;
}

MyNode* MyList::head() {
    return _headPtr;
}

void MyList::printList() {
    _marker = _headPtr;
    if (_marker == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }

    while (_marker != nullptr) {
        cout << "[ " << _marker->name() << ", " << _marker->score() << " ]" << endl;
        _marker = _marker->next();
    }
}

MyNode::MyNode(std::string name, int score) {
    _name = name;
    _score = score;
    _nextPtr = nullptr;
}

std::string MyNode::name()  {
    return _name;
}

int MyNode::score() {
    return _score;
}

void MyNode::setNext(MyNode* other) {
    _nextPtr = other;
}

MyNode* MyNode::next() {
    return _nextPtr;
}