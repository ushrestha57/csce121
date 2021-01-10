// starter code for Piece of Cake!
// https://open.kattis.com/problems/pieceofcake2
 
#include <iostream>
 
using std::cin;
 using std::cout;
 using std::endl;
 
int main() {
    unsigned n, h, v;
    cin >> n >> h >> v;

    if(n - h > h)
    {
        h = n - h;
    }
    if(n - v > v)
    {
        v = n - v;
    }
    unsigned volume = v * h * 4;
    cout << volume << endl;
}