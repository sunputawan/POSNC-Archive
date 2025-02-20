#include <stdio.h>
int divident, divider, result, remainder;
int main()
{
	printf("Input the divident: ");
	scanf("%d", &divident);
	printf("\nInput the divider: ");
	scanf("%d", &divider);
	result = divident/divider;
	remainder = divident% divider;
	printf("\nThe result is %d ", result);
	printf(" and the remainder is %d", remainder);
}
