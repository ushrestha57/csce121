#include <iostream>
#include <stdexcept>
#include <string>

using std::cout; 
using std::cin;
using std::endl;
using std::string;
using std::stoi;

/*
task: convert strings to integers so they can be factored
if the string cannot be converted to a number, then print "not a number"
else if the number is outside the range of int, then print "too big"
else if the number is less than 1, print "not positive"
else, print the prime factorization of the number

Examples:
> apple
not a number
> 12345678901234567890
too big
> -6
not positive
> 90
2 * 3^2 * 5
> quit
bye!
*/

void print_prime_factorization(int);

int main() {
    string str;
    int num;
    
    cout << "enter numbers to factor or \"quit\" to end" << endl;
    
    cout << "> ";
    cin >> str;
    
    while (str != "quit") {
        // convert string to integer
        num = stoi(str);
        
        print_prime_factorization(num);
        
        cout << "> ";
        cin >> str;
    }
    cout << "bye!" << endl;
}

// NODO(student): don't touch me!
//   none of what you need to do right now happens down here
//   you can implement this yourself later (it's good practice!)
void print_prime_factorization(int n) {
    cout << "<prime factorization of "<<n<<">" << endl;
}