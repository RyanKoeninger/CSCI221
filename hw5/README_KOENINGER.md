## Homework 5

To compile this code, run the following command: 

```gcc hw5.c test.c -o test```

For the MIPS, open hw5.asm in QTSpim and run as normal

### 1(a). maximum()
- **where** the code for maximum() can be found in hw5.c and hw5.h
- **how** takes the base address of an array as a void*, the size of an element in the array, and the number of elements in the array and uses pointer arithmetic and a simple comparison to return a pointer to the highest value in the array
- **notes** none

### 1(b). CmpInt()
- **where** the code for CmpInt() can be found in hw5.c and hw5.h
- **how** takes in two void*s a and b. If a < b, returns -1. If a > b, returns 1. Otherwise if a == b, return 0
- **notes** none 

### 1(c). CmpFloat()
- **where** the code for CmpFloat() can be found in hw5.c and hw5.h
- **how** carries out the same function and returns the same values as CmpInt(), but with floats rather than ints. 
- **notes** none

### 1(d). maximum_v2()
- **where** the code for maximum_v2() can be found in hw5.c and hw5.h
- **how** takes the base address of an array as a void*, the size of an element in the array, the number of elements in the array, and either CmpInt() or CmpFloat() as a comparison function, and uses those functions to find the highest value in the input array. That value is then returned as a void*
- **notes** none


### 2. Assembly power 2
- **where** the assembly code for computing powers of 2 can be found in hw5.asm
- **how** place the desired power of 2 in the second argument of the first line under main:, then run the program through QTSpim. The power of 2 will be placed in $v1
- **notes** stored the answer in $v1 rather than $v0 to keep it there after running the program in full since $v0 is used to terminate the program and will overrwrite the value that we are trying to get

### 3(a). sCPU
- **where** the struct for sCPU can be found in hw5.h
- **how** stores 2 arrays of signed 32-bit integers: RAM, whose array is 1024 integers, and reg, whose array is 32 integers
- **notes** none

### 3(b). CPU_init()
- **where** the code for cpu_init() can be found in hw5.c and hw5.h
- **how** takes no parameters, but allocates a new sCPU on the heap and sets all the values of its alu and RAM to 0.  Returns a pointer to the new sCPU as a void* 
- **notes** none

### 3(c). CPU_destroy()
- **where** the code for CPU_destroy() can be found in hw5.c and hw5.h
- **how** takes a pointer to an allocated sCPU and frees the memory used to store it
- **notes** none

### 3(d). Checkpoint 1: See test file

### 4. CPU_step()
- **where** the code for CPU_step can be found in hw4.c and hw4.h
- **how** takes 4 uint8_ts as opcode, arg1, arg2, and arg3, as well as a pointer to an sCPU
- **notes** none

### 4(a). print
- **where** the code for print can be found under CPU_step in hw4.c
- **how** if the opcode is 0, prints the value in the 0th register of the input sCPU
- **notes** none

### 4(b). put
- **where** the code for put can be found under CPU_step in hw4.c
- **how** if the opcode is 1, concatonates the values in arg2 and arg3 (both 8-bit integers) into a single 32-bit integer with 16 zeroes followed by arg2 and then arg3. The new value is placed into the register, in position designated by the value of arg1
- **notes** none

### 4(c). Checkpoint 2: See test file

### 5. ALU

### 5(a). add
- **where** the code for add can be found under CPU_step in hw4.c
- **how** if the opcode is 2, add the values of arg2 and arg3 and store the result in the register, position designated by arg1
- **notes** none

### 5(b). mul
- **where** the code for mul can be found under CPU_step in hw4.c
- **how** when the opcode is 5, multiply the values of arg2 and arg3 and store the result in the register, position designated by arg1

### 5(c). Checkpoint 3: see test file

### 6. RAM

### 6(a). store
- **where** the code for store can be found under CPU_step in hw4.c
- **how** if the opcode is 3, take a value in the register, whose position is designated by arg1, and place it in RAM, position designated by arg2
- **notes** none

### 6(b). load
- **where** the code for load can be found under CPU_step in hw4.c
- **how** if the opcode is 4, takes a value stored in RAM, position designated by arg2, and places it in the register, designated by arg1
- **notes** none

### 6(c). Checkpoint 4: See test file

### 7. Executing machine instructions: see test file