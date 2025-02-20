#include <stdio.h>
#include <math.h>
float a,b,c;
int main(){
	printf("Please input 2 lenght of the cathetus. : ");
	scanf("%f%f", &a, &b);
	c = sqrt(a*a+b*b);
	printf("The lenght of hypotenuse is %f.", c);
}
