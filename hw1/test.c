#include <stdio.h>
#include "hw1.h"

int main(){
    printf("haha wooo test i am going to punch a wall\n");

    printf("\nTests for bob and alice: \n");
    printf("test 1: choose_mover(15) -- %c expected return: A\n", choose_mover(15));
    printf("test 2: choose_mover(29) -- %c expected return: B\n", choose_mover(29));

    printf("\nTests for fib: \n");
    printf("test 1: fib(18) -- %d expected return: 2584\n", fib(18));
    printf("test 2: fib(3) -- %d expected value: 1\n", fib(3));

    int_three x;
    x.one = 1;
    x.two = 1;
    x.four = 1;

    int_three y;
    y.one = 0;
    y.two = 0;
    y.four = 1;

    int_three z;
    z.one = 1;
    z.two = 0;
    z.four = 1;

    printf("\nTests for print_three_unsigned:\n");
    printf("test 1: print_three_unsigned 111, expected value: 7 ");
    print_three_unsigned(x);
    printf("test 2 int_three_unsigned 101, expected value 5 ");
    print_three_unsigned(z);
    printf("\n");

    printf("Tests for print_three_signed:\n");
    printf("Test 1: print_three_signed 100, expected value: -4 ");
    print_three_signed(y);
    printf("Test 2: print_three_signed 101, expected value -3 ");
    print_three_signed(z);

    printf("\n");
    printf("Tests for tiny_add [not working, sorry]\n");
    printf("Test 1: 111 + 001, expected value: 000 ");
    tiny_add(x,y);
    printf("\n");
}


