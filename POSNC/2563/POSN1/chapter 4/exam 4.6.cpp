#include <stdio.h>
int x,n;
int input(void);
void reorder(int);
int main(){
	n=input();
	printf("New order of the number : ");
	reorder(n);
}
int input(){
	printf("Please input a number : ");
	scanf("%d", &x);
	if(x<=0){
		printf("Please input positive integer , please try again!\n");
		input();
	}
	else
		return x;
}
void reorder(int x){
	int y;
	y=x%10;
	printf("%d", y);
	if(x/10!=0)
		reorder(x/10);
}
