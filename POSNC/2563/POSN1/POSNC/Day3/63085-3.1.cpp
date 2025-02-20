#include <stdio.h>
int main(){
	int n,i=0;
	float sum=0;
	while(i<10){
		printf("Input integer%d : ", i+1);
		scanf("%d", &n);
		sum+=n;
		i++;
	}
	printf("The average is %.2f", sum/10);
}
