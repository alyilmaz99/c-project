#include <stdio.h>
#include <stdlib.h>

int main (void){
	
	unsigned int counter;
	int grade;
	int total;
	float average;
	
	total= 0;
	counter= 0;
	
	printf("Enter grade or -1 to end: ");
		scanf("%d",&grade);
	
	while (grade !=-1){
		counter= counter+1;
		total= total+ grade;
		
		printf("Enter grade or -1 to end: ");
		scanf("%d",&grade);
		
		
	}
	
	if(counter!=0){
		average =(float) total/counter;
		
		printf("Average grade: %.2f",average);
		
		
	}
	else {
		printf("SYSTEM EROR!!!");
	}
	
	return 0;
}
