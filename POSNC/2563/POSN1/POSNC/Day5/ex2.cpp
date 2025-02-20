#include <stdio.h>
#define SIZE 4
int num,sum,i;
int main(){
	int num[SIZE]={1,4,5,7};
	for(i=0;i<SIZE;i++)
		sum+=num[i];
	printf("%d", sum);
}
