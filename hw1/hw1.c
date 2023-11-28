#include <stdio.h>
#include "hw1.h"

char choose_mover(boxes){
    char alice = 'A';
    char bob = 'B';
    int aliceLoads = 0;
    int bobLoads = 0;

    aliceLoads += (boxes / 25);
    bobLoads += (boxes / 31);

    if ((boxes % 25 != 0) & (boxes > 25)){
        aliceLoads ++;
    }
    if ((boxes % 31 != 0) & (boxes > 31)){
        bobLoads ++;
    }

    int alicePrice = aliceLoads * 215;
    int bobPrice = bobLoads * 270;

    if (alicePrice <= bobPrice){
        return alice;
    }
    return bob;
}

int fib(num){
    int fib1 = 0;
    int fib2 = 1;
    int pholder = 0;

    for (int i = 0; i < num; i++){
        pholder = fib2;
        fib2 = fib1 + fib2;
        fib1 = pholder;
    }

    return fib1;

}




void print_three_unsigned(int_three x){
    int val = 0;
   
    if (x.four > 0){
        val += 4;}
    if (x.two > 0){
        val += 2;}
    if (x.one > 0){
        val += 1;}

    printf("value of num: %d\n", val);
     
}

void print_three_signed(int_three x){
    int val = 0;
    
    if (x.four > 0){
        val -= 4;
    }
    if (x.two > 0){
        val += 2;
    }
    if (x.one > 0){
        val += 1;
    }
    
    printf("Value : %d\n", val);
}

int_three tiny_add(int_three x, int_three y){
    int_three ans;
    
    int carry = 0;
    
    if (x.one & y.one ){
        ans.one = 0;
        carry = 1;
        }
    else if (x.one | y.one){
        ans.one = 1;
    }
    else {
        ans.one = 0;
    }
   
    if (carry & x.two & y.two){
        ans.two = 1;
        carry = 1;
    }
    else if ((carry & x.two) | (carry & y.two) | (x.two & y.two)){
        ans.two = 0;
        carry = 1;
    }
    else if ((carry | x.two | y.two)){
        ans.two = 1;
        carry = 0;
    }
    else{
        ans.two = 0;
    }

    if (carry & x.four & y.four){
        ans.four = 1;
        carry = 1;
    }
    else if ((carry & x.four) | (carry & y.four) | (x.two & y.four)){
        ans.four = 0;
        carry = 1;
    }
    else if ((carry | x.four | y.four)){
        ans.four = 1;
        carry = 0;
    }
    else{
        ans.four = 0;
    }
    

    printf("Added value: %d%d%d", ans.one, ans.two, ans.four);

    return ans;
}
