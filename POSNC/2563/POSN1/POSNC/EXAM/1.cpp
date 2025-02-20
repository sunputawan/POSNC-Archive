#include <stdio.h>
int main(){
	int i,j,n,sum=0;
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++)
			printf("%d ", j);
		printf("\n");
	}
	if(n<=3)
		printf("No answer");
	else{
		for(i=2;i<=n-2;i++){
			for(j=2;j<=i;j++)
				sum+=j;
		}
		printf("%d", sum);
	}
}
