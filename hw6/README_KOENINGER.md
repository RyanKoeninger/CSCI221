## Homework 6

To compile this code, run the following command: 

```gcc hw6.c test.c -o test```

To run MIPS code, open desired file and run through QTspim

### 1(a). iCPU
- **where** the iCPU struct can be found in hw6.h
- **how** stores 3 arrays of signed 32-bit integers: RAM, whose array is 1024 integers, reg, whose array is 32 integers, and prog, whose array is 32 integers. Also contains an int pc, which serves as the program counter
- **notes** none

### 1(b). iCPU_init() and iCPU_destroy()
- **where** the code for iCPU_init() and iCPU_destroy() can be found in hw6.c and hw6.h
- **how** iCPU_init allocates space for a new iCPU, and initializes it with all values in all arrays set to zero. It then returns a pointer to the new iCPU. iCPU_destroy frees the memoey used to store an
- **notes** none 

### 1(c). iCPU_step()
- **where** the code for iCPU_step() can be found in hw6.c and hw6.h
- **how** functions similarly to sCPU_step from hw5, but contains new instructions as well as iterates the pc when certain instructions are called. 
- **notes** none

### 2(a). read_instruction()
- **where** the code for read_instruction() can be found in hw6.c and hw6.h
- **how** takes a 32-bit integer as well as a pointer to an iCPU. The integer is interpreted as the four 8-bit integers required to run iCPU_step, then runs iCPU_step using those integers as well as the pointer to the iCPU
- **notes** none

### 2(b). write_instruction()
- **where** the code for write_instruction() can be found in hw6.c and hw6.h
- **how** takes the four 8-bit integers required to run iCPU_step, an int line_num, and a pointer to an sCPU. It concatenates the four 8-bit integers into a 32-bit integer and places it in the cpu's prog array, at position designated by line_num
- **notes** none

### 2(c). clock_cycle()
- **where** the code for clock_cycle() can be found in hw6.c and hw6.h
- **how** takes a pointer to an iCPU, and runs read_instruction() on the value stored in the pc-th position in the cpu's prog array
- **notes** none

### 2(d). run_program()
- **where** the code for run_program can be found in hw6.c and hw6.h
- **how** takes a pointer to an iCPU and repeatedly runs clock_cycle until the pc reaches 32, indicating that the program has ended. At this point, it prints "program finished" to the console
- **notes** none

### 2(e). Checkpoint 3 from hw5: see test file

### 3(a). jump
- **where** the code for jump can be found under iCPU_step in hw6.c
- **how** if the opcode is 6, sets the pc to the value of arg3
- **notes** none

### 3(b). beq
- **where** the code for beq can be found under CPU_step in hw6.c
- **how** if the opcode is 7, compare the values in registers indicated by arg1 and arg2. If they are equivalent, set the pc to the value of arg3
- **notes** none

### 3(c). bne
- **where** the code for bne can be found under CPU_step in hw6.c
- **how** functions similarly to beq, but sets the pc to the value of arg3 if the values in the register indicated by arg1 and arg2 are not equivalent

### 3(d). terminate
- **where** the code for terminate can be found under CPU_step in hw6.c
- **how** if the opcode is 9, sets the pc to 32 so that run_program() ends the program the next time it is run
- **notes** none

### 4. Executing Machine Instructions: See test file

### 5 - 7: Run as stated above
