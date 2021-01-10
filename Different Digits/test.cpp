#include <iostream>
#include <limits>
#include "functions.h"

using std::cout;
using std::cin;
using std::endl;

int count_valid_numbers(int a, int b) {
    // return count of valid numbers in range
    int counter = 0;
    for(int i = a; i <= b; i++){
        if(has_repeated_digits(i)){
                counter++;
        }
    }
    return counter;
}
bool is_valid_range(int a, int b) {
    // validate input range
    return (a > 0 && a <= b && b<= 10000);
}

int count_digit_occurrences(int number, int digit) {
 int counter = 0; //counts how many times digit occurs
    while(number > 0)
    {
        int peeled = number % 10; //gets the last digit
        if(peeled == digit)
        {
            counter++;
        }
         number /= 10; //sets up peeling the digit from the next place
    }
    return counter;
}

bool has_repeated_digits(int number) {
    while(number > 0)
    {
        int peeled = number % 10; //gets the last digit
        for(int i = number; i > 0; i/= 10)
        {
            if(count_digit_occurrences(number,peeled) % 2 == 0)
            {
                return true;
            }
        }
        number /= 10; //sets up peeling the digit from the next place
    }
    return false;
}


int main()
{
    cout << count_valid_numbers(1,40);
    return 0;
}