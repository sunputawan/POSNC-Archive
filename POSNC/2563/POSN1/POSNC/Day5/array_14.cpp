#include <stdio.h>
int n,i,j;
int main(){
	int a[5][3];
	int row[5]={};
	int column[3]={};
	for(i=0;i<5;i++){
		for(j=0;j<3;j++){
			printf("Index[%d][%d] : ", i,j);
			scanf("%d", &a[i][j]);
			printf("%d\n", a[i][j]);
		}
	}
	for(i=0;i<5;i++){
		for(j=0;j<3;j++){
			row[i]+=a[i][j];
		}
		printf("row%d : %d\n", i,row[i]);
	}
	for(i=0;i<3;i++){
		for(j=0;j<5;j++){
			column[i]+=a[j][i];
		}
		printf("\ncolumn%d : %d", i, column[i]);
	}
}
