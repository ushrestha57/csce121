#ifndef TAXI_TRIPS_H
#define TAXI_TRIPS_H
#include <string>
using std::string;

/*
returns true if type is one of the type values in array valid_types
input:  type - string with payment type that we are checking for validity
        valid_types - array of strings listing the valid types
        size - the number of elements in array valid_types
output: returns true if string type appears in array valid_types and
        false otherwise
        if there are no numbers in the array or size is negative,
        throws std::invalid_argument
*/
bool is_payment_valid(string type, string valid_types[],unsigned int size);

/*
returns the max number in an array
input: values  - an array of double non-negative numbers
       size - the number of elements in the array
output: the largest number that appears in the array.
        if there are no numbers in the array or size is negative,
        throws std::invalid_argument
*/
double max(double values[], unsigned int size);

/*
returns the min number in an array
input: values  - an array of double non-negative numbers
       size - the number of elements in the array
output: the smallest number that appears in the array.
        if there are no numbers in the array or size is negative,
        throws std::invalid_argument
*/
double min(double values[], unsigned int size);

/*
returns the average of the numbers in an array
input: values  - an array of double non-negative numbers
       size - the number of elements in the array
output: the average of the numbers in the array.
        if there are no numbers in the array or size is negative,
        throws std::invalid_argument 
*/
double average(double values[], unsigned int size);

/*
returns how many times a number occurs in the array
if size is 0 or negative, throws std::invalid_argument
input: v - a double that you are finding the duplicates for
       values  - an array of double non-negative numbers
       size - the number of elements in the array
output: number of occurances of a number in an array 
*/

int count_occurrences(double v, double values[], unsigned int size);

/*
returns the mode of the numbers in the array. If there are
multiple values for mode (i.e., multiple occur most frequently),
the function returns the first of them.

input: values  - an array of double non-negative numbers
       size - the number of elements in the array
output: the mode of the numbers in the array
        if there are no numbers in the array or size is negative,
        throws std::invalid_argument 
*/

double mode(double values[], unsigned int size);

/*
returns the length of the longest sequence of zeroes in the array
input: values  - an array of double non-negative numbers
       size - the number of elements in the array
output: the length of the longest zero sequence in the array
        if there are no numbers in the array or size is negative,
        throws std::invalid_argument 
*/
int length_longest_seq_zeros(double values[], unsigned int size);


bool valid_trip_miles(const double miles);
bool valid_trip_seconds(const unsigned int seconds);
bool valid_revenue(const double fare, const double tip);
bool valid_logic(const unsigned int seconds, const double miles, const double fare);
#endif  // TAXI_TRIPS_H
