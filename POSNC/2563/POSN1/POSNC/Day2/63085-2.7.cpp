#include <stdio.h>
int th,h,t,o,sum,AD,BE;
int main(){
	printf("Input A.D. : ");
	scanf("%d", &AD);
	BE = AD + 543;
	if(AD>9456)
		printf("A.D. must not be more than 9456.");
	else
	{
		printf("Change to B.E. => %d", BE);
		th=AD/1000;
		h=(AD%1000)/100;
		t=(AD%100)/10;
		o=AD%10;
		sum = th+h+t+o;
		printf("\nSum of A.D. = %d + %d + %d + %d = %d\n", th,h,t,o,sum);
		
		th=BE/1000;
		h=(BE%1000)/100;
		t=(BE%100)/10;
		o=BE%10;
		sum = th+h+t+o;
		printf("Sum of B.E. = %d + %d + %d + %d = %d ", th,h,t,o,sum);
	}
}
