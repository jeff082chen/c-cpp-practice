#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Bank{
	float amount; int year;
} John, Mary;

void rate(struct Bank* info){
	int i;
	if(info->amount <= 100000) for(i = 0; i < info->year; i++) info->amount *= 1.015;
	else if(info->amount <= 1000000) for(i = 0; i < info->year; i++) info->amount *= 1.017;
	else if(info->amount <= 5000000) for(i = 0; i < info->year; i++) info->amount *= 1.02;
	else for(i = 0; i < info->year; i++) info->amount *= 1.005;
}

int main(){
    int a;
    FILE* input; FILE* output;
    input = fopen("/Users/jeffrey/Library/Mobile Documents/com~apple~CloudDocs/程式設計/計算機概論/train 6/input", "r");
    output = fopen("/Users/jeffrey/Library/Mobile Documents/com~apple~CloudDocs/程式設計/計算機概論/train 6/output", "w");
    if(input == NULL || output == NULL){
        printf("Error\n");
        return 1;
    }
    fprintf(output, "\nPlease enter John's deposit amount and year\n");
	fscanf(input, "%f %d", &John.amount, &John.year);
	fprintf(output, "\nPlease enter Mary's deposit amount and year\n");
	fscanf(input, "%f %d", &Mary.amount, &Mary.year);
	fprintf(output, "\nJohn's money is %f, and year is %d", John.amount, John.year);
	fprintf(output, "\nMary's money is %f, and year is %d", Mary.amount, Mary.year);
	rate(&John); rate(&Mary);
	fprintf(output, "\n\nYear %d, John's money is %f\n", John.year + 1, floor(John.amount));
	fprintf(output, "Year %d, Mary's money is %f\n\n", Mary.year + 1, floor(Mary.amount));
	fprintf(output, "%s's money is best!\n\n", John.amount > Mary.amount ? "John" : "Mary");
    fclose(input); fclose(output);
    return 0;
}