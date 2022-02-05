#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[4], g[4], c[4];
    int i, j, A, B;
    printf("input four number(0-9) as answer(not repeatable):\n");
    scanf("%d %d %d %d", a, a+1, a+2, a+3);
    while(A != 4){
        A = 0;
        B = 0;
        printf("input four number(0-9) as your guess(not repeatable):\n");
        scanf("%d %d %d %d", g, g+1, g+2, g+3);
        for(i=0; i<4; i++){
            if(a[i] == g[i]){
                A += 1;
                c[i] = 1;
            }
            else{
                c[i] = 0;
            }
        }
        for(i=0; i<4; i++){
            if(c[i] == 0){
                for(j=0; j<4; j++){
                    if(a[i] == g[j]){
                        B += 1;
                    }
                }
            }
        }
        if(A != 4){
            printf("%dA%dB\nTry again!\n", A, B);
        }
    }
    printf("You win!!");
    return 0;
}
