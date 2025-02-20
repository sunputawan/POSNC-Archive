#include <stdio.h>
float u,a,s,t;
int main(){
	printf("Enter u : ");
	scanf("%f", &u);
	printf("Enter a : ");
	scanf("%f", &a);
	for(t=2;t<=20;t+=2){
		s = u*t+0.5*a*t*t;
		printf("S(%.0f) = %.2f m\n", t, s);
	}
}
