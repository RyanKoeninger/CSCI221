#ifndef HW3_H
#define HW3_H
#include <stdint.h>

float power2_floor(float);

float pow(int,int);

float set_exp(float,int);

typedef struct sfloat16{
    int8_t exp;
    uint16_t sig;
    } sfloot16;
float sig_dig(float);

void print_fixed_pt(uint16_t);

float set_exp(float, int);



uint16_t ith_bit(int16_t, int);

int32_t replace_bit(int32_t, int32_t, int32_t);

sfloot16 add_sfloat(sfloot16, sfloot16);



void print_sfloat_dec(sfloot16);


#endif