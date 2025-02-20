#include<stdio.h>
float r,a;
float area(float);
int main(){
	printf("Please input the radius : ");
	scanf("%f", &r);
	a = area(r);
	printf("The area of %f radius circle is %f", r,a);
}
float area(float r){
	return (3.1415926 * r * r);
}
