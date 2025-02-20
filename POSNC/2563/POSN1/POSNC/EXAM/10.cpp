#include <stdio.h>
int main(){
	int n,k,j,i,max;
	printf("Enter the number of mountain : ");
	scanf("%d", &n);
	int h[n];
	for(i=0;i<n;i++){
		printf("Enter mount%d height : ", i+1);
		scanf("%d", &h[i]);
		h[i]=2*h[i]-1;
		if(h[i]>max||i==0)
			max=h[i];
	}
	printf("\n");
	for(i=0;i<max;i++){
		if(i%2==1){
			printf("\n");
			continue;
		}
		for(j=0;j<n;j++){
			if(h[j]>max-i-1){
				for(k=0;k<max-i-1;k++)
					printf(" ");
				printf("/");
				for(k=0;k<2*(h[j]+i-max);k++)
					printf(" ");
				printf("\\");
				for(k=0;k<max-i-1;k++)
					printf(" ");
			}
			else
				for(k=0;k<2*h[j];k++)
					printf(" ");
		}
		printf("\n");
	}
}
