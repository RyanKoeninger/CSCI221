#include <stdio.h>

int pow(int base, int power){
    
    for (int i = 0; i < power; i++){
        base *= base;
    }
    return base;
}

int main(){
    int num = pow(2,3);

    printf("%d", num);

    return 0;
}