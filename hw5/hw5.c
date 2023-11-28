#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "hw5.h"

// uses memcmp, which returns -1 if the second input is larger than the first, to 
// compare values in the array. max, initialized as a void*, is compared with all 
// subsequent values. if the new value is larger, it replaces max. 

void* maximum (void* arr, int size, int number){
    void* max = (char*)arr; 
    
    for (int i = 0; i < number; i++){
        void* address = (char*)arr + (i * size);
        if(memcmp(max, address, size) < 0){
            max = address;
        }
    }
    return max;
}

// casts both inputs as ints, then compares them and returns -1 if the second is larger,
// 0 if they are the same, and 1 if the first is larger.

int CmpInt(void* a_ptr, void* b_ptr){
    int* a = (int*)a_ptr;
    int* b = (int*)b_ptr;

    if (a < b) {
        return -1;
    }
    else if (a == b){
        return 0;
    }
    return 1;
    
}

// casts both inputs as floats, then compares them and returns -1 if the second is larger,
// 0 if they are the same, and 1 if the first is larger.

int CmpFloat(void* a_ptr, void* b_ptr){
    float* a = (float*)a_ptr;
    float* b = (float*)b_ptr;

    if (a < b) {
        return -1;
    }
    else if (a == b){
        return 0;
    }
    return 1;
    
}

// takes the same inputs as the original maximum() along with comparison function cmpfn. 
// uses CmpInt() or CmpFloat() to play the same role as memcmp in the original function
// to find the highest value of the input array in the same way. 

void* maximum_v2 (void* arr, int size, int number, int (*cmpfn) (void*, void*)){
    void* max = (char*)arr; 
    
    for (int i = 0; i < number; i++){
        void* address = (char*)arr + (i * size);
        if(cmpfn(max, address) < 0){
            max = address;
        }
    }
    return max;
}

// allocates the required amount of memory to store a CPU, then loops through the ram
// and reg to turn each value in the array to 0.

CPU* CPU_init(){
    CPU* cpu = (CPU*) malloc(sizeof(CPU)); 
    for(int i = 0; i < 32; i++){
        cpu -> reg[i] = 0;
    }

    for(int i = 0; i < 1024; i++){
        cpu -> ram[i] = 0;
    }

    return cpu;
}

// takes a CPU, then frees the memory used to store it

void CPU_destroy(CPU* cpu){
    free(cpu);
}

// contains all of the various operations a CPU can carry out

void CPU_step(uint8_t opcode, uint8_t arg1, uint8_t arg2, uint8_t arg3, CPU* cpu){
    
    // print: prints the value in the 0th register position
    if (opcode == 0){
        printf("%d\n", cpu -> reg[0]);
    }
    
    // put: uses the values in arg2 and arg3 to simulate the 16 least significant bits
    // of a 32 bit integer (other bits are 0) and stores it in the register position
    // indicated by arg1
    else if (opcode == 1){
        uint32_t num = arg2;
        num <<= 8;
        num = num | arg3;

        cpu -> reg[arg1] = num;
    }
    
    // add: takes the sum of arg2 and arg3 and places it in the register position indicated
    // by arg1
    else if (opcode == 2){
        cpu -> reg[arg1] = cpu -> reg[arg2] + cpu -> reg[arg3];
    }
    
    // mul: does the same thing as add, just multiplying arg2 and arg3 rather than adding them
    else if (opcode == 5){
        cpu -> reg[arg1] = cpu -> reg[arg2] * cpu -> reg[arg3];
    }

    // store: takes the value in reg indicated by arg and places it into a position in ram
    // indicated by arg2
    else if (opcode == 3){
        cpu -> ram[cpu -> reg[arg2]] = cpu -> reg[arg1];
    }
    
    // load: takes the value stored in ram indicated by arg2, and places it into a position in 
    // reg indicated by arg1
    else if (opcode == 4){
        cpu -> reg[arg1] = cpu -> ram[cpu -> reg[arg2]];
    }
}