#include <stdio.h>
float b,h,area;
int main(){
	printf("Please enter triangle base : ");
	scanf("%f", &b);
	printf("Please enter triangle height : ");
	scanf("%f", &h);
	area=b*h/2;
	printf("The area of he triangle is %.2f", area);
}
