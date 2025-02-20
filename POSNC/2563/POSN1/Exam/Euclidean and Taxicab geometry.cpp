#include<stdio.h>
#define pi 3.1415926
float taxicab, euclidean, radius;
int main(){
	printf("Please input the radius of taxi's service circle. : ");
	scanf("%f", &radius);
	taxicab = 2*radius*radius;
	euclidean = pi*radius*radius;
	
	if(0<=radius && radius<=10000)
	{
		printf("\nThe Euclidean area is %f\n",euclidean );
		printf("The Taxicab area is %f",taxicab );
	}
	else
			printf("\n\n--- Out of RANGE!, please run the program again.---");
}
