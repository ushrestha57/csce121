// q1_remove.cpp
#include <iostream>
#include "exam_helpers.h"

using std::cout, std::endl;

void print_array(std::ostream& os, const int* A, size_t size) {
    if (size) {
        os << A[0];
        for (size_t index = 1; index < size; index++) {
            os << ", " << A[index];
        }
    } else {
        os << "<empty>";
    }
    os << std::endl;
}

// TODO(student): declare and define the remove() function
int Remove(int* list, size_t &size) //pass by reference
{
    int* evens = new int[size];
    size_t evensIndex = 0;
    size_t initialSize = size;
    for(size_t i = 0; i < size; ++i)
    {
        if(list[i] % 2 != 0)
        {
            evens[evensIndex] = list[i];
            evensIndex++;
        }
    }
    for(size_t i = 0; i < evensIndex; ++i)
    {
        list[i] = evens[i];
    }
    size = evensIndex;
    delete[] evens;
    return initialSize-evensIndex;

}

int main() {
    int A[9] = {0,0,0,0,0,0,0,0,0};
    size_t size_A = 9; 
    print_array(cout, A, size_A);
    size_t return_value = Remove(A, size_A);
    INFO(return_value);     
    INFO(size_A);
    print_array(cout, A, size_A);
    
    return 0;
}
