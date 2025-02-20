#include<stdio.h>
int itisprime=1;
int main(){
	int n;
	printf("Enter \"n\" : ");
	scanf("%d", &n);
	int i=2;
	while(i<n){
		if(n%i==0)
			itisprime=0;
		i++;
	}
	if(itisprime&&n!=1)
		printf("%d is prime!", n);
	else
		printf("%d is not prime!", n);
}
