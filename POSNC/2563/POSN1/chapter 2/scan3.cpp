#include <stdio.h>
int main()
{
	int month;
	int day;
	int year;
	printf("Pls enter your birthday(dd-mm-yyyy) : ");
	scanf("%d%*c%d%*c%d", &day, &month, &year);
	printf("My birthday is : %d-%d-%d",day, month, year );
}
