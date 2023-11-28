#include <stdio.h>
#include <stdint.h>
#include "hw3.h"

// union to alter floats using bitwise operators
union float_bits {
    float f;
    uint32_t bits;
};

// turns the significand to 0 using a mask in order to return just the 
// value of the exponent
float power2_floor(float x){
    union float_bits floot;
    floot.f = x;
    
    uint32_t mask = 0b01111111100000000000000000000000;
    floot.bits = mask & floot.bits;
    
    return floot.f;
}

// turns the exponent to 0 using a mask in order to return just the value of 
// the significand
float sig_dig(float x){
    union float_bits floot;
    floot.f = x;
    
    uint32_t mask = 0b11111111100000000000000000000000;
    mask = ~mask;
    floot.bits = mask & floot.bits;
    
    return floot.f;
}

// prints a fixed point integer from a 16 bit integer with the 
// first 8 bits being the whole number part and the last 8 bits
// being the fractional part
void print_fixed_pt(uint16_t x){
    uint16_t mask = 0b0000000011111111;
    uint16_t frac = x & mask;
    
    
    uint16_t integ = x >> 8;
    float ans = 0.0f;
    ans += integ;

    int counter = 1;
    for (int i = 7; i >= 0; i--){
        ans += ith_bit(x, i) * (1.0f/(pow(2, counter)));
        counter ++;
    }

    printf("%f", ans);
}

// zeroes the exponent, then uses a mask with the new exponent left shifted
// into the position of the exponent to change the exponent of a float
float set_exp(float x, int new_exp){
    union float_bits floot;
    floot.f = x;
    
    uint32_t mask = 0b01111111100000000000000000000000;
    mask = ~mask; //i wrote my mask wrong and am too lazy to fix it
    floot.bits = floot.bits & mask;
    
    // need to account for the biased representation
    uint32_t newer_exp = new_exp + 127;
    // shifting it into the position of the exponent
    newer_exp <<= 23;

    floot.bits = floot.bits | newer_exp;

    return floot.f;
    
}

// power function from earlier in the semester, altered to be able to take
// values below 1
float pow (int base, int power) {
    if(power == 0){
        return 1.0f;
    }
    
    if(power < 0){
        int res = base;
        for (int i = 1; i < -power; i++){
            res = res * base;
        }

        float result = 1.0f/res;
        return result;
    }

    int res = base;
    for (int i = 1; i < power; i++){
        res = res * base;
    } 
    
    return res;
}

// ith_bit function from earlier in the semester
uint16_t ith_bit(int16_t x, int i){
    x = x >> i;
    int16_t mask = 0b1;
    int16_t ans = x & mask;
    if (ans > 0){
        return (1);
    }
    return (0);

}


// creates a float out of the values in an sfloat16, then prints them out
void print_sfloat_dec(sfloot16 x){
    // set to 1 initially to account for the implicit 1
    float ans = 1;
    // 2 ^ <exponent value>
    float power = pow(2, x.exp);
    
    // loops through all of the values of the significand, adding them to the
    // answer in proper fractional form 1 / 2 ^ <bit position>
    for (int i = 0; i < 16; i++){
        float fr = ith_bit(x.sig, i) * (1.0f/pow(2,(16-i)));
        ans += fr;
    }

    // finally, multiply the significand by the exponent
    ans *= power;
    
    printf("%f", ans);
}

// replace_bit function from earlier in the semester
int32_t replace_bit (int32_t x, int32_t i, int32_t b) {
    int32_t mask = 0b000000000000001 << i;
    int32_t num;
    if (b == 0) {
        int32_t nmask = ~mask;
        num = x & nmask;
    } else {
        num = x | mask;
    }
    
    return num;
}



sfloot16 add_sfloat(sfloot16 x, sfloot16 y){
    
    // creates 32 bit integers for the significands of x and y
    uint32_t ysig = y.sig;
    ysig = replace_bit(ysig,16,1);

    uint32_t xsig = x.sig;
    xsig = replace_bit(xsig,16,1);



    // since x is always greater than y, leftshifts the y significand and
    // increases the y exponent by 1 until the exponents are equal
    if (x.exp != y.exp){
        while (x.exp != y.exp){
        y.exp ++;
        ysig = ysig >> 1;
    }
    }

    // adds the two significands
    uint32_t sum = xsig + ysig;
    sfloot16 summ;
    
    // while the value of the added significands is above the max value 
    // of a 16 bit integer, right shift it
    // keep track of how many times the rightshift needed to happen
    int count = 0;
    while (sum > 131071){
        sum = sum >> 1;
        count ++;
    }
    
    sum = replace_bit(sum, 16, 0);
    
    // add x's exp and the count to get the final exponent
    summ.exp = x.exp + count;
    summ.sig = sum;
    
    return summ;
}