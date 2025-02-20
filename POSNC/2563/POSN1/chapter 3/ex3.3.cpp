#include <stdio.h>
int n;
int main(){
	for(n=2;n<=100; n+=2)
		printf("%d\n", n);
	
	
	int n=2;
		while(n<=100)
		{
			printf("%d\n", n);
			n+=2;
		}
	
	n=2;
		
	do
	{
		printf("%d\n",n);
		n+=2;
	}
		while(n<=100);
}
