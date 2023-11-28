#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "hw4.h"

void print_uint8_arr(uint8_t* arr, int num){
    int i = 0;
    printf("[ ");
    
    while (i < num){
        printf("%d ", arr[i]);
        i++;
    }
    printf("]\n");

}

void print_uint8_arr_v2(uint8_t* arr, int num){
    printf("[ ");
    int i = 0;

    while (i < num){
        printf("%d ", *(arr + i));
        i++;
    }
    printf("]\n");

}

void print_uint16_arr(uint16_t* arr, int num){
    printf("[ ");
    int i = 0;

    while (i < num){
        printf("%d ", *(arr + i));
        i++;
    }
    printf("]\n");


    

}

void surgical_mult4(float* fp){
    uint8_t* cast_fp = (uint8_t*) fp;
    
    cast_fp += 3;
    *cast_fp += 1;
}

char* find_substring(char* str1, char* str2){
    int i = 0;
    int j = 0;
    
    char letter1 = str1[i];
    char letter2 = str2[j];

    while (letter1 != '\0'){

        while (letter2 != '\0'){
            
            if (letter1 == letter2){
                return &letter1;
                j++;
            }
            
            i++;
            j = 0;
        }
    }
    return &letter1;
}   

void print_board(char** board, int n){
    for (int i = 0; i < n; i++){
        printf("[ ");
        
        for (int j = 0; j < n; j++){
            printf("%c ", board[i][j]);
        }
        
        printf("]\n");
    }
    printf("\n");
}

void move_piece(char** board, int n, char dir){
    if (dir == 'n'){
        char* temp = board[0];

        for (int i = 1; i < 1; i++){
            board[i - 1] = board[i];
        }
        
        board[n-1] = temp;
    }


    if (dir == 's') {
        char* temp = board[n-1];
        
        for (int i = n-1; i > 0; i--) {
            board[i] = board[i-1];
        }
        
        board[0] = temp;
    }


    if (dir == 'e') {
        
        for (int i = 0; i < n; i++) {
            char temp = board[i][n-1];
            
            for (int j = n-1; j > 0; j--) {
                board[i][j] = board[i][j-1];
            }
            
            board[i][0] = temp;
        }
    }

    if (dir == 'w') {
        
        for (int i = 0; i < n; i++) {
            char temp = board[i][0];
            
            for (int j = 0; j < n-1; j++) {
                board[i][j] = board[i][j+1];
            }
            
            board[i][n-1] = temp;
        }
    }
}  

void push(stack* stack, uint32_t x){
    node* newpt = (node*) malloc(sizeof(node));
    newpt -> value = x;
    
    if (stack -> top == NULL){
        newpt -> next = NULL;
    }
    else{
        newpt -> next = stack -> top;
    }
    
    stack -> top = newpt;
    stack -> num_nodes++;
}

void print_stack(stack* stack){
    int n = stack -> num_nodes;
    node* currentNode = (*stack).top;

    for(int i = 0; i < n; i++){
        printf("%d: %d\n", i+1, (*currentNode).value);
        currentNode = (*currentNode).next;    
    }
}

int pop(stack* stack){
    node* top = stack -> top;
    node* newTop = top -> next;

    if(newTop != NULL){
        stack -> top = newTop;
        stack -> num_nodes--;
        return top -> value;
        free(top);
    }
    else{
        return 0;
    }
}

void free_stack(stack* stack){
    int n = stack -> num_nodes;
    node* currentNode = (*stack).top;
    node* nextNode = currentNode -> next;

    for(int i = 0; i < n; i++){
        free(currentNode);
        currentNode = nextNode;
        nextNode = currentNode -> next;
    }
    free(stack);
}   


