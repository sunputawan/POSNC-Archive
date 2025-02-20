#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int random(int,int);
int main(){
	srand(time(NULL));
	int r;
	r=rand()%100+1;
	random(r,0);
}
int random(int r,int count){
	int n;
	printf("Enter number(1-100) : ");
	scanf("%d",&n);
		if(n>r){
			printf("The number is too high. Try again.");
			count++;
			return random(r,count);
		}
		if(n<r){
			printf("The number is too low. Try again.");
			count++;
			return random(r,count);
		}
		if(n==r){
			printf("Correct!!!");
			if(count==0)
				printf("\nExactly right.");
			return 0;
		}
}
