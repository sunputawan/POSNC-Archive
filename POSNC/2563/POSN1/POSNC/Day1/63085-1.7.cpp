#include<stdio.h>
#include<math.h>
float a1,a2;
float b1,b2;
float P1,P2,l;
int main(){
	printf("Please input x1,y1 : ");
	scanf("%f%*c%f", &a1,&b1);
	printf("Please input x2,y2 : ");
	scanf("%f%*c%f", &a2,&b2);
	P1 = pow(a1-a2,2);
	P2 = pow(b1-b2,2);
	l=sqrt(P1+P2);
	printf("The lenght between 2 point is %f", l);
}
