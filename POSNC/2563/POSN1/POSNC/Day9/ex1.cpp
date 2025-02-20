#include <stdio.h>
int main(){
	char s[20]="COMPUTER";
	char *sp=s;
	while(*sp){
		if(*sp%2==0)
			printf("%c", *sp);
		else
			*sp=*sp+1;
		sp++;
	}
	printf("\n%s", s);
}
