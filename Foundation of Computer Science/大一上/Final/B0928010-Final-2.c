#include <stdio.h>
#include <stdlib.h>

int additionTest(int num1, int num2);
int substractionTest(int num1, int num2);
int multiplicationTest(int num1, int num2);
int divisionTest(int num1, int num2);

int main(void){
    int num1, num2, isCorrect = 0, total = 0, correct_time = 0, option;
    while(1){
        printf("Exit or Not? (y or n)\n");
        if(getchar() != 'n'){
            break;
        }
        printf("Please input two integers:");
        scanf("%d %d", &num1, &num2);
        printf("\nThe input two integers are: %d %d\n", num1, num2);
        printf("(1) Addition exercises:\n");
        printf("(2) Substraction exercises:\n");
        printf("(3) Multiplication exercises:\n");
        printf("(4) Division exercises:\n");
        printf("Please select the choice:");
        scanf("%d", &option);
        printf("\nThe choice is: %d\n", option);
        switch(option){
            case 1:
                isCorrect = additionTest(num1, num2);
                break;
            case 2:
                isCorrect = substractionTest(num1, num2);
                break;
            case 3:
                isCorrect = multiplicationTest(num1, num2);
                break;
            case 4:
                isCorrect = divisionTest(num1, num2);
                break;
        }
        printf("anser is %s!\n\n", isCorrect ? "correct" : "wrong");
        total += 1;
        correct_time += isCorrect;
        while(getchar() != '\n');
    }
    printf("This exam has %d question, the correct anser is %d\n\n", total, correct_time);
    return 0;
}

int additionTest(int num1, int num2){
    int anser;
    printf("Please do the addition for %d and %d\n", num1, num2);
    printf("Please input the answer:");
    scanf("%d", &anser);
    return (anser == (num1 + num2));
}

int substractionTest(int num1, int num2){
    int anser;
    printf("Please do the substraction for %d and %d\n", num1, num2);
    printf("Please input the answer:");
    scanf("%d", &anser);
    return (anser == (num1 - num2));
}

int multiplicationTest(int num1, int num2){
    int anser;
    printf("Please do the multiplication for %d and %d\n", num1, num2);
    printf("Please input the answer:");
    scanf("%d", &anser);
    return (anser == (num1 * num2));
}

int divisionTest(int num1, int num2){
    int anser;
    printf("Please do the division for %d and %d\n", num1, num2);
    printf("Please input the answer:");
    scanf("%d", &anser);
    return (anser == (num1 / num2));
}