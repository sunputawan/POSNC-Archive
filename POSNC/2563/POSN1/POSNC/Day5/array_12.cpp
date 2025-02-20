#include<stdio.h>
#include <math.h>
int sum,n,r,i,t;
int main(){
	printf("Enter 5-digit binary number : ");
	scanf("%d", &n);
	if(n<9999||n>19999){
		printf("Invalid input!");
		return 0;
	}
	int t=n;
	for(i=0;i<5;i++){
		r=t%10;
		if(r>1){
			printf("Invalid input!");
			return 0;
		}
		sum+=r*pow(2,i);
		t=t/10;
	}
	printf("%d in decimal number is %d", n,sum);
}
