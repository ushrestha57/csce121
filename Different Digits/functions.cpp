#include "functions.h"
bool is_valid_range(int a, int b) {
    // validate input range
    return (a > 0 && a <= b && b<= 10000);
}

int count_digit_occurrences(int number, int digit) {
    int counter = 0; //counts how many times digit occurs
    if(number == digit)
    {
        return 1;
    }
    if(number < 0)
    {
        number *= -1;
    }

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
//this is a pretty tricky function to understand
//basically I end up peeling the peeled variable
//Ex: 434, I'd start with 4 by peeling it resulting in 43 so I don't create a false positive.
//Then I'd peel 3, check then peel the 4, check. Boom! We have a match! Since we have ONE match, we just return which breaks the loop
bool has_repeated_digits(int number) {
    while(number > 0)
    {
        int peeled = number % 10; //gets the last digit
        for(int i = number; i > 0; i/= 10)
        {
            if(count_digit_occurrences(number,peeled) > 1)
            {
                return true;
            }
        }
        number /= 10; //sets up peeling the digit from the next place
    }
    return false;
}
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