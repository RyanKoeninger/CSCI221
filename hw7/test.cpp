#include <iostream>
using namespace std;
# include <vector>
# include <string>
# include <cmath>
#include "hw7.hpp"

int main(){
    cout << "\n\n\nHOMEWORK 7\n\n";

    cout << "tests for appendable arrays:\n\n";

    cout << "initialized a vec: length and capacity 4, with all values = 0\n\n";
    vec* v1 = vec_init();

    cout << "vec_print(vec): should be 4 0s\n";
    vec_print(v1);

    cout << "vec_dprint(vec):\n";
    vec_dprint(v1);

    cout << "vec_append(vec, 5): first vec_print() should be 4 0s and a 5, while vec_dprint()'s array should have another 3 trailing 0s\n\n";

    vec_append(v1, 5);
    vec_print(v1);
    vec_dprint(v1);

    cout << "vec_append(vec,1), (vec,2), (vec,3), (vec,4): should be length 9, and dprint's array should have 16 total values now\n\n";
    vec_append(v1, 1);
    vec_append(v1, 2); 
    vec_append(v1, 3);
    vec_append(v1, 4);

    vec_print(v1);
    vec_dprint(v1);

    cout << "vec_reallocate(vec): should have capacity 32 now\n\n";
    vec_reallocate(v1);
    vec_dprint(v1);

    cout << "Tests for piCalc: \n\n";

    

    // double g = piCalc(100000);


    cout << "piCalc(10): " << piCalc(10) << "\n";
    cout << "piCalc(100): " << piCalc(100) << "\n";
    cout << "piCalc(1000): " << piCalc(1000) << "\n";
    // cout << "piCalc(100000): " << g << "\n";

    return 0;
}