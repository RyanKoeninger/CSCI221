#ifndef HW1_H
#define HW1_H

char choose_mover(int);

int fib(int);

typedef struct int_threes{
    int one;
    int two;
    int four;
} int_three;

void print_three_unsigned(int_three);

void print_three_signed(int_three);

int_three tiny_add(int_three, int_three);

#endif 
