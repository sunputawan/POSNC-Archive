#include <stdio.h>
int i,j,k,l;
int a,b,c;
int main(){
	printf("Enter matrix A dimension (m*n) : ");
	scanf("%d%*c%d", &i, &j);
	printf("Enter matrix B dimesion (n*k) : ");
	scanf("%d%*c%d", &k, &l);
	if(j!=k){
		printf("B can't be multiply by A!'");
		return 0;
	}
	printf("\n");
	int A[i][j];
	int B[j][l];
	int C[i][l]={};
	for(a=0;a<i;a++){
		for(b=0;b<j;b++){
			printf("Enter Matrix A [%d][%d] : ", a+1,b+1);
			scanf("%d",  &A[a][b]);
		}
	}
	for(a=0;a<j;a++){
		for(b=0;b<l;b++){
			printf("Enter Matrix B [%d][%d] : ", a+1,b+1);
			scanf("%d", &B[a][b]);
		}
	}
	for(a=0;a<i;a++){
		for(b=0;b<l;b++){
			for(c=0;c<j;c++){
				C[a][b]+=(A[a][c]*B[c][b]);
			}
		}
	}
	for(a=0;a<i;a++){
		for(b=0;b<l;b++){
			printf("%d ", C[a][b]);
		}
		printf("\n");
	}
}
