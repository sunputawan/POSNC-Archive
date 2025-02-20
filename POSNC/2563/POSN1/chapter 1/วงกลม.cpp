#include <stdio.h>
float radius, area, circumference, pi= 3.141592;
int main(){
	printf("Input the radius : ");
	scanf("%f", &radius);
	area = pi * radius * radius;
	circumference = 2 * pi * radius;
	printf("The area is %f", area);
	printf("\nThe circumference is %f",circumference);
}
