#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b){ \
    a = a ^ b;      \
    b = a ^ b;      \
    a = a ^ b;      \
}

int main(void){
    srand((unsigned)time(NULL));
    int Jiugongge[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, num;
    for(i = 0; i < 7; i++){
        num = rand() % (9 - i) + i;
        if(i != num) swap(Jiugongge[i], Jiugongge[num]);
    }
    for(i = 0; i < 9; i++){
        printf("%d%c", Jiugongge[i], (i % 3) == 2 ? '\n' : ' ');
    }
    return 0;
}