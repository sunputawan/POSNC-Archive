#include <stdio.h>
int n,i,j,k,t=1;
int main(){
	printf("Enter a number : ");
	scanf("%d", &n);
	int l=n;
	for(i=1;i<n;i++){
		t=1;
		for(k=1;k<=l-1;k++)
			printf(" ");
		for(j=1;j<=2*i-1;j++){
			switch(t){
				case 1:
					printf("*");
					t=0;
					break;
				case 0:
					printf("_");
					t=1;
					break;
			}
		}
		printf("\n");
		l--;
	}
	t=1;
	for(i=1;i<2*n;i++){
		switch(t){
				case 1:
					printf("*");
					t=0;
					break;
				case 0:
					printf("_");
					t=1;
					break;
			}
	}
	printf("\n");
	t=1;
	l=2;
	for(i=n-1;i>0;i--){
		t=1;
		for(k=1;k<=l-1;k++)
			printf(" ");
		for(j=1;j<=2*i-1;j++){
			switch(t){
				case 1:
					printf("*");
					t=0;
					break;
				case 0:
					printf("_");
					t=1;
					break;
			}
		}
		printf("\n");
		l++;
	}
}
