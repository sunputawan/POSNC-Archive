#include <stdio.h>
void generatemid(int);
void generateedge(int);
int main(){
	int n,i,j;
	scanf("%d", &n);
	for(i=1;i<=(n-1)/2;i++){
		generateedge((n-(2*i-1))/2);
		generatemid(2*i-3);
		generateedge((n-(2*i-1))/2);
		printf("\n");
	}
	for(i=0;i<=(n+1)%2;i++){
		generatemid(n-2-((n-1)%2));
		printf("\n");
	}
	for(i=(n-1)/2;i>=1;i--){
		generateedge((n-(2*i-1))/2);
		generatemid(2*i-3);
		generateedge((n-(2*i-1))/2);
		printf("\n");
	}
}
void generatemid(int a){
	int i;
	printf("*");
	if(a>0){
		for(i=0;i<a;i++)
			printf("-");
		printf("*");
	}
}
void generateedge(int a){
	int i;
	for(i=0;i<a;i++)
		printf("-");
}
