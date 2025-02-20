#include <stdio.h>
int n,i,j,l;
int main(){
	printf("Enter : ");
	scanf("%d", &n);
	l=n;
	for(i=0;i<n;i++){
		for(j=l;j>1;j--)
			printf(" ");
		for(j=i;j>=0;j--)
			printf("%d", j);
		for(j=1;j<=i;j++)
			printf("%d", j);
		printf("\n");
		l--;
	}
}
