#include <stdio.h>
int num,limit,i;
void text(int num,int limit);
int main()
{
	printf("Input one digit number : ");
	scanf("%d", &num);
	printf("Input limit : ");
	scanf("%d",&limit);
	text(num,limit);
}
void text(int num, int limit)
{
	for(i=1;i<=limit;i++)
		printf("%d", num);
}
