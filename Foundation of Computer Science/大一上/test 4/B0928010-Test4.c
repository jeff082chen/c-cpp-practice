#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int id, year;
    float money, interest, total; 
    char name[20];
} data;

void insert(data* info);
void rate(data* info);

int main(void){
    int option, num = 0, i;
    data customer[10];
    printf("(1) Please insert a costomer:\n");
    printf("(2) Please compute the compound interest for all costomers:\n");
    printf("(3) Please show the list of all costomers:\n");
    printf("(4) Exit:\n\n");
    do{
        printf("please input the choice:\n");
        scanf("%d", &option);
        printf("option is %d\n", option);
        switch(option){
            case 1:
                if(num > 9){
                    printf("error\n\n");
                    break;
                }
                customer[num].id = num;
                insert(&customer[num]);
                printf("insert is ok\n");
                num++;
                break;
            case 2:
                for(i = 0; i < num; i++){
                    rate(&customer[i]);
                }
                printf("compute is ok\n");
                break;
            case 3:
                printf("ID\tName\tMoney\t\tYear\tInterest\tTotal\n");
                for(i = 0; i < num; i++){
                    printf("%d\t%s\t%.1f\t\t%d\t%f\t%f\n", customer[i].id, customer[i].name, customer[i].money, customer[i].year, floor(customer[i].interest), floor(customer[i].total));
                }
        }
        printf("\n");
    }while(option != 4);
    return 0;
}

void insert(data* info){
    printf("Please input the name of the customer:\n");
    scanf("%s", info->name);
    printf("Please input the money of the customer:\n");
    scanf("%f", &info->money);
    printf("Please input the year of the customer:\n");
    scanf("%d", &info->year);
    info->interest = info->total = 0;
}

void rate(data* info){
	int i; float rate;
	if(info->money <= 100000) rate = 1.015;
	else if(info->money <= 1000000) rate = 1.017;
	else if(info->money <= 5000000) rate = 1.02;
	else rate = 1.005;
    info->total = info->money;
	for(i = 0; i < info->year; i++) info->total *= rate;
    info->interest = info->total - info->money;
}