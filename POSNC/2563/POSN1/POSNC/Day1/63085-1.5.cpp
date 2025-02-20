#include <stdio.h>
float w,h,BMI;
int main(){
	printf("Please input your weight(kg) : ");
	scanf("%f", &w);
	printf("Please input your height(m) : ");
	scanf("%f", &h);
	BMI = w/(h*h);
	printf("Your BMI is %.2f", BMI);
}
