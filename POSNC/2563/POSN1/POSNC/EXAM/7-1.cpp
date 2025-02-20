#include <stdio.h>
int main(){
	int max,n,i,j,k;
	printf("Enter the number of stalactite : ");
	scanf("%d", &n);
	int h[n];
	for(i=0;i<n;i++){
		printf("Enter stalactite%d height : ", i+1);
		scanf("%d", &h[i]);
		if(i==0||h[i]>max)
			max=h[i];
	}
	printf("\n");
	for(i=0;i<max;i++){
		for(j=0;j<n;j++){
			if(h[j]>i){
				for(k=0;k<i;k++)
					printf(" ");
				printf("\\");
				for(k=0;k<2*(h[j]-(i+1));k++)
					printf(" ");
				printf("/");
				for(k=0;k<i;k++)
					printf(" ");
			}
			else
				for(k=0;k<2*h[j];k++)
					printf(" ");
		}
		printf("\n");
	}
}
