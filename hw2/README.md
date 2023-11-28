## Homework 2

To compile this code, run the following command: 

```gcc hw2.c test.c -o test```

### 1. mod32() and mod16()
- **where** the code for both programs is in hw1.c and hw1.h
- **how** run both programs by inputting a positive integer to find what that number %32 or %64 is. For example, mod16(17) is 1, and mod32(17) is 17.
- **notes** none

### 2. cond()
- **where** the code for cond() is in hw1.c and hw1.h
- **how** run cond() by inputting three integers: x, y, and z. x is the true/false integer, so zero means false and any other number means true. y is what is returned if x is true, and z is what is returned if x is false.
- **notes** none

### 3. Number Representation
(a) max: 8191 min: 0
(b) max: 4095 min: -4096
(c) max: 4294967295  min: 0
(d) max: 18446744073709551615 min: 0
(e) max: 65535.9999847412109375 min: 0.0000152587890625
(f) max: 4294967295.99999999976716935634 min: 0.00000000023283064365


### 4(a) swap_bits()
- **where** the code for swap_bits() can be found in hw2.c and hw2.h
- **how** input 3 unsigned 16 bit integers x, i, and j. x is the number which will be altered, i is position of the first bit, and j is the second bit. swap_bits() switches the bits in positions i and j, so swap_bits(5,0,1) should return 6 because 101 becomes 111 after the 0th and 1st bit change positions.
- **notes** none

### 4(b). reverse()
- **where** the code for reverse() is in hw2.h and hw2.c
- **how** reverse() takes three unsigned 16 bit integers x, i, and j. x is the number which will be changed, i is one bound, and j is another bound. The bits in positions i --> j will be reversed. For example, reverse(12,1,2) should return 10.
- **notes** none

### 4(c). is_bin_pal()
- **where** the code for is_bin_pal is in hw2.h and hw2.c
- **how** is_bin_pal() takes an unsigned integer x and checks if that number's reverse is the same, ignoring leading and trailing zeros. It returns 1 if the number is a palindrome, and 0 if the number is not. For example, is_bin_pal(5) should return 1, and is_bin_pal(6) should return 0.
- **notes** none

### 4(d). 
A number that is a hexadecimal palindrome is not neccesarily a binary palindrome. For example, 0xFEF is a palindrome, but its binary representation 111111101111 is not a palindrome. Similarly, a binary palindrome is not neccesarily a hex palindrome. For example, 111101111 is a palindrome, but its hex representation 1EF is not a palindrome.