#include <stdio.h>
int sum=0,n,i;
int main(){
	int num[20];
	for(i=0;i<20;i++){
		printf("Enter num%d : ", i+1);
		scanf("%d", &num[i]);
		sum+=num[i];
	}
	printf("Result : %d", sum);
}
