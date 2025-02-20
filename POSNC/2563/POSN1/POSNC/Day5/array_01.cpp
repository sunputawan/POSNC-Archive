#include <stdio.h>
int i;
int main(){
	int num[5];
	for(i=0;i<5;i++){
		printf("Enter num%d : ", i);
		scanf("%d", &num[i]);
	}
	for(i=4;i>=0;i--)
		printf("%d ", num[i]);
}
