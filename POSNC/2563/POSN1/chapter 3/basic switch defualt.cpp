#include <stdio.h>
int value;
int main(){
	puts ("Enter 1 or 2: ");
	scanf("%d", &value);
	switch (value)
	{
		case 1 :
			printf("It\'s one.\n");
			break;
		case 2 :
			printf("It\'s two.\n");
			break;
		default :
			printf("Out of RANGE!\n");
	}
	puts("End of program");
}
