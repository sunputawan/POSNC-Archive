#include<stdio.h>
int i,j,k,n;
int count=0,ItIsPrime=1;
int main(){
	printf("Please input \"n\" : ");
	scanf("%d", &n);
	printf("%d = ", n);
	for(i=2;i<=n; i++)
	{
		if(n%i==0)
		{
			for(j=2;j<i;j++)
			{
				if(i%j==0)
					ItIsPrime=0;
			}
			if(ItIsPrime)
			{
				k=i;
				for(count=0;i<=n;count++)
				{
					if(n%i==0)
						k=k*i;
				}
				printf("%d^%d * ", i, count);
			}
			ItIsPrime =1;
		}
	}				
}
