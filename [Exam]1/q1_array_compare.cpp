#include <iostream>
using namespace std;
bool array_compare(int A[], unsigned int size_A, int B[], unsigned int size_B) {

    if(size_A == 0) //solving for test case 3 because thatll automatically terminate the for loop and result in function returning false
    {
        return true;
    }
    for(unsigned int i = 0; i < size_A && i < size_B; i++) //compares till it reaches the end of each array
    {
        if(A[i] < B[i]) //if an Bi > Ai, we return true.
        {
            return true;
        }
    }
    if(size_A < size_B) // if everythings equal up to size_A
    {
      return true;
    }
    else
    {
      return false;
    }
}

int main()
{
    int A[] = {1,2,4,3};
    int B[] = {1,2,3,4};
    cout << array_compare(A,5,B,5);
}