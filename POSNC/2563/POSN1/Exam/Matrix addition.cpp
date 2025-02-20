#include <stdio.h>
int m,n,i,j;
int main(){
	printf("Please input m,n (mxn) : ");
	scanf("%d%*c%d", &m,&n);
	int A[m][n], B[m][n];
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("Please input matrixA\'s\' %d%d data: ", i+1,j+1);
		scanf("%d",&A[i][j] );
		}
	}
	printf("\n");
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("Please input matrixB\'s\' %d%d data: ", i+1,j+1);
		scanf("%d",&B[i][j] );
		}
	}
	printf("\n");
	printf("Matrix A + MatrixB :\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("%d ", A[i][j]+B[i][j]);
		}
		printf("\n");
	}
}
