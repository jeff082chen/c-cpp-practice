#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i, j;
    for(i = 0; i < 17; i++) printf("\t%3d", i);
    printf("\n");
    for(i = 0; i < 17; i++){
        printf("%3d", i);
        for(j = 0; j < 17; j++) printf("\t%3d", i * j);
        printf("\n");
    }
    return 0;
}