#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int roll(void);
int main(){
	srand(time(NULL));
	for(int i=0;i<3;i++){
		printf("dice : ");
		roll();
		printf("%d", roll());
		if(roll()<=3)
			printf("\nlow\n");
		else
			printf("\nhigh\n");
	}
}
int roll(){
	return rand()%6+1;
}
