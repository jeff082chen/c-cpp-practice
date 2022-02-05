#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand((unsigned)time(NULL));
    int i, j, counter = 0, temp;
    int Jiugongge[9], check[9] = {0};
    while(counter != 9){
        temp = rand() % 9;
        if(check[temp] == 0){
            Jiugongge[counter] = temp + 1;
            counter++;
            check[temp] = 1;
        }
    }
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d ", Jiugongge[i * 3 + j]);
        }
        printf("\n");
    }
    return 0;
}