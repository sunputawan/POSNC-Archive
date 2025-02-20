#include<stdio.h>
int n1,n2,n3,v1,v2,v3;
int m,i,A,B,C;
int main(){
	printf("Please connectedly enter permutable A,B,C (BCA,CAB,CBA, for instance) : ");
	scanf("%c%c%c", &v1,&v2,&v3);
	
	for(i=1;i<=3;i++)
	{
		
		printf("Please input the number%d : ", i);
		scanf("%d",&m);
		if(m<0 || m>100)
		{
			printf("An ERROR occur!, the integer must be different and be positive not more than 100.\n");
			printf("Please run the program again!");
			break;
		}
		else
		{
			if(m>C)
				C=m;
			if(m<A)
				A=m;
			if(m<C && m>A)
				B=m;
		}		
	}
	printf("")
}
