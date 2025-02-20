#include <stdio.h>
int i,j,n;
int main(){
	printf("Enter : ");
	scanf("%d", &n);
	int l=n;
	for(i=1;i<=n;i++){
		for(j=l-1;j>0;j--)
			printf(" ");
		for(j=1;j<=i;j++)
			printf("%d", j);
		for(j=i-1;j>0;j--)
			printf("%d", j);
		printf("\n");
		l--;
	}
}
