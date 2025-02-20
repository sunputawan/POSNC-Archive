#include <stdio.h>
int x=1,n1,n2;
int main(){
	printf("Enter 2 number : ");
	scanf("%d%d", &n1,&n2);
	while(x<=1000){
		if(x%n1==0&&x%n2==0)
			printf("%d\t", x);
		x++;
	}
}
