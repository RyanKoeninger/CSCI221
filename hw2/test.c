#include <stdio.h>
#include "hw2.h"


int main() {
    printf("HOMEWORK TWO\n\n");

    printf("tests for mod32:\n");
    printf("test 1: mod32(35): %d, expected: 3\n", mod32(35));
    printf("test 2: mod32(64): %d, expected: 0\n\n", mod32(64));

    printf("tests for mod16:\n");
    printf("test1: mod16(64): %d, expected: 0\n", mod16(64));
    printf("test2: mod16(25): %d, expected: 9\n\n", mod16(25));

    printf("tests for swap_bits:\n");
    printf("test 1: swap_bits(5,0,1): %d, expected: 6\n", swap_bits(5,0,1));
    printf("test 2: swap_bits(7,1,2): %d, expected: 7\n\n", swap_bits(7,1,2));

    printf("tests for reverse:\n");
    printf("test 1: reverse(12,1,2): %d, expected: 10\n", reverse(12,1,2));
    printf("test 2: reverse(1,0,15): %d, expected: 32768\n\n", reverse(1,0,15));

    printf("tests for is_bin_pal\n");
    printf("test 1: is_bin_pal(5): %d, expected: 1\n", is_bin_pal(5));
    printf("test 2: is_bin_pal(15): %d, expected: 1\n", is_bin_pal(15));
    printf("test 3: is_bin_pal(40): %d, expected: 1\n", is_bin_pal(40));
    printf("test 4: is_bin_pal(19): %d, expected: 0\n", is_bin_pal(19));
    





    
    
    
    
    return 0;
}
