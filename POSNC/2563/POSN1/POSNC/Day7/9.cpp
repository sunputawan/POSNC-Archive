#include <stdio.h>
#include <math.h>
#define pi 3.14159265
float print(int);
int main(){
	printf("sin\t\t\tcos\t\t\ttan\n");
	print(0);
}
float print(int a){
	printf("%.4f\t\t\t%.4f\t\t\t%.4f\n", sin(a*pi/180),cos(a*pi/180),tan(a*pi/180));
	if(a<85)
		return print(a+5);
	else
		return 0;
}
