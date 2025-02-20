#include <stdio.h>
int value;
int main(){
	puts("Please enter an intger: ");
	scanf("%d", &value);
	switch(value % 2)
	{
		case 0 :
			printf("It\'s even.\n");
			break;
		case 1 :
			printf("It\'s odd.\n");
	}
}
