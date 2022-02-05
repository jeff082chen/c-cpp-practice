#include <stdio.h>
#include <stdlib.h>

#define foreach(item, arr)                                                                       \
    for(int size = *(&arr + 1) - arr, i = 0, loop = 1; i < size && loop == 1; i++, loop = !loop) \
        for(item = arr + i; loop; loop = !loop)

int main(){
    int arr[5] = {10, 20, 30, 40, 50}; 
    foreach(int* n, arr){
        if(*n > 30)
            break;
        printf("%d ", *n);
    }
    return 0;
}