#include<stdio.h>
int num[10];
int count=0;
int i;
int main(){
	for(i=0;i<10;i++){
		printf("Enter num%d : ", i+1);
		scanf("%d", &num[i]);
		if(num[i]==0){
			printf("Invalid input!, please try again!");
			return 0;
		}
		if(40%num[i]==0)
			count++;
	}
	printf("There are %d number which can divide 40.", count);
}
