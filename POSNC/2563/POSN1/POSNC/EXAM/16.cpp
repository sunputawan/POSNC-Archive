#include <stdio.h>
int main(){
	int n,i,j,t;
	scanf("%d", &n);
	if(n%2==0){
		printf("odd number!");
		return 0;
	}
	int a[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d", &a[i][j]);
	for(i=0;i<n;i++){
		if(i<=n/2){
			for(j=0;j<i+1;j++){
				t=a[i][j];
				a[i][j]=a[i][n-1-j];
				a[i][n-1-j]=t;
			}
		}
		else{
			for(j=i-1;j>=0;j--){
				t=a[i][j];
				a[i][j]=a[i][n-1-j];
				a[i][n-1-j]=t;
			}
		}
	}
	printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
