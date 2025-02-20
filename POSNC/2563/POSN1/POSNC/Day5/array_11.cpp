#include <stdio.h>
int main(){
	int n[5];
	int i,j;
	for(i=0;i<5;i++){
		printf("Enter num%d : ", i+1);
		scanf("%d", &n[i]);
	}
	for(i=0;i<5;i++){
		printf("%d\t", n[i]);
		for(j=0;j<n[i];j++)
			printf("*");
		printf("\n");
	}
}
