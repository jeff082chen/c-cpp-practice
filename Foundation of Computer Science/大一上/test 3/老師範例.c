#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int option, sum1, sum2, fi, product1, product2;
	int i;
	int sum=0, fib1=0, fib2=0, fib3=1, product=1;
	
	printf("(1) Do the Sum with continuous numbers: (ex. 2 10)\n");
    printf("(2) Do the Fibonacci with several times: (ex. 10)\n");
    printf("(3) Do the Product with continuous numbers: (ex. 2 10)\n");
	printf("Please input the choice:\n");
    scanf("%d",&option);
    printf("option is: %d\n\n",option);
    
    switch(option)
    {
    	case 1:
    		   printf("Please input the continuous numbers for sum:");
    		   scanf("%d %d",&sum1, &sum2);
    		   printf("continuous numbers: %d %d\n",sum1, sum2);
    		   for (i=sum1;i<sum2+1;i++)
    		   {
    		   	sum=sum+i;
    		   }
    		   printf("Th sum is: %d\n",sum);
    		   break;
    	case 2:
    		   printf("Please input the times of Fibonacci:");
	           scanf("%d",&fi);
	           printf("times is: %d\n",fi);
	           printf("Fibonacci sequence: ");
	           for (i=0;i<fi;i++)
    		   {
    		   	printf("%d ",fib3);
    		   	fib1=fib2;
    		   	fib2=fib3;
    		    fib3=fib1+fib2;    		   	
    		   }
    		   printf("\n");
    		   break;
    	case 3:
	           printf("Please input the continuous numbers for product:");
	           scanf("%d %d",&product1, &product2);
	           printf("continuous numbers: %d %d\n",product1, product2);
			   for (i=product1;i<product2+1;i++)
    		   {
    		   	product=product*i;
    		   }
    		   printf("Th product is: %d\n",product);
    		   break;   
     }

    return 0;
}