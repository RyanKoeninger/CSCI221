## Homework 4

To compile this code, run the following command: 

```gcc hw4.c test.c -o test```

### 1(a). print_uint8_arr
- **where** the code for print_uint8_arr can be found in hw4.c and hw4.h
- **how** prints the elements in an array the traditional way, by printing the ith element in the array
- **notes** none

### 1(b). print_uint8_arr_v2
- **where** the code for print_uint8_arr_v2 can be found in hw4.c and hw4.h
- **how** operates similarly to print_uint8_arr, but uses pointer arithmetic to print the values of the first slot in the array and then those afterward by adding 1 to the address of the first slot, and printing the value at that slot
- **notes** none

### 1(c). print_uint16_arr
- **where** the code for print_uint16_arr can be found in hw4.c and hw4.h
- **how** same as print_uint8_arr_v2, just with 16-bit integers rather than 8-bit
- **notes** none

### 1(d) and all of 2: see pdf included in hw4


### 3. surgical_mult4
- **where** surgical_mult4 can be found in hw4.c and hw4.h
- **how** takes a pointer to a float, then interprets it as a pointer to a uint8 and adds 3 to it. This changes the exponent of the float, which results in multiplying it by 4
- **notes** none

### 4. find_substring
- **where** the code for find_substring can be found in hw4.c and hw4.h
- **how** takes 2 char*s, then loops through each string comparing each individual substring (ig thats what they're called). If the substrings match, it is returned; otherwise, the /0 signaling the end of a string is returned
- **notes** none

### 5(a). print_board()
- **where** the code for print_board can be found in hw4.c and hw4.h
- **how** takes the board as a char** and an integer representing the size of the board. For each location in the board, it prints the character in that spot in the board char**, as well as brackets for formatting. 
- **notes** none

### 5(b). move_piece
- **where** the code for move_piece can be found in hw4.c and hw4.h
- **how** takes a board as a char** and a char n,e,s,w to indicate the direction the piece should be moved. All of the elements in the board are moved in the direction indicated
- **notes** none

### 6(a). node
- **where** the struct for node can be found in hw4.h
- **how** takes a value as a 32 bit integer and a pointer to the node after it
- **notes** none

### 6(b). stack
- **where** the struct for stack can be found in hw4.h
- **how** takes a node* for its top position, and has an integer representing the total number of nodes in the stack
- **notes** none

### 6(c). push
- **where** the code for push can be found in hw4.c and hw4.h
- **how** takes a stack* and a 32-bit integer, and replaces the top node(if there is one) of the stack with a new node with a value equal to the input integer. If the stack is empty, the stack gets a top node with the value input and nothing needs to be replaced. 
- **notes** none

### 6(d). print_stack
- **where** the code for print_stack can be found in hw4.c and hw4.h
- **how** takes a stack*, and prints the values of all nodes in the stack in the form:
1. <value>
2. <value>

### 6(e). pop
- **where** the code for pop can be found in hw4.c and hw4.h
- **how** takes a stack*, and prints the value of the stack's top node. That node is then removed from the stack and freed from memory, and the stack's new top node is the next node off the previous top node. 
- **notes** only works for the original top node in the stack

### 6(f). free_stack
- **where** the code for free_stack can be found in hw4.c and hw4.h
- **how** takes a stack* and loops through each node in the stack, freeing it. It then frees the empty stack. 
- **notes** none