#include <stdio.h>
float min,max,aver;
int i,n;
float x;
int main(){
	printf("Please enter \"n\" : ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		printf("Data%d : ", i+1);
		scanf("%f", &x);
		if(x<=0||x>=100){
			printf("Out of RANGE!");
			return 0;
		}
		if(i==0)
			min=max=x;
		if(x>=max)
			max=x;
		if(x<=min)
			min=x;
		aver+=(x/n);
	}
	printf("The maximum is %.2f\nThe minnimum is %.2f\nThe average is %.2f", max,min,aver);
}
