#include <stdio.h>
int n,sum=0;
int main(){
	int i=1;
	printf("Enter \"n\" : ");
	scanf("%d", &n);
	while(i<=n){
		sum+=i;
		i++;
	}
	printf("Summation from 1 to %d : %d", n,sum);
	sum=0;
	i=1;
	do{
		sum+=i;
		i++;
	}while(i<=n);
	printf("\nSummation from 1 to %d : %d", n,sum);
}
