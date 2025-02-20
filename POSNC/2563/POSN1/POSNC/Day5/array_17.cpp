#include <stdio.h>
int main(){
	int A[3][2];
	int B[3][2];
	int sum[3][2]={};
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			printf("Enter A[%d][%d] : ",i+1,j+1 );
			scanf("%d", &A[i][j]);
		}
	}
	printf("\n");
	for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			printf("Enter B[%d][%d] : ",i+1,j+1 );
			scanf("%d", &B[i][j]);
		}
	}
	printf("\nsum :\t");
	for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			sum[i][j]=A[i][j]+B[i][j];
			printf("%d ", sum[i][j]);
		}
		printf("\n\t");
	}
}
