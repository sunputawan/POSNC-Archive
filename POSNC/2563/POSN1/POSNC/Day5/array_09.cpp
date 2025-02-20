#include <stdio.h>
float min,max,aver;
int n,i;
int main(){
	printf("How many data do you want to input (max=5) : ");
	scanf("%d", &n);
	if(n>5||n<=0){
		printf("Invalid input!");
		return 0;
	}
	float num[n];
	for(i=0;i<n;i++){
		printf("Enter data%d : ", i+1);
		scanf("%f", &num[i]);
		if(i==0)
			min=max=num[i];
		if(num[i]>max)
			max=num[i];
		if(num[i]<min)
			min=num[i];
		aver+=num[i]/(n);
	}
	printf("Average ; %.3f\nMaximum : %f\nMinnimum : %f", aver,max,min);
}
