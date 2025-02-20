#include<stdio.h>
int fibonacci(int);
int f,n;
int main(){;
	printf("Please input \"n\" : ");
	scanf("%d", &n);
	f = fibonacci(n);
	printf("The %dth fibonacci sequence is %d", n, f);
}
fibonacci(int n){
	if(n==1 || n==2)
		return (n-1);
	else
		return (fibonacci(n-1)+fibonacci(n-2));
}
