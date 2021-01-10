#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

bool isPrime(int n)
{
    
    if( n == 1)
    {
        return false;
    }
    else if( n % 2 == 0)
    {
        return false;
    }
    else
    {
        int m = 3;
        while(m*m <=n)
        {
            if(n % m == 0)
            {
                return false;
            }
            m+=2;
        }
    }
    return true;
}
int main()
{
    int num;
    cin >> num;
    cout << isPrime(num);
}