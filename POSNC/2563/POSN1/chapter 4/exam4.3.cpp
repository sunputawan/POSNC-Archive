#include<stdio.h>
float maximum(float,float);
float minnimum(float,float);
float average(float,float,int);
float x,y;
float a,max,min,aver;
int n,i;
int main(){
	printf("Please input \"n\" : ");
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		printf("Please input data%d : ", i);
		scanf("%f", &a);
		if(i==1)
			max=min=a;
		max = maximum(a,max);
		min = minnimum(a,min);
		aver = average(a,aver,n);
	}
	printf("\nThe maximum of the data is %f\n", max);
	printf("The minnimum of the data is %f\n", min);
	printf("The average of the data is %f", aver);
}
float maximum(float x,float y){
	if(x>y)
		return x;
	else
		return y;
}
float minnimum(float x,float y){
	if(x>y)
		return y;
	else
		return x;
}
float average(float a,float aver,int n){
	return (aver+(a/n));
}

