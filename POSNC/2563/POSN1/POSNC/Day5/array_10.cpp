#include<stdio.h>
int n,i,num,max,COUNT;
int main(){
	printf("Enter the number of data : ");
	scanf("%d", &n);
	int count[100]={};
	printf("\n  ********* Please enter POSTIVE data less than 100!.*********\n\n");
	for(i=0;i<n;i++){
		printf("Enter data%d : ", i+1);
		scanf("%d" ,&num);
		count[num-1]++;
		if(num<=0||num>100){
			printf("Invalid input!");
			return 0;
		}
	}
	max=count[0];
	for(i=0;i<100;i++)
		if(count[i]>max)
			max=count[i];
	if(max==1)
		printf("There is no mode in this data.");
	else{
		printf("Mode is ");
		COUNT=0;
		for(i=0;i<100;i++){
			if(max==count[i]){
				COUNT++;
				if(COUNT!=1)
					printf(", ");
				printf("%d",i+1);
			}
		}
		printf(".");
	}
}
