#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "hw4.h"


int main() {
    printf("\n HOMEWORK 4\n\n");

    printf("arr1: arr1[4] = {5, 27, 11, 43}\n");
    printf("Test for uint8_t_arr : uint8_t_arr(arr1): " );
    uint8_t arr1[4] = {5, 27, 11, 43};
    print_uint8_arr(arr1, 4);
    printf(" expected: [ 5 27 11 42 ]\n\n");

    printf("Test for uint8_t_arr_v2: uint8_t_arr_v2(arr1): ");
    print_uint8_arr_v2(arr1, 4);
    printf(" expected: [ 5 27 11 42 ]\n\n");

    printf("Tests for surgical_mult4: \n\n");
    float f1 = 4.0;
    surgical_mult4(&f1);
    printf("Test 1: surgical_mult4(4.0): %f, expected: 16.0\n", f1);

    float f2 = 100.0;
    surgical_mult4(&f2);
    printf("Test 2: surgical_mult4(100.0): %f, expected: 400.0\n\n", f2);

    printf("Test for print_board: size 5, piece at [3][2]:\n");
    int board_size = 5;
    char** board = malloc(sizeof(char*) * board_size);
    for (int j=0; j<board_size; j++) {
        board[j] = malloc(sizeof(char) * board_size);
        for (int i=0; i<board_size; i++) {
            board[j][i] = '.';
        }
    }
    board[3][2] = '@';
    print_board(board, board_size);
    
    printf("Test for move_piece: move_piece(board, 5, 'n') - piece should move to [3][1]\n");
    move_piece(board,5,"e");
    print_board(board, board_size);
    printf("\n");

    printf("Tests for print_stack: will be used to show the rest of question 6\n\n");

    stack stac;
    stac.num_nodes = 0;
    stac.top = NULL;


    printf("Tests for push:\n\n");
    printf("Test 1: push(stack*, 35): should print a stack with one node with value 35\n");
    push(&stac, 35);
    print_stack(&stac);
    printf("\n");
    printf("Test 2: push(stack*, 17): should add a node above the first with value 17\n");
    push(&stac, 17);
    print_stack(&stac);
    printf("\n\n");

    printf("Tests for pop:\n\n");
    printf("Test 1: pop(stack): %d, expected: 17\n", pop(&stac));
    printf("Test 2: pop(stack): %d, expected: 35\n", pop(&stac));
    printf("Test 3: pop(stack): %d, expected: 0\n\n", pop(&stac));

    printf("Test for free_stack: ???\n");
    printf("Not quite sure how to show that i deleted something...\n\n");


    



    

    


    return 0;
}