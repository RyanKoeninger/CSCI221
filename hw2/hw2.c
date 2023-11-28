#include <stdio.h>
#include <stdint.h>
#include "hw2.h"


// uses a mask to change all binary numbers in the 5th position and 
// higher to 0, since they are all divisible by 16. The remaining
// representation is x % 16
uint32_t mod32(uint32_t x){
    uint32_t mask = 0b11111;
    x = x & mask;
    return x;
}

// similar to mod32, but masks numbers in the 4th position and higher
uint32_t mod16(uint32_t x){
    u_int32_t mask = 0b1111;
    x = x & mask;
    return x;
}

// converts x to either 0 or 1, 1 if x is true, and 0 if x is false. 
// the tru variable is multiplied by y, and fals is multiplied by z. 
// since one will always end up being zero, the answer will depend on wether 
// x is true or false
int cond(int x, int y, int z){
    int tru = x != 0;
    int fals = x == 0;
    int ans = (tru * y) + (fals * z);
    return ans;

}

// the ith_bit function from hw1
uint16_t ith_bit(int16_t x, int i){
    x = x >> i;
    int16_t mask = 0b1;
    int16_t ans = x & mask;
    if (ans > 0){
        return (1);
    }
    return (0);

}



// uses ith_bit to find the value of the bit in positions i and j. 
// If they are the same, nothing needs to be done. Otherwise, uses a mask 
// and logical operations to change each bit to the value of its opposite. 
// left shifting the mask is done before each alteration to x, and the mask
// is then right shifted back to its original state.
uint16_t swap_bits(uint16_t x, uint16_t i, uint16_t j){
    uint16_t ibit = ith_bit(x, i);
    uint16_t jbit = ith_bit(x, j);

    uint16_t mask = 0b1;

    if (ibit == jbit){
        return x;
    }

    mask = mask << i;
    if (jbit){
        x = x | mask;
    }
    else {
        mask = ~mask;
        x = x & mask;
        mask = ~mask;
    }
    mask = mask >> i;

    mask = mask << j;
    if (ibit){
        x = x | mask;
    }
    else{
        mask = ~mask;
        x = x & mask;
        mask = ~mask;
    }
    return x;
}

// Begins by making sure i is smaller than j. Then, while i is still smaller
// than j, iterates i up 1 and j down 1 until i is no longer smaller than j, 
// i.e, all numbers in between the original i and j have been swapped. At each
// iteration, swap_bits is used to switch the ith and jth bit. 
u_int16_t reverse(u_int16_t x, u_int16_t i, u_int16_t j){
    if (i > j){
        int x = i;
        i = j;
        j = x;
    }
    while (i < j){
        x = swap_bits(x, i, j);
        i++;
        j--;
    }
    
    return x;
}

// Starts at position 15 for 'left' and 0 for 'right', and 
// increases/decreases them until the bit is no longer 0
// in order to ignore trailing 0s. Then, a new number 'rev'
// is created after reverse(x, left, right) is run. If the
// two numbers are equal, return 1, otherwise return 0
u_int16_t is_bin_pal(u_int16_t x){
    int left = 15;
    int right = 0;
    while (ith_bit(x, left) == 0){
        left --;
    }
    while (ith_bit(x, right) == 0){
        right ++;
    }
    u_int16_t rev = reverse(x, left, right);
    if (rev == x){
        return 1;
    }
    return 0;   
    

}


