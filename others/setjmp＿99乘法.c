#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf jmpbuf1, jmpbuf2;

int main(){
    int n1, n2;
    n1 = setjmp(jmpbuf1) + 1;
    n2 = setjmp(jmpbuf2) + 1;
    if(n1 < 10){
        printf("%d*%d=%2d", n2, n1, n1*n2);
        if(n2 < 9){
            printf("\t");
            longjmp(jmpbuf2, n2);
        }
        else{
            printf("\n");
            longjmp(jmpbuf1, n1);
        }
    }
    return 0;
}