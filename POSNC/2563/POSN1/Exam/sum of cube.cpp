//consider the value of 1^3 + 2^3 + 3^3 + ... + n^3
#include <stdio.h>
int sum,i,n;
int main(){
	sum =0;
	printf("Please input \"n\" : ");
	scanf("%d", &n);
	for(i=1;i<=n;i++)
		 sum += i*i*i;
	if(n>=1)
	{
		switch(n){
			case 1 :
				printf("1^3 = %d", sum);
				break;
			case 2 :
				printf("1^3 + 2^3 = %d", sum);
				break;
			case 3 :
				printf("1^3 + 2^3 + 3^3 = %d", sum);
				break;
			default :
				printf("1^3 + 2^3 + 3^3 + ... + %d^3 = %d", n,sum);
				break;
		}
	}
	else
		printf("\"n\" must be positive integer, please try agian!");
	
}
