#include <stdio.h>
int count,n,i;
int main(){
	int num[20];
	for(i=0;i<20;i++){
		printf("Enter num%d : ", i+1);
		scanf("%d", &num[i]);
		if(num[i]>0)
			count++;
	}
	printf("There are %d positive integer(s).", count);
}
