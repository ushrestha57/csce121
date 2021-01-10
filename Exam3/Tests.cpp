#include <iostream>
#include "LinkedList.h"
int main() {
    // TODO(student): the rest of the Tests
    LinkedList list;
    for(size_t i = 1; i < 6; ++i)
    {
        list.push_back(i);
    }
    list.print();
    LinkedList listTwo(list);
    listTwo.print();
    LinkedList listThree = list;
    listThree.print();
    return 0;
}
