// q2_rule_of_three.cpp

/*
Part 1
======
Describe, in your own words, what is the difference between deep copy and shallow copy. 

Reponse
-------
A shallow copy is a copy that refers to the same object in memory as the original. For example, if you had an int with the value of 2
and made a shallow copy with it, the shallow copy would refer to the same 2. So, if you changed the value of the original from 2 to 9,
the shallow copys value will also be a 9 because it's referring to the same object in memory. However, with a deep copy, it creates a whole new
object that just has the same data as the original copy. So, with a deep copy, the value wouldn't change, it'd still remain a 2 while the original
changes into a 9. 

Part 2
======
List the three methods that make up the Rule of Three.  For each method, specify whether the method handles memory leaks, shallow vs. deep copy, both, or neither.

Reponse
-------
The destructor is one of the methods that make up the rule of three. This method is supposed to handle memory leaks when working with
dynamically allocated memory. A great use of the destructor would be in a LinkedList. Since all the nodes are dynamically allocated,
the destructor traverses through the LinkedList and manually deallocates all those Nodes. That prevents memory leaks from occuring in your
program. The great thing about the destructor is that it automatically occurs whenever the scope of the function ends so it handles
both shallow and deep copies equally. It doesn't return anything.

The copy constructor is one of the methods that make up the rule of three. This method creates a deep copy of an object of the same class.
This method is not designed to handle memory leaks, it's just designed to copy over the data from the parameter into a newly instantiated class.
It doesn't return anything. 

The copy assignment operator is used to create a copy of the object. Usually when dealing with memory that isn't dynamically
allocated, the default copy assignment operator is fine. However, when dealing with dynamically allocated memory, we need to overload it
or else it'll create shallow copies. For example, a dynamically allocated array in the copy would point to the same array in the original 
and we usually don't want that. This method does handle memory leaks as it allocates a new instance of the dynamically allocated variable and then
it copies over the data from the original copy. Then, it deletes the old dynamically allocated variable and sets that equal to the new instance.
Without it deleting the old data, that block of memory would cause a memory leak as we cannot access it anymore. 
*/

#include <iostream>
#include "exam_helpers.h"

using std::cout, std::endl;

struct Pixel {
    unsigned int r = 0, g = 0, b = 0;
};

class SmartPointerPixel {
    Pixel* data;

 public:
    SmartPointerPixel(Pixel p) : data(new Pixel(p)) {}

    // value access by dereference
    const Pixel& operator*() const { return *data; }
    Pixel& operator*() { return *data; }

    // value assignment
    SmartPointerPixel& operator=(const Pixel& p) { 
        *data = p;
        return *this;
    }
    ~SmartPointerPixel() //the destructor
    {
        delete data; 
    }
    SmartPointerPixel(const SmartPointerPixel& original) //copy consturctor
    {
        data = new Pixel; //create new dynamically allocated pixel and assign the values of it with original's values
        data->r = original.data->r;
        data->g = original.data->g;
        data->b = original.data->b;
    } 
    SmartPointerPixel& operator=(const SmartPointerPixel& original){ //copy assignment constructor
        if(this != &original) //make sure we aren't being redundant
        {
            delete data; //delete it to ensure we don't have any memory leaks.
            data = new Pixel;
            data->r = original.data->r;
            data->g = original.data->g;
            data->b = original.data->b;
        }
        return *this;
    }

    // TODO(student): declare and define the rule of three methods
};

std::ostream& operator<<(std::ostream& os, const Pixel& p) {
    return (os << "{" << p.r << ", " << p.g << ", " << p.b << "}");
}

std::ostream& operator<<(std::ostream& os, const SmartPointerPixel& sp) { 
    return (os << *sp);
}

int main() {
    Pixel maroon = {80, 0, 0};
    INFO(maroon);
    Pixel white = {255, 255, 255};
    INFO(white);
    SmartPointerPixel sp_maroon(maroon);
    INFO(sp_maroon);
    SmartPointerPixel sp_white(white);
    INFO(sp_white);
    *sp_maroon = white;
    INFO(sp_maroon);
    sp_maroon = maroon;
    INFO(sp_maroon);   
    {
        SmartPointerPixel sp = sp_white;
        INFO(sp);
    }
    INFO(sp_white);
    {
        SmartPointerPixel sp = sp_white;
        INFO(sp);
        sp = sp;
        INFO(sp);
        sp = sp_maroon;
        INFO(sp);
        sp = {0xcc, 0x55, 0x00};
        INFO(sp);
        INFO(sp_maroon);
    }
    INFO(sp_maroon);
}
