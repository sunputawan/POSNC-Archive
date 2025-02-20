#include <stdio.h>
int n;
int main(){
	for(n=1;n<=5;n++)
		printf("%d\n",n);
	
	n=10;
	for(;n>=0;n--)
		printf("\n%d",n);
		
	n=7;
	for(;n<=10;)
		printf("\n%d", n++);
	
	n=2;
	for(;n<=5;)						
	{							//for with more than on order must contain "{}" like if.
		printf("\n%d\n", n);
		n=n+1;
	}
	for(n=100;n<=200;printf("%d ", n), n=n+20);   //for which contain order must have ";" at the end.
	
	
	for(n=1;n>5;n++)				//not error but the program wont run the order below this "false" for.
		printf("%d\n", n);
}
