#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int possAns[5040][4], ans[4], c[4] = {0};
int i, j = 0, left = 5040, A, B;
bool over = false;

void allAnser(void);
void makeAnser(void);
void guess(void);
void response(void);
void think(void);

int main(){
    printf("Hello, I'm 1A2B master.\n");
    printf("Each turn, I will guess a 4 digit number.\n");
    printf("And, you're going to tell me A and B according to the 1A2B rule.\n");
    printf("You ready? Let the game start.\n\n");
    allAnser();
	makeAnser();
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

void makeAnser(void){
	srand(time(0));
	bool error;
	  do{
	 	error = false;
	 	for(i = 0; i < 4; i++){
		 	ans[i] = rand() % 10;
		}
		if(ans[0] == ans[1] || ans[0] == ans[2] || ans[0] == ans[3] || ans[1] == ans[2] || ans[1] == ans[3] || ans[2] == ans[3]){
			error = true;
		}
	 }while(error);
}

void guess(void){
    printf("is ");
    for(i = 0; i < 4; i++){
        printf("%d", possAns[0][i]);
    }
    printf(" the anser?\n");
}

void response(void){
    A = B = 0;
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(ans[i] == possAns[0][j]){
                (i == j) ? A++ : B++;
            }
        }
    }
    if(A != 4){
       printf("\n%dA%dB\nTry again!\n\n", A, B);
    }
    else{
		printf("\n%dA%dB\nYou Won!!\n\n", A, B);
        printf("\nI won~~\n");
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
        for(j = 1; j <= 4; j++){
            for(k = 1; k <= 4; k++){
                if(ans[k-1] == possAns[i][j-1]){
                    (j == k) ? a++ : b++;
                }
            }
        }
        if(!(a == A && b == B)){
            for(j = i + 1; j <= left; j++){
                for(k = 1; k <= 4; k++){
                    possAns[j-1][k-1] = possAns[j][k-1];
                }
            }
            left--;
            i--;
        }
    }
}