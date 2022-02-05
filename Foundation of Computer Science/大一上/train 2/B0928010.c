#include <stdio.h>

int star(){
		for(int i=0; i<63; i++){
				printf("*");
		}
		printf("\n");
		return 0;
}

int main(){
		float a[6] = {0}, b[6] = {0}, c[5];
		printf("請輸入王曉民的數學, 國文, 英文, 物理, 化學成績:\n");
		scanf("%f %f %f %f %f", a, a+1, a+2, a+3, a+4);
		printf("\n請輸入李春嬌的數學, 國文, 英文, 物理, 化學成績:\n");
		scanf("%f %f %f %f %f", b, b+1, b+2, b+3, b+4);
		printf("\n");
		for(int i=0; i<5; i++){
				a[5] += a[i];
				b[5] += b[i];
				c[i] = ( a[i] + b[i] ) / 2;
		}
		star();
		printf("姓名     數學     國文    英文     物理    化學    總分     平均\n");
		printf("王曉明%6.0f%9.0f%8.0f%9.0f%8.0f%8.0f%10.2f\n",a[0],a[1],a[2],a[3],a[4],a[5],a[5]/5);
		printf("李春嬌%6.0f%9.0f%8.0f%9.0f%8.0f%8.0f%10.2f\n",b[0],b[1],b[2],b[3],b[4],b[5],b[5]/5);
		star();
		printf("科平均   數學     國文     英文    物理     化學\n");
		printf("%13.2f%9.2f%9.2f%8.2f%9.2f\n",c[0],c[1],c[2],c[3],c[4]);
		star();
		return 0;
}

