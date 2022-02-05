#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Bank{
	float amount; int year;
} John, Mary;

void rate(struct Bank* info){
	int i; float rate;
	if(info->amount <= 100000) rate = 1.015;
	else if(info->amount <= 1000000) rate = 1.017;
	else if(info->amount <= 5000000) rate = 1.02;
	else rate = 1.005;
	for(i = 0; i < info->year; i++) info->amount *= rate;
}

int main(void){
	printf("\nPlease enter John's deposit amount and year\n");
	scanf("%f %d", &John.amount, &John.year);
	printf("\nPlease enter Mary's deposit amount and year\n");
	scanf("%f %d", &Mary.amount, &Mary.year);
	printf("\nJohn's money is %f, and year is %d", John.amount, John.year);
	printf("\nMary's money is %f, and year is %d", Mary.amount, Mary.year);
	rate(&John); rate(&Mary);
	printf("\n\nYear %d, John's money is %f\n", John.year + 1, floor(John.amount));
	printf("Year %d, Mary's money is %f\n\n", Mary.year + 1, floor(Mary.amount));
	printf("%s's money is best!\n\n", John.amount > Mary.amount ? "John" : "Mary");
	return 0;
}