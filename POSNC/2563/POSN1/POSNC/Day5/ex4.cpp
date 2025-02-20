#include <stdio.h>
int i,j;
int main(){
	int a[2][2];
	int b[2][2];
	int sum[2][2];
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Aindex[%d][%d] : ", i,j);
			scanf("%d", &a[i][j]);
		}
	}
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Bindex[%d][%d] : ", i,j);
			scanf("%d", &b[i][j]);
		}
	}
	printf("\nsum :\t");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			sum[i][j]=a[i][j]+b[i][j];
			printf("%d ", sum[i][j]);
		}
		printf("\n\t");
	}
}

