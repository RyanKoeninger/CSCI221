// compile this file using:
// g++ hello_world.cpp -o hello

#include <iostream> // contains cout, the C++ version of printf

using namespace std; 
// makes it so that we don't have to write std:: before things imported
// from standard libraries. Without this line we would have to say
// std::cout and std::endl instead of just cout and endl below.

int main() {
    cout << "hello world!\n";
    cout << "hi world!" << endl;
    // for all intents and purposes in this class, 
    // endl is basically the same as \n

    return 0;
}