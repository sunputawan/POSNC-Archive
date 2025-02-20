#include <stdio.h>
int fibonacci(int,int,int);
int count=1;
int main(){
	int n;
	scanf("%d", &n);
	if(n==1){
		printf("%d", 1);
		return 0;
	}
	if(n>1){
		printf("%d ", 1);
		fibonacci(n,0,1);
	}
	else
		return 0;
}
int fibonacci(int n,int x1,int x2){
	printf("%d ", x1+x2);
	count++;
	if(count!=n)
		return (fibonacci(n,x2,x1+x2));
}
