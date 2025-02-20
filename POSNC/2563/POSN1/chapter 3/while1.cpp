#include <stdio.h>
int n;
int main(){
	n=1;
	while(n<=5)
	{
		printf("%d\n", n);
		n++;				//n++ (operate before adding one)
	}
	n=1;
	while(n<=5)
		printf("\n%d", ++n); //++n(add one before operating)
	n=1;
	while(n=5)
		printf("\n%d", n++);	//keep on printing 5
}


