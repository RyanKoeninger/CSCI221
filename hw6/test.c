#include "hw6.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int main(){
    printf("HOMEWORK 6\n\n");

    printf("hw5 checkpoint 3: expected 40, followed by 'program finished'\n");
    
    CPU* cpu1 = iCPU_init();
    
    // opcode, arg1, arg2, arg3, line
    
    write_instruction(1,1,0,4,0,cpu1); // put 4 into r1
    write_instruction(1,2,0,6,1,cpu1); // put 6 into r2
    write_instruction(2,0,1,2,2,cpu1); // r0 = r1 + r2
    write_instruction(5,0,0,1,3,cpu1); // r0 = r0 * r1
    write_instruction(0,0,0,0,4,cpu1); // print r0
    write_instruction(9,0,0,0,5,cpu1); // terminate
    run_program(cpu1);

    printf("\n");
    printf("i ++ 100 times: expected 100, followed by 'program finished'\n");

    CPU* cpu2 = iCPU_init();

    // -------------------- setup --------------------
    write_instruction(1,0,0,1,0,cpu2); // put 1 into r0 : this will be placed in ram to be iterated
    write_instruction(3,0,20,0,1,cpu2); // put the value in r0 into the 20th spot in ram
    write_instruction(1,1,0,1,2,cpu2); // put 1 into r1 : this will be used to iterate
    write_instruction(1,2,0,100,3,cpu2); // put 100 into r2 to use beq to run the loop until i reaches 100
    // -------------------- setup --------------------

    // -------------------- loop ---------------------
    write_instruction(4,0,20,0,4,cpu2); // load the number being iterated from the 20th spot in ram to r0
    write_instruction(7,0,2,9,5,cpu2); // beqs the number being iterated, stored in r0, with
                                                     // 100 which is stored in r2. if equal, moves to the end
                                                     // of the program
    write_instruction(2,0,1,0,6,cpu2); // adds the number, in r0, with 1, in r1, and stores that number back in
                                       // r0
     
    write_instruction(3,0,20,0,7,cpu2); // stores the newly added number back in the 20th spot in ram
    write_instruction(6,0,0,4,8,cpu2); // jumps back to the beginning of the loop
    // -------------------- loop ---------------------

    // -------------------- ending ---------------------
    write_instruction(4,0,20,0,9,cpu2); // loads the value in the 20th spot of ram into r0
    write_instruction(0,0,0,0,10,cpu2); // prints the value in r0 to the console
    write_instruction(9,0,0,0,11,cpu2); // terminates the program
    run_program(cpu2);
    

    return 0;
}