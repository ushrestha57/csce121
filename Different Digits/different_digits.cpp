#include <iostream>
#include <limits>
#include "functions.h"

using std::cout;
using std::cin;
using std::endl;

// call this function to reset cin to a good state
void reset_cin();

int main() {
    int a;
    int b;
    // print prompt for input
    bool cont = true;
    while(cont)
    {
        cout << "Enter numbers 0 < a <= b <= 10000: ";
        cin >> a >> b;
        if(is_valid_range(a,b))
        {
            cout << "There are " << count_valid_numbers(a,b) <<  " valid numbers between " << a << " and " << b << endl; //output
            cont = false;
        }
        else //keeps asking for input until they input a valid one
        {
            cout << "Invalid input" << endl;
        }
    }

    return 0;
}

void reset_cin() {
    // clear the stream state flags
    cin.clear();
    // clear the stream buffer up to the first newline character
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
