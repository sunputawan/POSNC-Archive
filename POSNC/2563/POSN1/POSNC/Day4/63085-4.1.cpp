#include <stdio.h>
int i,n,x=1;
int main(){
	printf("Enter a positive number : ");
	scanf("%d", &n);
	if(n<=0)
	{
		printf("Invalid input!");
		return 0;
	}
	for(i=1;i<=n;i++){
		if(i>=2)
			printf("x ");
		printf("%d ", i);
		x*=i;
	}
	printf("= %d", x);
}
