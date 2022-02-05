#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i, n1, n2, option;
    printf("(1) Do the Sum with continuous numbers: (ex. 2 10)\n");
    printf("(2) Do the Fibonacci with several times: (ex. 10)\n");
    printf("(3) Do the Product with continuous numbers: (ex. 2 10)\n");
    printf("Please input the choice:\n");
    scanf("%d", &option);
    printf("option is: %d\n\n", option);
    switch(option){
        case 1:
            printf("Please input the continuous numbers for sum:");
            scanf("%d %d", &n1, &n2);
            printf("continuous numbers: %d %d\n", n1, n2);
            printf("The sum is: %d\n\n", (n1 + n2) * (n2 - n1 + 1) / 2);
            return 0;
        case 2:
            printf("Please input the times of Fibonacci:");
            scanf("%d", &n1);
            printf("times is: %d\nFibonacci sequence:", n1);
            int* arr = (int*)calloc(n1, sizeof(int));
            for(i = 2; i < n1; i++) arr[i] = arr[i - 1] + arr[i - 2] + 1;
            for(i = 0; i < n1; i++) printf("%d%s", arr[i] + 1, i == n1 - 1 ? "\n\n" : " ");
            free(arr);
            return 0;
        case 3:
            printf("Please input the continuous numbers for product:");
            scanf("%d %d", &n1, &n2);
            printf("continuous numbers: %d %d\n", n1, n2);
            for(i = n1 + 1; i <= n2; i++) n1 *= i;
            printf("The product is: %d\n\n", n1);
            return 0;
    }
}