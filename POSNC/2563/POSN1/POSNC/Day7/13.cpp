#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void roll(void);
int main(){
	printf("dice : ");
	roll();
}
void roll(){
	srand(time(NULL));
	int r;
	r=rand()%6+1;
	printf("%d", r);
	if(r<=3)
		printf("\nlow");
	else
		printf("\nhigh");
}
