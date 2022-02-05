#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int i;
    printf("argument count : %d\n", argc);
    for(i = 0; i < argc; i++){
        printf("argument value [%d] : %s\n", i, argv[i]);
    }
    return 0;
}