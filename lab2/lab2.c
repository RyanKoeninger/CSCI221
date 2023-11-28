#include <stdio.h>
#include <stdint.h>

int ith_bit(int16_t x, int i){
    x = x >> i;
    int16_t mask = 0b1;
    int16_t ans = x & mask;
    if (ans > 0){
        return (1);
    }
    return (0);

}

void print_binary(int16_t x){
    int ans = 0;
    for (int i = 15; i >= 0; i--){
        if (ith_bit(x, i)){
            printf("1");
        }
        else(printf("0"));
    }
    printf("\n");
}

int set_one(int16_t x, int16_t i){
    int16_t mask = 0b1 << i;
    
    x = x|mask;
    
    return x;
}
int set_zero(int16_t x, int16_t i){
    int16_t mask = 0b1 << i;
    mask = ~mask;
    x = x & mask;

    return x; 
}

// int replace_bit(int16_t)

int main(){
    printf("sb 1, %d\n", ith_bit(7,0));
    printf("sb 0, %d\n", ith_bit(7,5));
    printf("\n");

    printf("sb 0...11,");
    print_binary(3);
    printf("\n");

    printf("sb 0...1010, ");
    print_binary(10);
    printf("\n");

    printf("sb 4, %d\n", set_one(0,2));
    printf("sb 4, %d\n", set_one(4,2));
    printf("\n");
// 1 1 3 1 221 2
// 1 1 217
    printf("sb 1, %d\n", set_zero(1,1));
    printf("sb 1, %d\n", set_zero(3, 1));
    printf("sb 217, %d\n", set_zero(221, 2));



}