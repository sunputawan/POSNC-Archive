#include <stdio.h>
int f(int);
int main(){
	int x;
	scanf("%d", &x);
	printf("%d", f(x));
}
int f(int x){
	return x*x+1;
}
