#include <stdio.h>
int i,k,l,n;
int main(){
	printf("Enter a number : ");
	scanf("%d", &n);
	l=n;
	for(i=1;i<=n;i++){
		for(k=1;k<i;k++)
			printf(" ");
		printf("\\");
		for(k=l-1;k>0;k--)
			printf("  ");
		printf("/\n");
		l--;
	}
}
