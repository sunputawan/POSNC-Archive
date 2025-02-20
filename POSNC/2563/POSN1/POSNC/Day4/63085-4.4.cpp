#include <stdio.h>
int i,j,n;
int main(){
	printf("Enter a number : ");
	scanf("%d", &n);
	for(i=1;i<n;i++){
		for(j=1;j<=i;j++){
			printf("*");
		}
		for(j=1;j<=2*(n-i);j++)
			printf(" ");
		for(j=1;j<=i;j++)
			printf("*");
		printf("\n");
	}
	for(i=0;i<2*n;i++)
		printf("*");
	printf("\n");
	for(i=n-1;i>=1;i--){
		for(j=1;j<=i;j++){
			printf("*");
		}
		for(j=1;j<=2*(n-i);j++)
			printf(" ");
		for(j=1;j<=i;j++)
			printf("*");
		printf("\n");
	}
}
