#include <stdio.h>
int n,count, truth_value=1;
int i,j,k;
int main(){
	printf("Please input \"n\" : ");
	scanf("%d", &n);
	
	for(i=2;count!=n;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
				truth_value=0;
		}
		if(truth_value)
			count++;
				
		if(count==n)
			break;
	}
	printf("The %dth prime number is %d", n, i);
}
