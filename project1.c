#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int num1;
	int num2;
	int sum;
	int sub;
	int div;
	int mod;
	int mult;
	
	
	
	printf("Enter first number: ");
	scanf("%d",&num1);
	
	printf("Enter seconda number: ");
	scanf("%d", &num2);
	
	sum = num1+num2 ;
	sub = num1 - num2;
	div = num1 / num2;
	mod = num1 % num2 ;
	mult = num1 * num2;
	
	printf("Sum: %d \n",sum);
	printf("Sub: %d \n",sub);
	printf("Div: %d\n",div);
	printf("Mod:%d \n",mod);
	printf("Multy: %d\n",mult);
	printf("End of the prog..");
	
	
	
	return 0;
}