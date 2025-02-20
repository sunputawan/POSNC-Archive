#include<stdio.h>
int i,j,k,n;
int count=0,ItIsPrime=1;
int main(){
	printf("Please input \"n\" : ");
	scanf("%d", &n);
	printf("%d = ", n);
	for(i=2;n%i==0; i++)
	{
		for(j=2;j<i;j++)
			if(i%j==0)
				ItIsPrime=0;
		switch(ItIsPrime)
		{
			case 0:
				break;
			case 1:
				k=i;
				while(n%k==0)
				{
					count++;
					k=k*i;
				}
				printf("%d^%d * ", i, count);
				break;
		}
		ItIsPrime=1;
		count=0;
	}
}
	
	
