#include <stdio.h>
#include <stdlib.h>


int main (){
	
		//10 student in this class and their grades s avarage 
	
	unsigned int counter;
	int grade;
	int total;
	int average;
	
	counter = 1;
	total = 0;
	 
	while (counter<=10){
		
		printf("Enter grade: ");
		scanf("%d",&grade);
		
		total= total + grade;
		counter = counter + 1;
			}
	
	average= total/10 ;
	
	printf("Average : %d",average);
	
	
	
	return 0 ;
}
