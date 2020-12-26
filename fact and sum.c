#include <stdio.h>
#include <stdlib.h>


int factorial(int n );

int cumSum(int n );

int main(){
	int n ;
	int sum;
	
	printf("Please enter a number: ");
	scanf("%d", &n);
	if(n<0) {
		printf("ERROR!!");
		
	}else{
	
	
	printf("%d! = %d\n", n , factorial(n));
	
}
	printf("Please enter a number : ");
	scanf("%d", &sum);
	printf("%d ",cumSum(sum));
	
	return 0;
}

int factorial(int n){
	
	
	int fact = 1, i;
	
	for(i=1; i <=n ; i ++){
		fact *=i;
	}
	
	return fact;
}

int cumSum(int n){
	
	int sum = 0, i;
	
	for (i=1; i<=n ; i++){
		sum += i;
	}
	
	return sum;
}
