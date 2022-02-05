#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//sort Strings by the first character, with descending order
void bubble_sort(char** table, int size);
//get input String into 'str', with maximum length of 'size'
void get_str(char* str, int size);
//retrun true if a < b, otherwise return false
bool is_smaller(char* a, char* b);

int main(void) {
    int x, y;
    printf("How many String you would like to input?: ");
    scanf("%d", &x);
    printf("Input the maximum length for each String: ");
    scanf("%d", &y);
    putchar('\n');
    getchar(); //ignore '\n'

    //creat two dimensional array with dynamic allocation
    char** table = (char**)calloc(x, sizeof(char*));
    for (int i = 0; i < x; ++i) {
        table[i] = (char*)calloc(y + 1, sizeof(char)); //one more space for '\0'
    }

    //get input Strings from user
    for (int i = 0; i < x; ++i) {
        printf("String #%d: ", i + 1);
        get_str(table[i], y);
    }
    putchar('\n');

    bubble_sort(table, x);

    //print out each String
    printf("Strings in descending order:\n");
    for (int i = 0; i < x; ++i) {
        printf("%s\n", table[i]);
    }

    //release the two dimensional array
    for (int i = 0; i < x; ++i) {
        free(table[i]);
    }
    free(table);
    return 0;
}

void bubble_sort(char** table, int size) {
    char* temp = NULL; //temporary buffer
    //bubble sort
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (is_smaller(table[j], table[j + 1])) {
                temp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = temp;
            }
        }
    }
}

void get_str(char* str, int size) {
    for (int i = 0; i < size; ++i) {
        if ((str[i] = getchar()) != '\n') continue;
        
        //input string is short then 'size'
        str[i] = '\0'; //replace '\n' with '\0'
        return;
    }
    //input string is equal or longer then 'size'
    while(getchar() != '\n'); //clear buffer
    str[size] = '\0'; //terminate
}

bool is_smaller(char* a, char* b) {
    //compare each character till one of the String is end
    while (*a != '\0' && *b != '\0') {
        if (*a < *b) return true;
        if (*a > *b) return false;
        ++a; ++b;
    }
    //if one of the String is ended, the other one is larger
    return *b != '\0';
}
