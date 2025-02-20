#include <stdio.h>
#include <stdio.h>
int x,n,i,digit=0;
int input(void);
void contain(int);
int CONTAIN[20];
int main(){
	x=input();
	contain(x);
	printf("This is new order of your number : ");
	for(i=0;i<digit+1;i++)
		printf("%d", CONTAIN[i]);
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
void contain(int x){
	CONTAIN[digit]=x%10;
	if(x/10!=0){
		digit++;
		contain(x/10);
		
	}
}

