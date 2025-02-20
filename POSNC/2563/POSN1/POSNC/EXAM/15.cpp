#include <stdio.h>
int main(){
	int pin[3][7],sum[7]={},pass[5]={};
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<7;j++)
			scanf("%d", &pin[i][j]);
	for(i=0;i<7;i++)
		sum[i]+= (pin[0][i]+pin[1][i]+pin[2][i]);
	for(i=0;i<5;i++){
		pass[i]+=(sum[i]+sum[i+1]+sum[i+2]);
		printf("%d ", pass[i]);
	}
}
