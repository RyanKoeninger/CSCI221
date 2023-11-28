## Homework 2

To compile this code, run the following command: 

```gcc hw3.c test.c -o test```

### 1(a). float_bits
- **where** the code for the float_bits union can be found in hw3.c
- **how** uses a union to allow floating point numbers to be edited with bitwise operators
- **notes** none

### 1(b). power2_floor()
- **where** the code for power2_floor can be found in hw3.c and hw3.h
- **how** input a float, and the function will return the highest power of 2 less than the value of the input. For example, power2_floor(19) should return 16. 
- **notes** none

### 1(c). set_exp()
- **where** the code for set_exp can be found in hw3.c and hw3.h
- **how** input a float for the base number and an int for what the float's new exp should be. The old exp in the float will be swapped out for the new one. For example, set_exp(2, 5) should return 32.
- **notes** none

### 2. print_fixed_pt()
- **where** the code for print_fixed_pt can be found in hw3.c and hw3.h
- **how** input a uint16_t. The first 8 digits will be interpreted as the whole number portion of the number, and the last 8 will be interpreted as the fractional part. For example, print_fixed_point(0000000110000000) should return 1.5.
- **notes** none

### 3(a). sfloat16
- **where** the struct for sfloat16 can be found in hw3.h
- **how** name the struct, then set the structs exp and sig to use it in later functions. For example, if the struct is named x, then if x.sig = 1 and x.exp = 1, it represents a floating point number with those same values in the exponent and significand. 
- **notes** none

### 3(b). print_sfloat_dec()
- **where** the code for print_sfloat_dec can be found in hw3.c and hw3.h
- **how** input any sfloat16, and print_sfloat_dec will print out the decimal number represented by the sfloat16.
- **notes** none

### 3(c). add_sfloat()
- **where** the code for add_sfloat can be found in hw3.c and hw3.h
- **how** input two sfloat16s, and their sum will be returned as a floating point number. 

