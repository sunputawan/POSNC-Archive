#include <stdio.h>
int factorial(int);
int sumfactorial(int,int);
int main(){
	int n;
	scanf("%d", &n);
	printf("%d", 1+sumfactorial(n,0));
}
int factorial(int n){
	if(n>1)
		return n*factorial(n-1);
}
int sumfactorial(int n,int sum){
	sum+=factorial(n);
	if(n>1)
		return sumfactorial(n-1,sum);
}
