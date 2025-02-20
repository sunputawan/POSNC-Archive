#include <stdio.h>
#include <math.h>
float perimeter(float,float);
int main(){
	float a,b,x;
	scanf("%f", &a);
	scanf("%f", &b);
	printf("%.2f", perimeter(a,b));
}
float perimeter(float a, float b){
	return (a+b+sqrt(pow(a,2)+pow(b,2)));
}
