#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int possAns[5040][4];
int i, j = 0, left = 5040, A, B;
bool over = false;

void allAnser(void);
void guess(void);
void response(void);
void think(void);

int main(){
    printf("Hello, I'm 1A2B master.\n");
    printf("Each turn, I will guess a 4 digit number.\n");
    printf("And, you're going to tell me A and B according to the 1A2B rule.\n");
    printf("You ready? Let the game start.\n\n");
    while(true){
        allAnser();
        while(!over){
            guess();
            response();
            if(over){
                break;
            }
            think();
            printf("-------------------------------\n");
        }
        printf("Game Over.");
        break;
    }
    return 0;
}

void allAnser(void){
    int dig1, dig10, dig100, dig1000;
    for(i = 0; i < 10000; i++){
        dig1 = i % 10;
        dig10 = ( i / 10 ) % 10;
        dig100 = ( i / 100 ) % 10;
        dig1000 = ( i / 1000 ) % 10;
        if(dig1 != dig10 && dig1 != dig100 && dig1 != dig1000 && dig10 != dig100 && dig10 != dig1000 && dig100 != dig1000){
            possAns[j][3] = dig1;
            possAns[j][2] = dig10;
            possAns[j][1] = dig100;
            possAns[j][0] = dig1000;
            j++;
        }
    }
}

void guess(void){
    printf("is ");
    for(i = 0; i < 4; i++){
        printf("%d", possAns[0][i]);
    }
    printf(" the anser?\n");
}

void response(void){
    bool error;
    do{
        error = false;
        printf("A : ");
        scanf("%d", &A);
        printf("B : ");
        scanf("%d", &B);
        if(A + B > 4 || A < 0 || A > 4 || B < 0 || B > 4){
            printf("error!!\n");
            error = true;
        }
    }while(error);
    if(A == 4){
        printf("\nI won~~\n");
        over = true;
    }
    else if(left == 1){
        printf("Wait, that's impossible......\n");
        printf("YOU Liar!!\n\n");
        over = true;
    }
}

void think(void){
    int k, a, b;
    int ans[4];
    for(i = 0; i < 4; i++){
        ans[i] = possAns[0][i];
    }
    for(i = 0; i < left; i++){
        a = b = 0;
        for(j = 1, k = 1; j <= 4; k == 4 ? k = 1, j++ : k++){
            if(ans[k-1] == possAns[i][j-1]){
                if(j == k){
                    a++;
                }
                else{
                    b++;
                }
            }
        }
        if(!(a == A && b == B)){
            for(j = i, k = 1; j <= left; k == 4 ? k = 1, j++ : k++){
                possAns[j][k-1] = possAns[j+1][k-1];
            }
            left--;
            i--;
        }
    }
    if(left == 0){
        printf("Wait, that's impossible......\n");
        printf("YOU Liar!!\n\n");
        over = true;
    }
}