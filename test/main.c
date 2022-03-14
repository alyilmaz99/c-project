#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void fun1(int j);
int ali(int i);

int main(void) {
        int i = 3;
        fun1(i);
        printf("%d",i);
        ali(i);
        printf("%d",i);



	return 0;
}
int fun1(int j)
{
    printf("%d \ ",++j);
      int a = j;

}
int ali(int i){
printf("%d",++i);
return 0;
}
