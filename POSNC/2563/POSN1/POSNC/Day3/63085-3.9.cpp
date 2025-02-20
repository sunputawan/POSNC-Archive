#include <stdio.h>
int n;
int i=1,j=1,k=1,l;
int main(){
	printf("Enter a number : ");
	scanf("%d",&n);
	l=n;
	if(n>60)
		printf("The maximum triangle height is 60, please try again!");
	else{
		while(i<=n){
			while(k<l){
				printf(" ");
				k++;
			}
			while(j<=2*i-1){
				printf("*");
				j++;
			}
			printf("\n");
			j=1;
			i++;
			k=1;
			l--;
		}
	
	}
}
