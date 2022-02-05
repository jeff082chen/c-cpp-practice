#include <stdio.h>
#include <stdlib.h>

int i;

int rate(int a, int y, int r){
	for(i = 0; i < y; i++){
		a *= r;
		a /= 1000;
	}
	return a;
}

int money(int a, int y){
	if(a <= 100000){
		return rate(a, y, 1015);
	}
	else if(100000 < a && a <= 1000000){
		return rate(a, y, 1017);
	}
	else if(1000000 < a && a <= 5000000){
		return rate(a, y, 1020);
	}
	else{
		return rate(a, y, 1005);
	}
}

int main(){
	int Ja, Ma;
	int Jy, My;
	printf("Please enter the John's deposit amount and year\n");
	scanf("%d %d", &Ja, &Jy);
	printf("\nPlease enter the Mary's deposit amount and year\n");
	scanf("%d %d", &Ma, &My);
	printf("\nJohn's money is %d, and year is %d", Ja, Jy);
	printf("\nMary's money is %d, and year is %d", Ma, My);
	printf("\n\nYear %d, Johnmoney is %d", Jy + 1, money(Ja, Jy));
	printf("\nYear %d, Marymoney is %d", My + 1, money(Ma, My));
	if(money(Ja, Jy) > money(Ma, My)){
		printf("\n\nJohn's money is best!\n");
	}
	else{
		printf("\n\nMary's money is best!\n");
	}
	return 0;
}