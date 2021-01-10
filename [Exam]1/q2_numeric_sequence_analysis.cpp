#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int input;
    int max;
    int min;
    int sum = 0;
    int terms = 0;
    //do while: if input isnt 0 we continue
    do{
        cin >> input;
        if(input % 2 == 0 && input > 0) //if number is even we compute
        {
            sum+= input;
            terms++;
            if(terms == 1)
            {
                max = input;
                min = input;
            }
            if(input > max)
            {
                max = input;
            }
            if(input < min)
            {
                min = input;
            }
        }

    }
    while(input != 0);
    if(terms > 0)
    {
        cout << "min " << min << " max " << max << " average " << sum/terms;
    }
    else
    {
        cout << "no values";
    }
    

}
