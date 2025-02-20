#include <stdio.h>
int t,a,b,count,n;
int main(){
	printf("Enter number : ");
	scanf("%d", &n);
	a=0,b=1;
	if(n==1)
		printf("%d", a);
	else{
		printf("%d %d ", a,b);
		for(count=3;count<=n;count++){
			t=b;
			b+=a;
			a=t;
			printf("%d ", b);
		}
	}
}
