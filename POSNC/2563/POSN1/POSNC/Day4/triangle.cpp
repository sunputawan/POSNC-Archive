#include <stdio.h>
int n,i,j,k,l;
int main(){
	printf("Enter number : ");
	scanf("%d", &n);
	l=n;
	for(i=0;i<=n;i++){
		for(k=0;k<l;k++)
		{
			printf(" ");
		}
		for(j=0;j<2*i-1; j++)
			printf("*");
		printf("\n");
		l--;
	}
}
