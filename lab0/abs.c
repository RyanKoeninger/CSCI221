#include <stdio.h>
    
int abs(int num) {
    if (num < 0) {
        return (- num);
    }
    return (num);
}   

int main(){
    int num = abs(-5);
    
    printf("%d\n", num);

    return 5;

}

