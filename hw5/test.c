#include "hw5.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){
    printf("HOMEWORK 5\n\n");

    printf("Tests for maximum: \n");
    
    int arr1[5] = {5,10,15,20,25};
    printf("Test 1: maximum({5,10,15,20,25}, sizeof(int), 5): %d, expected: 25\n",*(int*) maximum(arr1,sizeof(int), 5));
    
    int arr2[5] = {'a','b','c','d','e'};
    printf("Test 2: maximum({'a','b','c','d','e'}, sizeof(int), 5): %c, expected: e\n\n",*(char*) maximum(arr2,sizeof(int), 5));

    int x = 10;
    int y = 100;

    printf("Tests for CmpInt:\n");

    printf("Test 1: CmpInt(10, 100): %d, expected: -1\n", CmpInt(&x, &y));
    printf("Test 2: CmpInt(100, 10): %d, expected: 1\n", CmpInt(&y, &x));
    printf("Test 3: CmpInt(10, 10): %d, expected: 0\n\n", CmpInt(&x, &x));

    float a = 1.5;
    float b = 27.5;
    printf("Tests for CmpFloat:\n");

    printf("Test 1: CmpFloat(1.5, 27.5: %d, expected: -1\n", CmpFloat(&a,&b));
    printf("Test 2: CmpFloat(1.5, 1.5): %d, expected: 0\n\n", CmpFloat(&a,&a));

    printf("Tests for maximum_v2: \n");
    int arr3[5] = {1,2,3,4,5};
    int ans1 = *(int*) maximum_v2(arr3, sizeof(int), 5, CmpInt);

    float arr4[5] = {1.1, 1.2, 1.5, 1.4, 1.3};
    float ans2 = *(float*) maximum_v2(arr4, sizeof(float), 5, CmpFloat);

    printf("Test 1: maximum_v2({1,2,3,4,5}, sizeof(int), 5, CmpInt): %d, expected: 5\n", ans1);
    printf("Test 2: maximum_v2({1.1, 1.2, 1.5, 1.4, 1.3}, sizeof(float), 5, CmpFloat): %f, expected: 1.5\n\n", ans2);

    printf("Test for CPU_init, CPU_destroy, and CPU_utility: \n\n");

    printf("Checkpoint 2: expected 0, then 257\n");
    CPU* cpu_ptr = CPU_init();
    CPU_step(0,0,0,0, cpu_ptr);
    CPU_step(1,0,1,1, cpu_ptr);
    CPU_step(0,0,0,0, cpu_ptr);
    CPU_destroy(cpu_ptr);

    printf("\nTest for CPU ALU:\n\n");

    printf("Checkpoint 3: expected 40\n");
    CPU* cpu_ptr2 = CPU_init();
    CPU_step(1,1,0,4, cpu_ptr2);
    CPU_step(1,2,0,6, cpu_ptr2);
    CPU_step(2,0,1,2, cpu_ptr2);
    CPU_step(5,0,0,1, cpu_ptr2);
    CPU_step(0,0,0,0, cpu_ptr2);
    CPU_destroy(cpu_ptr2);
    printf("\n");

    printf("Test for CPU RAM:\n\n");
    printf("Checkpoint 4: expected 4\n");
    CPU* cpu_ptr3 = CPU_init();
    CPU_step(1,1,0,4, cpu_ptr3);
    CPU_step(1,2,0,200, cpu_ptr3);
    CPU_step(3,1,2,0, cpu_ptr3);
    CPU_step(4,0,2,0, cpu_ptr3);
    CPU_step(0,0,0,0, cpu_ptr3);
    CPU_destroy(cpu_ptr3);

    printf("\n7. Executing machine instructions:\n\n");
    printf("(a) sum of 1 + 3 + 5 + 7 + 9: ");

    CPU* cpu_ptr4 = CPU_init();
    CPU_step(1,1,0,1, cpu_ptr4); 
    CPU_step(1,2,0,3, cpu_ptr4);
    CPU_step(2,0,1,2, cpu_ptr4);  
    CPU_step(1,1,0,5, cpu_ptr4); 
    CPU_step(2,0,0,1, cpu_ptr4);  
    CPU_step(1,1,0,7, cpu_ptr4); 
    CPU_step(2,0,0,1, cpu_ptr4);  
    CPU_step(1,1,0,9, cpu_ptr4); 
    CPU_step(2,0,0,1, cpu_ptr4); 
    CPU_step(0,0,0,0, cpu_ptr4);
    CPU_destroy(cpu_ptr4);
    printf("expected: 25\n\n");
    
    printf("(b) x++: ");

    CPU* cpu_ptr5 = CPU_init();
    CPU_step(1,1,0,1,cpu_ptr5); 
    CPU_step(1,2,0,20,cpu_ptr5); 
    CPU_step(4,2,2,0, cpu_ptr5);
    CPU_step(2,0,1,2,cpu_ptr5);
    CPU_step(0,0,0,0,cpu_ptr5);
    CPU_destroy(cpu_ptr5);
    printf("expected: 1\n\n");

    printf("(c) array of first 5 powers of 2:\n");

    CPU* cpu_ptr6 = CPU_init();
    CPU_step(1,3,0,2, cpu_ptr6); 
    CPU_step(1,1,0,2, cpu_ptr6); 
    CPU_step(1,2,0,50,cpu_ptr6);  
    CPU_step(3,1,2,0, cpu_ptr6);  
    CPU_step(4,0,2,0, cpu_ptr6); 
    CPU_step(0,0,0,0, cpu_ptr6); 
    CPU_step(5,1,3,1, cpu_ptr6); 
    CPU_step(1,2,0,51,cpu_ptr6);  
    CPU_step(3,1,2,0, cpu_ptr6); 
    CPU_step(4,0,2,0, cpu_ptr6); 
    CPU_step(0,0,0,0, cpu_ptr6); 
    CPU_step(5,1,3,1, cpu_ptr6); 
    CPU_step(1,2,0,52,cpu_ptr6); 
    CPU_step(3,1,2,0, cpu_ptr6);  
    CPU_step(4,0,2,0, cpu_ptr6); 
    CPU_step(0,0,0,0, cpu_ptr6); 
    CPU_step(5,1,3,1, cpu_ptr6); 
    CPU_step(1,2,0,53,cpu_ptr6);  
    CPU_step(3,1,2,0, cpu_ptr6);  
    CPU_step(4,0,2,0, cpu_ptr6); 
    CPU_step(0,0,0,0, cpu_ptr6); 
    CPU_step(5,1,3,1, cpu_ptr6);
    CPU_step(1,2,0,54,cpu_ptr6); 
    CPU_step(3,1,2,0, cpu_ptr6);  
    CPU_step(4,0,2,0, cpu_ptr6); 
    CPU_step(0,0,0,0, cpu_ptr6); 
    CPU_destroy(cpu_ptr6);
    printf("expected: 2, 4, 8, 16, 32\n");
















    return 0;
}