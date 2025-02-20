#include <stdio.h>
int thousand,five_hundred,one_hundred;
int remain1,remain2,money;
int main(){
	printf("Enter money : ");
	scanf("%d", &money);
	thousand = money/1000;
	remain1 = money%1000;
	five_hundred = remain1/500;
	remain2 = remain1%500;
	one_hundred = remain2/100;
	
	printf("Here is your cash\nB1000 = %d\nB500 = %d\nB100 = %d", thousand, five_hundred, one_hundred);
}
