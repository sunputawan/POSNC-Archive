#include <stdio.h>
int x,y;
int main(){
	printf("Please input \"x\" : ");
	scanf("%d", &x);
	y = x*x+8*x+4;
	printf("x^2+8x+4 = %d", y);
}
