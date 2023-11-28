#include <stdio.h>
#include <stdlib.h>
#include "hw1.h"

int main(int argc, char *argv[]) {
    int x = atoi(argv[1]);
    printf("Your number is %d\n", fib(x));
}