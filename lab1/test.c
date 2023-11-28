#include <stdio.h>
#include "python_lib.h"

int main() {
    // TESTS FOR power()
    printf("Tests for power():\n");
    
    // test 1: 2^4
    // expected output: 16
    printf("test 1 -- power(2,4): %d\t expected: 16\n", power(2,4));
    
    // test 2: 3^3 
    // expected output: 27
    printf("test 2 -- power(3,3): %d\t expected: 27\n", power(3,3));
    
    // test 3: 0^15
    // expected output: 0
    printf("test 3 -- power(0,15): %d\t expected: 0\n", power(0,15));
    
    // test 4: 152^0
    // expected output: 1
    printf("test 4 -- power(152,0): %d\t expected: 1\n", power(152,0));
    
    // TESTS FOR abs()
    printf("Test for abs(): \n");

    //test 1: 5
    // expected output: 5
    printf("test 1 -- abs(5): %d\t expected: 5\n", abs(5));

    // test 2: 0
    // expected output: 0
    printf("test 2 -- abs(0): %d\t expected: 0\n", abs(0));

    // test 3: -1
    // expected output: 1
    printf("test 3 -- abs(-1): %d\t expected: 1\n", abs(-1));

    // test 4: -2380
    // expected output: 2380
    printf("test 4 -- abs(-2380): %d\t expected: 2380\n", abs(5));

    int another_array[5] = {0, 3, 6, 9, 12};

    // printf(another_array);



    // TESTS FOR max()
    // printf("Test for max:\n");

    // printf("test 1 -- max: %d\t expected: 5\n", abs(5));

    return 0;
}