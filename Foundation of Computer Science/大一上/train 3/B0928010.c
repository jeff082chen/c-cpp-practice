#include <stdio.h>
#include <stdlib.h>

float month(float a, int m, float r1, float r2, float r3){
	switch(m){
		case 1: case 2: case 3:
			return a * r1;
		case 4: case 5: case 6:
			return a * r2;
		default:
			return a * r3;
	}
}

float DM(float a, int m){
	if(a <= 100000){
		return month(a, m, 0.005, 0.01, 0.015);
	}
	else if(100000 < a && a <= 1000000){
		return month(a, m, 0.007, 0.012, 0.017);
	}
	else if(1000000 < a && a <= 5000000){
		return month(a, m, 0.01, 0.015, 0.02);
	}
	else{
		return a * 0.005;
	}
}

int main(){
	float Ja, Ma;
	int Jm, Mm;
	printf("Please enter the John's deposit amount and deposit month\n");
	scanf("%f %d", &Ja, &Jm);
	printf("\nPlease enter the Mary's deposit amount and deposit month\n");
	scanf("%f %d", &Ma, &Mm);
	printf("\nJohn's deposit amount is %.0f, and deposit month is %d", Ja, Jm);
	printf("\nMary's deposit amount is %.0f, and deposit month is %d", Ma, Mm);
	printf("\n\nJohnDM is %f", DM(Ja, Jm));
	printf("\nMaryDM is %f", DM(Ma, Mm));
	if(DM(Ja, Jm) > DM(Ma, Mm)){
		printf("\n\nJohn's deposit interest is best!\n");
	}
	else{
		printf("\n\nMary's deposit interest is best!\n");
	}
	return 0;
}