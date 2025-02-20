#include <stdio.h>
int factorial(int);
int n;
int main(){
	printf("Please input \"n\" : ");
	scanf("%d", &n);
	printf("%d! = %d ", n ,factorial(n));
}
int factorial(int n){
	if(n<=1)
		return (1);
	else
		return (n * factorial(n-1));
}
