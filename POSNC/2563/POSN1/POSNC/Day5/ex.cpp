#include<stdio.h>
int i;
int main(){
	int a[4]={-1,6,9,2};
	int max=-1;
	for(i=1;i<4;i++){
		if(a[i]>max)
			max=a[i];
	}
	printf("The maximum is %d", max);
}
