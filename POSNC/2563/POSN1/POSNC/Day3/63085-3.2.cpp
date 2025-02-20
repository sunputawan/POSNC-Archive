#include <stdio.h>
int main(){
	int n,i=0;
	int max,min;
	while(i<10){
		printf("Input integer%d : ", i+1);
		scanf("%d", &n);
		if(i==0)
			max=min=n;
		if(n>=max)
			max=n;
		if(n<=min)
			min=n;
		i++;
	}
	printf("\n\n\tThe minnimum is %d", min);
	printf("\n\tThe maximum is %d\n", max);
}
