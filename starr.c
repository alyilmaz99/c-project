#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int counter2;
	int value;
	int counter;
	int star;
	int space;
	
	printf ("Value: ");
	scanf("%d", &value);  
	
	star = 2;
	space = value - 1;
	
	for ( counter= 0 ; counter < value ; counter++ ){
		for ( counter2 = 0; counter2 < space ; counter2++){
			printf(" ");
		}
		for(counter2 = 0 ; counter2 < star ; counter2++){
			if(counter2 == 0 ){
				printf("/");
			}else if (counter2 == star -1){
				printf("\\");
			}else {
				printf("*");
			}
			
			}
		printf("\n");
		space--;
		star +=2;
	}
	
	
	star -= 2;
	space = 0;
	
	for ( counter= 0 ; counter < value ; counter++ ){
		for ( counter2 = 0; counter2 < space ; counter2++){
			printf(" ");
		}
		for(counter2 = 0 ; counter2 < star ; counter2++){
			if(counter2 == 0 ){
				printf("\\");
			}else if (counter2 == star -1){
				printf("/");
			}else {
				printf("*");
			}
			
			}
		printf("\n");
		space++;
		star -=2;
	}
	
	
	return 0;
}
