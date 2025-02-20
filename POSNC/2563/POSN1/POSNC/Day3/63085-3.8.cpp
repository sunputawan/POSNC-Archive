#include <stdio.h>
int i=1,j=1;
int n;
int main(){
	printf("Enter a number : ");
	scanf("%d", &n);
	while(i<=n){
		while(j<=n){
			printf("*");
			j++;
		}
		j=1;
		i++;
		printf("\n");
	}
}
