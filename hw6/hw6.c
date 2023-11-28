#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hw6.h"

// initializes the iCPU in the same way as in hw5, but with another array of 32 32-bit integers prog 
// and an int for program counter. all values in all arrays are set to zero initially.
CPU* iCPU_init(){
    CPU* cpu = (CPU*) malloc(sizeof(CPU)); 
    for(int i = 0; i < 32; i++){
        cpu -> reg[i] = 0;
    }

    for(int i = 0; i < 1024; i++){
        cpu -> ram[i] = 0;
    }

    for(int i = 0; i < 32; i++){
        cpu -> prog[i] = 0;
    }

    cpu -> pc = 0;

    return cpu;
}

// same as sCPU_destroy, just takes a pointer to an iCPU instead
void iCPU_destroy(CPU* cpu){

    free(cpu);
}

// similar to sCPU_step, just adds 1 to the pc whenever it runs (except in the case of new 
// instructions jump, beq, and bne)
void iCPU_step(uint8_t opcode, uint8_t arg1, uint8_t arg2, uint8_t arg3, CPU* cpu){
    if (opcode == 0){
        printf("%d\n", cpu -> reg[0]);
    }
    else if (opcode == 1){
        uint32_t num = arg2;
        num <<= 8;
        num = num | arg3;

        cpu -> reg[arg1] = num;
    }
    else if (opcode == 2){
        cpu -> reg[arg1] = cpu -> reg[arg2] + cpu -> reg[arg3];
        // printf("%d", cpu -> reg[arg1]);
    }
    else if (opcode == 5){
        cpu -> reg[arg1] = cpu -> reg[arg2] * cpu -> reg[arg3];
    }
    else if (opcode == 3){
        cpu -> ram[cpu -> reg[arg2]] = cpu -> reg[arg1];
    }
    else if (opcode == 4){
        cpu -> reg[arg1] = cpu -> ram[cpu -> reg[arg2]];
    }
    
    // jump, beq, bne: changes the pc to the value in arg3 if parameters are met
    else if (opcode == 6){
        cpu -> pc = arg3;
        return;
    }
    else if (opcode == 7){
        if (cpu -> reg[arg1] == cpu -> reg[arg2]){
            cpu -> pc = arg3;
            
            return;
        }
    }
    else if (opcode == 8){
        if (arg1 != arg2){
            cpu -> pc = arg3;
            return;
        }
    }
    
    // terminate: sets the pc to 32, meaning run_instruction() won't be run
    else if (opcode == 9){
        cpu -> pc = 32;
    }

    else if (opcode == 10){
        printf("here\n");
    }
    
    // iterates pc in the case of most instructions in this function; those that don't require 
    // an increase return within their specific cases
    cpu -> pc++;
}

// uses pointer arithmetic to divide the 32-bit integer into 8-bit integers required for iCPU_step(), 
// then runs iCPU_step() using those integers as inputs
void read_instruction(uint32_t x, CPU* cpu){
    uint8_t* casted_x = (uint8_t*) &x;

    uint8_t opcode = *(casted_x + 3);
    uint8_t arg1 = *(casted_x + 2);
    uint8_t arg2 = *(casted_x + 1);
    uint8_t arg3 = *(casted_x);

    iCPU_step(opcode, arg1, arg2, arg3, cpu);
}


// takes the same inputs as iCPU_step and puts them together as a 32-bit integer in order to be
// interpreted and run by read_instruction(). line_num specifies when the instruction should be
// carried out as the program runs
void write_instruction(uint8_t opcode, uint8_t arg1, uint8_t arg2, uint8_t arg3, int line_num, CPU* cpu){
    uint32_t instruction = 0b0;

    instruction = instruction | opcode;
    instruction = instruction << 8;
    instruction = instruction | arg1;
    instruction = instruction << 8;
    instruction = instruction | arg2;
    instruction = instruction << 8;
    instruction = instruction | arg3;

    cpu -> prog[line_num] = instruction;
}

// uses read_instruction() to run the instruction on whatever line the program is on
void clock_cycle(CPU* cpu){
    read_instruction(cpu -> prog[cpu -> pc], cpu);
}

// runs clock_cycle() repeatedly until the pc reaches 32, when the program ends and "program finished"
// is printed to the console
void run_program(CPU* cpu){
    while (cpu -> pc < 32){
        clock_cycle(cpu);
    }
    printf("program finished\n");
}   