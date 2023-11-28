#ifndef HW4_H
#define HW4_H
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_uint8_arr(uint8_t*, int);

void print_uint8_arr_v2(uint8_t*, int);

void surgical_mult4(float*);

void print_uint16_arr(uint16_t*, int);

void surgical_mult4(float*);

char* find_substring(char*, char*);

void print_board(char**, int);

void move_piece(char**, int, char);

typedef struct Node{
    uint32_t value;
    void* next;
} node;

typedef struct Stack{
    node* top;
    int num_nodes;
} stack;

void push(stack*, uint32_t);

void print_stack(stack*);

int pop(stack*);

void free_stack(stack*);
#endif