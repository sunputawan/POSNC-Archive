#include <stdio.h>
int max,min,n,i;
float aver=0;
int main(){
	printf("Please input \"n\" ; ");
	scanf("%d",&n);
	int data[n];
	for(i=0;i<n;i++){
		printf("Please enter data%d : ", i+1);
		scanf("%d", &data[i]);
	}
	max=data[0];
	min=data[0];
	for(i=0;i<n;i++){
		if(data[i]>=max)
			max=data[i];
		if(data[i]<=min)
			min=data[i];
		aver+= float(data[i])/n;
	}
	printf("\nThe maximum of the data is %d", max);
	printf("\nThe minnimum of the data is %d", min);
	printf("\nThe average of the data is %f", aver);
}
