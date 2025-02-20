#include <stdio.h>
int main(){
	int i,n,j,max;
	printf("Input index : ");
	scanf("%d", &n);
/*	if(n<1||n>10){
		printf("Out of RANGE!");
		return 0;
	}*/
	int data[n];
	for(i=0;i<n;i++){
		printf("Input number [%d] : ",i);
		scanf("%d", &data[i]);
		if(i==0||data[i]>max)
			max=data[i];
	}
	printf("   ");
	for(i=0;i<n;i++){
		printf("__ ");
	}
	printf("\n");
	for(i=max;i>=1;i--){
		printf("%2d|", i);
		for(j=0;j<n;j++){
			if(data[j]>=i)
				printf("* |");
			else
				printf("  |");
		}
		printf("\n");
	}
/*	printf("%2d|", 0);
	for(i=0;i<n;i++)
		printf("  |");*/
	printf("   ");
	for(i=0;i<n;i++)
		printf("__ ");
	printf("\n   ");
	for(i=0;i<n;i++)
		printf("%-3d", i);
}
