#include <stdio.h>

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

int main() {
    int my_array[5];
    for (int i=0; i < 5; i++){
        my_array[i] = i * 3;
    }
    int result = max(5, my_array);
    printf("result: %d\n", result);
    
    return 0;
}