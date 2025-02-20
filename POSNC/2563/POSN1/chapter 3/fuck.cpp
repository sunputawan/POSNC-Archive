#include<stdio.h>
int n,count,truth_value=1;
int i,j;
int main(){
	printf("Please input \"n\" : ");
	scanf("%d", &n);
	count =0;
	
	for(i=2;count!=n;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				truth_value=0;
			}
		}
		if(truth_value)
			count ++;
		truth_value=1;
		if(count==n)
		{
			printf("The %dth prime number is \"%d\"", n, i);
			break;
		}
	}
}

