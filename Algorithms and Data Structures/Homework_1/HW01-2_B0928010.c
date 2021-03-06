#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//get input string into 'str'
char* readline(void);

//return the length of first name
int firstname_count(char* name);

//insert spaces between first and last name
//original string will be release and return the new one
char* insert_spaces(char* name, int space_count, int firstname_len);

int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int x = 0;
    printf("How many names you would like to input? ");
    scanf("%d", &x);
    putchar('\n');
    getchar();
    
    char** table = (char**)calloc(x, sizeof(char*));
    
    //get input names
    for (int i = 0; i < x; ++i) {
        printf("Name #%d: ", i + 1);
        table[i] = readline();
    }
    putchar('\n');
    
    //find the longest firstname
    int max_firstname = 0;
    for (int i = 0; i < x; ++i) {
        max_firstname = max(max_firstname, firstname_count(table[i]));
    }
    
    //iterate through the names and insert spaces to align the lastname
    for (int i = 0; i < x; ++i) {
        //checking how many extra spaces need to be insert
        int space_count = max_firstname - firstname_count(table[i]);
        if (space_count == 0) continue;
        
        table[i] = insert_spaces(table[i], space_count, firstname_count(table[i]));
    }
    
    //print out
    for (int i = 0; i < x; ++i) {
        printf("%s\n", table[i]);
    }
    
    //release
    for (int i = 0; i < x; ++i) {
        free(table[i]);
    }
    free(table);
    return 0;
}

char* readline(void) {
    int length = 0;
    char* str = (char*)calloc(length + 1, sizeof(char)); //initialize
    //reapeating creat a larger string until '\n'
    while (true) {
        if ((str[length] = getchar()) == '\n') break;
        
        str = (char*)realloc(str, ++length + 1); //resize
    }
    str[length] = '\0'; //terminate
    return str;
}

int firstname_count(char* name) {
    int length = 0;
    //count the number of character before first ' '
    while (*name != ' ' && *name != '\0') {
        ++length; ++name;
    }
    return length;
}

char* insert_spaces(char* name, int space_count, int firstname_len) {
    //creat a temporary string contain spaces
    char* spaces = (char*)calloc(space_count + 1, sizeof(char));
    for (int j = 0; j < space_count; ++j) spaces[j] = ' ';
    spaces[space_count] = '\0'; //terminate
    
    int total_length = (int)strlen(name) + space_count;
    char* temp = (char*)calloc(total_length + 1, sizeof(char)); //temporary buffer
    strncpy(temp, name, firstname_len); //copy first name to temp
    strcat(temp, spaces); //append spaces to temp
    strcat(temp, name + firstname_len); //append rest of the name
    temp[total_length] = '\0'; //terminate
        
    free(name);
    free(spaces);
    return temp;
}
