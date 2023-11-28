#ifndef HW6_H
#define HW6_H
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// similar to sCPU from hw5, but with integer pc and another array of 32 32-bit integers prog

typedef struct iCPU{
    int32_t ram[1024];
    int32_t reg[32];
    int pc;
    uint32_t prog[32];
}CPU;

CPU* iCPU_init();

void iCPU_destroy(CPU*);

void iCPU_step(uint8_t, uint8_t, uint8_t, uint8_t, CPU*);

void read_instruction(uint32_t, CPU*);

void write_instruction(uint8_t, uint8_t, uint8_t, uint8_t, int, CPU*);

void clock_cycle(CPU*);

void run_program(CPU*);

#endif