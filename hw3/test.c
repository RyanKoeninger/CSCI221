#include <stdio.h>
#include <stdint.h>
#include "hw3.h"

int main(){
    printf("\nHOMEWORK 3\n\n");

    printf("Tests for power2_floor():\n");
    printf("Test 1: power2_floor(14): %f, expected: 8\n", power2_floor(14));
    printf("Test 2: power2_floor(257): %f, expected: 256\n\n", power2_floor(257));


    printf("Tests for set_exp:\n");
    printf("Test 1: set_exp(16, 5): %f, expected: 32\n", set_exp(16,5));
    printf("Test 2: set_exp(23, 17): %f, expected: 188416\n\n", set_exp(23,17));

    printf("Tests for print_fixed_pt:\n");
    printf("Test 1: print_fixed_pt(0000000110000000): ");
    print_fixed_pt(0b0000000110000000);
    printf(", expected: 1.5\n");
    printf("Test 2: print_fixed_pt(1110010100000001): ");
    print_fixed_pt(0b1110010100000001);
    printf(", expected: 229.003906\n\n");

    sfloot16 x;
    x.exp = 1;
    x.sig = 0;

    // sfloot16 y;
    // y.exp = 1;
    // y.sig = 0;

    sfloot16 y;
    y.exp = -1;
    y.sig = 0b1100000000000000;
    
    
    printf("Tests for print_sfloat_dec:\n");
    printf("Test 1: print_sfloat_dec(exp = 1, sig = 0): ");
    print_sfloat_dec(x);
    printf(", expected: 2\n");

    printf("Test 2: print_sfloat_dec(exp = -1, sig = 0xC000): ");
    print_sfloat_dec(y);
    printf(", expected: 0.875\n\n");

    printf("Tests for add_sfloat:\n");
    printf("Test 1: add_sfloat(2 + 0.875 <in sfloats>): ");
    sfloot16 add1 = add_sfloat(x,y);
    print_sfloat_dec(add1);
    printf(", expected: 2.875\n");

    printf("Test 2: add_sfloat(0.875 + 0.875 <in sfloats>): ");
    sfloot16 add2 = add_sfloat(y,y);
    print_sfloat_dec(add2);
    printf(", expected: 1.75\n\n");


    return 0;
}