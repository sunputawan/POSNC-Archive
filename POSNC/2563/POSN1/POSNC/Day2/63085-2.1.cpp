#include <stdio.h>
int s1,s2,s3,s4,x;
int main(){
	printf("Enter 4 subject score seperately : ");
	scanf("%d%d%d%d", &s1,&s2,&s3,&s4);
	if(s1>100||s2>100||s3>100||s4>100)
		printf("Invalid input!!");
	else
	{
		x = (s1+s2+s3+s4)/4;
		printf("The average is %d", x);
	}
}
