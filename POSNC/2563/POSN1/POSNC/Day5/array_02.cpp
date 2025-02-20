#include <stdio.h>
int i,n;
int main(){
	printf("Please enter \"N\" : ");
	scanf("%d", &n);
	int num[n];
	for(i=0;i<n;i++){
		printf("Enter num%d : ", i+1);
		scanf("%d", &num[i]);
	}
	for(i=n-1;i>=0;i--)
		printf("%d ", num[i]);
}
