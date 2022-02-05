#include <stdio.h>
#include <stdlib.h>

int i;

int rate(float a, int y, float r){
	for(i = 0; i < y; i++){
		a *= r;
	}
	return a;
}

float money(float a, int y){
	if(a <= 100000){
		return rate(a, y, 1.015);
	}
	else if(100000 < a && a <= 1000000){
		return rate(a, y, 1.017);
	}
	else if(1000000 < a && a <= 5000000){
		return rate(a, y, 1.02);
	}
	else{
		return rate(a, y, 1.005);
	}
}

int main(){
	float Ja, Ma;
	int Jy, My;
	printf("Please enter the John's deposit amount and year\n");
	scanf("%f %d", &Ja, &Jy);
	printf("\nPlease enter the Mary's deposit amount and year\n");
	scanf("%f %d", &Ma, &My);
	printf("\nJohn's money is %f, and year is %d", Ja, Jy);
	printf("\nMary's money is %f, and year is %d", Ma, My);
	printf("\n\nYear %d, Johnmoney is %f", Jy + 1, money(Ja, Jy));
	printf("\nYear %d, Marymoney is %f", My + 1, money(Ma, My));
	if(money(Ja, Jy) > money(Ma, My)){
		printf("\n\nJohn's money is best!\n");
	}
	else{
		printf("\n\nMary's money is best!\n");
	}
	return 0;
}
