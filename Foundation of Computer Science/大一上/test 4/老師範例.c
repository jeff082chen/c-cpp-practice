#include<stdio.h>
#include<stdlib.h>

struct customer
{
	int create=0; 
	char name[20];
	int year=0;
	float initial_money=0;
	int compute=0;
	float interest=0; 
	float total=0;		
} static bank[10];
	
struct customer *ptr=bank;
int order=0;
void customerdata(void);
void list(void);
void interestcomput(void);
int bank2(float,int);
int option=0;

int main()
{
	printf("(1) Please insert a customer:\n");
	printf("(2) Please compute the compound interest for all customers:\n");
	printf("(3) Please show the lists of all customers:\n");
	printf("(4) Exit:\n");
	    
	do {
		printf("\nPlease input the choice:\n");
	    scanf("%d", &option);
	    printf("option is %d \n", option);
		switch(option)
        {
        	case 1:
    	     	   customerdata();
				   printf("Insert is ok\n");       
    		       break;
    	    case 2:
    		       interestcomput();
    		       printf("compute is ok\n"); 
    		       break;
    	    case 3:
	               list();
    		       break;   
    	    case 4:
		           break;	   
        }
    }while(option!=4);
}

void customerdata()
{
  int i;
  
  for(i=0;i<10;i++)
  {
  	if(ptr[i].create==0)
  	{
  	 printf("Please input the name of customer:\n");
     scanf("%s", ptr[i].name);
     ptr[i].create=1;
     printf("Please input the money of customer:\n");
     scanf("%f", &ptr[i].initial_money);
     printf("Please input the year of customer:\n");
     scanf("%d", &ptr[i].year);
     break;
    }
  }
}

void interestcomput()
{
  int i;
  
  for(i=0;i<10;i++)
  {
   if(ptr[i].compute==0 && ptr[i].create==1)
   {
   	ptr[i].total=bank2(ptr[i].initial_money,ptr[i].year);
   	ptr[i].interest=ptr[i].total-ptr[i].initial_money;
   	ptr[i].compute=1;   	
   }	
  }
}

int bank2(float money, int year)
{
	float DM, Drates;
	int i;
	
	if(money<=100000)
	{
	  Drates = 0.015;
	  for (i=0; i<year; i++)
	  {
	  	DM= money*Drates;
	  	money= money+DM;
		}
		
	  return money;	  
	}
	else if(money>100000&&money<=1000000)
	{
	  Drates = 0.017;
	  for (i=0; i<year; i++)
	  {
	  	DM= money*Drates;
	  	money= money+DM;
		}
		
	  return money;	  
	}
	else if(money>1000000&&money<=5000000)
	{
	  Drates = 0.02;
	  for (i=0; i<year; i++)
	  {
	  	DM= money*Drates;
	  	money= money+DM;
		}
	  
	  return money;	  
	}
    else if(money>5000000)
	{
	  Drates = 0.005;
	  for (i=0; i<year; i++)
	  {
	  	DM= money*Drates;
	  	money= money+DM;
		}
	  
	  return money;
	 }
}

void list()
{
  int i;
  
  printf("ID\tName\tMoney\t\tYear\tInterest\tTotal\n");

  for(i=0;i<10;i++)
  {
  	if(ptr[i].create==1)
  	{
  	  printf("%d\t%s\t%.1f\t\t%d\t%f\t%f\n",i, ptr[i].name, ptr[i].initial_money, ptr[i].year, ptr[i].interest, ptr[i].total);
  	}
  } 
}
