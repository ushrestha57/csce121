// main.cpp
#include <iostream>
#include <limits>
#include "my_string.h"
#include "my_sstream.h"
#include "./string_calculator.h"

using std::cout, std::endl, std::cin, std::istream;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    my_string lhs;
    while(cin>>lhs)
    {
        char operato;
        my_string rhs;
        if(lhs == "q" || lhs == "quit")
        {
            cout << ">> " << endl << "farvel!" << endl << endl;
            return 0;
        }
        else
        {
            cin >> operato;
            cin.ignore();
            cin >> rhs;
            cout  << ">> " << '\n';
            if(operato == '+')
            {
                cout << "ans =" << endl << endl  << "    "  << add(lhs,rhs) << endl << endl;
            }
            else if(operato == '-')
            {
                cout << "ans =" << endl << endl << "    " <<  subtract(lhs,rhs) << endl << endl;
            }
            else if(operato == '*')
            {
                cout << "ans =" << endl << endl <<  "    "  << multiply(lhs,rhs) <<  endl<<endl;
            }
            
        }
    }
    
    
    // TODO(student): put your existing implementation of main here
}
