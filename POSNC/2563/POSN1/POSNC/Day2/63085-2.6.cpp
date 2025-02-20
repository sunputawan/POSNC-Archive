#include<stdio.h>
char x;
int main(){
	printf("Please enter a character : ");
	scanf("%c", &x);
	if(x<65||x>122)
		printf("Error!");
	else
	{
		if(x<=90)
			printf("%c",x+32);
		else	if(x>=97)
					printf("%c", x-32);
				else
					printf("Error!");
	}
}
