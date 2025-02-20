#include <stdio.h>
int i,n,j;
int main(){
	printf("Enter a number : ");
	scanf("%d", &n);
	if(n>26){
		printf("Out of RANGE!");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		for(j=65;j<=65+i;j++)
			printf("%c", j);
		printf("\n");
	}
}
