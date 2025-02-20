#include <stdio.h>
int n,i;
float aver=0;
int main(){
	int num[20];
	for(i=0;i<20;i++){
		printf("Enter num%d : ", i+1);
		scanf("%d", &num[i]);
		aver+= num[i]/20.0;
	}
	printf("The average is %.3f", aver);
}
