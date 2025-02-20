#include <stdio.h>
int n;
int main(){
	while(n!=3){
		printf("Enter a number : ");
		scanf("%d", &n);
		switch(n){
			case 1:
				printf("Hello\n");
				break;
			case 2:
				printf("Thank you\n");
				break;
			case 3:
				printf("Good bye");
				break;
			default :
				printf("Sorry\n");
				break;
		}
	}
}
