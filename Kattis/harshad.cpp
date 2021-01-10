// starter code for Harshad Numbers
// https://open.kattis.com/problems/harshadnumbers

#include <iostream>

using std::cin, std::cout, std::endl;
bool isHarshad(int num)
{
    int sum = 0;
}

int main() {
    unsigned n;
    for(int i = n+1; i < 1000000001; i++)
    {
        if(isHarshad(i))
        {
            n = i;
            i  = 1000000001;
        }
    }
    cin >> n;

    // TODO(student): Display the smallest Harshad number greater than or equal to n.
}

