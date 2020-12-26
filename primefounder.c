#include <stdio.h>
#include <stdlib.h>

void find_prime(int number);

int main() {
	
	int prime_number;
	
	printf("Please enter a number to find prime numbers that are smaller than the number:");
	scanf("%d", &prime_number);
	
	find_prime(prime_number);
	
	
	
	
	return 0;
}


void find_prime(int number){
	
	int i,j,counter,total_count=0;
	
	for(i=2; i <number; i++){
		counter=0;
		
		for(j=1;j<=i ; j++){
			
			if(i%j == 0){
				counter++;
			}
		}
		
		if(counter==2 ){
			printf("%d ", i);
			total_count++;
		}
	}
	
	printf("There are %d prime number that are smaller than %d \n",total_count, number);
	
}
