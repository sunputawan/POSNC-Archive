/* second form of if
	if()
	{
		order1;
		order2;
		order3;
		... 
		ordern;
    }
*/
#include <stdio.h>
int main(){
	int x, y, z;
	printf("Pls enter 2 integers :");
	scanf("%d%d", &x, &y);
	
	if(x>y)
	{
	
		z = x-y;
		printf("x is more than y by %d", z);
	}
	if(x==y)
		printf("x is equal to y");	
	if(x<y)
	{
		z = y -x;
		printf("x is less than y by %d", z);
	}
}
