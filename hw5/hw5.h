#ifndef HW5_H
#define HW5_H
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void* maximum (void*, int, int);

int CmpInt(void*, void*);

int CmpFloat(void*, void*);

void* maximum_v2(void*, int, int, int (*cmpfn) (void*, void*));

// sCPU struct: contains ram and reg, with arrays of 32-bit integers of size 1024 and 32
// respectively. Named CPU because typing a lowercase s follwed by 3 capital letters 
// is annoying
typedef struct sCPU{
    int32_t ram[1024];
    int32_t reg[32];
}CPU;

CPU* CPU_init();

void CPU_destroy(CPU*);

void CPU_step(uint8_t, uint8_t, uint8_t, uint8_t, CPU*);
#endif