#include <stdio.h>
#include "python_lib.h"

// computes exponentiation w/ a non-negative exponent
// via repeated (integer) multiplication.
int power(int base, int exp) {
    int res = 1;
    for (int i=0; i<=exp; i++) {
        res *= base;
    }
    return res;
}

// computes absolute value of an input by checking 
// if the input is positive or negative
int abs(int num) {
    if (num < 0) {
        return (- num);
    }
    return (num);
}  


// helper function that creates an array counting up by three
// for each slot in the array, starting at 0
int my_array(int num){
    int my_array[num];
    for (int i=0; i < num; i++){
        my_array[i] = i * 3;
    }
    int result = max(5, my_array);
    printf("result: %d\n", result);
    
    return 0;
}


// Loops through an array and returns the highest 
// number
int max(int size, int * array) {
    int x = array[0];
    for (int i = 1; i < size; i++){
        printf("Number : %d\n", i);
        if (x < array[i]){
            x = array[i];
        } 
    }
    return x;
    
}

// loops through an array and returns the lowest number
int min(int size, int * array) {
    int x = array[0];
    for (int i = 1; i < size; i++){
        printf("Number : %d\n", i);
        if (x > array[i]){
            x = array[i];
        } 
    }
    return x;
}

