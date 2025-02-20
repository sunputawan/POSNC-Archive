#include <stdio.h>
int counteven,countodd;
int max;
int main(){
	int n,i,j;
	printf("Please input \"n\" : ");
	scanf("%d", &n);
	int a[n];
	for(i=0;i<n;i++){
		printf("Enter data%d : ", i+1);
		scanf("%d", &a[i]);
	}
	printf("\n\n");
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if(a[i]+a[j]==37)
				printf("(a[%d]=%d)+(a[%d]=%d)=37\n", j,a[j],i,a[i]);
		}
	}
	for(i=0;i<n;i++){
		if(a[i]%2==0)
			counteven++;
		else
			countodd++;
	}
	printf("There are %d evens and %d odds.", counteven,countodd);
	if(counteven>0){
		for(i=0;i<n;i++){
			if(a[i]%2==0){
				if(i==0){
					max=a[i];
				}
				if(a[i]>=max)
					max=a[i];
			}
		}
		printf("\nThe maximum value of the even data is %d", max);
	}
	else
		printf("Can\'t find the maximum value of the even data because there is no even.");
}
