#include <stdio.h>
int sum=0,n,i;
int main(){
	int num[20];
	for(i=0;i<20;i++){
		printf("Enter index[%d] : ", i);
		scanf("%d", &num[i]);
		if(i%2==1)
			sum+=num[i];
	}
	printf("Result : %d", sum);
}
