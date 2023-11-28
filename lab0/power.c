#include <stdio.h>

int pow(int base, int power){
    
    int x = base;
    for (int i = 1; i < power; i++){
        base *= x;
    }
    return base;
}

int main(){
    int num = pow(2,3);

    printf("%d\n", num);

    return 0;
}