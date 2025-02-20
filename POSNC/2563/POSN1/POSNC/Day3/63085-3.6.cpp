#include <stdio.h>
char c;
int main(){
	printf("Please enter a character : ");
	scanf("%c", &c);
	if(c>=97)
		c-=32;
	while(c>=65){
		printf("%c\t", c--);
	}
}
