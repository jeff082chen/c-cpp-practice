#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i, j, k, l;
    for (i = 1, j = 1, k = 1, l = 1; l < 10; i == 9 ? (j == 9 ? (k == 9 ? (i = j = k = 1, ++l) : (i = j = 1, ++k)) : (i = 1, ++j)) : ++i) {
        printf("%d*%d*%d*%d=%4d%s", l, k, i, j, i * j * k * l, i == 9 ? (j == 9 ? (k == 9 ? "\n\n\n\n\n" : "\n\n") : "\n") : "\t");
    }
    return 0;
}
