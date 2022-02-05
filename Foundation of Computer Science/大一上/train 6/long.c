#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float amount;
	int year;
} Bank;

void rate(Bank* bank, float rate);
void money(Bank* bank);

int i;

int main(){
	Bank John, Mary;
	printf("\nPlease enter the John's deposit amount and year\n");
	scanf("%f %d", &John.amount, &John.year);
	printf("\nPlease enter Mary's deposit amount and year\n");
	scanf("%f %d", &Mary.amount, &Mary.year);
	printf("\nJohn's money is %f, and year is %d", John.amount, John.year);
	printf("\nMary's money is %f, and year is %d", Mary.amount, Mary.year);
    money(&John);
	money(&Mary);
	printf("\n\nYear %d, Johnmoney is %f\n", John.year + 1, floor(John.amount));
	printf("Year %d, Marymoney is %f\n\n", Mary.year + 1, floor(Mary.amount));
    printf("%s's money is best!\n\n", John.amount > Mary.amount ? "John" : "Mary");
	return 0;
}

void rate(Bank* bank, float rate){
	for(i = 0; i < bank->year; i++){
		bank->amount *= rate;
	}
}

void money(Bank* bank){
	if(bank->amount <= 100000){
		rate(bank, 1.015);
	}
	else if(bank->amount <= 1000000){
		rate(bank, 1.017);
	}
	else if(bank->amount <= 5000000){
		rate(bank, 1.02);
	}
	else{
		rate(bank, 1.005);
	}
}