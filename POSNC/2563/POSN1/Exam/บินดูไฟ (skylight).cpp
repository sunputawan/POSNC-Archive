#include <stdio.h>
#include <math.h>
int main(){
	int m,n,l,k;
	float c;
	int total=0;
	scanf("%d%d", &n,&m);
	scanf("%d%d", &l,&k);
	scanf("%f", &c);
	int cost[n][m];
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&cost[i][j]);
			total+=cost[i][j];
		}
	}
	total+=(l*k*c);
	printf("%.f", ceil(total/c));
}
