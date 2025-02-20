#include <stdio.h>
int i,m,n,min,max;
int main(){
	printf("Please input the number of numbers : ");
	scanf("%d", &n);
	printf("Please input the number1 : ");
	scanf("%d", &max);
	min=max;
	for(i=2;i<=n;i++)
	{
		printf("Please input the number%d : ", i);
		scanf("%d",&m);
		if(m>max)
			max=m;
		if(m<min)
			min=m;
	}
	printf("\n\nThe minnimum value of the data is %d\n", min);
	printf("The maximum value of the data is %d\n\n\n", max);
	printf("-----------------------THE END OF PROGRAM-----------------------");
}
