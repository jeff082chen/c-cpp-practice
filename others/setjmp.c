#include <stdio.h>
#include <setjmp.h>

jmp_buf jmpbuffer;

int fun_a(int v){
    if(v < 0){
        longjmp(jmpbuffer, 1);
    }
    return v * 2 - 1;
}

int fun_b(int v){
    if(v > 10){
        longjmp(jmpbuffer, 2);
    }
    return fun_a(v) + 6;
}

int fun_c(int v){
    if(v == 5){
        longjmp(jmpbuffer, 3);
    }
    return fun_b(v) * 5 - 21;
}

int main(){
    int jmpVal = setjmp(jmpbuffer);
    if (jmpVal == 1){
        printf("fun_a error");
    }
    else if(jmpVal == 2){
        printf("fun_b error");
    } 
    else if(jmpVal == 3){
        printf("fun_c error");
    } 
    else{ 
        int x = 4;
        int result = fun_c(x);
        printf("Result = %d", result);
    }
    return 0;
}