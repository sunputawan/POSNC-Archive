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
	for(i=0;i<4;i++){
		r=t%10;
		if(r>1){
			printf("Invalid input!");
			return 0;
		}
		sum+=r*pow(2,i);
		t=t/10;
	}
	switch(sum){
		case 10:
			printf("%d in hexadecimal number is 1A", n);
			break;
		case 11:
			printf("%d in hexadecimal number is 1B", n);
			break;
		case 12:
			printf("%d in hexadecimal number is 1C", n);
			break;
		case 13:
			printf("%d in hexadecimal number is 1D", n);
			break;
		case 14:
			printf("%d in hexadecimal number is 1E", n);
			break;
		case 15:
			printf("%d in hexadecimal number is 1F", n);
			break;
		default :
			printf("%d in hexadecimal number is 1%d", n,sum);
	}

}
