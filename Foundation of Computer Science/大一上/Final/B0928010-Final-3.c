#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, Chi, Eng, Math;
    char name[20];
} grade;

int main(void){
    FILE* input = fopen("/Users/jeffrey/Library/Mobile Documents/com~apple~CloudDocs/程式設計/計算機概論/Final/Final-3.txt", "r");
    FILE* output = fopen("/Users/jeffrey/Library/Mobile Documents/com~apple~CloudDocs/程式設計/計算機概論/Final/B0928010-Final-3r.txt", "w");
    grade student;
    int i, Sum, Average;
    for(i = 0; i < 10; i++){
        fscanf(input, "%d %s %d %d %d", &student.id, student.name, &student.Chi, &student.Eng, &student.Math);
        Sum = student.Chi + student.Eng + student.Math;
        Average = Sum / 3;
        fprintf(output, "%2d\t%8s\t%3d\t%3d\t%3d\t%3d\t%f\n", student.id, student.name, student.Chi, student.Eng, student.Math, Sum, (float)Average);
    }
    fclose(input); fclose(output);
    return 0;
}