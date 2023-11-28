## Homework 1

To compile this code, run the following command: 

```gcc hw1.c test.c -o test```

To compile command_line_fib, run the following command:

```gcc hw1.c command_line_fib.c -o fib```

### 1. choose_mover()
- **where** the code for choose_mover is in hw1.c and hw1.h
- **how** run choose_mover() code by inputting an integer boxes for the number of boxes moved. For example, choose_mover(27) should output B, since Bob would be cheaper
- **notes** none

### 2(a). fib()
- **where** the code for fib() is in hw1.c and hw1.h
- **how** run fib() by inputting an integer num to find the nth fibbonacci number in the sequence. For example, fib(2) should output 1
- **notes** none

### 3(b). command_line_fib
- **where** the code for command_line_fib is in command_line_fib.c, and it uses code from fib() which is in hw1.c and hw1.h
- **how** run command_line_fib by first compiling it, then inputting ./fib <number>. For example, ./ fib 11 should output 89
- **notes** none

### 3(a). int_three 
- **where** the struct for int_three is in hw1.h
- **how** create a new int_three by assigning each of its three variables one, two, four (each corresponding to which "place" in a binary number they represent) either 0 or 1
- **notes** none

### 3(b). print_three_unsigned()
- **where** the code for print_three_unsigned() is in hw1.h and hw1.c
- **how** run print_three_unsigned() by inputting a predefined int_three. For example, an int_three a with a.one = 1, a.two = 1, a.3 = 0 inputted into print_three_unsigned() should output 3
- **notes** none

### 3(c). tiny_add()
- **where** the code for tiny_add is in hw1.h and hw1.c
- **how** run tiny_add() by inputting two predefined int_three. For example, an int_three 001 and int_three 001 should output 010
- **notes** this program isn't working, and it's too late to actually go through the logic to find what's wrong