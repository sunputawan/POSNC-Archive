#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count=0;
int random(void);
int main(){
	int i,n;
	for(i=0;i<10;i++){
		printf("Enter a number (1-100) : ");
		scanf("%d", &n);
		if(n==random())
			count++;
	}
	printf("you guessed %d times wrong.", 10-count);
}
int random(){
	srand(time(NULL));
	return rand()%100+1;
}
