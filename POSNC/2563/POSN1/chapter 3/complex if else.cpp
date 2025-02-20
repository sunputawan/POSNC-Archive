#include <stdio.h>
int main(){
	int a,b,c1,c2,c3,x=2,y=5050,z1=26, z2=06, z3=2004;
	printf("consider the value of 1+1 : ");
	scanf("%d", &a);
	
	if(a==x)
	{
		printf("Correct!\nconsider the value of 1+2+3+...+99 : ");
		scanf("%d", &b);
		if(b==y)
		{
			printf("Correct!\nwhen was sun's birthday (dd-mm-yyyy): ");
			scanf("%d%*c%d%*c%d", &c1, &c2, &c3);
			if(c1==z1 && c2==z2 && c3==z3)
				printf("Correct!\nYou are at level 3!");
			else
				printf("Incorrect\nYou are at level 2!");
		}
		else
			printf("Incorrect!\nYou are at level 1!");
	}
	else
		printf("STUPID!");
}
