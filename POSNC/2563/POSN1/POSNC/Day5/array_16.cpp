#include <stdio.h>
int sum=0;
int i,j;
int main(){
	int a[4][4];
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("Enter index[%d][%d] : ", i,j);
			scanf("%d", &a[i][j]);
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(j>i){
				sum+=a[i][j];
			}
		}	
	}

	printf("The sum of this array diagonol is %d", sum);
}
