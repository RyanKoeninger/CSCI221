#include <iostream>
using namespace std;

// reference semantics
void add_two(int & x) {
    x += 2;
}

// putting & in the argument line means that variable is passed by reference
// it will not be copied when the function is called
// and modifications to that variable will persist outside the function scope
void swap(int & x, int & y) {
    int temp = x;
    x = y;
    y = temp;
}


int main() {

    int* ptr = new int; // heap allocate a single integer
    delete ptr; // deallocate integer

    int* arr = new int[30]; // heap allocate an array of 30 ints
    delete [] arr; // deallocate the array

    int x = 3;
    add_two(x);
    cout << x << endl;

    int a = 5;
    int b = 17;
    swap(a, b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}