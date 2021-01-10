#include <iostream>
#include <stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

void printCompilerErrors();

int main() {
double getTriangleArea(double base, double height);
    
    double base;
    double height;
    double area;

    try {

        cout << "Please enter values for base: ";
        cin >> base;
        cout << "Please enter values for height: ";
        cin >> height;
        
        area = getTriangleArea(base, height);

        cout << "Area of triangle: " <<  area << endl;

    }
    catch (runtime_error& exception) {

        cout << "Cannot compute value. " << exception.what() << endl;
    }
    printCompilerErrors();

    return 0;
}   

// do not move this function above main() function
double getTriangleArea(double base, double height){

    if (base <= 0) {
        throw runtime_error("Base is non-positive.");
    }
    else if (height <= 0) {
        throw runtime_error("Height is non-positive.");
    }

    double area = base * height / 2.0;
 
    return area;
}

void printCompilerErrors() {
    cout << "error: iostreams: No such file or directory" << endl;
    cout << "error: stray '\' in program" << endl;
    cout << "error: expected ';' before 'cin'" << endl;
    cout << "error: no match for 'operator<<' (operand types are 'std::istream' {aka 'std::basic_istream<char>'} and 'double')" << endl;
    cout << "error: 'area' was not declared in this scope" << endl;
    cout << "error: 'getTriangleArea' was not declared in this scope" << endl;
    cout << "error: expected ';' before 'area'" << endl;
    cout << "error: expected primary-expression before 'catch'" << endl;
    cout << "error: 'runtime_error' does not name a type" << endl;
    cout << "error: expected unqualified-id before '{' token" << endl;


}
