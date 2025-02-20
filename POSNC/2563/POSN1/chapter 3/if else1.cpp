#include <stdio.h>
int main(){
	int pin=260647, input;
	printf("Please enter the PIN :");
	scanf("%d", &input);
	if(input==pin)
		printf("The PIN is correct!");
	else
		printf("The PIN is incorrect, please try again.");
}
